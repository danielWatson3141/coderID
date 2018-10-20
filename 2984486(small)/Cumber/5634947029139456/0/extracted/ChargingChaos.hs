{-# LANGUAGE MultiWayIf #-}

module Main where

import Control.Applicative ((<$>), pure)
import Control.Arrow (first)
import Control.Monad (guard, join)
import Text.Printf (printf)
import qualified Data.Set as S
import Data.Set (Set)
import qualified Data.Vector as V
import Data.Vector (Vector, (!))

main :: IO ()
main = mapM_ doCase =<< enumFromTo 1 <$> readLn


doCase :: Int -> IO ()
doCase caseNo
  = do  _ <- getLine -- don't care how many flows/digits
        have <- V.fromList . map toBitList . words <$> getLine
        need <- V.fromList . map toBitList . words <$> getLine

        printf "Case #%d: %s\n" caseNo (format $ solve have need)


format :: Maybe Int -> String
format Nothing = "NOT POSSIBLE"
format (Just x) = show x


type BitList = [Bool]

toBitList :: String -> BitList
toBitList "" = []
toBitList ('0' : cs) = True : toBitList cs
toBitList ('1' : cs) = False : toBitList cs
toBitList _ = error "bad input"


solve :: Vector BitList -> Vector BitList -> Maybe Int
solve have need = pick $ go (splitDigits have) (splitDigits need)
  where
    go [h] [n] = map (first pure) $ checkDigit h n
    go (h : hs) (n : ns)
      = let possibles = go hs ns
        in  checkDigit h n >>= extendSolution (go hs ns)

    pick [] = Nothing
    pick xs = Just . minimum . map (length . filter id . fst) $ xs


checkDigit h n
  = let hTF = countTF h
        nTF = countTF n
    in  join  [ guard (hTF == nTF) >> [(False, compats h n)]
              , guard (hTF == swap nTF) >> [(True, compats (V.map not h) n)]
              ]


compats h n
  = V.map (compat n) h


compat n hb = V.ifoldr (\i nb is-> if hb == nb then S.insert i is else is) S.empty n


extendSolution :: [([Bool], Vector (Set Int))] -> (Bool, Vector (Set Int)) -> [([Bool], Vector (Set Int))]
extendSolution solutions (flip, compats)
  = do  (flips, oldCompats) <- solutions
        let newCompats = V.zipWith S.intersection compats oldCompats
        guard $ V.all (not . S.null) newCompats
        return (flip : flips, newCompats)
    
{-
        if| hTF == nTF && hTF == swap nTF
            ->  mergePossibilities False h n (possibles)
          | hTF == nTF
            ->  [True]
          | hTF == swap nTF
                ->  [False]
              | otherwise
                ->  []
-}


splitDigits :: Vector BitList -> [Vector Bool]
splitDigits flows
  | null (flows ! 0)    = []
  | otherwise           = V.map head flows : splitDigits (V.map tail flows)


swap (a, b) = (b, a)

countTF :: Vector Bool -> (Int, Int)
countTF = V.foldl' count (0, 0)
  where
    count (t, f) True  = (t + 1, f)
    count (t, f) False = (t, f + 1)
