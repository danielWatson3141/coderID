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


let solve () =
  let t = read_int () in
  for i = 1 to t do
    print_string "Case #";
    print_int i;
    print_string ": ";

    let l_one = get_line () in
    let n = get_int l_one in
    let l = get_int l_one in

    let l_two = get_line () in
    let l_three = get_line () in
    
    let outl = ref [] in
    let devl = ref [get_string l_three] in

    let first_out = get_string l_two in
    
    let s_myget s i =
      String.get s (i - 1)
    in

    let s_myset s i =
      String.set s (i -1)
    in

    for j = 2 to n do
      outl := (get_string l_two) :: !outl;
      devl := (get_string l_three) :: !devl
    done;

    let diff k r =
      let res = String.create l in
      for i = 1 to l do
	if s_myget k i != s_myget r i then
	  s_myset res i '1'
	else
	  s_myset res i '0'
      done;
      res
    in

    let eq_with_diff diff k r =
      let res = ref true in
      for i = 1 to l do
	if (s_myget k i != s_myget r i) && s_myget diff i != '1' ||
	   (s_myget k i = s_myget r i) && s_myget diff i = '1' then
	  res := false
      done;
      !res
    in

    let numb_one s =
      let res = ref 0 in
      for i = 1 to l do
	if s_myget s i = '1' then
	  res := !res + 1
      done;
      !res
    in

    let possib = ref [] in

    List.iter (function x -> possib := (diff first_out x) :: !possib) !devl;
    
    let real_poss = List.filter
	(function p ->
	  List.for_all
	    (function o ->
	      List.exists 
		(function d ->
		  eq_with_diff p o d
		)
		!devl)
	    !outl)
	!possib
    in    

    begin match real_poss with
    | [] -> print_string "NOT POSSIBLE"
    | x :: q ->
      let res = ref (numb_one x) in
      List.iter
	(function y ->
	  let new_res = numb_one y in
	  if new_res < !res then res := new_res
	)
	q;
      print_int !res
    end;

    print_newline()
  done


let () = solve ()
