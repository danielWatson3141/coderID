exception Found of int

let _ =
  let sb = Scanf.Scanning.stdib in
  let cases = Scanf.bscanf sb "%d " (fun s -> s) in
    for ca = 1 to cases do
      let n = Scanf.bscanf sb "%d " (fun s -> s) in
      let l = Scanf.bscanf sb "%d " (fun s -> s) in
      let f = Array.make n "" in
      let d = Array.make n "" in
      let _ =
	for i = 0 to n - 1 do
	  f.(i) <- Scanf.bscanf sb "%s " (fun s -> s)
	done;
	for i = 0 to n - 1 do
	  d.(i) <- Scanf.bscanf sb "%s " (fun s -> s)
	done;
      in
      let convert s =
	let x = ref 0 in
	  for i = 0 to l - 1 do
	    if s.[i] = '0'
	    then x := !x * 2
	    else x := !x * 2 + 1
	  done;
	  !x
      in
      let d = Array.map convert d in
      let f = Array.map convert f in
      let a = Array.make n false in
      let b = Array.make n false in
      let res = ref 1000000000 in
      let rec bf k c mask =
(*Printf.printf "bf %d %d %d\n" k c mask;*)
	if c < !res then (
	  if k <= l then (
	    for i = 0 to n - 1 do
	      b.(i) <- false
	    done;
	    try
	      for i = 0 to n - 1 do
		try
		  for j = 0 to n - 1 do
		    if not b.(j) &&
		      (f.(j) lsr (l - k)) lxor mask = d.(i) lsr (l - k)
		    then raise (Found j)
		  done;
		  raise Not_found
		with
		  | Found j ->
		      b.(j) <- true
	      done;
	      if k < l then (
		bf (k + 1) c (mask * 2);
		bf (k + 1) (c + 1) (mask * 2 + 1);
	      ) else (
		res := c
	      )
	    with
	      |	Not_found -> ()
	  )
	)
      in
	bf 0 0 0;
	if !res < 1000000000
	then Printf.printf "Case #%d: %d\n" ca !res
	else Printf.printf "Case #%d: NOT POSSIBLE\n" ca;
    done
