module A

open System

module R =
    let readLine()  = Console.In.ReadLine()

//module R1 =
//    let inputStream = System.IO.File.OpenText(@"C:\proj\2013\codejam2014\A\A.txt")
//    let readLine()  = inputStream.ReadLine()

open R

module Read =
    let private read fx = readLine() |> fx
    let int()           = read int
    let decimal()       = read decimal
    let int64()         = read int64
    let double()        = read double
    let bigint()        = read (fun e -> bigint.Parse(e))
    let string()        = read string

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
    
    let [|N;L|] = ReadXs.int()
    let mutable sw = Read.string().Split(' ') |> Array.map (fun s -> Convert.ToInt64(s, 2)) |> Array.sort
    let mutable dev = Read.string().Split(' ') |> Array.map (fun s -> Convert.ToInt64(s, 2)) |> Array.sort
    let mutable cnt = 0


    //if sw = dev then printfn "%i" 0
    //else
    let dec (x : int64) = System.Convert.ToString(x, 2)
    let bin (x : int64) = System.Convert.ToString(x, 2)

    try
        for i = 0 to N - 1 do
            let dx = sw.[i] ^^^ dev.[0]
            //printfn "++\r\n %A\r\n%A\r\n%A\r\n" (bin dx) (bin sw.[i]) (bin dev.[0])
            let y = Array.map (fun e -> e ^^^ dx) sw |> Array.sort
            //printfn "-- %A\r\n%A\r\n%A\r\n" (Array.map bin dev) (Array.map bin sw) (Array.map bin y)
            if y = dev then
                let bits = bin dx
                printfn "%A" (bits |> Seq.filter ((=)'1') |> Seq.length)
                failwith ""

        printfn "NOT POSSIBLE"

    with _ -> ()
    
    



[<EntryPoint>]
let main argv = 
    
    let T = Read.int()
    for T = 1 to T do
        printf "Case #%i: " T
        solve T

    doned()
    0 
