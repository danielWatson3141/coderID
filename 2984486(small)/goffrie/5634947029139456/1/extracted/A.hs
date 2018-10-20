{-# LANGUAGE NoMonomorphismRestriction #-}
module Main where

import Control.Monad
import Control.Applicative
import Data.List
import Data.Binary
--import Data.Lens
import Data.Char
import Numeric
import Data.Maybe
import Data.Bits
import Data.Int

import Data.Set (Set)
import qualified Data.Set as IS
import qualified Data.ByteString.Char8 as BSS
import qualified Data.ByteString.Lazy.Char8 as BS
import qualified Data.Vector.Unboxed as V
import Data.Vector.Unboxed (Vector)

readBin x = case readInt 2 (flip elem "01") digitToInt x of (x,_):_ -> x

rd = do
    line <- getLine
    let w = words line
    return $ map read w

solve :: Set Int64 -> Set Int64 -> Maybe Int
solve a b = IS.foldr (m . go) Nothing a
    where m (Just x) (Just y) = Just $ min x y
          m (Just x) _        = Just x
          m _        y        = y
          f = IS.findMin b
          go x = if a == IS.map (xor q) b
                    then Just $ popCount q
                    else Nothing
                where q = xor x f

main = do
    t <- readLn
    forM_ [1..t] $ \t -> do
        putStr $ "Case #" ++ show t ++ ": "
        [n, l] <- map read <$> words <$> getLine :: IO [Int]
        pA <- IS.fromList <$> map readBin <$> words <$> getLine
        pB <- IS.fromList <$> map readBin <$> words <$> getLine
        case solve pA pB of
            Nothing -> putStrLn "NOT POSSIBLE"
            Just x -> putStrLn $ show x
        return ()
