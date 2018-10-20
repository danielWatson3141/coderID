{-# LANGUAGE QuasiQuotes,TemplateHaskell,ScopedTypeVariables,ViewPatterns,TupleSections,LambdaCase #-}
import Data.List.Split
import Data.String.Here
import Text.Printf
import Data.List
import Data.BitVector
import Data.Function
import Text.Groom

main = interact (unlines.f.lines) where
	f (x:xs) = zipWith (++) [[i|Case #${x}: |]|(x::Int)<-[1..]] $ reverse $ fst $ (!! read x) $ iterate fCase ([],xs)
		where
		ints::String -> [Int] = map read.words
		fCase:: ([String],[String]) -> ([String],[String])
		fCase (results,(ints->[_N,_L]::[Int]):(words->cf0::[String]):(words->cf1::[String]):more) = (,more) $ (:results) $
			let 
				masks :: [((Int,Integer), (Int,Int))]
				masks = [g x y| f<-[zip [1..]], x<-f cf0, y<-f cf1]
					where
					g (i,x) (j,y) = let bs = zipWith (/=) x y 
						in ((length (filter id bs), nat $ fromBits bs), (i,j))	
				sorted = sort masks
				groups = groupBy ((==) `on` fst) $ sorted
				result = \case
					((((n,_),_):_):_) -> show (n::Int)
					[] -> "NOT POSSIBLE"
			--in show $ map ((<_N) . length . group . map snd) groups
			in result $ (`dropWhile` groups) $ (<_N) . length . group . map snd 
			--in groom $ groups
			--in unlines $ ("":) $ map groom $ groups
