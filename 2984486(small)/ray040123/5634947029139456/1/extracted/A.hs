import Control.Applicative
import Control.Monad
import Data.List

solveAll :: IO String -> IO ()
solveAll solve = do
  nCases <- read <$> getLine :: IO Int
  forM_ [1..nCases] $ \i -> do
    putStr . foldr1 (++) $ ["Case #", show i, ": "]
    putStrLn =<< solve

readNums :: (Num a, Read a) => IO [a]
readNums = map read . words <$> getLine

applyMask :: [Bool] -> [Bool] -> [Bool]
applyMask = zipWith xor where
  xor m b = if m then not b else b

match :: [[Bool]] -> [[Bool]] -> Bool
match a b = sort a == sort b

solve :: [[Bool]] -> [[Bool]] -> Maybe Int
solve src dst = ans . minimum . map solveBy $ dst where
  x = head src
  oo = length x + 1
  solveBy y = let
    mask = zipWith (/=) x y
    isMatch = match (map (applyMask mask) src) dst
    in if isMatch then length . filter id $ mask else oo

  ans count = if count >= oo then Nothing else Just count

convert = map (=='1')

main = solveAll $ do
  [n, m] <- readNums
  flowSrc <- map convert . words <$> getLine
  flowDst <- map convert . words <$> getLine
  return $ case solve flowSrc flowDst of
    Nothing -> "NOT POSSIBLE"
    Just ans -> show ans
