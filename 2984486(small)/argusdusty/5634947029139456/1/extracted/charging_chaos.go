package main

import (
	"fmt"
	"os"
	"sort"
	"strconv"
)

func chargingchaos(N, L int, initialstr, requiredstr []string) string {
	initial := make([]int, N)
	required := make([]int, N)
	for i := 0; i < N; i++ {
		x := 0
		r := 0
		for j := 0; j < L; j++ {
			if initialstr[i][j] == '1' {
				x = (x << 1) + 1
			} else {
				x = (x << 1)
			}
			if requiredstr[i][j] == '1' {
				r = (r << 1) + 1
			} else {
				r = (r << 1)
			}
		}
		initial[i] = x
		required[i] = r
	}
	sort.Ints(required)
	matched := false
	best := L
	for i := 0; i < N; i++ {
		toFlip := initial[i] ^ required[0]
		a := 0
		x := toFlip
		for x > 0 {
			if (x & 1) == 1 {
				a++
			}
			x >>= 1
		}
		if matched {
			if a > best {
				continue
			}
		}
		c := make([]int, len(initial))
		for j := 0; j < N; j++ {
			c[j] = initial[j] ^ toFlip
		}
		sort.Ints(c)
		match := true
		for j := 1; j < N; j++ {
			if c[j] != required[j] {
				match = false
				break
			}
		}
		if match {
			matched = true
			best = a
		}
	}
	if !matched {
		return "NOT POSSIBLE"
	}
	return strconv.Itoa(best)
}

func main() {
	args := os.Args
	file := args[1]
	filein, _ := os.Open(file + ".in")
	fileout, _ := os.Create(file + ".out")
	var cases int
	fmt.Fscanln(filein, &cases)
	for i := 0; i < cases; i++ {
		var N, L int
		fmt.Fscanln(filein, &N, &L)
		initial := make([]string, N)
		required := make([]string, N)
		for j := 0; j < N; j++ {
			fmt.Fscan(filein, &initial[j])
		}
		for j := 0; j < N; j++ {
			fmt.Fscan(filein, &required[j])
		}
		fmt.Fprintln(fileout, "Case #"+strconv.Itoa(i+1)+": "+chargingchaos(N, L, initial, required))
	}
}
