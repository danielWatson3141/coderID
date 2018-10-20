module Main where

import Control.Monad
import Text.Printf

good :: [Int] -> Bool
good p = length [() | (i, pi) <- zip [0..] p, pi > i] >= 514

main :: IO ()
main = do t <- liftM read getLine :: IO Int
          sequence_ $ flip map [1..t] $ \i ->
            do n <- liftM read getLine :: IO Int
               p <- liftM (map read . words) getLine
               printf "Case #%d: %s\n" i (if not (good p) then "GOOD" else "BAD")
