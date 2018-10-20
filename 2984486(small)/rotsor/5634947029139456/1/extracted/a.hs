{-# LANGUAGE ScopedTypeVariables #-}
import System.Directory
import Control.Applicative
import Control.Monad
import Numeric
import Data.List
import qualified Data.Set as Set

split l = (filter ((=='0').head) l, filter ((=='1').head) l)

flipp True '0' = '1'
flipp True '1' = '0'
flipp False x = x

go inp flips = guard check >> recc where
  recc = if length flips < length (head $ fst inp) then
           (go inp (flips ++ [True])) ++ (go inp (flips ++ [False]))
           else return flips
  check =
    let l = length flips in
    case inp of
      (init, desir) ->
        let init' = map (take l) init in
        let desir' = map (zipWith flipp flips) desir in
        sort init' == sort desir'

solve inp =
  let l = map (length . filter id) (go inp []) in
  if null l then "NOT POSSIBLE"
                 else show $ minimum l

readInput = do
  [n,l :: Integer] <- map read . words <$> getLine
  initial <- words <$> getLine
  desired <- words <$> getLine
  return (initial, desired)

main = do
  n <- readLn
  flip mapM_ [1..n] $ \tc -> do
    i <- readInput
    putStrLn $ "Case #" ++ show tc ++ ": " ++ solve i
