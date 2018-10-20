module Main where

import Control.Applicative
import Control.Monad
import Data.Bits
import qualified Data.Set as S

main = do
  t <- readLn
  forM_ [1..t] $ \caseNumber -> do
    getLine
    xs <- map readBin . words <$> getLine
    ys <- map readBin . words <$> getLine
    answer <- -- I think my spaces aren't all spaces... let answer = aint parsing
      return $ case solve xs ys of
        Nothing -> "NOT POSSIBLE"
        Just x -> show x
    putStrLn $ "Case #" ++ show caseNumber ++ ": " ++ answer

readBin :: String -> Int
readBin = go 0 0 where
  go v _ [] = v
  go v shift (x:xs) = go (v + (read [x] :: Int) `shiftL` shift) (shift + 1) xs

solve :: [Int] -> [Int] -> Maybe Int
solve xs (y:ys) = go (setForY y) ys where
  go s [] 
    | S.null s = Nothing
    | otherwise = Just . minimum . map popCount $ S.toList s
  go s (y:ys) = go (S.intersection s $ setForY y) ys

  setForY y = S.fromList (map (xor y) xs)
