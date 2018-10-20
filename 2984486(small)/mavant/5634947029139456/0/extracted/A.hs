import System.Environment
import Data.List.Split
import Data.List
import Numeric
import Data.Function (on)
import qualified Data.Set as Set

main = do
	[f] <- getArgs
	fileIO f

fileIO f = do
	input <- readFile (inputFilename f)
	writeFile (outputFilename f) (finalOutput input)

inputFilename f = f ++ ".in"
outputFilename f = f ++ ".out"
printCase n c = "Case #" ++ show n ++ ": " ++ c 
finalOutput = unlines . outputLines
outputLines = zipWith printCase [1..] . solutions 
solutions = map solveCase . textToCases
--roundTo :: (Num a, Ord a, Real a) => Int -> a -> Double 
--roundTo digits = fromRational . (/x) . toRational . round . (*x) . toRational where x = 10^digits 

-- In theory everything above this line will be the same for all problems.

textToCases = map tail . chunksOf 3 . map ((map (map boolify)) . words) . tail . lines
-- This is a hideous mess and it took me like an HOUR to debug.
boolify c = c == '1'

solveCase [inits,needs] = format . filter (satisfiesAll (Set.fromList needs) inits) $ possibilities (head inits) needs

format [] = "NOT POSSIBLE"
format xs = show . countTrue . head $ xs

satisfiesAll needs inits poss = needs == Set.fromList (map (applyMask poss) inits)

possibilities i needs = sortBy (compare `on` countTrue) $ map (switchesNeeded i) needs 

switchesNeeded i n = zipWith (/=) i n

applyMask m x = zipWith xor m x

xor True b = not b
xor False b = b

maskSatisfies m i n = n == applyMask m i

countTrue = length . filter ((==) True)
