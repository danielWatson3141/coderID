{-# LANGUAGE BangPatterns #-}
import Control.Monad
import Data.List
import Data.Set (Set)
import qualified Data.Set as Set
import Data.IntSet (IntSet)
import qualified Data.IntSet as IntSet
import Text.Printf

main :: IO ()
main = do
  t <- readLn
  forM_ [(1::Int)..t] $ \i -> do
    [n,l] <- liftM (map read . words) $ getLine
    xs <- liftM (map readBits . words) $ getLine
    ys <- liftM (map readBits . words) $ getLine
    printf "Case #%d: " i
    case solve n l xs ys of
      Nothing -> putStrLn "NOT POSSIBLE"
      Just i  -> print i

type Bits = [Bool]

readBits :: String -> Bits
readBits s = [c=='1' | c <- s]

flipBit :: Int -> Bits -> Bits
flipBit 0 (b:bs) = not b : bs
flipBit i (b:bs) = b : flipBit (i-1) bs

solve :: Int -> Int -> [Bits] -> [Bits] -> Maybe Int
solve n l xs ys = go 0 (Set.singleton (IntSet.empty, sort xs))
  where
    ys' = sort ys
    go !m ss
      | m > l = Nothing
      | or [bs == ys' | (is, bs) <- Set.toList ss] = Just m
      | otherwise = go (m+1) $ Set.fromList [(IntSet.insert i is, sort [flipBit i bs | bs <- xs]) | (is, xs) <- Set.toList ss, i <- [0..l-1], i `IntSet.notMember` is]


