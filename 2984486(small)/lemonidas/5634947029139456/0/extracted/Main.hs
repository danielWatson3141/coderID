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
import Data.Function
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

--------------------------------------------------------------------------------
------------------------------- SOLUTION ---------------------------------------
--------------------------------------------------------------------------------

flipC '0' = '1'
flipC '1' = '0'
flip' = map flipC
powerset = filterM $ const [True, False]

doFlips :: [Int] -> [String] -> [String] 
doFlips f l = transpose $ applyFlips f 0 $ transpose l

applyFlips :: [Int] -> Int -> [String] -> [String]
applyFlips [] _ l = l
applyFlips (c:cs) n (h:t)
    | n == c    = flip' h : applyFlips cs (n+1) t
    | otherwise = h : applyFlips (c:cs) (n+1) t


main :: IO ()
main = do 
  all   <- BS.getContents
  input <- newIORef all
  let parse = next input 
  cases <- parse int
  forM_ [1..cases] $ \caseNum -> do
         (n,l)  <- parse int2
         flow   <- parse $ readMany string n
         target <- fmap sort $ parse $ readMany string n
         all <- forM (sortBy (compare `on` length) $ powerset [0..l-1]) $ \flips ->
                  return $ (length flips, sort $ doFlips flips flow)
         let solution =
                 case filter ((== target) . snd) all of 
                   [] -> "NOT POSSIBLE"
                   ((len,_):_) -> show $ len
         -- let solution = 
         -- solution <- 
         printf "Case #%d: %s\n" caseNum solution

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
