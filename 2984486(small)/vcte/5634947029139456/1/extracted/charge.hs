-- --------------------------------------------- --
-- -------------| Charging Chaos |-------------- --
-- --------------------------------------------- --

-- charging chaos
-- > display $ map charge $ parse example

-- determines answer
charge						:: (Int, Int, Int, [String], [String]) -> String
charge (c, n, l, fs, cs)	| not $ null ds = cn ++ (show $ minimum $ map fst ds)
							| otherwise     = cn ++ "NOT POSSIBLE"
							where
								cn = "Case #" ++ show c ++ ": "
								switches = map (switch (head fs)) cs
								switch fs cs = [fs !! (i - 1) /= cs !! (i - 1) | i <- [1 .. l]]
								ds = filter (match cs . snd) $
									 [(length $ filter id (switches !! (x - 1)),
									  map (\s -> [if switches !! (x - 1) !! (i - 1) 
												  then inv (s !! (i - 1))
												  else s !! (i - 1)
												 | i <- [1 .. l]]) (fs))
									 | x <- [1 .. n]]
								inv '0' = '1'
								inv '1' = '0'
								match [] [] = True
								match cs fs | (length $ filter ((==) (head cs)) cs) /= 
											  (length $ filter ((==) (head cs)) fs) = False
											| otherwise = match [c | c <- cs, c /= head cs]
																[f | f <- fs, f /= head cs]

-- parse string
parse						:: String -> [(Int, Int, Int, [String], [String])]
parse s						= parse' 0 s'
							where
								(n':s') = lines s
								n = read n' :: Int
								parse' m _       | m == n = []
								parse' m (fs:ss:ts:rs) = (m + 1, read ((words fs) !! 0) :: Int,
																 read ((words fs) !! 1) :: Int,
																 words ss, words ts)
														 : parse' (m + 1) rs
								 
-- display answers
display						:: [String] -> IO ()
display						= mapM_ putStrLn

example = unlines [
    "3", 
    "3 2", 
    "01 11 10", 
    "11 00 10", 
    "2 3", 
    "101 111", 
    "010 001", 
    "2 2", 
    "01 10", 
    "10 01"]
	
large = unlines []