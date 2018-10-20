package main

import (
	"fmt"
)

func main() {
	var T int
	var N int

	fmt.Scanln(&T)
	
	for i := 1; i <= T; i++ {
		fmt.Scanln(&N)
		perm := make([]int, N)
		for j := 0; j < N; j++ {
			fmt.Scan(&perm[j])
		}
		fmt.Scanln()
		fmt.Printf("Case #%d: ", i)
		if displacement(perm) < 32 {
			fmt.Println("GOOD")
		} else {
			fmt.Println("BAD")
		}
	}
}

// calculate the displacement of all the indicies in the permutation
func displacement(perm []int) int {
	di := 0
	for i := 0; i < len(perm); i++ {
		var diff int
		p := perm[i]
		if p < i {
			diff = -1
		} else if p == i{
			diff = 0
		} else {
			diff = 1
		}
		// diff = (p - i) * (p - i)
		
		//diff = perm[i] - i
		// if diff < 0 {
			// diff = -diff
		// }
		// diff = diff
		di += diff
	}
	return di
}