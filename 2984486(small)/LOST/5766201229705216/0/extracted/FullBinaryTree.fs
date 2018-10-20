open System
open System.Collections.Generic
open System.Globalization
open System.IO
open System.Threading

open Option.Operators

[<EntryPoint>]
let rec main argv = 
    Thread.CurrentThread.CurrentCulture <- CultureInfo.InvariantCulture
    Thread.CurrentThread.CurrentUICulture <- CultureInfo.InvariantCulture

    use input = new StreamReader(argv.[0])
    use output = new StreamWriter(argv.[1])

    let caseCount = Int32.Parse(input.ReadLine())
    for caseN = 1 to caseCount do
        fprintf output "Case #%d: " caseN 
        solveCase input output

    input.Close()
    output.Close()

    0

and solveCase input output =
    let nodeCount = input.ReadLine() |> Int32.Parse
    let edges = Array.init nodeCount (fun _ -> List())
    for e = 1 to nodeCount - 1 do
        let [| e1; e2 |] = input.ReadLine().Split(' ') |> Array.map Int32.Parse
        edges.[e1 - 1].Add(e2 - 1)
        edges.[e2 - 1].Add(e1 - 1)

    [0 .. nodeCount - 1]
    |> List.map(fun root -> maxSubtree(edges, root, None))
    |> List.max
    |> (fun treeSize -> fprintfn output "%d" (nodeCount - treeSize))

and maxSubtree(edges, root, parent) =
    let subtreeSizes =
        edges.[root]
        |> Seq.filter(fun child -> child =? parent <> Some(true))
        |> Seq.map(fun child -> maxSubtree(edges, child, Some root))
        |> Seq.toArray

    if subtreeSizes.Length < 2 then 1
    else
        let t1, t2 = top2 subtreeSizes
        1 + t1 + t2


and top2 array =
    let mutable t1 = 0
    let mutable t2 = 0
    for a in array do
        if a > t1 then
            t2 <- t1
            t1 <- a
        elif a > t2 then
            t2 <- a
    t1, t2



