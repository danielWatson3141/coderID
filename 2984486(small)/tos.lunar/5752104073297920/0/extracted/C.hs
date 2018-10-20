import qualified System.IO
import Data.List
import Data.Bits
import Data.Ord
import Data.Array
import Control.Monad
import Control.Applicative

main = gcj $ do
  n <- read <$> getLine :: IO Z
  xs <- map read . words <$> getLine :: IO [Z]
  return $ solve n xs

solve n xs =
  let f    = array (0,n-1) $ zip [0..] xs
      finv = array (0,n-1) $ zip xs [0..]
      ave = average (0.5:[fint y / fint (x-1)| x<-[n`div`2 .. n-1], let y=finv!x, y<x])
  in if ave > 0.51
        then "BAD"
        else "GOOD"

average xs = sum xs / fint (length xs)

-- type Z = Integer
type Z = Int
type Q = Rational
type R = Double
type S = String

fint = fromIntegral

gcj solver =
  System.IO.hSetBuffering System.IO.stdout System.IO.NoBuffering >>
  readLn >>= sequence_ . flip take [solver >>= output num | num <- [1..]] where
    output num ans = putStrLn $ "Case #"++show num++": "++ans
    -- output num ans = putStrLn ("Case #"++show num++":") >> mapM_ putStrLn ans
