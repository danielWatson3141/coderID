import System.IO
import Data.List
import Control.Monad

import Debug.Trace
import Data.Tuple

import qualified Data.HashMap.Lazy as HM

import Data.List
import Data.Maybe
import Control.Monad
import Data.Serialize
import qualified Data.ByteString as BS
import Data.Array.IArray
import Data.Word

data DP a b = DP b (Array Word8 (DP a b))

fromMap :: (Serialize a) => (a -> b) -> DP a b
fromMap f = fromMap' (f . fromRight . decode . BS.pack)
   where
     fromRight (Right x) = x
     fromMap' :: ([Word8] -> b) -> DP a b
     fromMap' f' = DP (f' []) $ array (0, 255) [(i, fromMap' (f' . (i:))) | i <- [0..255]]

eval :: (Serialize a) => DP a b -> a -> b
eval dp x = eval' dp (BS.unpack $ encode x)
   where
     eval' (DP r _) [] = r
     eval' (DP _ a) (b:bs) = eval' (a ! b) bs

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

data Case = Case ([(Int,Int)])

type Solution = Int

addEdge :: HM.HashMap Int [Int] -> (Int,Int) -> HM.HashMap Int [Int]
addEdge m (n1,n2) = addEdge' n1 n2 $ addEdge' n2 n1 m
  where
    addEdge' n1 n2 m =
        let v = HM.lookupDefault [] n1 m
        in HM.insert n1 (n2:v) m

children :: HM.HashMap Int [Int] -> Int -> Int -> [Int]
children m p n = filter (/= p) $ m HM.! n


{--
solveEdgeTree :: HM.HashMap Int [Int] -> HM.HashMap (Int,Int) Int -> HM.HashMap (Int,Int) Int -> Int -> Int
solveEdgeTree g stc sts n =
    if length chs == 0 || length chs == 2
       then sum $ map (stc HM.!) es
       else if length chs == 1
               then sum $ map (sts HM.!) es
               else let totalSubSize = sum $ map (sts HM.!) es
                        removeAdaptCosts = map (removeAdaptCost) chs
                    in totalSubSize - (sum $ take 2 $ reverse $ sort removeAdaptCosts)
  where
    chs = children g 0 n
    es = map ((,) n) chs
    removeAdaptCost ch =
        (sts HM.! (n,ch)) - (stc HM.! (n,ch))

genSizeMap :: HM.HashMap Int [Int] -> [(Int,Int)] -> HM.HashMap (Int,Int) Int
genSizeMap m = foldl calcEdge HM.empty
  where
    calcEdge im (n1,n2) =
        HM.insert (n1,n2) (subTreeSize m n1 n2) im

genCostMap :: HM.HashMap Int [Int] -> [(Int,Int)] -> HM.HashMap (Int,Int) Int
genCostMap m = foldl calcEdge HM.empty
  where
    calcEdge im (n1,n2) =
        HM.insert (n1,n2) (solveSubTree m n1 n2) im
--}

solve :: Case -> Int
solve (Case es) = 
    let subTreeSize (p,n) = 1 + (sum $ map (subTreeSize' . (,) n) chs)
          where
            chs = children edgeMap p n

        sizeDp = fromMap subTreeSize
        subTreeSize' x = eval sizeDp x

        solveSubTree (p,n) =
            if length chs == 0 || length chs == 2
               then sum $ map (solveSubTree' . (,) n) chs
               else if length chs == 1
                       then sum $ map (subTreeSize' . (,) n) chs
                       else let totalSubSize = sum $ map (subTreeSize' . (,) n) chs
                                removeAdaptCosts = map (removeAdaptCost) chs
                                in totalSubSize - (sum $ take 2 $ reverse $ sort removeAdaptCosts)
           where
              chs = children edgeMap p n
              removeAdaptCost ch =
                  subTreeSize' (n,ch) - solveSubTree' (n,ch)

        subTreeDp = fromMap solveSubTree
        solveSubTree' x = eval subTreeDp x

    in minimum $ map (solveSubTree) $ map ((,) 0) keys
    where keys = HM.keys edgeMap
          edgeMap = foldl addEdge HM.empty es
          --stc = genCostMap edgeMap allEs
          --sts = genSizeMap edgeMap allEs
          allEs = es ++ map swap es

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
           return $ Case nodes
