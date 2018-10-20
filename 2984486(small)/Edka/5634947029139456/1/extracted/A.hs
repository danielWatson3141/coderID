{-# LANGUAGE BangPatterns #-}
import Data.List
import Data.Bits
import Data.Ord
import Control.Monad.State
import Control.Applicative
import qualified Data.Map as M
import Data.Map ((!))
import qualified Data.Set as S
import Text.Printf
import Debug.Trace


fromBin = foldl' (\a b -> a*2+b) 0


calc os ds = 
    let ps = [(o`xor`d,(oi,di)) | (o,oi) <- zip os [0..],(d,di) <- zip ds [0..]]
        sps = groupBy (\l r -> fst l == fst r) . sortBy (comparing fst) $ ps
    in case filter cr sps of
         [] -> "NOT POSSIBLE"
         rs -> show . minimum . map (popCount . fst . head) $ rs
    where
      n = length os
      cr g = 
          let (ois,dis) = unzip . map snd $ g
          in S.size (S.fromList ois) == n && S.size (S.fromList dis) == n
       


sol (os,ds) = calc os ds 

-- Input parser
parse = runParser $ do
  t <- lineOf number
  count t testCase <* eof

testCase = do
  [n,l] <- lineOf (count 2 int)
  os <- lineOf (count n binStr)
  ds <- lineOf (count n binStr)
  return (map fromBin os, map fromBin ds)

binStr = string >>= return . map (\c -> if c == '0' then (0::Int) else 1) 

-- Output formatter
format i c = "Case #" ++ show i ++ ": " ++ sol c

main = do
  c <- getContents
  mapM_ (putStrLn . uncurry format) . zip [1..] . parse $ c


-- GCJ Parser combinator
type Input = [[String]]
type Parser = State Input

runParser :: Parser a -> String -> a
runParser p = evalState p . map words . lines

string :: Parser String
string = state $ \((w:ws):ls) -> (w, ws:ls)

token :: Read a => Parser a
token = string >>= return .read

number :: (Read n, Num n) => Parser n
number = token

int :: Parser Int
int = number

double :: Parser Double
double = number

eol :: Parser ()
eol = state $ \([]:ls) -> ((), ls)

eof :: Parser ()
eof = state $ \[] -> ((), [])

line :: Parser String
line = state $ \ (ws:ls) -> (unlines ws, ls)

lineOf :: Parser a -> Parser a
lineOf p = p <* eol

count :: Integral n => n -> Parser a -> Parser [a]
count 0 p = return []
count n p = do
  a <- p
  as <- count (n-1) p
  return (a:as)
