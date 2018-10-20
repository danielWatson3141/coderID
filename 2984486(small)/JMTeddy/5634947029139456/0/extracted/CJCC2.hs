import Data.List
import Data.Maybe (catMaybes)

main = interact $ unlines . zipWith (++) ["Case #" ++ show i ++ ": " |i<-[1..]] . map solve . slice . tail . lines

slice :: [String] -> [ ((Integer,Integer), [String], [String]) ]
slice (a:b:c:cs) = ((a',b') , words b, words c) : slice cs
	where [a',b'] = map read $ words a
slice _ = []

solve :: ((Integer,Integer), [String], [String]) -> String
solve ((a,b), cs, ds)
	| (mod a 2 == 1) = if (cc == "0") then (if (sort cs == sort ds) then "0" else "NOT POSSIBLE") else (if (elem csds bfc) then cc else "NOT POSSIBLE")
	| (cc /= "0") = "NOT POSSIBLE"
	| otherwise = minimum $ map count $ bfc
	where
		csds = xors cs ds
		cc = count csds
		bfc = bf cs ds

count :: String -> String
count = show . length . elemIndices '1'

type Bits = String

xor :: Bits -> Bits -> Bits -- assume equal length
xor [] [] = []
xor (a:as) (b:bs) = (x' a b) : xor as bs
	where
		x' '1' '1' = '0'
		x' '0' '0' = '0'
		x' _ _ = '1'

xors :: [Bits] -> [Bits] -> Bits
xors a b = foldl1 xor $ zipWith xor a b


bf :: [Bits] -> [Bits] -> [Bits]
bf (a:as) bs = catMaybes $ map (\x -> test (xor a x) as (bs \\ [x])) bs

test a bs cs 
	| sort bs' == sort cs = Just a
	| otherwise = Nothing
	where bs' = map (xor a) bs