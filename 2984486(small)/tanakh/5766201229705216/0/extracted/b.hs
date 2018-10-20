import Control.Monad
import Control.Applicative
import Data.List
import Data.Maybe
import Text.Printf
import Debug.Trace
import qualified Data.Map.Strict as M

main :: IO ()
main = do
  cases <- readLn
  forM_ [1..cases::Int] $ \cn -> do
    printf "Case #%d: " cn

    n <- readLn
    eds <- replicateM (n-1) $ do
      [f, t] <- map read . words <$> getLine
      return [(f, t), (t, f)]
    let g = M.fromList $ map (\grp -> (fst$head$grp, map snd grp)) $ groupBy (\a b -> fst a == fst b) $ sort $ concat eds

        f :: Bool -> Int -> Int -> Int
        f True p i =
          let child = M.findWithDefault [] i g \\ [p]
          in 1 + sum (map (f True i) child)
        f _ p i =
          let child = M.findWithDefault [] i g \\ [p]
              c2 | length child >= 2 =
                    [ f False i x + f False i y + sum (map (f True i) (child\\[x, y]))
                    | (x:tls) <- tails child
                    , y <- tls
                    ]
                 | otherwise = []
              c0 = sum (map (f True i) child)
          in minimum $ c0 : c2

        ans = minimum $ map (f False 0) [1..n]

    printf "%d\n" ans

inf = 99999
