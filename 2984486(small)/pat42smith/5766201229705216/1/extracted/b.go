package main

import "fmt"

func getSize(x int, i int, next, size [][]int) {
   if size[x][i] >= 0 {
      return
   }
   y := next[x][i]
   for j := range next[y] {
      if next[y][j] != x {
         getSize(y, j, next, size)
      }
   }
   a, b := 0, 0
   for j := range next[y] {
      if next[y][j] == x {
         continue
      }
      s := size[y][j]
      if s > a {
         b = a
         a = s
      } else if s > b {
         b = s
      }
   }
   if b == 0 {
      size[x][i] = 1
   } else {
      size[x][i] = a + b + 1
   }
}

func doCase(N int, next [][]int) {
   size := make([][]int, N + 1)
   for x := range size {
      size[x] = make([]int, len(next[x]))
      for i := range size[x] {
         size[x][i] = -1
      }
   }
   for x := 1; x <= N; x++ {
      for i := range next[x] {
         getSize(x, i, next, size)
      }
   }
   best := 0
   for x := 1; x <= N; x++ {
      a, b := 0, 0
      for i := range next[x] {
         s := size[x][i]
         if s > a {
            b = a
            a = s
         } else if s > b {
            b = s
         }
      }
      n := 1
      if b > 0 {
         n = a + b + 1
      }
      if n > best {
         best = n
      }
   }
   fmt.Println(N - best)
}

func main() {
   var T int
   fmt.Scanln(&T)
   if T < 1 || T > 100 { panic(T) }
   for t := 1; t <= T; t++ {
      var N int
      fmt.Scanln(&N)
      if N < 2 || N > 1000 { panic(N) }
      next := make([][]int, N + 1)
      for n := 1; n < N; n++ {
         var x, y int
         fmt.Scanln(&x, &y)
         if x < 1 || x > N { panic(x) }
         if y < 1 || y > N { panic(y) }
         next[x] = append(next[x], y)
         next[y] = append(next[y], x)
      }
      fmt.Printf("Case #%d: ", t)
      doCase(N, next)
   }
}
