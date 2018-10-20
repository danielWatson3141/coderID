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
	
large = unlines ["100", 
    "1 2", 
    "00", 
    "01", 
    "10 10", 
    "1101101001 1001110000 0101010110 0100001010 0001000101 1010111010 0111001001 1010111100 1010100111 0110010111", 
    "1101110010 1010100001 0100010001 0111010010 0101001101 0001011110 1001101011 1010100111 0110001100 1010111100", 
    "2 2", 
    "00 01", 
    "11 10", 
    "10 10", 
    "1101001000 1100110010 0011101101 1010001001 0100100000 0000110101 1011011111 0011110010 1101010111 0110001110", 
    "1111011010 0110111110 0101100110 0001110011 1000011011 1110001100 0110100001 1000000100 1001100001 0011011101", 
    "10 9", 
    "111110101 101001011 001001011 001110011 011001000 100110011 100001011 101110011 111001101 011110000", 
    "011110111 101001100 001110001 010001111 010110111 011001111 001001001 101110100 111001111 111110111", 
    "1 8", 
    "00101001", 
    "00101110", 
    "3 8", 
    "11000110 11000011 10001001", 
    "11101110 10100001 11101011", 
    "6 6", 
    "101011 001110 010110 010101 111001 010000", 
    "110110 010011 000001 101000 101110 101101", 
    "8 7", 
    "1111010 1000101 1111011 0101011 1010100 1010101 0000101 1101011", 
    "1111011 0000100 1101010 1111010 1000100 1010100 0101010 1010101", 
    "6 9", 
    "000010000 010001111 011101001 010001001 010100110 001001111", 
    "001101010 000100101 010010011 000001100 011001100 000001010", 
    "10 10", 
    "0011110011 0111101100 1010100101 1101001101 0010001010 0100000010 1001011111 0011110110 1100111001 1100010000", 
    "1101110100 0100100111 1011101000 1011000001 0101011011 0000111101 1110001110 0100100010 0011010011 1010011100", 
    "10 10", 
    "0100011100 1111101111 0000110011 1011000011 1111111000 1101011000 1100100110 0010001101 0011100100 0000010011", 
    "0011000011 1111011111 1100001000 0000011101 1100101000 1110110110 0111111000 1000100111 0001100011 0011010100", 
    "10 10", 
    "0110101111 1000111001 0100001101 1000111011 0101010010 0010110100 0011000010 1111010101 1011001000 1101100110", 
    "1110001111 0010111001 0101110110 1001100001 0011100110 0100000000 1110001101 1011010010 1101111100 0000011011", 
    "1 6", 
    "010010", 
    "110001", 
    "8 8", 
    "01001000 11100000 11001111 00111010 00010101 01110101 10011000 00001100", 
    "11011000 01111001 11100011 10111100 00000000 11111000 00111110 11110110", 
    "10 10", 
    "0001001111 1111110100 1001001010 1011001111 0101110101 1110111001 0000111100 0000010010 0110000010 1110100001", 
    "1100010111 0011100001 1101011010 0010010010 0010111100 1100001111 1001100001 1011100100 0111011011 0100101100", 
    "10 10", 
    "0111011010 1110001010 0101010011 1001100000 1011100101 0000000010 0010111100 1100101101 1011111101 0100010111", 
    "1010110010 1101111010 1111111111 0100100011 0011001100 0001000101 0110011101 1000010101 1101100010 0010001000", 
    "10 10", 
    "0100100100 1100001000 0111111111 0110110101 0010010010 0101100011 1010000111 1001111110 1011001001 1001011000", 
    "0111100001 1011010111 0101010110 1010011101 0000100000 1001001011 0101110000 1110111010 0110101111 1000001100", 
    "4 3", 
    "011 110 010 111", 
    "011 010 110 111", 
    "3 5", 
    "10111 00110 01100", 
    "00010 11001 10011", 
    "10 10", 
    "0100111100 1110100011 0110111110 0011101101 0110000111 1001010010 1001011000 0001000000 1100111011 1011000101", 
    "0001111101 1110101000 0001000100 0011000110 1100111111 1110100010 1001011001 0100010111 1011000001 0110111010", 
    "10 10", 
    "0001011001 1110011000 1101000100 1010110011 1101100110 0010101111 0111110111 1011001010 0100011001 0000100100", 
    "1100011110 1101100011 0010100010 1011001101 0110001001 0111110000 1000100011 0001011100 0001111110 1110010101", 
    "10 10", 
    "1101001001 0110101100 0000110011 0111000110 0001000010 1101011110 0110100101 1010111011 1000110100 1011011001", 
    "0011011010 1110110111 1001010010 1011011101 1110100000 0100101111 0101000101 1000110000 0010101011 0101001100", 
    "10 10", 
    "1010110110 1101011110 1001101001 0010000001 1110010010 0101001001 0110001110 0110101011 1001110101 0001110100", 
    "1001110011 0110101101 0010000111 1110010100 0001110010 0110001000 0101001111 1101011000 1001101111 1010110000", 
    "6 6", 
    "000001 010101 111110 010001 101010 111010", 
    "111010 000001 101010 101110 000101 010001", 
    "3 3", 
    "000 011 010", 
    "001 000 011", 
    "2 9", 
    "100101110 000100110", 
    "100101101 000100101", 
    "10 10", 
    "1111101001 1010101100 1010111000 0100110100 0000101001 0001000110 0110011010 0101010111 1111000011 1001010111", 
    "1111111011 1010010100 0000000000 1010111110 1111101111 0011001101 0100010001 0101111110 1100000000 0001100011", 
    "10 10", 
    "1111010111 1001001100 0100100010 0100111011 1011000100 1011101001 0110111001 0011000010 1100110110 0000011101", 
    "1101100000 0110111001 1101001101 1010010010 0010011111 1001110011 1111101000 0010000110 0000011101 0101100110", 
    "8 7", 
    "0001010 0001111 1101110 1001011 0001110 1110011 0000100 0101100", 
    "1110110 0000110 0110010 0001000 1111111 1100000 0111110 0000111", 
    "4 7", 
    "1101010 0000001 1000010 0101001", 
    "0101000 1101011 1000011 0000000", 
    "6 10", 
    "0101011010 1000000101 1100000111 0101111000 1100100101 0001011000", 
    "0011111010 0111111000 1010100111 1110100101 0011011000 1010000101", 
    "4 7", 
    "0000000 0110010 0011111 0011001", 
    "0110011 0000001 0011000 0011110", 
    "10 10", 
    "1011101111 1111000111 0010110110 1101100000 0001111000 0001000001 1110010010 0110011100 1100011101 0000101011", 
    "0100111011 1011010111 0110100110 1001110000 0101010001 0010001100 1111111111 1000001101 1010000010 0101101000", 
    "6 9", 
    "110101111 110001001 001000100 110111111 011110101 100100110", 
    "010111011 101101100 000000010 010100101 111010000 001010001", 
    "10 10", 
    "1100010000 0000110010 0000101011 0111111110 1011011000 1110011111 0110100111 1011000001 0101100100 1001001101", 
    "0111110110 1100001101 0000100100 0010110001 1001011011 0010101000 1001000010 1111001110 1110010111 0101111001", 
    "7 10", 
    "0010000001 1101110101 0100010011 0001100000 1100111110 0010101110 1110111101", 
    "0101000001 1010011100 0111000010 1111101111 0110001001 1001111101 1001010010", 
    "10 10", 
    "1111001010 1000011000 1001010100 0111111010 1111100100 0000101001 1111100101 0100000011 0010010111 0000111111", 
    "0100001000 1110000111 0101000100 0011011010 1100101111 1100111001 1011101010 0011110101 1000010011 0011110100", 
    "6 6", 
    "010011 101101 110100 001011 010010 110101", 
    "111101 011011 000011 100100 100101 000010", 
    "4 10", 
    "1111001000 0010110111 0010110000 1111001111", 
    "0010110000 1111001000 0010110111 1111001111", 
    "6 9", 
    "110000110 010001011 100001000 010011011 001001110 100100110", 
    "111011011 010101111 000110001 111100110 000110011 100011001", 
    "4 9", 
    "010010111 110101011 110011111 000000010", 
    "000110111 000000011 100001011 110011110", 
    "4 8", 
    "00000111 10100001 01101101 00110101", 
    "00001111 11000011 01100101 01010111", 
    "10 10", 
    "0001111011 1010011001 0101000011 0000101101 0010100110 1111110100 1000001000 1110010100 1101000010 0111111111", 
    "0001011011 0101100011 1110110100 1111010100 0010000110 1000101000 1101100010 0111011111 1010111001 0000001101", 
    "2 4", 
    "1010 1000", 
    "1101 1111", 
    "10 10", 
    "1110111100 1000011101 0000100111 0010001111 0001011000 0110100000 0101100010 1111010110 1001110001 1111001011", 
    "1101111100 0111001000 0001101111 1001000110 1110111110 1010010001 0110100010 0111010101 0000000011 1000111001", 
    "10 5", 
    "00111 10100 11010 00100 10111 01101 11101 01010 01000 11000", 
    "01000 11010 01101 10111 00100 11101 10100 01010 11000 00111", 
    "2 7", 
    "1111011 1000010", 
    "1111101 1000100", 
    "10 10", 
    "0010011100 1001010110 1110000100 0010100101 0001101011 1100001100 0101111011 0110111011 1001000001 1111110010", 
    "0010101111 1010000101 0001011000 1100110110 0101111111 0001100001 1101000000 1010010010 0110111111 1111001000", 
    "10 10", 
    "0001110101 0010111011 1101100000 1100111011 1011001111 0000010010 1110001111 0101111100 0110000000 1011000100", 
    "0011110001 0100001110 1001000000 1000100111 1101001001 0101010101 1010001110 0110111010 0011111010 1110110101", 
    "10 10", 
    "0001010100 1110110100 0111101110 0000010010 0101101000 0111001101 1000110001 1110011011 1000101111 1011000011", 
    "0000101000 0000001011 1001110010 1100000101 1111101001 1111110111 0010101110 1001011101 0111010100 0110010010", 
    "10 8", 
    "01000011 10010100 01101010 11110010 00100111 10100101 10011100 00111100 01000100 00101100", 
    "11101011 10000111 11001001 01111011 00111000 00111101 01101101 01100000 11110100 01011101", 
    "10 5", 
    "00000 01001 00010 11111 01111 00110 10000 10110 11001 01011", 
    "01001 11011 00010 10010 11101 01101 10100 00000 00100 01011", 
    "4 3", 
    "100 000 110 111", 
    "110 100 101 010", 
    "6 7", 
    "1101111 1101010 0101000 1100100 0011010 1000000", 
    "0111110 1000110 0110010 0100100 0101011 0001111", 
    "4 9", 
    "100001110 100100101 111100100 111111000", 
    "000110111 011000001 000101011 011101010", 
    "10 10", 
    "1101010100 0001111011 1000000001 0011100110 0111101110 1111111111 1110001001 0000000101 1100110000 0010011010", 
    "0110110001 0100001000 1010100010 0101101100 0000111001 1001000011 0111000111 1111010110 1011011110 1000111101", 
    "8 8", 
    "01001100 01000000 11001111 00010101 11111110 00110001 01101101 10000000", 
    "10110000 00111111 10000001 01001110 11111111 00110011 01101010 00010010", 
    "5 10", 
    "1000010110 1110010000 1000110111 1100010110 0111110111", 
    "1011101010 1100001000 1010001010 0100110000 1011000100", 
    "1 8", 
    "00001101", 
    "00001110", 
    "8 5", 
    "11110 01100 10101 00011 00101 01101 01000 10000", 
    "10100 00010 11010 11011 11111 00111 01001 10010", 
    "4 10", 
    "1001001001 1101010100 0011111000 0000101110", 
    "0111100101 0010010000 1000110100 0001110001", 
    "4 6", 
    "011101 010010 000010 001011", 
    "001110 000111 010001 011110", 
    "3 3", 
    "101 100 011", 
    "011 010 101", 
    "8 10", 
    "0100101110 0011110000 1000101111 0000101110 1000001111 1011010001 1011110001 0111110000", 
    "0000101110 0100101110 1100001111 0111110000 0011110000 1100101111 1111010001 1111110001", 
    "10 10", 
    "1111100111 0010000000 1110110011 1001100110 1101111110 0101011001 0010011101 0000011000 1010001111 0101100000", 
    "1101110101 1001001001 0001011011 0011011110 1110111000 0110100110 1100100001 0110011111 0001000110 1010100000", 
    "8 7", 
    "1011010 0001111 0010100 0100101 1111100 1100100 0101001 0011111", 
    "0100101 0011101 1011111 1000111 1000001 0010100 1111101 0110000", 
    "3 9", 
    "111011010 000000011 010110010", 
    "001100110 011001101 000010010", 
    "10 10", 
    "1111100111 0100001000 1100010100 0000100001 1000011101 1001101110 0010110000 0111111110 1111010011 0011001011", 
    "1111100010 0100001000 0111001111 1011010111 1010101100 0111111011 0001110010 0000000001 1000111101 1100010100", 
    "10 10", 
    "1010111001 1011000010 0100001100 0011111110 0101100100 1111000010 0010011011 0100110111 1101001001 1000110101", 
    "0000111001 0010110101 1010010111 1101101000 1100000000 0011001110 1011110010 0111001110 1100111011 0101000101", 
    "2 6", 
    "100010 111110", 
    "111111 111101", 
    "6 10", 
    "1111101100 1001000110 1001100100 1000000010 0011011011 0111101001", 
    "0001011110 1111000011 0100010101 0010000010 0011100011 0111111011", 
    "4 5", 
    "10011 11111 11101 10001", 
    "01110 00010 01100 00000", 
    "6 7", 
    "1000111 0100110 0110111 1110010 1111011 0111000", 
    "0000111 1111000 0001000 0011001 1000100 1001101", 
    "7 8", 
    "10111111 11010100 00000101 10100010 11100111 00111110 01011110", 
    "00011101 10110110 00100011 01011111 11011000 11101101 11001010", 
    "10 10", 
    "1110100101 1001001101 1101100111 0110010000 0101111000 0010110110 0010001000 1001011010 0100101111 1011010011", 
    "0010000111 1011001111 1101111011 1111100101 0000111000 0011010000 0100100000 0100011110 1000001101 1111110010", 
    "4 4", 
    "0010 1110 0001 1101", 
    "0110 0101 1010 1001", 
    "10 10", 
    "0100111100 1111001010 1111010001 1000100011 0001001100 1011001000 0100111111 0011110111 1000010001 0110100110", 
    "1011100010 1100111001 0000000100 0010111111 0111001111 0111001100 1000111011 1100100010 1011010000 0101010101", 
    "8 10", 
    "1101000001 0111101000 0100111001 1000110110 1010001100 0000011100 1000101110 0010001111", 
    "0001111101 1011010100 1100011001 0100011010 1110100011 1110111011 0110001001 0010101100", 
    "8 10", 
    "1001100110 0001110101 0100001100 0001110111 0001111110 1001100100 0001111100 0100001110", 
    "1110101010 0110110010 1110101000 0011000000 0110111011 0011000010 0110110000 0110111001", 
    "2 4", 
    "0110 1000", 
    "0011 1101", 
    "2 6", 
    "101001 111101", 
    "110100 100000", 
    "6 9", 
    "110100111 000011011 001100011 110110110 100011100 101011111", 
    "001100010 101011110 110110111 000011010 110100110 100011101", 
    "6 9", 
    "010001101 100101001 111111110 100101111 101110101 101101010", 
    "010001011 000000000 101110011 011010001 010010100 011010111", 
    "10 10", 
    "0111111101 0000100110 1100011011 1011100000 1010000011 1111011000 0101111001 1000000110 0011001110 0100110101", 
    "0001000110 1100111001 1001100110 0101011011 1010001110 1101110101 1110111101 0011000011 0110011000 0010100000", 
    "10 10", 
    "1110111110 1001100011 0101001000 0100100000 1001011001 0111100010 0011001111 0010111101 1100010101 1010010110", 
    "0011000111 0000110010 0111101111 1010011110 1110110011 0101000100 1011101100 1101110001 1100011001 0000001000", 
    "6 8", 
    "00100110 01100010 10111100 11100000 11111000 10100100", 
    "01011001 10011111 00011101 01000001 00000101 11011011", 
    "1 8", 
    "11101010", 
    "10100010", 
    "5 6", 
    "101010 111001 011001 000000 000101", 
    "100000 001010 110011 001111 010011", 
    "10 10", 
    "0100001101 0011010011 1110100110 0001111101 1011100000 0100010100 0001011010 1010000111 1110111010 1101101001", 
    "0110001000 0110101111 1010111011 1101010101 0011011111 1100110010 1001110100 0100000001 0011000110 1001101000", 
    "10 10", 
    "1110101101 0101000110 1001111011 0011111000 0010110101 0100010101 0110101011 1110000100 1001011010 1001000010", 
    "0111111101 1100110011 1100001010 1011001100 1100010010 0001011101 0110110000 0000001110 1011100101 0011100011", 
    "10 10", 
    "0010110001 1100100010 0111101001 0100001111 0111001101 1001010100 1000011110 1101110010 1011110110 0010001001", 
    "0001001100 0111001000 0011101110 1101010011 0010100100 1101110111 1000001011 1000110011 0110011000 1110110101", 
    "10 10", 
    "1000011101 0111010100 0001110000 1110100111 0110001100 1011101000 0101011011 1100110110 0000001011 1011100011", 
    "1101110100 1001011111 1000100100 0011001100 0011000111 1110100011 0000110010 0110001000 1111111011 0100011001", 
    "10 10", 
    "1000111011 0001000000 1110111100 0000010100 1011000011 1001000111 0111001110 1110111001 0111111001 0100100110", 
    "1111100000 1000011011 0111100111 0010000001 1000011110 0001011110 0001101001 1101100100 0110110011 1110011100", 
    "7 8", 
    "11110110 00100010 01001011 10101110 00110100 10110001 11111101", 
    "10110011 01100111 10111000 01110001 11110100 00001110 11101011", 
    "4 6", 
    "111110 001111 111111 001110", 
    "000010 000011 110010 110011", 
    "4 7", 
    "1100101 0011000 1111011 0101000", 
    "1000111 0111010 1011001 0001010", 
    "10 10", 
    "1011110010 0001010111 1000100101 0110011011 0101001111 1000000110 1011011000 0110101000 1100111000 0111100101", 
    "1000000001 1010101011 0101101011 1100011001 1011100110 0001110110 1011010101 0110111100 0110010110 0101001000", 
    "6 9", 
    "010000110 101101101 110001001 010011111 010100110 111010010", 
    "111011011 010010110 110000000 010001111 010101111 101100100", 
    "6 10", 
    "1001111101 0100001010 0111100011 1111011010 1101100010 0010111111", 
    "1000011110 0101111011 1101000010 0011011100 1110101011 0111000011"]
