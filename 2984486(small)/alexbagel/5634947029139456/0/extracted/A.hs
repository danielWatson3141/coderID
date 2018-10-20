module Main where

import Control.Applicative
import Control.Monad
import Data.Bits
import Data.List
import Data.Maybe
import Data.Word
import System.IO

readBits :: String -> Word64
readBits "" = 0
readBits ('0':bs) = 0 + 2 * (readBits bs)
readBits ('1':bs) = 1 + 2 * (readBits bs)

elemRest n xs = (xs!!n,(take n xs) ++ (drop (n + 1) xs))

tryPlug (x,xs) (y,ys)
  | (sort xs) == (sort ys') = Just m
  | otherwise = Nothing
  where m = x `xor` y
        ys' = map (xor m) ys

solve :: Int -> [Word64] -> [Word64] -> String
solve l flow devices = case switches of
    [] -> "NOT POSSIBLE"
    xs -> show $ minimum xs
  where n = length flow
        plugs = [ tryPlug (elemRest i flow) (elemRest j devices) | i <- [0..(n-1)], j <- [0..(n-1)] ]
        switches = map popCount . catMaybes $ plugs

runCase :: IO String -> IO String
runCase getLine
  = do [n,l] <- (map read . words <$> getLine) :: IO [Int]
       flow <- map readBits . words <$> getLine
       devices <- map readBits . words <$> getLine
       return $ solve l flow devices

run fileName
  = do hIn <- openFile (fileName ++ ".in") ReadMode
       hOut <- openFile (fileName ++ ".out") WriteMode
       t <- hGetLine hIn >>= readIO :: IO Int
       forM_ [1..t] (\i -> (showResult i <$> runCase (hGetLine hIn)) >>= (\result -> putStrLn result >> hPutStrLn hOut result))
       hClose hIn
       hClose hOut
  where
    showResult i result = "Case #" ++ (show i) ++ ": " ++ result
