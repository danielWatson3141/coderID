import System.IO
import Data.List
import Control.Monad

import Debug.Trace

import qualified Data.HashMap.Lazy as HM

readInts :: IO [Int]
readInts = liftM (map read . words) getLine

readLine :: IO String
readLine = getLine

readInt :: IO Int
readInt = liftM read getLine

readDouble :: IO Double
readDouble = liftM read getLine

readDoubles :: IO [Double]
readDoubles = liftM (map read . words) getLine

printCase :: Int -> String -> IO ()
printCase caseNo sol =
    putStrLn $ "Case #" ++ show caseNo ++ ": " ++ sol

data Case = Case (HM.HashMap Int [Int])

type Solution = Int

addEdge :: HM.HashMap Int [Int] -> (Int,Int) -> HM.HashMap Int [Int]
addEdge m (n1,n2) = addEdge' n1 n2 $ addEdge' n2 n1 m
  where
    addEdge' n1 n2 m =
        let v = HM.lookupDefault [] n1 m
        in HM.insert n1 (n2:v) m

children :: HM.HashMap Int [Int] -> Int -> Int -> [Int]
children m p n = filter (/= p) $ m HM.! n

subTreeSize :: HM.HashMap Int [Int] -> Int -> Int -> Int
subTreeSize m p n = 1 + (sum $ map (subTreeSize m n) chs)
    where
     chs = children m p n

solveSubTree :: HM.HashMap Int [Int] -> Int -> Int -> Int
solveSubTree m p n =
    if length chs == 0 || length chs == 2
       then sum $ map (solveSubTree m n) chs
       else if length chs == 1
               then sum $ map (subTreeSize m n) chs
               else let totalSubSize = sum $ map (subTreeSize m n) chs
                        removeAdaptCosts = map (removeAdaptCost) chs
                    in totalSubSize - (sum $ take 2 $ reverse $ sort removeAdaptCosts)
 where
   chs = children m p n
   removeAdaptCost ch =
       subTreeSize m n ch - solveSubTree m n ch

solve :: Case -> Int
solve (Case m) = minimum all
    where keys = HM.keys m
          all = map (solveSubTree m 0 ) keys

main =
    do numCases <- readInt
       forM_ [1..numCases] $ \caseNo ->
           do x <- readCase
              printCase caseNo $ show $ solve x
  where
    readCase =
        do n <- readInt
           nodes <- forM [1..n-1] $ \_ ->
                        do [x,y] <- readInts
                           return (x,y)
           return $ Case $ foldl addEdge HM.empty $ nodes
