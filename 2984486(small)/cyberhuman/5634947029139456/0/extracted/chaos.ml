open Printf
open Scanf

module IS = Set.Make(struct type t = int * int let compare = compare end)

external id : 'a -> 'a = "%identity"
external (|>) : 'a -> ('a -> 'b) -> 'b = "%revapply"
external (@@) : ('a -> 'b) -> 'a -> 'b = "%apply"

let solve () =
  let n, l = scanf " %d %d" (fun n l -> n, l) in
  let read () = let a = Array.make n 0 in Array.iteri (fun i _ -> a.(i) <- sscanf ("0b" ^ scanf " %s" id) "%i" id) a; a in
  let out = read () in
  let dev = read () in
  let trans b = let rec loop a = function 0 -> a | x -> loop (a + (x land 1)) (x lsr 1) in loop 0 b, b in
  match Array.map (fun f -> Array.fold_left (fun a e -> IS.add (trans (e lxor f)) a) IS.empty dev) out |> Array.to_list with
  | hd :: tl ->
    let m = List.fold_left IS.inter hd tl in
    (try printf "%d" (fst @@ IS.min_elt m) with Not_found -> printf "NOT POSSIBLE")
  | _ ->
    assert false

let () =
  let t' = scanf " %d" id in
  for i' = 1 to t' do
    printf "Case #%d: " i';
    solve ();
    printf "\n"
  done
