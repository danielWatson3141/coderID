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
		nodes := make([][]int, N)
		for j := 0; j < N-1; j++ {
			var x, y int
			fmt.Scanln(&x, &y)
			edgeAdd(nodes, x, y)
			edgeAdd(nodes, y, x)
		}
		tedge := make([]int, 0)
		for j := 0; j < len(nodes); j ++ {
			if len(nodes[j]) == 2 || len(nodes[j]) > 3 {
				tedge = append(tedge, j)
			}
		}
		fmt.Printf("Case #%d: %d\n", i, len(tedge)-1)
	}
}

func edgeAdd(nodes [][]int, x, y int) {
	x = x-1
	if nodes[x] == nil {
		nodes[x] = make([]int, 0)
	}
	nodes[x] = append(nodes[x], y)
}