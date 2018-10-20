open Parse

let debug = false

let parse_string_list_size n =
  let rec aux i =
    if i = 0 then []
    else
      let v = parse_string () in 
      parse_space ();
      v :: aux (i-1)
  in
  aux n

let parse_one () =
  let n, l = Scanf.scanf "%d %d\n" Parse.tuple2 in
  let o = parse_string_list_size n in
  let d = parse_string_list_size n in
  (n, l, o, d)

let rec count0 i acc = function
  | [] -> acc
  | s :: q ->
    (* if debug then Format.eprintf "Counting %d in %s@." i s; *)
    if s.[i-1] = '0' then count0 i (acc+1) q else count0 i acc q

let count0 i l = count0 i 0 l

let partition i list =
  let rec aux acc0 acc1 = function
    | [] -> (acc0, acc1)
    | s :: q ->
      if s.[i-1] = '0' then aux (s :: acc0) acc1 q else aux acc0 (s :: acc1) q
  in
  aux [] [] list

let update_matching i matching =
  let rec aux acc = function
    | [] -> acc
    | (o, d) :: q ->
      let o0, o1 = partition i o in
      let d0, d1 = partition i d in
      if not (List.length o0 = List.length d0) then raise Exit;
      aux ((o0, d0) :: (o1, d1) :: acc) q
  in
  aux [] matching

let switch_o i l =
  List.iter
    (fun s -> if s.[i-1] = '0' then s.[i-1] <- '1' else s.[i-1] <- '0') l

let solve_one (n, l, o, d) =
  let matching = ref [(o, d)] in
  let switch = ref 0 in
  try
    for i = l downto 1 do
      if debug then Format.eprintf "i: %d@." i;
      let zo = count0 i o in
      let zd = count0 i d in
      if debug then Format.eprintf "zo %d, zd %d, l %d@." zo zd l;
      if zo = zd (* no switch *) then begin
        matching := update_matching i !matching
      end else if zo = n - zd (* switch *) then begin
        incr switch;
        switch_o i o;
        matching := update_matching i !matching
      end else (if debug then Format.eprintf "Giving up@."; raise Exit)
    done;
    Some !switch
  with Exit -> None

exception Found of int

let solve_one' (n, l, o, d) =
  let rec aux i matching (switch:int) =
    if i = 0 then switch
    else begin
      if debug then Format.eprintf "i: %d@." i;
      let zo = count0 i o in
      let zd = count0 i d in
      if debug then Format.eprintf "zo %d, zd %d, l %d@." zo zd l;
      let noswitch =
        if zo = zd (* no switch *) then
          try
            aux (i-1) (update_matching i matching) switch
          with Exit -> max_int
        else max_int
      in
      let withswitch =
        if zo = n - zd (* switch *) then begin
          switch_o i o; 
          let r =
            try aux (i-1) (update_matching i matching) (switch+1)
            with Exit -> max_int
          in
          switch_o i o;
          r
        end
        else
          max_int
      in
      min noswitch withswitch
    end
  in
  let r = aux l [(o, d)] 0 in
  if r = max_int then None else Some r


let () =
  let n = parse_int () in
  parse_new_line ();
  for i = 1 to n do
    let v = parse_one () in
    let r = solve_one' v in
    match r with
    | None ->     Format.printf "Case #%d: NOT POSSIBLE@." i
    | Some v ->  Format.printf "Case #%d: %d@." i v
  done


(*
Local Variables:
compile-command: "ocamlopt -annot parse.ml trie.ml a.ml -o a"
End:
*)
