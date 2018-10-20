let bin_of l s =
  let n = String.length s in
  assert (n = l);
  let rec aux acc i = 
    if i = n then acc
    else aux (if s.[i] = '0' then acc * 2 else (assert (s.[i] = '1'); acc * 2 + 1)) (i+1)
  in
  aux 0 0

let rec count_bits i =
  if i = 0 then 0
  else if i mod 2 = 1 then 1+count_bits (i/2)
  else count_bits (i/2)

let read_int _ = Scanf.scanf " %d" (fun x -> x)
let read_bin l = Scanf.scanf " %s" (fun s -> bin_of l s)

let test i = 
  let n = read_int () in
  let l = read_int () in
  let outs = Array.init n (fun _ -> read_bin l) in
  let devhash = Hashtbl.create 17 in
  let firstdev = read_bin l in
  Hashtbl.add devhash firstdev ();
  for i = 2 to n do Hashtbl.add devhash (read_bin l) () done;
  assert (Hashtbl.length devhash = n);
  let min = ref (l+1) in
  let outlist = Array.to_list outs in
  let dev_ok diff =
    (* It's okay if for every outlet we have a device *)
    List.for_all (fun k -> Hashtbl.mem devhash (k lxor diff)) outlist
  in
  for i = 0 to n-1 do
    let diff = outs.(i) lxor firstdev in
    if count_bits diff < !min && dev_ok diff
    then min := count_bits diff
  done;
  Printf.printf "Case #%d: %s\n" i (if !min = l+1 then "NOT POSSIBLE" else string_of_int !min)

let _ =
  let ncases = read_int () in
  for i = 1 to ncases do
    test i
  done
