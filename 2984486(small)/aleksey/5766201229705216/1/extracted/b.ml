let _ =
  let sb = Scanf.Scanning.stdib in
  let cases = Scanf.bscanf sb "%d " (fun s -> s) in
    for ca = 1 to cases do
      let n = Scanf.bscanf sb "%d " (fun s -> s) in
      let es = Array.make n [] in
      let _ =
	for i = 1 to n - 1 do
	  let u = Scanf.bscanf sb "%d " (fun s -> s) - 1 in
	  let v = Scanf.bscanf sb "%d " (fun s -> s) - 1 in
	    es.(u) <- v :: es.(u);
	    es.(v) <- u :: es.(v);
	done;
      in
      let es = Array.map Array.of_list es in
      let res = ref 1000000000 in
      let used = Array.make n false in
      let a = Array.make n 0 in
      let c = Array.make n 0 in
      let rec dfs u =
(*Printf.printf "dfs %d\n" u;*)
	used.(u) <- true;
	c.(u) <- 1;
	let d = ref [] in
	  for i = 0 to Array.length es.(u) - 1 do
	    let v = es.(u).(i) in
	      if not used.(v) then (
		dfs v;
		c.(u) <- c.(u) + c.(v);
		d := (a.(v), c.(v)) :: !d;
	      )
	  done;
	  let d = Array.of_list !d in
	    if Array.length d = 0
	    then a.(u) <- 0
	    else if Array.length d = 1
	    then a.(u) <- c.(u) - 1
	    else (
	      a.(u) <- 1000000000;
	      for i = 0 to Array.length d - 1 do
(*Printf.printf "qwe %d %d %d\n" i (fst d.(i)) (snd d.(i));*)
		for j = 0 to i - 1 do
		  let (a1, c1) = d.(i) in
		  let (a2, c2) = d.(j) in
		  a.(u) <- min a.(u)
		    (c.(u) - 1 - c1 - c2 + a1 + a2)
		done
	      done
	    )
(*;Printf.printf "dfs <- %d %d %d\n" u a.(u) c.(u);*)
      in
	for i = 0 to n - 1 do
	  for j = 0 to n - 1 do
	    used.(j) <- false;
	  done;
	  dfs i;
(*Printf.printf "asd %d %d\n" i a.(i);*)
	  res := min !res a.(i)
	done;
	Printf.printf "Case #%d: %d\n%!" ca !res
    done
