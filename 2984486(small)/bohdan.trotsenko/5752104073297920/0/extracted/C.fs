// run as a script
open System
open System.IO
open System.Text
//open System.Numerics

let inpFile = ref @"c:\CJ\2014_1A\C\C.in" 
let outFile = ref @"C.out"

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

let N = NXi()

let inp = [|for i in 1..N do 
                              let _ = NXi()
                              yield NXarr()
          |]

let rnd = new Random()
let genOk l = 
    let arr = Array.init l (fun el -> el + 1)
    for i in 0..l-1 do
        let q = rnd.Next(i, l)
        let t = arr.[i]
        arr.[i] <- arr.[q]
        arr.[q] <- t
    arr

let genFuu l = 
    let arr = Array.init l (fun el -> el + 1)
    for i in 0..l-1 do
        let q = rnd.Next(0, l)
        let t = arr.[i]
        arr.[i] <- arr.[q]
        arr.[q] <- t
    arr

let getBar (p : int array) =
    let l = p.Length
    let threshold = l * (l - 1) / 4
    let _, barrie = p |> Seq.scan (fun (acc, idx) el -> (acc + el, idx + 1)) (0, -1)
                      |> Seq.skipWhile (fun (acc, _) -> acc < threshold)
                      |> Seq.head
    barrie

(*
seq {
    for _ in 0..1000 do
        yield genFuu 1000 |> getBar |> float
} |> Seq.average

*)

let solve (p : int array) =
    //(MyM p).ToString()
    if getBar p >= 518 then
        "BAD"
    else
        "GOOD"

let out = inp |> Array.Parallel.map solve
//let out = inp |> Array.map solve

//let r = Console.Out
let r = new StreamWriter(!outFile)

for i in 1..N do
    printfn "Case #%d: %s" i out.[i - 1]
    fprintfn r "Case #%d: %s" i out.[i - 1]

r.Dispose()
