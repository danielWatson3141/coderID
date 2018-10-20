{-# LANGUAGE MultiParamTypeClasses,FlexibleContexts,FlexibleInstances,TypeSynonymInstances,BangPatterns,RankNTypes,TupleSections #-}
import Control.Monad
import Control.Monad.ST
import Control.Applicative
import Control.Arrow
import Debug.Trace
import Text.Printf

import Data.List
import Data.Int
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
        (n,l) <- readIntPair
        as <- words <$> getLine
        bs <- words <$> getLine
        printf "Case #%d: " (i :: Int)
        putStrLn $ case solveLarge l as bs of
            Nothing ->  "NOT POSSIBLE"
            Just x -> show x
           
solveSmall :: Int -> [String] -> [String] -> Maybe Int
solveSmall l as bs = case res of
    [] -> Nothing
    _  -> Just $ minimum res
    where
    res = do
        c <- replicateM l ['0','1']
        guard $ sort [ c `xor` a | a <- as] == sort bs
        return $ popCount c

solveLarge :: Int -> [String] -> [String] -> Maybe Int
solveLarge l as bs = case res of
    [] -> Nothing
    _ -> Just $ minimum res
    where
    a = head as
    res = do
        b <- bs
        let c = xor a b
        guard $ sort [ c `xor` a | a <- as] == sort bs
        return $ popCount c


xor :: String -> String -> String
xor = zipWith (\a b -> if a == b then '0' else '1')

popCount :: String -> Int
popCount = length .filter (=='1') 
