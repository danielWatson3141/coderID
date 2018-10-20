package main

import "fmt"

func main() {
	T := scanint()
	for t := 1; t <= T; t++ {
		doone(t)
	}
}

func doone(t int) {
	var best int
	N := scanint()
	edges := make([][]int, N)
	for n := 0; n < N-1; n++ {
		a := scanint()
		b := scanint()
		edges[a-1] = append(edges[a-1], b-1)
		edges[b-1] = append(edges[b-1], a-1)
	}
	for i := 0; i < N; i++ {
		// try every node as root (it's just 1000).
		res := try(i, edges)
		if res > best {
			best = res
		}
	}
	fmt.Printf("Case #%d: %d\n", t, N-best)
}

func try(root int, edges [][]int) int {
	if len(edges[root]) < 2 {
		return 1
	}
	var best, nextbest int
	for _, c := range edges[root] {
		size := sizeSubtreeWithout(c, edges, root)
		if size > best {
			nextbest = best
			best = size
		} else if size > nextbest {
			nextbest = size
		}
	}
	return 1 + best + nextbest
}

func sizeSubtreeWithout(c int, edges [][]int, parent int) int {
	if len(edges[c]) < 3 {
		return 1
	}
	var best, nextbest int
	for _, cc := range edges[c] {
		if cc == parent {
			continue
		}
		size := sizeSubtreeWithout(cc, edges, c)
		if size > best {
			nextbest = best
			best = size
		} else if size > nextbest {
			nextbest = size
		}
	}
	return 1 + best + nextbest
}

func scanint() (n int) {
	_, err := fmt.Scan(&n)
	if err != nil {
		panic(err)
	}
	return
}
