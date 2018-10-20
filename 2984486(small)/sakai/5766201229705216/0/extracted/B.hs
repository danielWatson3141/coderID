{-# LANGUAGE BangPatterns #-}
import Control.Monad
import Data.Array
import Data.List
import Data.Set (Set)
import qualified Data.Set as Set
import Data.IntSet (IntSet)
import qualified Data.IntSet as IntSet
import Data.IntMap (IntMap)
import qualified Data.IntMap as IntMap
import Text.Printf
import Debug.Trace

main :: IO ()
main = do
  t <- readLn
  forM_ [(1::Int)..t] $ \i -> do
    n <- readLn
    es <- replicateM (n-1) $ do
      [xi,yi] <- liftM (map read . words) $ getLine
      return (xi,yi)
    let ans = solve n es
    printf "Case #%d: %d\n" i ans

solve :: Int -> [(Int,Int)] -> Int
solve n es = minimum [f (mkTree v g) | v <- [1..n]]
  where
    g = IntMap.fromListWith IntSet.union $ concat [[(x, IntSet.singleton y), (y, IntSet.singleton x)] | (x,y) <- es]
    degrees = IntMap.map IntSet.size g

data Tree
  = Tree
  { treeChildren :: [Tree]
  , treeSize :: Int
  }
  deriving (Show)

mkTree :: Int -> IntMap IntSet -> Tree
mkTree nd g = f Nothing nd g
  where
    f p nd g = Tree{ treeChildren = children, treeSize = 1 + sum [treeSize ch | ch <- children] }
      where
        children = [f (Just nd) ch g | ch <- IntSet.toList $ g IntMap.! nd, p /= Just ch]

f :: Tree -> Int
f t =
  case treeChildren t of
    [] -> 0
    [ch] -> treeSize ch
    cs -> minimum $ do
      (ch1,ch2,rest) <- pick2 cs
      return $ sum [treeSize n | n <- rest] + f ch1 + f ch2

pick2 :: [a] -> [(a,a,[a])]
pick2 [] = []
pick2 (x:xs) = [(x,y,zs) | (y,zs) <- pick1 xs] ++ [(y,z,x:ws) | (y,z,ws) <- pick2 xs]

pick1 :: [a] -> [(a,[a])]
pick1 [] = []
pick1 (x:xs) = (x,xs) : [(y,x:ys) | (y,ys) <- pick1 xs]
