import Control.Monad
import Text.Printf
import Data.List (foldr1, sort, sortBy)
import Data.Ord (comparing)
import Data.Bits (xor)

readWords :: Read a => IO [a]
readWords = getLine >>= mapM readIO . words

type Case = (Int, Int, [Bits], [Bits])

solve :: Case -> String
solve (n, l, outlets, devices) =
  let possibilities = flipWhich (n, l, outlets, devices)
      results = [ p | p <- possibilities, checkFlip p outlets devices ]
  in case results of
    [] -> "NOT POSSIBLE"
    (x:xs) -> show (sum x)

flipWhich :: Case -> [Bits]
flipWhich (n, l, outlets, devices) =
  let outletSum = checksum outlets
      deviceSum = checksum devices
      helper acc (outletBit, deviceBit)
        | outletBit == deviceBit && n - outletBit == deviceBit = [acc ++ [0]]--, acc ++ [1]]
        | outletBit == deviceBit = [acc ++ [0]]
        | n - outletBit == deviceBit = [acc ++ [1]]
        | otherwise = []
  in sortBy (comparing sum) $ foldM helper [] (zip outletSum deviceSum)

checkFlip :: Bits -> [Bits] -> [Bits] -> Bool
checkFlip p outlets devices =
  let outletsFlipped = [ zipWith xor p outlet | outlet <- outlets ]
  in sort outletsFlipped == sort devices

checksum bits =
  foldr1 (zipWith (+)) bits

type Bits = [Int]

readBits :: String -> Bits
readBits s = map readBit s where
  readBit '0' = 0
  readBit '1' = 1

readCase :: IO Case
readCase = do
  [a, b] <- readWords
  outlets <- getLine
  devices <- getLine
  return (a, b,
          map readBits $ words outlets,
          map readBits $ words devices)

printCase :: Int -> Case -> IO ()
printCase x c = printf "Case #%d: %s\n" x (solve c)

main :: IO ()
main = do
  t <- readLn
  cases <- replicateM t readCase
  zipWithM_ printCase [1..] cases
