(*
let _ =
  Printf.printf "100\n";
  let n = 1000 in
  let perm1 () =
    let a = Array.init n (fun i -> i) in
      for i = n - 1 downto 1 do
	let j = Random.int (i + 1) in
	let tmp = a.(i) in
	  a.(i) <- a.(j);
	  a.(j) <- tmp
      done;
      a
  in
  let perm2 () =
    let a = Array.init n (fun i -> i) in
      for i = 0 to n - 1 do
	let j = Random.int n in
	let tmp = a.(i) in
	  a.(i) <- a.(j);
	  a.(j) <- tmp
      done;
      a
  in
    for i = 1 to 100 do
      let perm = if i <= 50 then perm1 else perm2 in
      let a = perm () in
	Printf.printf "%d\n" n;
	for i = 0 to n - 1 do
	  Printf.printf "%d " a.(i)
	done;
	Printf.printf "\n"
    done
*)

let _ =
  let sb = Scanf.Scanning.stdib in
  let cases = Scanf.bscanf sb "%d " (fun s -> s) in
    for ca = 1 to cases do
      let n = Scanf.bscanf sb "%d " (fun s -> s) in
      let a = Array.make n 0 in
      let b = Array.make n 0 in
      let _ =
	for i = 0 to n - 1 do
	  let x = Scanf.bscanf sb "%d " (fun s -> s) in
	    a.(i) <- x;
	    b.(x) <- i;
	done;
      in
      let c0 = ref 0 in
      let c1 = ref 0 in
      let c2 = ref 0 in
      let c3 = ref 0 in
	for i = 0 to n - 1 do
	  if b.(i) = i
	  then incr c0;
	  if b.(i) = i + 1
	  then incr c1;
	  if b.(i) < i
	  then incr c2;
	  if b.(i) > i
	  then incr c3;
	done;
	Printf.eprintf "asd %d %d %d %d %d %d\n" ca !c0 !c1 !c2 !c3 (!c2 - !c3);
	if !c2 - !c3 >= 28
	then Printf.printf "Case #%d: BAD\n" ca
	else Printf.printf "Case #%d: GOOD\n" ca;
    done

