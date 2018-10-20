package main

import "fmt"
import "math/rand"

const T = 120
const N = 1000
const X = 1000000

var p [][]float64
func init() {
   p = make([][]float64, N)
   for i := range p {
      p[i] = make([]float64, N)
   }
   a := make([]int, N)
   for x := 0; x < X; x++ {
      for k := range a {
         a[k] = k
      }
      for k := range a {
         i := rand.Intn(N)
         a[i], a[k] = a[k], a[i]
      }
      for k := range a {
         p[k][a[k]] += 1.0 / X
      }
   }
}

func doCase(perm []int) {
   bal := float64(1)
   for k := range perm {
      bal *= p[k][perm[k]] * N
   }
   if bal > 1 {
      fmt.Println("BAD")
   } else {
      fmt.Println("GOOD")
   }
}

func main() {
   var tt int
   fmt.Scanln(&tt)
   if tt != T { panic(tt) }
   perm := make([]int, N)
   for t := 1; t <= T; t++ {
      var nn int
      fmt.Scanln(&nn)
      if nn != N { panic(nn) }
      for k := range(perm) {
         fmt.Scan(&perm[k])
         if perm[k] < 0 || perm[k] >= N { panic(perm[k]) }
      }
      fmt.Printf("Case #%d: ", t)
      doCase(perm)
   }
}
