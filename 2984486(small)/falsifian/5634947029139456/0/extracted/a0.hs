module Main where

import Control.Monad
import Data.List
import Data.Maybe
import Text.Printf

possible :: [[Bool]] -> [[Bool]] -> Bool
possible x y = sort x == sort y

singles :: [a] -> [(a, [a])]
singles = singles' []

singles' :: [a] -> [a] -> [(a, [a])]
singles' _ [] = []
singles' acc (h : t) = (h, acc ++ t) : singles' (h : acc) t

satisfy :: [Bool] -> [Bool] -> [[Bool]] -> (Int, [[Bool]])
satisfy device outlet rest =
  let diff = [d /= o | (d, o) <- zip device outlet]
  in (length (filter id diff), [[d /= b | (d, b) <- zip diff o] | o <- rest])

solve :: Int -> [[Bool]] -> [[Bool]] -> Maybe Int
solve _n os (d0 : ds) =
  let sols = catMaybes [ if possible ds oT' then Just nFlip else Nothing
                       | (oH, oT) <- singles os
                       , let (nFlip, oT') = satisfy d0 oH oT
                       ]
  in if null sols then Nothing else Just (minimum sols)

readBit :: Char -> Bool
readBit '0' = False
readBit '1' = True

readB :: String -> [Bool]
readB = map readBit

fmt :: Maybe Int -> String
fmt Nothing = "NOT POSSIBLE"
fmt (Just x) = show x

main :: IO ()
main = do t <- liftM read getLine :: IO Int
          sequence_ $ flip map [1..t] $ \i ->
            do [n, l] <- liftM (map read . words) getLine
               outlets <- liftM (map readB . words) getLine
               devices <- liftM (map readB . words) getLine
               printf "Case #%d: %s\n" i (fmt (solve n outlets devices))
