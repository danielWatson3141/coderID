module Main where

import Control.Monad
import Data.List
import qualified Data.Map as Map
import Data.Map (Map)
import Text.Printf

type Tree = Map Int [Int]

connect :: Int -> Int -> Tree -> Tree
connect u v tree = Map.update (\s -> Just (v : s)) u tree

makeTree :: Int -> [(Int, Int)] -> Tree
makeTree n = foldl' (\ tree (u, v) -> connect u v (connect v u tree)) (Map.fromList [(i, []) | i <- [0..n-1]])

solve :: Int -> Tree -> Int
solve n tree = minimum [minDel i (-1) tree | i <- [0..n-1]]

minDel :: Int -> Int -> Tree -> Int
minDel root parent tree =
  let children = filter (parent /=) ((Map.!) tree root)
  in
   case children of
     [] -> 0
     [c] -> stSize c root tree
     (_ : _ : _) ->
       let ds = [minDel c root tree | c <- children]
           ss = [stSize c root tree | c <- children]
           diffs = zipWith (-) ds ss
       in sum ss + sum (take 2 (sort diffs))
          
stSize :: Int -> Int -> Tree -> Int
stSize root parent tree =
  let children = filter (parent /=) ((Map.!) tree root)
  in 1 + sum [stSize c root tree | c <- children]

main :: IO ()
main = do t <- liftM read getLine :: IO Int
          sequence_ $ flip map [1..t] $ \i ->
            do n <- liftM read getLine
               edges <- sequence $ replicate (n - 1) $ liftM ((\[a, b] -> (a-1, b-1)) . map read . words) getLine
               printf "Case #%d: %d\n" i (solve n (makeTree n edges))
