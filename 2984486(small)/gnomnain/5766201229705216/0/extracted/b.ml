
let read_int _ = Scanf.scanf " %d" (fun x -> x)

let solve ncase =
  let n = read_int () in
  let edges = Array.make n [] in
  for i = 0 to n-2 do
    let x, y = read_int () - 1 , read_int () - 1 in
    edges.(x) <- (y,ref (-1))::edges.(x);
    edges.(y) <- (x, ref (-1))::edges.(y)
  done;
  let nodeval l =
    match List.sort (fun x y -> - compare x y) l with
      | u::v::xs -> 1 + u + v
      | _ -> 1
  in
  let rec getval x (y,r) = 
    if !r = (-1) then r := nodeval (List.map (getval y) (List.filter (fun (z,_) -> z <> x) edges.(y)));
    !r
  in
  let the_nodeval x =
    nodeval (List.map (getval x) edges.(x))
  in
  let rank = ref 0 in
  for i = 0 to n-1 do
 (*   Printf.printf "%d => %d\n" i (the_nodeval i); *)
    rank := max !rank (the_nodeval i)
  done;
  Printf.printf "Case #%d: %d\n" ncase (n - !rank)

let _ =
  let ncases = read_int () in
  for i = 1 to ncases do
    solve i
  done
