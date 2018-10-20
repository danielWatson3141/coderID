package main

import (
	"fmt"
)

func main() {
	var T int
	var N int
	var L int

	fmt.Scanln(&T)
	
	for i := 1; i <= T; i++ {
		fmt.Scanln(&N, &L)
		
		outlets := make(map[string]bool, N)
		for j := 0; j < N; j++ {
			var s string
			fmt.Scan(&s)
			outlets[s] = true
		}
		fmt.Scanln()
		
		devices := make([]string, 0, N)
		for j := 0; j < N; j++ {
			var s string
			fmt.Scan(&s)
			devices = append(devices, s)
		}
		fmt.Scanln()
		
		result := solve(outlets, devices, 0)
		if result >= 0 {
			fmt.Printf("Case #%d: %d\n", i, result)
		} else {
			fmt.Printf("Case #%d: NOT POSSIBLE\n", i)
		}
	}
}

func solve(outlets map[string]bool, devices []string, swi int) int {
	for i := 0; i < len(devices); i++ {
		if _, ok := outlets[devices[i]]; !ok {
			if swi == len(devices[0]) {
				return -100000000
			}
			if res := solve(outlets, devices, swi+1); res >= 0 {
				return res
			}
			newDevices := make([]string, 0, len(devices))
			for j := 0; j < len(devices); j ++ {
				s := []byte(devices[j])
				if s[swi] == '0' {
					s[swi] = '1'
				} else {
					s[swi] = '0'
				}
				newDevices = append(newDevices, string(s))
			}
			return solve(outlets, newDevices, swi+1) + 1
		}
	}
	return 0
}