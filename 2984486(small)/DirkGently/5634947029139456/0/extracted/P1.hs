import Control.Monad
import Data.Ratio
import Data.Maybe
import Data.Array
import Data.Word
import Data.List
import Data.Hashable
import Data.Serialize
import qualified DyadicMap as DM
import System.IO
import System.IO.Unsafe
import Data.Bits
import qualified Data.ByteString as BS


debug :: (Show a) => a -> a
debug t
   | False = unsafePerformIO $
    do hPutStrLn stderr $ show t
       return t
   | otherwise = t

solution :: Int -> Int -> [String] -> [String] -> Maybe Int
solution l i outlets devices
    | l == i = case sort (debug outlets) == sort (debug devices) of
                 True -> Just 0
                 _ -> Nothing
    | length devices0 == length outlet0
    , length devices0 /= length devices1 = snd $
        debug ("Normal"++show i, sn)
    | length devices0 == length outlet1
    , length devices0 /= length devices1 = snd $
        debug ("Switch"++show i, sns)
    | length devices0 == length outlet0
    , length devices1 == length outlet1
    , length devices0 == length devices1 =
        case catMaybes [sn, sns] of
           [] -> Nothing
           x -> Just $ minimum x
    | otherwise = Nothing
    where (outlet0,outlet1) = partition ((=='0') . (!! i)) outlets
          (devices0,devices1) = partition ((=='0') . (!! i)) devices
          sn = solution l (i+1) outlets devices
          sns = fmap (+1) $ solution l (i+1) (map (switch i) outlets) devices
          switch i s = x++[y']++z
              where (x,y:z) = splitAt i s
                    y' = case y of
                           '1' -> '0'
                           '0' -> '1'

main =
    do caseCountLn <- getLine
       forM_ [1..(read caseCountLn)] $ \caseNum ->
           do line1 <- getLine
              let [_,l] = map read $ words line1
              line2 <- getLine
              let outlets = words line2
              line3 <- getLine
              let devices = words line3
                  sol = case solution l 0 outlets devices of
                          Nothing -> "NOT POSSIBLE"
                          Just x -> (show x)
              --    solution = error "T"
              putStrLn $ "Case #" ++ show caseNum ++ ": " ++ sol

