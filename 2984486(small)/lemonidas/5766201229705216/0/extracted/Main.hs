{-# LANGUAGE TupleSections #-}

-- For Input
import qualified Data.ByteString as BS
import qualified Data.ByteString.Char8 as BSC
import qualified Data.ByteString.Lex.Double as BSD
import Data.Char (isSpace)
import Data.IORef
import Text.Printf

-- Data Structure Imports
import Data.Maybe
import Data.List
import Data.Set (Set)
import qualified Data.Set as Set
import Data.IntMap.Strict (IntMap)
import qualified Data.IntMap.Strict as IntMap
import Data.Map.Strict (Map)
import qualified Data.Map.Strict as Map

-- These should be imported by default... :)
import Control.Monad
import Control.Applicative
import Control.Arrow

import Debug.Trace

import Control.Monad
import Control.Monad.ST
import Data.Array
import Data.Array.ST

type Vertex  = Int
type Graph = Array Vertex [Vertex]


--------------------------------------------------------------------------------
------------------------------- SOLUTION ---------------------------------------
--------------------------------------------------------------------------------

createUndirGraph :: Int -> [(Vertex, Vertex)] -> Graph
createUndirGraph n edges = 
    runSTArray $ do
      arr <- newArray (1,n) []
      forM_ edges $ \(u,v) -> 
          readArray arr u >>= 
          writeArray arr u . (v:) >>
          readArray arr v >>= 
          writeArray arr v . (u:)          
      return arr

fullest :: Vertex -> Vertex -> Graph -> Int 
fullest root parent graph = 
    let children = filter (/= parent) $ graph ! root in
    case children of 
      (_:_:_) -> 
          let (n1:n2:_) = reverse $ sort $ map (\x -> fullest x root graph) children 
          in n1 + n2 + 1
      _ -> 1

main :: IO ()
main = do 
  all   <- BS.getContents
  input <- newIORef all
  let parse = next input 
  cases <- parse int
  forM_ [1..cases] $ \caseNum -> do
         n <- parse int
         edges <- parse . readMany int2 $ n - 1
         let graph = createUndirGraph n edges
         let solution = n - (maximum $ map (\n -> fullest n (-42) graph) [1..n])
         printf "Case #%d: %d\n" caseNum solution

--------------------------------------------------------------------------------
-------------------------- IO Function Helpers ---------------------------------
--------------------------------------------------------------------------------

type Parser a = BSC.ByteString -> (a, BSC.ByteString)

int :: Parser Int
int = second (BSC.dropWhile isSpace) . fromJust . BSC.readInt

int2 :: Parser (Int, Int)
int2 = uncurry (first . (,)) . second int . int

int3 :: Parser (Int, Int, Int)
int3 = uncurry (first . (uncurry (,,))) . second int . int2

double :: Parser Double
double = second (BSC.dropWhile isSpace) . fromJust . BSD.readDouble

char :: Parser Char
char = BSC.head &&& BSC.tail

letter :: Parser Char
letter = second (BSC.dropWhile isSpace) . char 

string :: Parser String
string = (BSC.unpack *** BSC.dropWhile isSpace) . BSC.span (not . isSpace)

readMany :: Parser a -> Int -> Parser [a]
readMany f n bs = first reverse $ 
                  foldr (\_ (l,bs) -> first (:l) $ f bs) ([],bs) [1..n]

intMany :: Int -> Parser [Int]
intMany = readMany int

next :: IORef BSC.ByteString -> Parser a -> IO a
next input parse = do
  bs <- readIORef input
  let (x, bs') = parse bs
  writeIORef input bs'
  return x