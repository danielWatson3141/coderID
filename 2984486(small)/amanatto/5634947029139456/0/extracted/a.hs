{-# LANGUAGE TupleSections #-}

import Control.Applicative
import Control.Monad
import System.IO
import System.Environment  
import qualified Data.Bimap as Bimap
--import Debug.Trace

import Data.Maybe
import Data.List



argsToHandle :: IO Handle
argsToHandle = do
  args <- getArgs
  if (null args)
     then return stdin
    else openFile (head args) ReadMode

readLn' :: Read a => Handle -> IO a
readLn' h = fmap read $ hGetLine h
           
main :: IO ()
main = do
  h <- argsToHandle
  q <- readLn' h
  forM_ [1..q] $ \qn -> do
    readPrint (hGetLine h) qn
  

readPrint ::  (IO String) -> Int -> IO ()
readPrint gl q = do
  (n:l:_) <- map read . words <$> gl
  ns <- words <$> gl
  ls <- words <$> gl
  putStrLn $ "Case #" ++ (show q) ++ ": " ++ (showResults $ mainCalc n l ns ls)

  
showResults :: Maybe Int -> String
showResults (Just n) = show n
showResults Nothing = "NOT POSSIBLE"


mainCalc :: Int -> Int -> [String] -> [String] -> Maybe Int
mainCalc n l ns ls =
  let res = dropWhile isNothing $ map lookForAns $ subsequences [0..l]
  in
   if null res
      then Nothing
      else head res
  where sortedLs = sort ls
        lookForAns :: [Int] -> Maybe Int
        lookForAns rplace = 
          let challenge = sort $ applyFlip rplace
          in
           if challenge == sortedLs
           then Just (length rplace)
           else Nothing
        applyFlip :: [Int] -> [String]
        applyFlip rp =
          foldl (\ns flipPos -> map (
                    \nstring -> (take flipPos nstring) ++
                                                 [(charBoolFlip (nstring !! flipPos))] ++
                                                 (drop (flipPos+1) nstring))
                                ns)
               ns rp
        charBoolFlip :: Char -> Char
        charBoolFlip '0' = '1'
        charBoolFlip '1' = '0'


--mainCalc 3 2 ["01", "11", "10"] ["11", "00", "10"]
--mainCalc 2 3 ["101", "111"] ["010", "001"]
--mainCalc 2 2 ["01", "10"] ["10", "01"]
        
