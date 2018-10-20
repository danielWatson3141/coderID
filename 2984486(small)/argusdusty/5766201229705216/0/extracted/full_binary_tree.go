package main

import (
	"fmt"
	"os"
	"strconv"
)

func tree_dist(parent, root int, Edges [][2]int) (int, int) {
	vals := [][2]int{}
	for _, edge := range Edges {
		if edge[0] == root {
			if edge[1] != parent {
				a, b := tree_dist(root, edge[1], Edges)
				vals = append(vals, [2]int{a, b})
			}
		} else if edge[1] == root {
			if edge[0] != parent {
				a, b := tree_dist(root, edge[0], Edges)
				vals = append(vals, [2]int{a, b})
			}
		}
	}
	if len(vals) == 0 {
		return 1, 0
	}
	if len(vals) == 1 {
		return vals[0][0] + 1, vals[0][0]
	}
	if len(vals) == 2 {
		return 1 + vals[0][0] + vals[1][0], vals[0][1] + vals[1][1]
	}
	a := 1
	b := 0
	for len(vals) > 2 {
		mn := vals[0][0] - vals[0][1]
		j := 0
		for i := 1; i < len(vals); i++ {
			if vals[i][0]-vals[i][1] < mn {
				mn = vals[i][0] - vals[i][1]
				j = i
			}
		}
		a += vals[j][0]
		b += vals[j][0]
		vals = append(vals[:j], vals[j+1:]...)
	}
	return a + vals[0][0] + vals[1][0], b + vals[0][1] + vals[1][1]
}

func fullBinaryTree(N int, Edges [][2]int) string {
	d := N
	for i := 1; i <= N; i++ {
		_, c := tree_dist(0, i, Edges)
		if c < d {
			d = c
		}
	}
	return strconv.Itoa(d)
}

func main() {
	args := os.Args
	file := args[1]
	filein, _ := os.Open(file + ".in")
	fileout, _ := os.Create(file + ".out")
	var cases int
	fmt.Fscanln(filein, &cases)
	for i := 0; i < cases; i++ {
		var N int
		fmt.Fscanln(filein, &N)
		edges := make([][2]int, N)
		for j := 1; j < N; j++ {
			fmt.Fscanln(filein, &edges[j][0], &edges[j][1])
		}
		fmt.Fprintln(fileout, "Case #"+strconv.Itoa(i+1)+": "+fullBinaryTree(N, edges))
	}
}
