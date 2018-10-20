import qualified System.IO
import Data.List
import Data.Char
import Data.Bits
import Data.Ord
import Control.Monad
import Control.Applicative

main = gcj $ do
  [n,l] <- map read . words <$> getLine :: IO [Z]
  as <- map (map digitToInt) . words <$> getLine :: IO [[Z]]
  bs <- map (map digitToInt) . words <$> getLine :: IO [[Z]]
  return . maybe "NOT POSSIBLE" show $ solve n l as bs

xors = zipWith xor

solve n l as bs =
  let a = head as
      cs = [c| b<-bs, let c=xors a b,
            sort as == sort (map (xors c) bs)]
  in if null cs
        then Nothing
        else Just $ minimum . map sum $ cs

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
