{-# LANGUAGE
ScopedTypeVariables
,Rank2Types
,GeneralizedNewtypeDeriving
 #-}

-- Start Parser 11:30:04
-- Ende

module GCJ (
  GCJ()
  ,module Control.Applicative
  ,module Control.Monad
  ,cLine
  ,cLines
  ,cBlock
  ,mainM
  ,mainId
  )
       where

import Control.Applicative
import Control.Monad
import Control.Monad.IO.Class
import Control.Monad.Identity
import Control.Monad.Trans.State.Lazy
import Control.Parallel.Strategies
import Data.List
import Safe
import System.Environment
import System.IO
import Text.Printf

-- data Type for Google Code Jam Solution Program
newtype GCJ m a = GCJ { fromGCJ :: (StateT [String] m a) }
                deriving (Functor,Applicative,Monad,MonadIO)

-- has to be Monad (e.g. to implement cBlock)
-- next action has to be able to depend on state

-- produce main from pure function
mainId :: GCJ Identity String -> IO ()
mainId = mainM $ return.runIdentity
                         
-- produce main from Monad
-- reads testInput or the file given on the command line
mainM :: Monad m => (forall a. (m a -> IO a)) -> GCJ m String -> IO ()
mainM exec (GCJ res) = do
  -- t <- hIsTerminalDevice stdin
  (h:t) <- lines <$> (readFile.i =<< getArgs)
  (a,l) <- exec $ flip runStateT t $ sequence $ take (read h) $ repeat res
  sequence_ $ zipWith (printf "Case #%u: %s") [(1::Int)..] $ parMap rdeepseq nl a
  p l
  where i [] = "testInput"
        i (b:_) = b
        nl y = y ++ if "\n" `isSuffixOf` y then "" else "\n"
        p [] = return ()
        p l = error $ "GCJ: not all input lines have been consumed:\n" ++ unlines l
-- WOW: althoug the parsing of the input cannot happen in parallel
-- (lines are consumed one by one, and input of the nexta example
-- depends on how much the current has consumed), the work can be
-- automatically parallized, if the number of lines to consume does
-- not depend on the result of the main workload of each case. THis is
-- demonstrated by the following example:

-- parallel test
mainP = mainId $ do
       r <- return . length . show . product . enumFromTo (1::Integer) . read =<< cLine
       if not parallel && r == 1 then return =<< cLine else return $ show r  
       where parallel = False
-- input file:
-- 2
-- 200000
-- 200000
-- 200000
-- 200000
         
-- consumes and returns one line
cLine :: Monad m => GCJ m String
cLine = GCJ $ do x <- get
                 put $ tail x
                 return $ headNote "GCJ: No input lines left to consume" x

-- consumes and returns n lines
cLines n = sequence $ take n $ repeat cLine

-- consumes next block: return lines 2::x where
-- x = integer in the first line
cBlock :: Monad m => GCJ m [String]
cBlock = cLine >>= (cLines . read)

