{-# LANGUAGE ScopedTypeVariables #-}
import System.Directory
import Control.Applicative
import Control.Monad
import Numeric
import Data.List
import Data.Ord
import Data.Maybe
import qualified Data.Set as Set
import qualified Data.Map as Map

solve (n,m) = show $ (n-) $ maximum $ map (walk Nothing) [1..n] where
  lookup parent node =
    (case parent of Nothing -> id; Just p -> filter (/= p)) (fromJust (Map.lookup node m))
  walk parent node = case lookup parent node of
    [] -> 1
    [_] -> 1
    l -> 1 + sum (take 2 (sortBy (comparing negate) (map (walk (Just node)) l)))

readInput = do
  [n :: Int] <- map read . words <$> getLine
  edges <- replicateM (n-1) $ do
    [x,y :: Int] <- map read . words <$> getLine
    return (x,y)
  return (n, Map.fromListWith (++) [r|(x,y)<-edges,r<-[(x,[y]),(y,[x])]])

main = do
  n <- readLn
  flip mapM_ [1..n] $ \tc -> do
    i <- readInput
    putStrLn $ "Case #" ++ show tc ++ ": " ++ solve i
