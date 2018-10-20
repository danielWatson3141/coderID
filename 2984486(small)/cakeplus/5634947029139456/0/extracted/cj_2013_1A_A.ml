(* Helper library: https://bitbucket.org/cakeplus/solution *)

open Batteries (* batteries.forge.ocamlcore.org *)


let print_result = function
  | Some n -> string_of_int n
  | None   -> "NOT POSSIBLE"


let rec gen_all l : string list =
  match l with
    | 0 -> [ "" ]
    | n ->
        let next = gen_all (l-1) in
        List.append
          (next |> List.map (fun s -> "0" ^ s))
          (next |> List.map (fun s -> "1" ^ s))


let apply_patt patt1 patt2 =
  Enum.combine (String.enum patt1, String.enum patt2)
  |> Enum.map (function
      | ('0', '1') -> '1'
      | ('0', '0') -> '0'
      | ('1', '0') -> '1'
      | ('1', '1') -> '0'
      | _ -> assert false)
  |> String.of_enum


let count_switches patt : int =
  patt |> String.enum
       |> Enum.map (function '1' -> 1 | '0' -> 0 | _ -> assert false)
       |> Enum.sum


Solution (n, l: int) (flow, req: list[n] of string) : string =
  let patterns = gen_all l in
  let req = List.sort compare req in

  let check_pattern patt =
    flow |> List.map (fun f -> apply_patt f patt)
         |> List.sort compare
         |> (=) req
  in

  match patterns |> List.filter check_pattern with
    | [] ->
        "NOT POSSIBLE"
    | xs ->
        xs |> List.map count_switches |> List.min |> string_of_int
