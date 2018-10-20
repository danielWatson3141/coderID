
(* Generates the matrix of n*P( sig(i) = j ) *)
(* n = normalization *)

(* At each step the P( sig(k) = j ) = (n-1)/n * P_old( sig(k) = j) + 1/n * P_old( sig(i) = j )  if k <> i
  and P( sig(i) = j ) = avg(P_old(sig(k) = j))
*)

let n = 1000
let nf = float_of_int n

let start = 
  Array.init n (fun k ->
    Array.init n (fun l ->
      if k = l then 1.0 else 0.0
    )
  )

let iter i p =
  Array.init n (fun k ->
    Array.init n (fun j ->
      if k = i then
        (Array.fold_left (fun s a -> s +. a.(j)) 0.0 p) /. nf
      else (nf -. 1.) /. nf *. p.(k).(j) +. 1. /. nf *. p.(i).(j)
    )
  )

let computed =
  let rec aux i acc =
    if i = n then acc
    else aux (i+1) (iter i acc)
  in
  aux 0 start

let read_int _ = Scanf.scanf " %d" (fun x -> x)

let solve ncase =
  let _ = read_int () in
  let perm = Array.init n read_int in
  let score = Array.fold_left ( *. ) 1.0 
    (Array.mapi (fun i j -> computed.(i).(j) *. nf) perm) in
  Printf.eprintf "Case #%d: %f\n" ncase score;
  Printf.printf "Case #%d: %s\n" ncase (if score < 1.0 then "GOOD" else "BAD")

let _ =
  let ncases = read_int () in
  for i = 1 to ncases do
    solve i
  done
  
