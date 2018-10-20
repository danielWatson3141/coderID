import Control.Monad
import Control.Applicative
import Data.List
import Data.Maybe
import Text.Printf
import Debug.Trace

main :: IO ()
main = do
  t <- readLn
  forM_ [1..t::Int] $ \cn -> do
    [n, l] <- map read . words <$> getLine
    ss <- words <$> getLine
    cs <- words <$> getLine

    printf "Case #%d: " cn
    let ans = go ss cs l 0 n
    if ans < inf
      then printf "%d\n" ans
      else printf "NOT POSSIBLE\n"

  return ()

inf = 99999

go :: [String] -> [String] -> Int -> Int -> Int -> Int
go ss cs l i n
  | l == i = 0
  | otherwise = do
    let fss = nflip i ss

        fsi = sort $ map (take $ i+1) fss
        ssi = sort $ map (take $ i+1) ss
        csi = sort $ map (take $ i+1) cs

    min (if ssi == csi then go ss cs l (i+1) n else inf)
        (if fsi == csi then 1 + go (nflip i ss) cs l (i+1) n else inf)

nflip :: Int -> [String] -> [String]
nflip i ss = map (\s -> take i s ++ [if (s!!i)=='0' then '1' else '0'] ++ drop (i+1) s) ss
