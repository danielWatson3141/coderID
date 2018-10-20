{-# OPTIONS_GHC -Wall -XScopedTypeVariables #-}
{-# LANGUAGE MultiParamTypeClasses, FunctionalDependencies #-}
{-# LANGUAGE TypeSynonymInstances, FlexibleInstances, TupleSections #-}

module Main where

-- Needed
import Control.Monad
import Text.Printf (printf)

-- For Debugging
import System.IO (stderr,hPrint)
import System.IO.Unsafe (unsafePerformIO)
import Control.DeepSeq () --(deepseq)

import Data.Maybe (catMaybes)
import Data.Set (Set)
import qualified Data.Set as Set

-- import Control.Monad.Instances ()
-- import Control.Arrow (first, second)
-- import Data.Function (on) -- on :: (b -> b -> c) -> (a -> b) -> a -> a -> c
-- TRY THIS: sortBy (compare `on` fst) || (*) `on` f = \x y -> f x * f y.

----------------------------------------------------------------------------------------------------------
readLines :: Int -> IO [String]
readLines n = mapM (const getLine) [1..n]

readIntLine :: IO [Int]
readIntLine = liftM (map read . words) getLine

readIntLines :: Int -> IO [[Int]]
readIntLines = liftM (map (map read . words)) . readLines
----------------------------------------------------------------------------------------------------------
debugIO :: Show a => a -> IO ()
debugIO = hPrint stderr

debugTrace :: Show a => a -> b -> b
debugTrace x y = unsafePerformIO $ debugIO x >> return y
----------------------------------------------------------------------------------------------------------
class CodeJamProblem i o x | i -> x, x -> o, o -> i where
  readCase  :: IO x
  solveCase :: i -> x -> o
  printCase :: o -> String

handleCase :: CodeJamProblem i o x => Bool -> i -> Int -> IO ()
handleCase inlined input no = do
  answer <- liftM (solveCase input) readCase
  let descriptor | inlined   = "Case #%d: %s\n"
                 | otherwise = "Case #%d:\n%s\n"
  printf descriptor no (printCase answer)
----------------------------------------------------------------------------------------------------------

-- Instantiation
--------------------------------------------
{-
type Game = (Int, Int)

instance CodeJamProblem Int Bool Game where
  readCase    = liftM (\[x,y] -> (x,y)) readIntLine
  --solveCase i = liftM2 (==) (max i . fst) (min i . snd)
  solveCase i = \(x,y) -> max i x == min i y
  printCase   = show
-}

oflip :: Char -> Char
oflip '0' = '1'
oflip '1' = '0'
oflip _   = error "oflip"

data Info = Info { info_n :: Int
                 , info_l :: Int
                 , info_outlets :: Set String
                 , info_devices :: Set String
                 }

instance CodeJamProblem () (Maybe Int) Info where
  readCase = do
    [n,l]   <- readIntLine
    outlets <- liftM words getLine
    devices <- liftM words getLine
    return $ Info n l (Set.fromList outlets)
                      (Set.fromList devices)

  solveCase () (Info _ l outlets devices) -- = undefined
    | null almost_there = Nothing
    | otherwise = Just $ minimum almost_there

    where all_possibles = explode 0 l (0,outlets)
          almost_there  = catMaybes $
            [ if out == devices then Just z else Nothing
            | (z,out) <- all_possibles]

  printCase Nothing  = "NOT POSSIBLE"
  printCase (Just i) = show i
  

fixNth :: Int -> Int -> Set String -> Set String
fixNth i n = Set.map (\s -> [ if j==i then oflip c
                                      else c
                            | (c,j) <- zip s [0..(n-1)]])

explode :: Int -> Int -> (Int, Set String) -> [(Int, Set String)]
explode i l (changes, outlets)
  | i >= l = []
  | otherwise
  = (changes  ,  outlets)
  : (changes+1, foutlets)
  :  explode (i+1) l (changes  , outlets)
  ++ explode (i+1) l (changes+1,foutlets)
  where foutlets = fixNth i l outlets



-------------------------------------------------

main :: IO ()
main = do
  [n] <- readIntLine
  forM_ [1..n] $ handleCase True ()


