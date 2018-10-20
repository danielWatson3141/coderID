package main

import (
	"fmt"
	"os"
	"strings"
)

func pie(err error) {
	if err != nil {
		panic(err)
	}
}

func main() {
	file, err := os.Open("A-large.in")
	pie(err)
	defer file.Close()

	fileout, err := os.Create("out.txt")
	pie(err)
	defer fileout.Close()

	var numProblems int
	_, err = fmt.Fscanln(file, &numProblems)
	pie(err)

	for casenum := 0; casenum < numProblems; casenum++ {
		var N, L int
		_, err = fmt.Fscan(file, &N, &L)
		pie(err)

		outlets := make([]string, N)
		for i := 0; i < N; i++ {
			_, err = fmt.Fscan(file, &outlets[i])
			pie(err)
		}
		fmt.Println(outlets)

		devices := make([]string, N)
		for i := 0; i < N; i++ {
			_, err = fmt.Fscan(file, &devices[i])
			pie(err)
		}
		fmt.Println(devices)

		switches := make(map[string]bool)
		for i := 0; i < N; i++ {
			switches[diff(devices[0], outlets[i])] = true
		}
		for i := 1; i < N; i++ {
			remove := make([]string, 0)
			for j := range switches {
				found := false
				for k := 0; k < N; k++ {
					if diff(devices[i], outlets[k]) == j {
						found = true
						break
					}
				}

				if !found {
					remove = append(remove, j)
				}
			}

			for _, j := range remove {
				delete(switches, j)
			}
		}

		if len(switches) == 0 {
			fmt.Fprintf(fileout, "Case #%d: NOT POSSIBLE\r\n", casenum+1)
		} else {
			smallest := 50
			for i := range switches {
				try := strings.Count(i, "1")
				if try < smallest {
					smallest = try
				}
			}
			fmt.Fprintf(fileout, "Case #%d: %d\r\n", casenum+1, smallest)
		}

		fmt.Println(switches)
	}
}

func diff(a, b string) string {
	items := make([]string, len(a))
	for i := 0; i < len(a); i++ {
		if a[i] == b[i] {
			items[i] = "0"
		} else {
			items[i] = "1"
		}
	}
	return strings.Join(items, "")
}
