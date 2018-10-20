import System.IO
import Data.List
import Control.Monad

main = do
 handle <- openFile "A-large.in" ReadMode
 t <- hGetLine handle
 perform 1 (read t) handle
 hClose handle

perform :: Int -> Int -> Handle-> IO()
perform t limit handle = 
 if (t<=limit) 
 then do l1 <- hGetLine handle
         l2 <- hGetLine handle
         l3 <- hGetLine handle
         let out = words l2
             res = words l3					   
         appendFile "output.txt" ("Case #"++(show t)++": "++(getAnswer out res)++"\n")
         perform (t+1) limit handle
 else return ()
   
getAnswer :: [String] -> [String] -> String
getAnswer out res = if (null answer)
                    then "NOT POSSIBLE"
					else show $ minimum answer
 where array = getCompForAll out res
       answer = filtering (head array) (compArrAll (head array) (tail array)) 0 (length $ head array)
 
compareWord :: String -> String -> Int -> Int -> [Int]
compareWord s1 s2 ind len = if (ind==len)
                            then []
							else  if (s1!!ind /= s2!!ind)
							      then 1:(compareWord s1 s2 (ind+1) len)
								  else 0:(compareWord s1 s2 (ind+1) len)

getComp :: String -> [String] -> [[Int]]
getComp a arr = map (\x -> compareWord a x 0 (length a)) arr

getCompForAll :: [String] -> [String] -> [[[Int]]]
getCompForAll q w = map (\x -> getComp x w) q

compArr :: [Int] -> [[[Int]]] -> Int -> Int -> Bool
compArr a1 mai i l = if (i==l)
                     then True
                     else elem a1 (mai!!i) && compArr a1 mai (i+1) l

compArrAll :: [[Int]] -> [[[Int]]] -> [Bool]
compArrAll o p = map (\x -> compArr x p 0 (length p)) o

filtering :: [[Int]] -> [Bool] -> Int -> Int -> [Int]
filtering forf comp index leng = if (index==leng)
                                 then []
                                 else if (comp!!index)
                                      then (sum $ forf!!index):(filtering forf comp (index+1) leng)
									  else filtering forf comp (index+1) leng
									  
