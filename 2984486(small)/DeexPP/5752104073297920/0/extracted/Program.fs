module C

open System

module R =
    let readLine()  = Console.In.ReadLine()

//module R1 =
//    let inputStream = System.IO.File.OpenText(@"C:\proj\2013\codejam2014\C\C.txt")
//    let readLine()  = inputStream.ReadLine()

open R

module Read =
    let private read fx = readLine() |> fx
    let int()           = read int
    let decimal()       = read decimal
    let int64()         = read int64
    let double()        = read double
    let bigint()        = read (fun e -> bigint.Parse(e))

module ReadXs =
    let private read fx = readLine().Split(' ') |> Array.map fx
    let int()           = read int
    let decimal()       = read decimal
    let int64()         = read int64
    let double()        = read double
    let bigint()        = read (fun e -> bigint.Parse(e))
    let string()        = read string

let doned() =
    if System.Diagnostics.Debugger.IsAttached then
         System.Console.ReadKey() |> ignore


let solve i = 
    
    let N = Read.int()
    let arr = ReadXs.int()
    let mutable isBad = 
        //(Array.mapi (fun i e -> if i = e then 1 else 0) arr |> Seq.sum > 5)
        //|| Array.mapi (fun i e -> if e % 2 = i % 2 then 1 else 0) arr |> Seq.sum > 500
        (Seq.pairwise arr |> Seq.map (fun (a, b) -> if a > b then 1 else -1) |> Seq.sum |> abs > 10
        )

        
    if isBad then 
        printfn "BAD"
    else 
        printfn "GOOD"


[<EntryPoint>]
let main argv = 
    
    let T = Read.int()
    for T = 1 to T do
        printf "Case #%i: " T
        solve T

    doned()
    0 
