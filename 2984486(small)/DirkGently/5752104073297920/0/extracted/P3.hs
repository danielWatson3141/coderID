import Control.Monad
import Data.Ratio
import Data.Array
import Data.Word
import Data.Hashable
import Data.Serialize
import qualified DyadicMap as DM
import System.IO
import System.IO.Unsafe
import Data.Bits
import System.Random
import qualified Data.ByteString as BS

isPermOdd :: [Int] -> Bool
isPermOdd xs
    | (_,1) <- (transpositions xs) `quotRem` 2 = True
    | otherwise = False

transpositions [] = 0
transpositions (x:xs) = length (filter (< x) xs) + transpositions xs

debug :: (Show a) => a -> a
debug t
   | (hash (show t) `mod` 1342) == 1000 = unsafePerformIO $
    do hPutStrLn stderr $ show t
       return t
   | otherwise = t

badperm :: StdGen -> Int -> [Int]
badperm g n = badperm' g n 0 [0..(n-1)]
    
badperm' :: StdGen -> Int -> Int -> [Int] -> [Int]
badperm' g n i perm
    | i < n = let (i', g') = randomR (0,n-1) g
              in badperm' g' n (i+1) $ swap i i' perm
    | otherwise = perm

swap i i' perm
    | i == i' = perm
    | i > i' = swap i' i perm
    | otherwise = s ++ [p2]++ r1 ++ [p2] ++ r2 
    where p1 = (perm !! i)
          p2 = (perm !! i')
          (s, (_:r)) = splitAt i perm
          (r1, (_:r2)) = splitAt (i'-i-1) perm
        


main =
    do caseCountLn <- getLine
       forM_ [1..(read caseCountLn)] $ \caseNum ->
           do line <- getLine
              line2 <- getLine
              let nums = map read $ words line2
                  solution =
                     case isPermOdd nums of
                         True -> "GOOD"
                         False -> "BAD"
              putStrLn $ "Case #" ++ show caseNum ++ ": " ++ solution

