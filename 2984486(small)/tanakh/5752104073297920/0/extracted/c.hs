{-# LANGUAGE BangPatterns #-}

import Control.Monad
import Control.Applicative
import Data.List
import Data.Maybe
import Text.Printf
import Debug.Trace
import qualified Data.Map.Strict as M
import qualified Data.IntMap.Strict as IM
import System.IO
import Data.Array.IO
import System.Random
import System.Random.MWC

good gen n = do
  arr <- newListArray (0, n-1) [0..n-1] :: IO (IOUArray Int Int)
  forM_ [0..n-1] $ \i -> do
    j <- uniformR (i, n-1) gen
    iv <- readArray arr i
    jv <- readArray arr j
    writeArray arr i jv
    writeArray arr j iv
  getElems arr

bad gen n = do
  arr <- newListArray (0, n-1) [0..n-1] :: IO (IOUArray Int Int)
  forM_ [0..n-1] $ \i -> do
    j <- uniformR (i, n-1) gen
    iv <- readArray arr i
    jv <- readArray arr j
    writeArray arr i jv
    writeArray arr j iv
  getElems arr

stat :: [[Int]] -> IM.IntMap Double
stat smpl = IM.map (\c -> log $ (c+1) / fromIntegral n) $ IM.fromListWith (+) $ concatMap (\ps -> zipWith (\i v -> (i*1000+v, 1)) [0..] $ take 100 ps) smpl
  where n = length smpl

main :: IO ()
main = do
  gen <- create
  hPutStrLn stderr "generating samples..."
  goods <- replicateM 10000 $ (good gen) 1000
  bads  <- replicateM 10000 $ (bad gen) 1000
  hPutStrLn stderr "calc stats..."
  let !goodst = stat goods
      !badst  = stat bads
  hPutStrLn stderr "done!"

  -- print badst

  cases <- readLn
  forM_ [1..cases::Int] $ \cn -> do
    printf "Case #%d: " cn

    n <- readLn :: IO Int
    ps <- map read . words <$> getLine

    let mi = log (1/fromIntegral n)

    let goodprec = sum $ zipWith (\i v -> IM.findWithDefault mi (i*1000+v) goodst) [0..] $ take 100 ps
        badprec  = sum $ zipWith (\i v -> IM.findWithDefault mi (i*1000+v) badst) [0..] $ take 100 ps

    hPrintf stderr "g:%.4f b:%.4f\n" goodprec badprec
    putStrLn $ if goodprec >= badprec then "GOOD" else "BAD"
    hFlush stdout
