<?php

/***************************************************************************************************

 ** Google code jam ** 

 Author: 	Ismail Ozturk
 E-Mail: 	ismail.ozturk@gmail.com
 Date:		April 25th, 2014
 Problem:	Round 1A 2014, Question A

***************************************************************************************************/

$startTime = microtime(true);
codejam::jam();
echo "\r\n\r\n" . " Script executed in " . round(( microtime(true) - $startTime ),2) . " seconds.\r\n";


class codejam
{	
	private static function deleteOutputFileIfExists() 
	{
		$outputFile = dirname(__FILE__) . '\\' . 'output.txt';
		
		if ( file_exists( $outputFile ) )
		{
			unlink( $outputFile );
		}
	}
	
	
	private static function getInputFileHandle()
	{
		$inputFileHandle = dirname(__FILE__) . '\\' . 'input.txt';
		return fopen( $inputFileHandle, 'r');
	}
	
	
	private static function closeFileHandle( $fileHandle )
	{
		return fclose( $fileHandle );
	}
	
	
	private static function writeToOutput( $lineToOutput )
	{
		$outputFile = dirname(__FILE__) . '\\' . 'output.txt';
		return file_put_contents( $outputFile , $lineToOutput, FILE_APPEND );
	}

	
	public static function jam()
	{
		self::deleteOutputFileIfExists();
		$fh = self::getInputFileHandle();
		
		$fileLineCounter = 0;
		$totalCaseCounter = 0;
		$caseLineCounter = 0;
		$case = 0;
		
		$devices = 0;
		$switches = 0;
		$outlets = array();
		$required = array();
		
		
		$matches = array();
		$flips = 0;
		
		while ( $line = trim( fgets( $fh ) ) )
		{
			$fileLineCounter++;
			
			if ( $fileLineCounter == 1 )
			{
				$totalCaseCounter = $line;
				continue;
			}
			
			$caseLineCounter++;
			
			if ( $caseLineCounter == 1 )
			{
				$inputs = explode(" ", $line);
				$devices = $inputs[0];
				$switches = $inputs[1];
				continue;
			}			
			
			if ( $caseLineCounter == 2 )
			{
				$outlets = explode(" ",$line);
				continue;
			}
			
			if ( $caseLineCounter == 3 )
			{
				$required = explode(" ",$line);
				
				$done = false;
				
				//count up from 0 to the 2^switches and use that binary string to flip the switches
				for ( $i=0; $i<=pow(2,$switches); $i++ )
				{
					$mask = str_pad( decbin($i), $switches, "0", STR_PAD_LEFT );
					$amask = str_split( $mask );
					
					$tOutlets = $outlets;
						
					for ( $k=0; $k<count($outlets); $k++ )
					{
						//flip based on the mask
						$aoutlet = str_split($outlets[$k]);
						
						$newstring = "";
						for ( $l=0; $l<count($aoutlet); $l++ )
						{
							if ( $amask[$l] == '0' )
							{
								$newstring .= $aoutlet[$l];
							}
							else
							{
								if ($aoutlet[$l]=='1')
								{
									$newstring .= '0';
								}
								else
								{
									$newstring .= '1';
								}
							}
							
						}
						
						$tOutlets[$k] = $newstring;
						
						//$tOutlets[$k] = $tOutlets[$k] ^ $mask;
						
						//echo $i . " " . $mask . " " . $outlets[$k] . " " . $tOutlets[$k] . "\r\n";
					}
						
					//are we good?
					$matches = self::dotheymatch( $required, $tOutlets);

					if ( count($matches) == count($required) )
					{
						//flips is the number of 1's in the mask
						$flips = substr_count($mask,'1');
						$done = true;
						break;
					}
				}
					
				if ( $done == false )
				{
					$flips = "NOT POSSIBLE";
				}
				
				$case++;
				$output = "Case #" . $case .": " . $flips;

				if ( $case < $totalCaseCounter )
				{
					$output .= "\r\n";
				}

				echo ' ' . $output;
				self::writeToOutput( $output );

				$caseLineCounter = 0;
				$devices = 0;
				$switches = 0;
				$outlets = array();
				$required = array();
				$matches = array();
				$flips = 0;
				
			}

			
			
		}
	}
	
	public static function dotheymatch( $a1, $a2 )
	{
		$matches = array();
		
		for ( $i=0; $i<count($a1); $i++ )
		{
			//is there an outlet that matches?
			for ( $j=0; $j<count($a2); $j++ )
			{
				if ( $a1[$i] == $a2[$j] && !in_array($j, $matches ) )
				{
					$matches[$i] = $j;
				}
			}
		}
		
		return $matches;
	}
	
}


?>