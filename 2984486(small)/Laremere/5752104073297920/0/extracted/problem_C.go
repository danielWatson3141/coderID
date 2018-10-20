package main

import (
	"fmt"
	"math/rand"
	"os"
)

func pie(err error) {
	if err != nil {
		panic(err)
	}
}

// var magic = []int{158, 2, 20, -13, -41, -48, 11, -35, -59, 5,
// 	137, 75, -63, 1, -54, -6, -60, -20, 45, -55,
// 	53, 160, 98, -85, -32, -92, -100, 28, -39, 9,
// 	43, 69, 114, -31, -79, 4, -37, -1, -57, -25,
// 	43, 29, 20, 125, -22, -87, -54, -76, 18, 4,
// 	-97, 55, -15, 82, 197, 13, -120, -47, -51, -17,
// 	-17, -29, -5, 5, 76, 57, 34, -130, -24, 33,
// 	-45, -99, -12, 3, 79, 57, 131, 25, -88, -51,
// 	-74, -117, -75, -82, -24, 45, 91, 154, 110, -28,
// 	-201, -145, -82, -5, -100, 57, 104, 102, 145, 125,
// }

func calcMagic() []int {
	result := make([]int, 100)
	for i := 0; i < 1000; i++ {
		arr := make([]int, 1000)
		for j := 0; j < 1000; j++ {
			arr[j] = j
		}

		for j := 0; j < 1000; j++ {
			k := rand.Int() % 1000
			arr[j], arr[k] = arr[k], arr[j]
		}
		for j := 0; j < 1000; j++ {
			result[j/100+(arr[j]/100)*10] += 1
		}
	}
	for i := 0; i < 100; i++ {
		result[i] -= 10000
	}
	return result
}

func main() {
	magic := calcMagic()
	fmt.Println(magic)

	//file, err := os.Open("test.in")
	file, err := os.Open("C-small-attempt2.in")
	pie(err)
	defer file.Close()

	fileout, err := os.Create("out.txt")
	pie(err)
	defer fileout.Close()

	var numProblems int
	_, err = fmt.Fscanln(file, &numProblems)
	pie(err)

	numGood := 0
	numBad := 0

	//buckets := make([]int, 100)
	for i := 0; i < numProblems; i++ {
		var arraySize int
		_, err = fmt.Fscan(file, &arraySize)
		pie(err)

		arr := make([]int, arraySize)

		for i := range arr {
			var j int
			_, err = fmt.Fscan(file, &j)
			arr[i] = j
			pie(err)

		}

		tally := 0
		for i := 0; i < len(arr); i++ {
			tally += magic[i/100+(arr[i]/100)*10]
			//buckets[i/100+(arr[i]/100)*10] += 1
		}

		var answer string
		if tally > 70000 {
			answer = "BAD"
			numBad++
		} else {
			answer = "GOOD"
			numGood++
		}
		fmt.Println(tally)
		//fmt.Println(fVal)
		fmt.Fprintf(fileout, "Case #%d: %s\r\n", i+1, answer)
		//	fmt.Println(buckets[0:10])
	}

	// for i := 0; i < 100; i += 10 {
	// 	for j := 0; j < 10; j++ {
	// 		buckets[j+i] -= 1200
	// 	}
	// 	fmt.Println(buckets[i : i+10])
	// }
	fmt.Println("Good", numGood, "Bad", numBad)
}
