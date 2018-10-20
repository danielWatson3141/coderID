open System
open System.Collections.Generic
open System.Globalization
open System.IO
open System.Linq
open System.Threading

type Flip = Impossible | Unknown | Needed | NotNeeded

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
    input.ReadLine() |> ignore
    let outlets: bool[][] = readCurrents input
    let devices: bool[][] = readCurrents input
    let plugSize = outlets.[0].Length
    let flips =
        [|0 .. plugSize - 1|]
        |> Array.map (needsFlip(outlets, devices))

    let deviceSet = toSet devices
    let possibleFlips = generateFlips flips
    let matchingFlips = possibleFlips |> Seq.filter (matches deviceSet outlets)
    let min = matchingFlips |> Seq.map(fun (f: bool[]) -> f.Count(fun i -> i)) |> Seq.minOpt
    match min with
    | None ->
        fprintfn output "NOT POSSIBLE"
    | Some value ->
        fprintfn output "%d" value

and toSet currents =
    HashSet(Array.map toLong currents)

and matches devices outlets flip =
    let outletSet = outlets |> Array.map (barrayXor flip) |> toSet
    outletSet.IsSubsetOf(devices)

and toLong current =
    let mutable result = 0L
    for i = 0 to current.Length - 1 do
        result <- result + if current.[i] then 1L <<< i else 0L
    result

and generateFlips flips =
    generateFlipsRec flips 0
    |> Seq.map List.toArray

and generateFlipsRec flips minIndex : bool list seq =
    if minIndex = flips.Length then upcast [[]]
    else
        seq {
            for tail in generateFlipsRec flips (minIndex + 1) do
                match flips.[minIndex] with
                | Impossible -> ()
                | Needed -> yield true :: tail
                | NotNeeded -> yield false :: tail
                | Unknown ->
                    yield true :: tail
                    yield false :: tail
        }

and barrayXor = Array.map2 (<>)

and needsFlip(outlets: bool[][], devices: bool[][]) switch =
    let outletOnes = outlets.Count(fun outlet -> outlet.[switch])
    let deviceOnes = devices.Count(fun dev -> dev.[switch])
    let outletZeroes = outlets.Length - outletOnes
    if deviceOnes <> outletOnes && deviceOnes <> outletZeroes then
        Impossible
    elif outletOnes = outletZeroes then
        Unknown
    elif deviceOnes = outletOnes then NotNeeded else Needed

and readCurrents input =
    input.ReadLine().Split(' ') |> Array.map toBits

and toBits str =
    str |> Seq.map (fun c -> c = '1') |> Seq.toArray