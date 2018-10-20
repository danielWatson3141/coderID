{-# OPTIONS_GHC -O2 -funbox-strict-fields #-}
{-# LANGUAGE BangPatterns, ViewPatterns, TupleSections #-}

import Control.Applicative
import Control.Monad
import Data.Bits
import Data.Fixed
import Data.List
import Data.Time.Clock
import Data.Time.Clock.POSIX
import System.IO

runGCJ :: IO () -> IO ()
runGCJ main_ = do
  t <- readLn
  forM_ [1..t] $ \i -> do
    putStr $ "Case #" ++ shows i ": "
    hPutStr stderr $ shows i "/" ++ shows t ": "
    hFlush stderr
    start <- getPOSIXTime
    main_
    end <- getPOSIXTime
    hPutStrLn stderr $ (shows.msec) (end - start) "ms"
    hFlush stderr

msec :: NominalDiffTime -> Int
msec s = let t = realToFrac s :: Milli in fromEnum t

main :: IO ()
main = runGCJ $ do
  [n, l] <- map read.words <$> getLine
  outlet <- map toInt.words <$> getLine
  shota <- map toInt.words <$> getLine
  putStrLn $ maybe "NOT POSSIBLE" show $ solveSmall n l outlet shota

solveSmall :: Int -> Int -> [Int] -> [Int] -> Maybe Int
solveSmall n l outlet shota = minimum'.map popCount $ filter isValid masks
   where
     masks = [0..2^l-1]
     isValid mask = sort shota == sort (map (xor mask) outlet)

minimum' :: [Int] -> Maybe Int
minimum' [] = Nothing
minimum' xs = Just $ minimum xs

toInt :: String -> Int
toInt cs = foldl' (\acc c->2*acc+read[c]) 0 cs