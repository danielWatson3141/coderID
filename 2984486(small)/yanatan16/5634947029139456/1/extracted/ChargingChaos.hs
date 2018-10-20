-- CodeJam 2014
-- Author: Jon Eisen
-- Round:
-- Problem:

-- Run from haskell directory in shell
-- cabal-dev ghci
-- > runWriteFile file.in
module ChargingChaos where

-- Open source `competition` package on hackage: http://hackage.haskell.org/package/competition (by Jon Eisen, yours truly)
import Code.Competition
import Control.Applicative ((<$>))
import Text.ParserCombinators.Parsec (parse, newline, char, optional, many1, oneOf, count, sepBy1)

--import Control.Monad.State
--import Control.Monad.Writer
--import Control.Monad.Identity
--import Data.Monoid
--import Data.Array (Array, (!), array, assocs)
import qualified Data.BitVector as BV
import Data.Map (Map,empty,alter,toList)
import Data.List(foldr,sortBy)

-------------
-- Types
-------------

data Problem = Problem { outlets :: [Flow], devices :: [Flow] } deriving (Show)
data Solution = NotPossible | MinSwitches Integer
type Flow = BV.BitVector

instance Parseable Problem where
  problem = parseProblem

instance Solveable Problem Solution where
  solve = solveProblem

instance Show Solution where
  show NotPossible = "NOT POSSIBLE"
  show (MinSwitches i) = (show i)

solveProblem :: Problem -> Solution
solveProblem p = (findMinSolution (length $ outlets p) . buildSwitchTable) p

buildSwitchTable :: Problem -> [((Int, Int), Flow)]
buildSwitchTable (Problem os ds) = assoc
  where
    assoc = [((i,j), diffVector o d) | (i,o) <- (zip [0..] os), (j,d) <- (zip [0..] ds)]
    diffVector = BV.xor

findMinSolution :: Int -> [((Int, Int), Flow)] -> Solution
findMinSolution len = findFirstFull len . invertFlowTable

findFirstFull :: Int -> [(Integer, [a])] -> Solution
findFirstFull n [] = NotPossible
findFirstFull n ((f,as):fas)
  | n == length as = MinSwitches f
  | otherwise = findFirstFull n fas

invertFlowTable :: [((Int, Int), Flow)] -> [(Integer, [(Int, Int)])]
invertFlowTable = sortBy cmp . map countFirstOnes . toList . foldr f empty
  where
    countFirstOnes (f,a) = (countOnes f, a)
    cmp (f,_) (g,_) = compare (fst f) (fst g)
    f (index,diff) = alter (push index) diff
    push index Nothing = Just [index]
    push index (Just is) = Just (index : is)

countOnes :: Flow -> Integer
countOnes = fromIntegral . length . filter id . BV.toBits

--- Parsers
int = (read :: String -> Int) <$> (many1 $ oneOf "-0987654321")
flow = do
  code <- many1 $ oneOf "01"
  return $ BV.join $ map oneOrZero code

oneOrZero '1' = BV.ones 1
oneOrZero '0' = BV.zeros 1

parseProblem = do
  [n,l] <- int `sepBy1` (char ' ')
  newline
  outlets <- flow `sepBy1` (char ' ')
  newline
  devices <- flow `sepBy1` (char ' ')
  return (Problem outlets devices)

main = runCompetition :: IO [(Problem, Solution)]

runFile s = do
  (output, _) <-  runSolution s :: IO (String, [(Problem, Solution)])
  return output

runWriteFile s t = do
  (output, _) <- runWriteSolution s t :: IO (String, [(Problem, Solution)])
  return output