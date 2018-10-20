-- @betaveros :: vim:set fdm=marker:
{-# LANGUAGE LambdaCase, NPlusKPatterns, TupleSections #-}
{-# OPTIONS_GHC -fno-warn-unused-imports -fno-warn-missing-signatures #-}
-- import ALL the things! {{{
-- seriously, there's a lot of stuff here, but very little of it is used (probably)
-- hiding clauses are to allow Data.Foldable's generalizations
import Prelude hiding (mapM, mapM_, sequence, sequence_, foldl, foldl1, foldr, foldr1, and, or, any, all, sum, product, concat, concatMap, maximum, minimum, elem, notElem)
import Control.Applicative
import Control.Arrow
import Control.Exception
import Control.Lens -- hackage: lens-4.1.2
import Control.Monad hiding (mapM, mapM_, forM, forM_, sequence, sequence_, msum)
import Control.Monad.Trans -- hackage: transformers-0.3.0.0
import Control.Monad.Trans.State -- ditto
import Control.Monad.Trans.Writer -- ditto
import Control.Monad.IO.Class
import Control.Monad.ST

import qualified Data.ByteString.Char8 as BS
import Data.ByteString.Char8 (ByteString)
import Data.Bits
import Data.Char
import Data.Either
import Data.Foldable
import Data.Function
import Data.IORef
import Data.List hiding (foldl, foldl', foldl1, foldl1', foldr, foldr1, concat, concatMap, and, or, any, all, sum, product, maximum, minimum, elem, notElem, find)
import Data.Maybe
import Data.Ord
import Data.Semigroup -- hackage: semigroups-0.13.0.1
import Data.STRef
import Data.String
import Data.Tuple

import qualified Data.List.NonEmpty as N -- part of semigroups-0.13.0.1
import Data.List.NonEmpty (NonEmpty ((:|)), nonEmpty)
import qualified Data.Map as Map
import Data.Map (Map)
import qualified Data.Set as Set
import Data.Set (Set)
import qualified Data.Sequence as Seq
import Data.Sequence (Seq)

import qualified Data.Vector as V -- hackage: vector-0.10.9.1
import qualified Data.Vector.Mutable as MV
import qualified Data.Vector.Unboxed as UV
import qualified Data.Vector.Unboxed.Mutable as MUV

import Debug.Trace
import Text.Read
import Text.Printf
import System.IO
import System.Random

import qualified Data.MemoCombinators as Memo -- hackage: data-memocombinators-0.5.1
-- }}}
-- silly utilities {{{
a &$ b = b a
infixl 0 &$
a &. b = b . a
infixl 9 &.
fi :: (Integral a, Num b) => a -> b
fi = fromIntegral
glength :: (Num b) => [a] -> b
glength = genericLength

readInt     = read :: String -> Int
readInteger = read :: String -> Integer
-- (!?) :: (Ord k) => Map k v -> k -> Maybe v
-- (!?) = flip Map.lookup
histogram :: (Ord a, Num b) => [a] -> Map a b
histogram = Map.fromListWith (+) . map (,1)
-- }}}
-- input and output {{{
bsGetLine :: IO ByteString
bsGetLine = fst . BS.spanEnd isSpace <$> BS.getLine

inputInt     = (read <$> getLine) :: IO Int
inputInteger = (read <$> getLine) :: IO Integer
inputDouble  = (read <$> getLine) :: IO Double

inputRow :: (Read a) => IO [a]
inputRow = map read . words <$> getLine
inputInts     = inputRow :: IO [Int]
inputIntegers = inputRow :: IO [Integer]
inputDoubles  = inputRow :: IO [Double]

ssUnwords :: [ShowS] -> ShowS
ssUnwords [] = id
ssUnwords (x:xs) = x . (' ':) . ssUnwords xs

ssUnlines :: [ShowS] -> ShowS
ssUnlines [] = id
ssUnlines (x:xs) = x . ('\n':) . ssUnlines xs

showMany :: (Show a) => [a] -> String
showMany xs = ssUnwords (map shows xs) ""
showMatrix :: (Show a) => [[a]] -> String
showMatrix xs = ssUnlines (map (ssUnwords . map shows) xs) ""

printMany :: (Show a) => [a] -> IO ()
printMany xs = putStrLn (showMany xs)
printMatrix :: (Show a) => [[a]] -> IO ()
printMatrix xs = putStr (showMatrix xs)
-- }}}

xorc x y = if x == y then '0' else '1'
xors = zipWith xorc

ones = length . filter (== '1')

tc :: Int -> IO ()
tc tci = do
	[n, len] <- inputInts
	ss@(s:_) <- words <$> getLine
	es <- sort . words <$> getLine
	let fs = [s `xors` e | e <- es]
	let ways = [(ones f, sort $ map (xors f) ss) | f <- fs]
	let okWays = filter ((== es) . snd) ways
	printf "Case #%d: " tci
	case okWays of
		[] -> putStrLn "NOT POSSIBLE"
		ok -> print (fst $ minimum ok)

main :: IO ()
main = do
	tcn <- inputInt
	forM_ [1..tcn] tc
