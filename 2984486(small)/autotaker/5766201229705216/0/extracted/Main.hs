{-# LANGUAGE MultiParamTypeClasses,FlexibleContexts,FlexibleInstances,TypeSynonymInstances,BangPatterns,RankNTypes,TupleSections #-}
import Control.Monad
import Control.Monad.ST
import Control.Applicative
import Control.Arrow
import Debug.Trace
import Text.Printf

import Data.List
import Data.Int
import Data.Bits
import Data.Maybe
import Data.Array.Unboxed
import Data.Array.ST
import qualified Data.Map as M
import qualified Data.Set as S
import qualified Data.ByteString.Char8 as B

readInt = fromJust . fmap fst . B.readInt
readInts = map readInt . B.words <$> B.getLine
readIntPair = l2p . map readInt . take 2 . B.words <$> B.getLine
readLns :: Read a => IO [a]
readLns = map read . words <$> getLine
cmpFst (a,_) (b,_) = compare a b
cmpSnd (_,a) (_,b) = compare a b
cmpLen a b = length a `compare` length b
swap (a,b) = (b,a)
l2p (a:b:_) = (a,b)
p2l (a,b) = [a,b]
itof :: Int -> Double
itof = fromIntegral
defaultArray :: (IArray a e,Ix i) => e -> (i,i) -> [(i,e)] -> a i e
defaultArray = accumArray $ curry snd
flatten :: [(a,[(b,c)])] -> [((a,b),c)]
flatten = (=<<) $ uncurry $ fmap . first . (,)
stepM_ :: Monad m => a -> (a -> Bool) -> (a -> a) -> (a -> m ()) -> m ()
stepM_ i judge incr step = sub i
    where 
    sub i | judge i = step i >> sub (incr i) | otherwise = return ()
inf = maxBound `div` 2 :: Int

main = do
    t <- readLn
    forM_ [1..t] $ \i -> do
        n <- readLn
        es <- replicateM (n-1) $ readIntPair
        printf "Case #%d: " (i :: Int)
        print $ solve n es

solve :: Int -> [(Int,Int)] -> Int
solve n es = minimum [ solveFrom i g | i <- [1..n]]
    where
    g = accumArray (flip (:)) [] (1,n) (es ++ map swap es)


solveFrom :: Int -> Array Int [Int] -> Int
solveFrom root g = fst $ go (-1) root
    where
    go prev v = case cs of
        [] -> (0,1)
        [(_,s)] -> (s,s+1)
        _ -> (r,s+1)
        where
        ns = filter (/=prev) $ g ! v
        cs = map (go v) ns
        r = minimum [ai + aj + s - (si + sj) | (ai,si):cs' <- tails cs, (aj,sj) <- cs']
        s = sum $ map snd cs
