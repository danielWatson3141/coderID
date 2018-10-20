module Main where

import Control.Applicative
import Control.Monad
import Data.Array
import Data.Bits
import Data.List
import Data.Maybe
import Data.Word
import System.Environment
import System.IO
import Debug.Trace

type Graph = Array Int [Int]

combinations :: Int -> [a] -> [[a]]
combinations 0 _  = [ [] ]
combinations n xs = [ y:ys | y:xs' <- tails xs
                           , ys <- combinations (n-1) xs']

delNode :: Int -> Graph -> Graph
delNode n graph = graph // ((n,[]) : [ (e,n `delete` (graph!e)) | e <- graph!n ])

countChildren :: Int -> Graph -> Int
countChildren n graph = sum [ 1 + (countChildren a (a `delNode` graph)) | a <- graph!n ]

findTree :: Int -> Graph -> Int
findTree n graph = case graph!n of
    [] -> 0
    [a] -> 1 + (countChildren a graph')
    [a,b] -> (findTree a graph') + (findTree b graph')
--     as -> minimum [ 1 + (countChildren a graph') + (findTree n (a `delNode` graph)) | a <- as,  ]
    as -> minimum [ 1 + d + (findTree a graph') + (findTree b graph') | [a,b] <- combinations 2 as, let cs = as \\ [a,b], let d = sum [ 1 + (countChildren c graph') | c <- cs ] ]
  where graph' = n `delNode` graph

runCase :: IO String -> IO String
runCase getLine
  = do n <- read <$> getLine :: IO Int
       edges <- map (map read . words) <$> (replicateM (n - 1) getLine) :: IO [[Int]]
       let graph = accumArray (flip (:)) [] (1,n) $ concatMap (\[a,b] -> [(a,b),(b,a)]) edges
       return . show . minimum $ [ findTree i graph | i <- [1..n] ]

run fileName
  = do hIn <- openFile (fileName ++ ".in") ReadMode
       hOut <- openFile (fileName ++ ".out") WriteMode
       t <- hGetLine hIn >>= readIO :: IO Int
       forM_ [1..t] (\i -> (showResult i <$> runCase (hGetLine hIn)) >>= (\result -> putStrLn result >> hPutStrLn hOut result))
       hClose hIn
       hClose hOut
  where
    showResult i result = "Case #" ++ (show i) ++ ": " ++ result

main = do (a:_) <- getArgs
          run a
