import Data.Set (Set)
import qualified Data.Set as Set

import Control.Monad
import Data.List
import Data.Ratio
import Data.Bits

-- import qualified Numeric
-- readFloat :: (RealFrac a) => String -> a
-- readFloat = fst . head . Numeric.readFloat

type Case = (Set [Int], Set [Int])

solve :: Case -> [Int]
solve (flows, devs) =
    do dev1 <- devs'
       let diff = zipWith xor (head flows') dev1
       guard (and $ map (\f -> Set.member (zipWith xor f diff) devs) flows')
       return (sum diff)
    where flows' = Set.elems flows
          devs' = Set.elems devs

solvecase :: Case -> String
solvecase c = let sol = solve c in
              if null sol then
                  "NOT POSSIBLE"
              else
                  show (minimum sol)

main :: IO ()
main = do
  text <- getContents
  let cases = getCases text
  putStr $ formatSolutions (map solvecase cases)

formatSolutions :: [String] -> String
formatSolutions cs = unlines $ zipWith formatSolution [1..] cs
    where
      formatSolution :: Int -> String -> String
      formatSolution n msg = "Case #" ++ show n ++ ": " ++ msg

getCases :: String -> [Case]
getCases text = (fetch . tail . lines) text

getbinary :: String -> [Int]
getbinary = map (read . return)

fetch :: [String] -> [Case]
fetch [] = []
fetch (ks:os:ds:xs) = this : fetch xs
    where flows = Set.fromList $ map getbinary $ words os
          devices = Set.fromList $ map getbinary $ words ds
          this = (flows, devices)
