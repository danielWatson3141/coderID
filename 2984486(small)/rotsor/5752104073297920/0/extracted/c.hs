{-# LANGUAGE ScopedTypeVariables #-}
import Control.Monad
import Control.Applicative
import Control.Arrow
import Data.List
import System.Random

score l = sum (zipWith (\i k -> i * k) l [1..])

set 0 x (_ : t) = x : t
set i x (h : t) = h : set (i - 1) x t

swap i j l = set i (l !! j) (set j (l !! i) l)
  
mkPerm is = go (take (length is) [0..]) (zip [0..] is) where
  go l ((i,j) : is) = go (swap i j l) is
  go l [] = l

go :: (Functor m, Monad m) => ([Int] -> m Int) -> Int -> m [Int]
go choose n = fmap mkPerm (replicateM n (choose [0..n-1]))

go_good choose n = fmap mkPerm $ sequence [choose [i..n-1]|i<-[0..n-1]]

choose_io = (\l -> randomRIO (0, length l - 1) >>= \i -> return $ l !! i)
gen_bad = go choose_io

gen_good = go_good choose_io

solve (w :: [Int]) = if score w > 254000000 then "BAD" else "GOOD"

test_good = replicateM 30 (fmap score $ gen_good 1000)
test_bad = replicateM 30 (fmap score $ gen_bad 1000)

readInput = do
  getLine
  map read . words <$> getLine

main = do
  n <- readLn
  flip mapM_ [1..n] $ \tc -> do
    i <- readInput
    putStrLn $ "Case #" ++ show tc ++ ": " ++ solve i
