package main

import (
	"fmt"
	"sort"
)

func main() {
	T := scanint()
	for t := 1; t <= T; t++ {
		doone(t)
	}
}

func doone(t int) {
	N := scanint()
	L := scanint()
	flows := readhelp(N, L)
	needed := readhelp(N, L)
	ans := recurse(tr(flows), tr(needed), 0)
	if ans == -1 {
		fmt.Printf("Case #%d: NOT POSSIBLE\n", t)
	} else {
		fmt.Printf("Case #%d: %d\n", t, ans)
	}
}

func recurse(flows, needed [][]bool, pos int) int {
	if pos == len(flows) {
		/*fmt.Println("flows, needed, pos:", flows, needed, pos)*/
		if similar(flows, needed) {
			/*fmt.Println("True!")*/
			return 0
		}
		return -1
	}
	if pos > 0 && pos%8 == 0 {
		if !similar(flows[:pos], needed[:pos]) {
			return -1
		}
	}

	// column sum shortcut:
	var colsumf, colsumn int
	for l := range flows[pos] {
		if flows[pos][l] {
			colsumf++
		}
		if needed[pos][l] {
			colsumn++
		}
	}
	if colsumf == colsumn && colsumf != len(needed[pos])-colsumf {
		ans := recurse(flows, needed, pos+1)
		if ans == -1 {
			return -1
		}
		return ans
	}
	if colsumf != colsumn && colsumf == len(needed[pos])-colsumf {
		for l := range flows[pos] {
			flows[pos][l] = !flows[pos][l]
		}
		ans := recurse(flows, needed, pos+1)
		if ans == -1 {
			return -1
		}
		return ans + 1
	}
	if colsumf != colsumn && colsumf != len(needed[pos])-colsumn {
		// impossible
		return -1
	}

	// copy flows:
	fflip := make([][]bool, len(flows))
	for i := range flows {
		fflip[i] = flows[i]
	}
	fflip[pos] = make([]bool, len(flows[pos]))
	for i := range flows[pos] {
		fflip[pos][i] = !(flows[pos][i])
	}

	ans := recurse(flows, needed, pos+1)
	if ans != -1 {
		return ans
	}
	ans = recurse(fflip, needed, pos+1)
	if ans != -1 {
		return ans + 1
	}
	return -1
}

func readhelp(N, L int) [][]byte {
	s := make([][]byte, N)
	for n := 0; n < N; n++ {
		s[n] = []byte(scans())
		if len(s[n]) != L {
			fmt.Println(s[n])
			panic("oops")
		}
		for l := range s[n] {
			s[n][l] -= '0'
		}
	}
	return s
}

func similar(a, b [][]bool) bool {
	at := wraps(make([][]bool, len(a[0])))
	bt := wraps(make([][]bool, len(b[0])))
	for i := range at {
		at[i] = make([]bool, len(a))
		bt[i] = make([]bool, len(a))
		for j := range a {
			at[i][j] = a[j][i]
			bt[i][j] = b[j][i]
		}
	}
	sort.Sort(at)
	sort.Sort(bt)
	/*fmt.Println("After sorting:", at, bt, sort.IsSorted(at))*/
	for i := range at {
		for j := range at[i] {
			if at[i][j] != bt[i][j] {
				return false
			}
		}
	}
	return true
}

type wraps [][]bool

func (p wraps) Len() int           { return len(p) }
func (p wraps) Less(i, j int) bool { return cmp(p[i], p[j]) }
func (p wraps) Swap(i, j int)      { p[i], p[j] = p[j], p[i] }

func cmp(x, y []bool) bool {
	for b := range x {
		if (!x[b]) && (y[b]) {
			/*fmt.Printf("x = %v and y = %v, returning true\n", x, y)*/
			return true
		} else if (x[b]) && (!y[b]) {
			return false
		}
	}
	/*fmt.Printf("x = %v and y = %v, returning false\n", x, y)*/
	return false
}

func tr(s [][]byte) [][]bool {
	ret := make([][]bool, len(s[0]))
	for r := range ret {
		ret[r] = make([]bool, len(s))
		for i := range s {
			if s[i][r] == 1 {
				ret[r][i] = true
			}
		}
	}
	return ret
}

func scan(arg ...interface{}) {
	_, err := fmt.Scan(arg...)
	if err != nil {
		panic(err)
	}
}

func scans() (s string) {
	_, err := fmt.Scan(&s)
	if err != nil {
		panic(err)
	}
	return
}

func scanf64() (x float64) {
	_, err := fmt.Scan(&x)
	if err != nil {
		panic(err)
	}
	return
}

func scanint() (n int) {
	_, err := fmt.Scan(&n)
	if err != nil {
		panic(err)
	}
	return
}
