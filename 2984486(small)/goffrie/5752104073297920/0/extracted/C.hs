-- {-# LANGUAGE NoMonomorphismRestriction #-}
module Main where

import Control.Applicative
import Data.List
import Control.Monad
import System.Random
import qualified Data.Foldable as F
import qualified Data.Vector.Unboxed.Mutable as VM
import qualified Data.Vector.Unboxed as V
import qualified Data.Vector as VV
import qualified Data.Sequence as S
import System.IO
import Data.Sequence (Seq)

shuffle vec gen = foldM go gen [0..end]
    where end = VM.length vec - 1
          go gen ix = do
            let (r, gen') = randomR (ix, end) gen
            VM.swap vec ix r
            return gen'

badShuffle vec gen = foldM go gen [0..end]
    where end = VM.length vec - 1
          go gen ix = do
            let (r, gen') = randomR (0, end) gen
            VM.swap vec ix r
            return gen'

swap i j seq = let x = S.index seq i
                   y = S.index seq j
                   in S.update i y $ S.update j x seq

add :: V.Vector Double -> V.Vector Double -> V.Vector Double
add = V.zipWith (+)
--average :: Seq [Double] -> [Double]
average xs = let inv = 1.0 / (fromIntegral $ VV.length xs) :: Double
                 --in V.map (* inv) $ foldl' add (V.replicate (V.length $ head xs) 0) xs
                 in V.generate (V.length $ VV.unsafeHead xs) $ \i ->
                    inv * (VV.foldr' ((+) . (`V.unsafeIndex` i)) 0 xs)

lincomb x y a = V.zipWith (\xx yy -> xx * a + yy * b) x y
    where b = 1 - a

--merge :: [Seq [Double]] -> Seq [Double]
merge xs = let len = length xs
               in fmap (map (/ (fromIntegral len))) $ foldr1 (zipWith (zipWith (+))) xs

initial end = VV.map go $ VV.fromList [0..end]
    where go i = V.fromList [if x == i then 1 else 0 | x <- [0..end]]

modelBadShuffle len = foldl' go (initial end) [0..end]
    where end = len - 1
          sz = 1.0 / fromIntegral len
          go state ix = let x = VV.unsafeIndex state ix
                            in VV.imap (\jx y -> if ix == jx then average state else lincomb x y sz) state
          --merge $ map (\r -> swap ix r state) [0..end]

modelGoodShuffle len = VV.replicate len (V.replicate len (1.0 / fromIntegral len))

modelBad = modelBadShuffle 1000
modelGood :: VV.Vector (V.Vector Double)
modelGood = modelGoodShuffle 1000

bayes permutation model counter = V.ifoldl' go 0.5 permutation
    where go state index value = state * pBA / pB
            where pBA = (V.unsafeIndex (VV.unsafeIndex model index) value)
                  pB = (pBA + (V.unsafeIndex (VV.unsafeIndex counter index) value)) / 2

main :: IO ()
main = do
        hPutStrLn stderr $ show $ average $ modelBad
        t <- readLn
        forM_ [1..t] $ \i -> do
            putStr $ "Case #" ++ show i ++ ": "
            getLine
--          gen <- getStdGen
--          let vec = V.fromList $ [0..99] :: V.Vector Int
--          v1 <- V.thaw vec
--          shuffle v1 gen
--          v2 <- V.thaw vec
--          badShuffle v2 gen
--          good <- V.unsafeFreeze v1
--          bad <- V.unsafeFreeze v2
--          putStrLn "good:"
--          putStrLn $ show good
--          putStrLn $ show $ bayes good modelBad modelGood
--          putStrLn $ show $ bayes good modelGood modelBad
--          putStrLn "bad:"
--          putStrLn $ show bad
--          putStrLn $ show $ bayes bad modelBad modelGood
--          putStrLn $ show $ bayes bad modelGood modelBad
            perm <- (V.fromList . map read . words) <$> getLine
            if bayes perm modelBad modelGood > bayes perm modelGood modelBad
                then
                    putStrLn "BAD"
                else
                    putStrLn "GOOD"
    --        putStrLn $ show $ average $ modelBad
    --        putStrLn $ show $ average $ modelBadShuffle 1000
    --        putStrLn "hi"
