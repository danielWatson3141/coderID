<?php

/***************************************************************************************************

 ** Google code jam ** 

 Author: 	Ismail Ozturk
 E-Mail: 	ismail.ozturk@gmail.com
 Date:		April 25th, 2014
 Problem:	Round 1A 2014, Question C

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
		
		$numCount = 0;
		$nums = array();
		
		$gc = 0;
		$bc = 0;
		
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
				$numCount = $line;
				continue;
			}
			
			if ( $caseLineCounter == 2 )
			{
				$nums = explode( " ", $line );
				$result = "BAD";
				
				//if the average of the numbers is distributed evenly, we probably used the bad algo
				//let's find the average of each 4th
				$first = 0;
				$second = 0;
				$third = 0;
				$fourth = 0;
				
				for ( $i=0; $i<250; $i++)
				{
					$first += $nums[$i];
				}
				
				$first = $first/250;
				
				for ( $i=250; $i<500; $i++)
				{
					$second += $nums[$i];
				}
				
				$second = $second/250;
				
				for ( $i=500; $i<750; $i++)
				{
					$third += $nums[$i];
				}
				
				$third = $third/250;
				
				for ( $i=500; $i<750; $i++)
				{
					$fourth += $nums[$i];
				}
				
				$fourth = $fourth/250;
				
				//if the difference between the lowest and biggest is 40 or less, then it's bad
				$min = min($first, $second, $third, $fourth);
				$max = max( $first, $second, $third, $fourth );
				
				echo $min . ' ' . $max . "\r\n";
				
				if ( $max - $min < 40 )
				{
					$result = 'GOOD';
					$bc++;
				}
				else 
				{
					$gc++;
				}

				$case++;
				$output = "Case #" . $case .": " . $result;

				if	( $case < $totalCaseCounter )	$output .= "\r\n";

				echo ' ' . $output;
				self::writeToOutput( $output );

				$caseLineCounter = 0;
				$numCount = 0;
				$nums = array();
				
			}

		}
		
		echo "\r\n" . $gc . ' - ' . $bc;
	}
	
}


?>