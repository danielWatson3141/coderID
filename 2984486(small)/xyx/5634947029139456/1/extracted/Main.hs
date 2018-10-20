{-# LANGUAGE TupleSections #-}
import Control.Monad
import Data.List
import qualified Data.Map as M
import qualified Data.Set as S
import Debug.Trace
import System.IO
import Text.Printf
import Data.Bits
import Data.Word
import Data.Ord

main = hSetBuffering stdout NoBuffering >> parseTest >>= writeTest . map solve

writeTest :: [String] -> IO ()
writeTest xs = zipWithM_ (\i x->printf "Case #%d: %s\n" (i :: Int) x) [1..] xs

parseTest = do
	n <- liftM read $ getLine
	replicateM n parseCase

parseCase = do
	_ <- getLine
	outs <- liftM words $ getLine
	devs <- liftM words $ getLine
	return (outs, devs)

solve :: ([String], [String]) -> String
solve (outs, devs)
	|null masks_ok = printf "NOT POSSIBLE"
	|otherwise = show $ popCount $ head masks_ok
	where
		masks_ok = filter check masks

		check mask = sort (map (xor mask) outs') == devs'
		masks = sortBy (comparing popCount) $ map (xor (head outs')) devs'
		
		outs' = map readBin outs
		devs' = sort $ map readBin devs



readBin :: String -> Word64
readBin = aux . reverse
	where
		aux [] = 0
		aux ('0':xs) = aux xs * 2
		aux ('1':xs) = aux xs * 2 + 1
