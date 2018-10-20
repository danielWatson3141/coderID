module S = Set.Make (struct type t = int let compare = compare end)

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
        let n = rdint () in
        let l = rdint () in
        let bit_to_dec x =
            let rec loop i acc =
                if i < 0 then acc else loop (i - 1) (if x.[i] = '0' then acc * 2 else acc * 2 + 1)
            in
            loop (l - 1) 0
        in
        let flow = Array.init n (fun _ -> bit_to_dec (read_word ())) in
        let dev = Array.init n (fun _ -> bit_to_dec (read_word ())) in
        let devset = Array.fold_left (fun set x -> S.add x set) S.empty dev in
        let bits x =
            let rec loop i acc =
                if i = 0 then acc else loop (i / 2) (acc + i land 1)
            in
            loop x 0
        in
        let rec loop i mini =
            if i < 0 then mini else
            let flowset = Array.fold_left (fun set x -> S.add (x lxor i) set) S.empty flow in
            if S.equal flowset devset then (
                let x = bits i in
                loop (i - 1) (min mini x)
            ) else loop (i - 1) mini
        in
        let k = loop ((1 lsl l) - 1) (l + 1) in
        if k <= l then Some k else None
        
    in
    let main () =
        let t = rdint () in
        for i = 1 to t do
            let a = match proc () with
            | None -> "NOT POSSIBLE"
            | Some x -> Printf.sprintf "%d" x
            in 
            Printf.printf "Case #%d: %s\n%!" i a
        done
    in
    main ()
