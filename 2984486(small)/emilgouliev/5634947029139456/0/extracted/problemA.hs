import Control.Monad
import GHC.Exts
import Data.Bits
import Data.Int
import Data.List
import qualified Data.Set as Set
import qualified Data.Map as Map

readBinary :: String  -> Int64
readBinary str = go str 0
    where
        go "" ans = ans
        go ('0':r) ans = go r (2*ans)
        go ('1':r) ans = go r (2*ans+1)

count1s :: Int64 -> Int
count1s 0 = 0
count1s n
    | n < 0 = count1s (complement n + 1)
    | otherwise = case quotRem n 2 of
        (n',0) -> count1s n'
        (n',1) -> count1s n' + 1

switchCount x y = xor x y

sortedJoin x y = sortWith BitKind (x++y)

getSwitches elecFlows req = Map.fromList $ zip [0..] (map ((\x -> [x]) . xor req) elecFlows)

convertProblem (Problem init req) = Map.unionsWith (sortedJoin) $ map (getSwitches init) req

newtype BitKind = BitKind Int64 deriving Eq

instance Ord BitKind where
    compare (BitKind x) (BitKind y) = compare (count1s x) (count1s y)

data Problem = Problem [Int64] [Int64] deriving (Show)

--solveProblem :: Int -> IO Problem
solveProblem i = do
    [n,l] <- liftM (map read . words) getLine :: IO [Int]
    iniElecFlow <- liftM (map readBinary . words) getLine
    reqElecFlow <- liftM (map readBinary . words) getLine
    let x = foldr1 intersect $ Map.elems $ convertProblem $ Problem iniElecFlow reqElecFlow
    putStr $ "Case #" ++ (show i) ++ ": "
    case x of
        [] -> putStrLn $ "NOT POSSIBLE"
        (x:_) -> putStrLn $ show $ count1s x

main :: IO ()
main = do
    t <- readLn :: IO Int
    mapM_ solveProblem [1..t]
