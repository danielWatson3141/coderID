{-# LANGUAGE TupleSections #-}

-- For Input
import qualified Data.ByteString as BS
import qualified Data.ByteString.Char8 as BSC
import qualified Data.ByteString.Lex.Double as BSD
import Data.Char (isSpace)
import Data.IORef
import Text.Printf

-- Data Structure Imports
import Data.Function
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

import System.Random (randomRIO)
import Debug.Trace

--------------------------------------------------------------------------------
------------------------------- SOLUTION ---------------------------------------
--------------------------------------------------------------------------------

good :: [(Int,Int)] -> Int -> IO [(Int,Int)]
good [] _ = return []
good l@((x1,x2):t) n = do 
  k <- randomRIO (0,n-1) 
  let (front, (y1,y2):back) = break ((< k) . fst) l 
  fmap ((x1,y2):) $ good (front ++ [(y1,x2)] ++ back) (n-1)

bad :: [(Int,Int)] -> Int -> Int -> IO [(Int,Int)]
bad l k n 
    | k == n = return l
    | otherwise = do
  k' <- randomRIO (0,n-1) 
  if k == k' then bad l (k+1) n 
  else let k1 = min k k'
           k2 = max k k'
           (front , (x1,x2):back ) = break ((>= k1) . fst) l 
           (front', (y1,y2):back') = break ((>= k2) . fst) back
       in bad (front ++ [(x1,y2)] ++ front' ++ [(y1,x2)] ++ back') (k+1) n

test :: Int -> IO [Int]
test n = do
  fmap (map snd) $ bad (map (join (,)) [0..n-1]) 0 n

test1 :: IO ()
test1 = do 
  let x = 8
  all <- fmap (sortBy (compare `on` (!! x))) $ forM [1..10000] $ const $ test 10
  putStrLn $ show $ map length $ (groupBy ((==) `on` (!! x))) all

main :: IO ()
main = do
  all   <- BS.getContents
  input <- newIORef all
  let parse = next input 
  cases <- parse int
  forM_ [1..cases] $ \caseNum -> do
         n <- parse int -- n == 1000
         perm <- parse $ intMany n
         printf "Case #%d: " caseNum
         let n1 = length $ filter id $ zipWith (==) [1..n] perm 
             n2 = length $ filter id $ zipWith (==) [2..(n+1)] perm
             n3 = length $ filter id $ zipWith (==) [3..(n+2)] perm
             n4 = length $ filter id $ zipWith (==) [4..(n+3)] perm
         if (n1+n2+n3+n4) >= 5 then
             putStrLn "BAD"
         else putStrLn "GOOD"
         
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
