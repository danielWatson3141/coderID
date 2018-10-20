import Control.Monad
import Text.Printf
import Data.Map (Map)
import Data.Set (Set)
import qualified Data.Map as Map
import qualified Data.Set as Set

readWords :: Read a => IO [a]
readWords = getLine >>= mapM readIO . words

type Case = (Int, [(Int, Int)])

type AdjacencyList = Map Int (Set Int)

data Tree = Full Tree Tree | Half Tree | Leaf | NonBinary [Tree] deriving (Show)

readCase :: IO Case
readCase = do
  n <- readLn
  edges <- replicateM (n-1) $ do
    [x, y] <- readWords
    return (x, y)
  return (n, edges)

makeAdjacencyList :: Case -> AdjacencyList
makeAdjacencyList (n, edges) =
  let forward = Map.fromListWith (Set.union) [(x, Set.singleton y) | (x, y) <- edges]
      backward = Map.fromListWith (Set.union) [(y, Set.singleton x) | (x, y) <- edges]
  in Map.unionWith (Set.union) forward backward

findAdjacent :: Int -> AdjacencyList -> Set Int
findAdjacent = Map.findWithDefault Set.empty

rootTreeAt n adjacencyList = helper n Set.empty where
  helper k seen = case Set.toList $ Set.difference (findAdjacent k adjacencyList) seen of
    [x, y] -> Full (helper x (Set.insert k seen)) (helper y (Set.insert k seen))
    [x] -> Half (helper x (Set.insert k seen))
    [] -> Leaf
    xs -> NonBinary [helper x (Set.insert k seen) | x <- xs]

treeScore :: Tree -> Int
treeScore (NonBinary xs) = sum (map treeWeight xs)
                           + minimum [ treeScore x + treeScore y - treeWeight x - treeWeight y
                                     | (i, x) <- zip [0..] xs,
                                       (j, y) <- zip [0..] xs, i /= j ]
treeScore (Full x y) = treeScore x + treeScore y
treeScore (Half x) = 1 + treeScore x
treeScore Leaf = 0

treeWeight (NonBinary xs) = 1 + sum (map treeWeight xs)
treeWeight (Full x y) = 1 + treeWeight x + treeWeight y
treeWeight (Half x) = 1 + treeWeight x
treeWeight Leaf = 1

bestTreeScore :: Int -> AdjacencyList ->  Int
bestTreeScore n adjacencyList = min (n-1) (minimum [treeScore (rootTreeAt k adjacencyList) | k <- [1..n]])

solve :: Case -> String
solve (n, edges) =
  let adjacencyList = makeAdjacencyList (n, edges)
  in show $ bestTreeScore n adjacencyList

printCase :: Int -> Case -> IO ()
printCase x c = printf "Case #%d: %s\n" x (solve c)

main :: IO ()
main = do
  t <- readLn
  cases <- replicateM t readCase
  zipWithM_ printCase [1..] cases
