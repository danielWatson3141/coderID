{-# LANGUAGE BangPatterns #-}
import Data.List
import Data.Ord
import Control.Monad.State
import Control.Applicative
import qualified Data.Map.Strict as M
import Data.Map ((!))
import qualified Data.Set as S
import Text.Printf
import Debug.Trace



build es = foldl' step M.empty es
    where
      step m (x,y) =
          let m' = M.insertWith S.union x (S.singleton y) m
          in M.insertWith S.union y (S.singleton x) m'

calc m | M.size m == 2 = 1
calc m =
    let rs = M.keys . M.filter ((>=2) . S.size) $ m
    in minimum . map (clean m []) $ rs

clean m pv v =
    case S.toList (m ! v) \\ pv of
      [] -> 0
      [v1] -> 1 + clean m [v] v1
      [v1,v2] -> clean m [v] v1 + clean m [v] v2
      vs -> 
          let cs = map (clean m [v]) vs
              rs = map (rm m [v]) vs
              crs = zip cs rs
          in fd crs
{-
              cr1@(c1,_) = fm crs
              crs' = delete cr1 crs
              cr2@(c2,_) = fm crs'
              crs'' = delete cr2 crs'
          in c1 + c2 + (sum' . map snd $ crs'')
-}

rm m pv v = 
    case S.toList (m ! v) \\ pv of
      [] -> 1
      vs -> 1 + (sum' . map (rm m [v]) $ vs)

fm crs = minimumBy (comparing (\(c,r) -> c - r )) crs

fd crs = minimum [c1 + c2 + (sum' . map snd . delete cr2 $ crs') | cr1@(c1,_) <- crs, let crs' = delete cr1 crs, cr2@(c2,_) <- crs']


{-
show (pv,v,vs) `trace`
          let (hs,ts) = splitAt 2 . reverse . sort . map (clean m [v]) $ vs
          in 
-}

sum' = foldl' (+) 0

sol es = show . calc . build $ es

-- Input parser
parse = runParser $ do
  t <- lineOf number
  count t testCase <* eof

testCase = do
  n <- lineOf int
  count (n-1) edge

edge = do
  [x,y] <- lineOf (count 2 int)
  return (x,y)

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
