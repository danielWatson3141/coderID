open Printf
open Scanf

external id : 'a -> 'a = "%identity"
external (|>) : 'a -> ('a -> 'b) -> 'b = "%revapply"
external (@@) : ('a -> 'b) -> 'a -> 'b = "%apply"

let solve () =
  let n = scanf " %d" id in
  let a = Array.make n 0 in
  Array.iteri (fun i _ -> a.(i) <- scanf " %d" id) a;
  let good = ref 0 and bad = ref 0 in
  Array.iteri (fun i e -> if e = i then incr good else if e = i + 1 then incr bad) a;
  printf (if !good >= !bad then "GOOD" else "BAD")

let () =
  let t' = scanf " %d" id in
  for i' = 1 to t' do
    printf "Case #%d: " i';
    solve ();
    printf "\n"
  done
