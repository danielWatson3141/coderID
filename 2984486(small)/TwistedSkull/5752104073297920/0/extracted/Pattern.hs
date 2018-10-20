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

type Input = [(Int,Int)] -- Index first, number second

instance CodeJamProblem () Bool Input where
  readCase = do
    nums <- getLine >> readIntLine
    return $ zip [0..999] nums

  -- oversimplified :P
  solveCase () inp = not $  anySamePos inp
                         || startsZero inp
                         || highLow inp

  printCase ans | ans  = "GOOD"
                | True = "BAD"

-- BAD
anySamePos :: [(Int,Int)] -> Bool
anySamePos = any (\(x,y) -> x==y)

-- BAD
startsZero :: [(Int,Int)] -> Bool
startsZero ((0,0):_) = True
startsZero _         = False

-- BAD
highLow :: [(Int,Int)] -> Bool
highLow list = length (filter (<500) ups) < 250
  where ups  = map snd (drop 500 list)
-------------------------------------------------

main :: IO ()
main = do
  [n] <- readIntLine
  forM_ [1..n] $ handleCase True ()


