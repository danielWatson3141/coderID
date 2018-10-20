import Control.Applicative
import Control.Monad
import Data.List
import Text.Printf

import qualified Data.Map as M
import qualified Data.Set as S

main :: IO ()
main = do
  tests <- readLn

  forM_ [1..tests] $ \caseNum -> do
    _ <- getLine

    d <- words <$> getLine
    o <- words <$> getLine

    let ans = filter (\x -> sort (toggleAll x o) == sort d) toggles
        toggles = map (toggle (head o)) d

        toggleAll x = map (toggle x)

        toggle [] [] = []
        toggle (x:xs) (y:ys) = let t = if x == y then '0' else '1'
                                   in t : toggle xs ys

    printf "Case #%d: %s\n" (caseNum::Int) $ case ans of
      [] -> "NOT POSSIBLE"
      xs -> show . minimum . map (length . filter (=='1')) $ xs

    -- print d
    -- print o
    -- print ans
