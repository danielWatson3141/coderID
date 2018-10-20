// run as a script
open System
open System.IO
open System.Text
open System.Numerics

let inpFile = ref @"C:\CJ\2014_1A\A\A.in"
let outFile = ref @"C:\CJ\2014_1A\A\A.out"

let args = Environment.GetCommandLineArgs()
if Path.GetFileName(args.[0].ToLowerInvariant()) <> "fsi.exe" then
    if args.Length > 1 then
        inpFile := args.[1]

let iLines = File.ReadAllLines(!inpFile)
let idx = ref 0
idx := 0

let NX() =
    let res = iLines.[!idx]
    idx := !idx + 1
    res
let NXi() = int (NX())
let NXarr() = (NX()).Split([|' '|], StringSplitOptions.RemoveEmptyEntries) |> Array.map int
let NXarrB() = (NX()).Split([|' '|], StringSplitOptions.RemoveEmptyEntries) |> Array.map (fun s -> Convert.ToInt32(s, 2))

let N = NXi()

let inp = [|for i in 1..N do 
                              let [|n; l|] = NXarr()
                              let have = NXarrB()
                              let want = NXarrB() |> Array.sort
                              yield (n, l, have, want)
          |]

let rec bits n =
    if n = 0 then 0
    else
        (n &&& 1) + bits (n >>> 1)


//let (n, l, have, want) = inp.[2]

let solve (n, l, have, want) =
    let cap = (1<<<l) - 1
    try
        let solution = seq {
                            for mask in 0..cap do
                                let res = have |> Array.map (fun el -> el ^^^ mask) |> Array.sort
                                if Seq.forall2 (fun a b -> a = b) res want then
                                    yield mask
                        } |> Seq.map bits |> Seq.min
        solution.ToString()
    with
    | _ -> "NOT POSSIBLE"

let out = inp |> Array.Parallel.map solve
//let out = inp |> Array.map solve

//let r = Console.Out
let r = new StreamWriter(!outFile)

for i in 1..N do
    printfn "Case #%d: %s" i out.[i - 1]
    fprintfn r "Case #%d: %s" i out.[i - 1]

r.Dispose()
