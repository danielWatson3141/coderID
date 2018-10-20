(* Helper library: https://bitbucket.org/cakeplus/solution *)

open Batteries (* batteries.forge.ocamlcore.org *)


type tree = Tree of int * tree list


let not_adjacent node (a, b) =
  a <> node && b <> node


let find_adjacent edges node : int list =
  edges |> List.filter_map (fun (a, b) ->
    if a = node then
      Some b
    else
      if b = node then
        Some a
      else
        None)


let rec build_tree edges node : tree =
  let adj = find_adjacent edges node in
  let edges = edges |> List.filter (not_adjacent node) in
  Tree (node, adj |> List.map (build_tree edges))


let rec count_nodes (Tree (_, tree)) : int =
  1 + (tree |> List.map count_nodes |> List.fold_left (+) 0)


let rec solve_tree (Tree (_, tree)) : int =
  match tree with
    | [] -> 0
    | [ t1 ]  ->
        count_nodes t1
    | ts ->
        let (t1 :: t2 :: rest) =
          ts |> List.map (fun t -> (t, solve_tree t))
             |> List.sort (fun (t1, s1) (t2, s2) -> compare s1 s2)
        in
        snd t1 + snd t2 + (rest |> List.map fst
                                |> List.map count_nodes
                                |> List.fold_left (+) 0)


Solution (n: int) (edges: list[n-1] of tuple(int, int)) : int =
  (1--n) |> Enum.map (build_tree edges)
         |> Enum.map solve_tree
         |> Enum.reduce min
