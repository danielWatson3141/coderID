-- idee nach 30 mmin
-- umsetzung
-- fehler: read für word ist nicht bina

import Control.Applicative
import Control.Arrow
import Control.Monad
import Control.Monad.Trans.State.Lazy
import Data.Bits
import Data.Char  (digitToInt)
import Data.List
import Data.Maybe
import Data.Set
import Data.Word
import GCJ
import Numeric    (readInt)
import System.IO
import Text.Printf


readBin :: Integral a => String -> a
readBin = fromJust . fmap fst . listToMaybe . readInt 2 (`elem` "01") digitToInt
  
main = mainId $ do
  (n:(l:[])) <- (fmap (read :: String -> Integer).words) <$> cLine
  a <- fmap (fmap (readBin :: String -> Word64) . words) <$> cLines 2
  let (o,d) = (sort (a !! 1),a!!0)
      even = listToMaybe $ sort $ catMaybes $ check o d . (o!!0 `xor`) <$> d
      odd = check o d (foldl1 xor $ concat  a)
      b = if n `mod` 2 == 1 then odd 
          else even
  return $ maybe "NOT POSSIBLE" show b
  -- return $ unlines $ [show c] ++ [show $ a !! 1] ++ (show <$> [n,l])

-- sorted first arg
check :: [Word64] -> [Word64] -> Word64 -> Maybe Int
check o d x = if sort d' == o then Just (popCount x)
              else Nothing
  where d' = xor x <$> d
