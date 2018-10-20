// Using only once

package main
import "fmt"

func bitcount(x int, count int) int {
	if x < 2 {
		return x + count
	}
	return bitcount(x/2, count+(x%2))
}

func binaryToInt(x string, k int) int {
	if len(x) == 0 {
		return k
	}
	if x[0] == '1' {
		return binaryToInt(x[1:], k*2 + 1)
	}
	return binaryToInt(x[1:], k*2)
}

func qsort(a []int) []int {
    if len(a) < 2 {
        return a
    }

    left, right := 0, len(a)-1

    // Pick a pivot
    pivotIndex := (left + right)/2
    a[pivotIndex], a[right] = a[right], a[pivotIndex]
    for i := range a {
        if bitcount(a[i], 0) < bitcount(a[right], 0) {
            a[i], a[left] = a[left], a[i]
            left++
        }
    }
    a[left], a[right] = a[right], a[left]

    qsort(a[:left])
    qsort(a[left+1:])

    return a
}

func possible(a []string , b []string, f int) bool {
	set := make(map[int]bool)
	for _, v := range a {
		set[binaryToInt(v, 0) ^ f] = true
	}
	for _, v := range b {
		_, found := set[binaryToInt(v, 0)]
		if !found {
			return false
		}
	}
	return true
}

func solve(ti int) {
	var N, L int
	fmt.Scanf("%d %d", &N, &L)
	
	outlets := make([]string, N, N)
	devices := make([]string, N, N)

	for i := 0; i < N; i++ {
		fmt.Scanf("%s", &(outlets[i]))
	}
	
	for i := 0; i < N; i++ {
		fmt.Scanf("%s", &(devices[i]))
	}

	tl := 1
	for i := 0; i < L; i++ {
		tl *= 2
	}

	trials := make([]int, tl, tl)
	for i := 0; i < tl; i++ {
		trials[i] = i
	}
	qsort(trials)

	for _, v := range trials {
		if possible(outlets, devices, v) {
			fmt.Printf("Case #%d: %d\n", ti, bitcount(v, 0))
			return
		}
	}

	fmt.Printf("Case #%d: NOT POSSIBLE\n", ti)
}

func main(){
	var T int
	fmt.Scanf("%d", &T)
	var ti int
	ti = 1
	for ti <= T {
		solve(ti)
		ti += 1
	}
}
