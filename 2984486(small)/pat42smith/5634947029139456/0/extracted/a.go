package main

import "fmt"

func sort(a []uint64) {
   n := len(a)
   for i := 0; i < n - 1; i++ {
      for j := i + 1; j < n; j++ {
         if a[j] < a[i] {
            a[i], a[j] = a[j], a[i]
         }
      }
   }
}

func doCase(N int, L uint, have []uint64, want []uint64) {
   sort(want)
   best := L + 1
   h := make([]uint64, N)
   for k := range have {
      mask := want[0] ^ have[k]
      for i := range have {
         h[i] = have[i] ^ mask
      }
      sort(h)
      ok := true
      for i := range want {
         if want[i] != h[i] {
            ok = false
            break
         }
      }
      if !ok {
         continue
      }
      bits := uint(0)
      for mask > 0 {
         if mask & 1 != 0 {
            bits++
         }
         mask >>= 1
      }
      if bits < best {
         best = bits
      }
   }
   if best > L {
      fmt.Println("NOT POSSIBLE")
   } else {
      fmt.Println(best)
   }
}

func main() {
   var T int
   fmt.Scanln(&T)
   if T < 1 || T > 100 { panic(T) }
   for t := 1; t <= T; t++ {
      var N int
      var L uint
      fmt.Scanln(&N, &L)
      if N < 1 || N > 150 { panic(N) }
      if L < 2 || L > 40 { panic(L) }
      have := make([]uint64, N)
      want := make([]uint64, N)
      for n := 0; n < N; n++ {
         fmt.Scanf("%b", &have[n])
      }
      for n := 0; n < N; n++ {
         fmt.Scanf("%b", &want[n])
      }
      fmt.Printf("Case #%d: ", t)
      doCase(N, L, have, want)
   }
}
