(******************************************************************************)
(************** Factorielle et big_int ****************************************)
(******************************************************************************)
open Big_int

let ( @+ ) a b = add_big_int a b

let ( @* ) a b = mult_int_big_int a b

let ( @@* ) a b = mult_big_int a b

let ( @@/ ) a b = div_big_int a b

let fact n =
  let rec aux acc = function
    | 1 -> acc
    | n -> aux (n * acc) (n - 1)
  in
  aux 1 n

(* Meaningless *)
let rec fact_part n = function
  | k when k = n -> n
  | k -> k * (fact_part n (k + 1))

(* Coeff binomiaux *)
let num_to_take k n =
  if n < k then 0 else
    (fact_part n (n - k + 1)) / (fact k)

let fact_b n =
  let rec aux acc = function
    | 1 -> acc
    | n -> aux (n @* acc) (n -1)
  in
  aux unit_big_int n

let rec fact_part_b n = function
  | k when k = n -> big_int_of_int n
  | k -> k @* (fact_part_b n (k+1))

let num_to_take_b k n =
  if n < k then zero_big_int else
    (fact_part_b n (n - k + 1)) @@/ (fact_b k)

(******************************************************************************)
(************** Entrees sorties ***********************************************)
(******************************************************************************)

type line_parsed = {mutable l : string list}

let get_line () = {l = Str.split (Str.regexp "[ \t]+") (read_line ())}

let get_int lp = match lp.l with
  | x :: q -> lp.l <- q; int_of_string x
  | _ -> 0

let get_float lp = match lp.l with
  | x :: q -> lp.l <- q; float_of_string x
  | _ -> 0.

let get_string lp = match lp.l with
  | x :: q -> lp.l <- q; x
  | _ -> ""

(******************************************************************************)
(************** Debut du programme ********************************************)
(******************************************************************************)

type tree = Leaf of int | Node of int * tree list


let solve () =
  let t = read_int () in
  for i = 1 to t do
    print_string "Case #";
    print_int i;
    print_string ": ";
    let l_one = get_line () in
    let n = get_int l_one in
    
    let tree = Array.make (n + 1) [] in
    for j = 1 to n - 1 do
      let l = get_line () in
      let x = get_int l in
      let y = get_int l in
      tree.(x) <- y :: tree.(x);
      tree.(y) <- x :: tree.(y)
    done;

    let parsed = Array.make (n + 1) false in
    let rec build_tree x =
      parsed.(x) <- true;
      let childr = List.filter (function y -> not (parsed.(y))) tree.(x) in
      match childr with
      | [] -> Leaf x 
      | l -> Node (x, (List.map build_tree l))
    in
    
    let r_tree = build_tree 1 in

    let rec nb_elm = function
      | Leaf _ -> 1
      | Node (_, l) -> List.fold_left (+) 1 (List.map nb_elm l)
    in

    let rec nb_del_if_root =
      let cache = Hashtbl.create 10 in
      begin fun t ->
	begin try Hashtbl.find cache t
	  with Not_found ->
	    begin
	      let res = match t with
		| Leaf _ -> 0
		| Node (_, l) -> match l with
		  | [] -> 0
		  | [x] -> nb_elm x
		  | x :: y :: [] -> (nb_del_if_root x) + (nb_del_if_root y)
		  | l -> let l = List.map 
			   (function y ->
			     (nb_elm y) - (nb_del_if_root y)) l in
			 let l = List.rev (List.sort compare l) in
			 match l with
			 | [] -> failwith "impossible"
			 | [x] -> failwith "impossible"
			 | x :: y :: _ -> n - (x + y) - 1
	      in
	      Hashtbl.add cache t res;
	      res
	    end
	end
      end
    in

    let parsed_as_root = Array.make (n+1) false in
    
    let parsed_as = function
      | Leaf x -> parsed_as_root.(x)
      | Node (x, _) -> parsed_as_root.(x)
    in

    let not_eq x = function
      | Leaf y -> x != y
      | Node (y, _) -> x != y
    in

    let res_final = ref n in

    let filter_tree x y l = match List.filter (not_eq y) l with
      | [] -> Leaf x
      | q -> Node (x, q)
    in

    let rec final_parse t = match t with
      | Leaf x ->
	parsed_as_root.(x) <- true;
	res_final := 0
      | Node (x, l) ->
	parsed_as_root.(x) <- true;
	let res = nb_del_if_root t in
	if res < !res_final then
	  res_final := res;
	let l_f = List.filter (function c -> not (parsed_as c)) l in
	List.iter (function child -> match child with
	| Leaf y -> final_parse (Node (y, [filter_tree x y l]))
	| Node (y, l_c) -> final_parse (
	  Node (y, (filter_tree x y l) :: l_c)
	)
	)
	  l_f
    in

    final_parse r_tree;
    print_int !res_final;

    print_newline()
  done


let () = solve ()
