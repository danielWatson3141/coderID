module S = Set.Make (struct type t = int let compare = compare end)
module M = Map.Make (struct type t = int let compare = compare end)

let _ =
    let read_word =
        let l = ref 0 in
        let i = ref 0 in
        let s = String.create 65536 in
        let refill () =
            let n = input stdin s 0 65536 in
            i := 0;
            l := n in
        refill ();

        fun () ->
            let rec loop2 j k buf =
                let fin j buf =
                    let _ = i := j in
                    Buffer.contents buf in

                if j = k then (
                    let _ = refill () in
                    if !l > 0 then loop2 !i !l buf else fin j buf
                ) else if s.[j] > ' ' then
                    let _ = Buffer.add_char buf s.[j] in
                    loop2 (j + 1) k buf
                else fin j buf in

            let rec loop1 j k =
                if j = k then (
                    let _ = refill () in
                    if !l > 0 then loop1 !i !l else ""
                ) else if s.[j] <= ' ' then loop1 (j + 1) k else
                    let buf = Buffer.create 16 in
                    let _ = Buffer.add_char buf s.[j] in
                    loop2 (j + 1) k buf in
            loop1 !i !l
    in

    let rdint () = int_of_string (read_word ()) in

    let proc () =
        let n = rdint() in
        let rec loop i map =
            if i < 0 then map else
                let a = rdint () in
                let b = rdint () in
                let map = M.add a (S.add b (try M.find a map with _ -> S.empty)) map in
                let map = M.add b (S.add a (try M.find b map with _ -> S.empty)) map in
                loop (i - 1) map
        in
        let tree = loop (n - 2) M.empty in
        let bits x =
            let rec loop i acc =
                if i = 0 then acc else loop (i / 2) (acc + i land 1)
            in
            loop x 0
        in
        let trim tree r =
            let remove i tree =
                let s = M.find i tree in
                let tree = M.remove i tree in
                S.fold (fun x tree ->
                    let s2 = M.find x tree in
                    let s3 = S.remove i s2 in
                    M.add x s3 tree) s tree
            in
            let rec loop r i tree =
                if r = 0 then tree else
                if r land 1 = 0 then loop (r / 2) (i + 1) tree else
                loop (r / 2) (i + 1) (remove i tree)
            in
            loop r 1 tree
        in
        let dump tree =
            M.iter (fun x set ->
                Printf.printf "%2d\n" x;
                S.iter (fun v -> Printf.printf "    %2d\n" v) set;
                print_newline ()) tree
        in
        let rec form2 parent x tree =
            let set = M.find x tree in
            if not (S.mem parent set) then (Printf.printf "parent??\n"; false) else
            let set = S.remove parent set in
            if S.cardinal set = 0 then true else
            if S.cardinal set = 2 then (
                S.fold (fun y acc ->
                    if acc then form2 x y tree else acc) set true
            ) else false
        in
        let formed tree =
            let flag = M.fold (fun key set acc -> if acc then not (S.is_empty set) else acc) tree true in
            if flag then (
                let keys = M.fold (fun key set acc ->
                    if S.cardinal set = 2 then key :: acc else acc) tree [] in
                match keys with
                | [ parent ] -> (
                    let s = M.find parent tree in
                    S.fold (fun x acc -> 
                        if acc then form2 parent x tree else acc) s true
                )
                | _ -> false
            ) else false
        in
        let rec loop i mini =
            if i < 0 then mini else
                let x = bits i in
                if x >= mini then loop (i - 1) mini else
                    let tree2 = trim tree i in
                    if formed tree2 then loop (i - 1) x else loop (i - 1) mini
        in
        loop ((1 lsl n) - 1) (n - 1)
    in
    let main () =
        let t = rdint () in
        for i = 1 to t do
            Printf.printf "Case #%d: %d\n%!" i (proc ())
        done
    in
    main ()
