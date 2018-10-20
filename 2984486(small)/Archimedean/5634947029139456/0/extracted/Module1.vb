Imports System.IO
Imports System.Math
Module Module1



    Sub R1A(ByVal InFile As String, ByVal OutFile As String)

        Dim inf As StreamReader = File.OpenText(InFile)
        Dim outf As StreamWriter = File.CreateText(OutFile)

        

        Dim numC As Integer = CInt(inf.ReadLine)

        Dim bLine As String

        Dim C As Integer

        Dim I As Integer, J As Integer

        Dim B(3, 3) As Integer

        Dim gStatus As String

        Dim sqFilled As Integer

        For C = 1 To numC

            sqFilled = 0
            For I = 0 To 3
                bLine = inf.ReadLine
                For J = 0 To 3
                    Select bLine.Substring(J, 1)
                        Case "X"
                            B(I, J) = 1
                            sqFilled += 1
                        Case "O"
                            B(I, J) = -1
                            sqFilled += 1
                        Case "T"
                            B(I, J) = 0
                            sqFilled += 1
                        Case Else
                            B(I, J) = 1000
                    End Select
                Next J
            Next I

            ' Handle Space

            bLine = inf.ReadLine

            ' Test Rows

            gStatus = ""

            For I = 0 To 3
                Select Case B(I, 0) + B(I, 1) + B(I, 2) + B(I, 3)
                    Case 3, 4
                        gStatus = "X won"
                    Case -3, -4
                        gStatus = "O won"
                End Select
                Select Case B(0, I) + B(1, I) + B(2, I) + B(3, I)
                    Case 3, 4
                        gStatus = "X won"
                    Case -3, -4
                        gStatus = "O won"
                End Select
            Next

            Select Case B(0, 0) + B(1, 1) + B(2, 2) + B(3, 3)
                Case 3, 4
                    gStatus = "X won"
                Case -3, -4
                    gStatus = "O won"
            End Select

            Select Case B(0, 3) + B(1, 2) + B(2, 1) + B(3, 0)
                Case 3, 4
                    gStatus = "X won"
                Case -3, -4
                    gStatus = "O won"
            End Select

            If gStatus = "" Then
                If sqFilled = 16 Then
                    gStatus = "Draw"
                Else
                    gStatus = "Game has not completed"
                End If
            End If

            outf.WriteLine("Case #" & CStr(C) & ": " & gStatus)




        Next C


        inf.Close()
        outf.Close()


    End Sub
    Sub R1B(ByVal InFile As String, ByVal OutFile As String)

        Dim inf As StreamReader = File.OpenText(InFile)
        Dim outf As StreamWriter = File.CreateText(OutFile)

        Dim numC As Integer = CInt(inf.ReadLine)

        Dim C As Integer

        Dim I As Integer, J As Integer, K As Integer
        Dim M As Integer, N As Integer

        Dim B(,) As Integer

        Dim gStatus As String


        Dim SplStr() As String

        Dim rowtest As Boolean
        Dim coltest As Boolean

        For C = 1 To numC

            SplStr = inf.ReadLine.Split(" ")

            N = CInt(SplStr(0))
            M = CInt(SplStr(1))

            ReDim B(N - 1, M - 1)

            For I = 0 To N - 1

                SplStr = inf.ReadLine.Split(" ")
                For J = 0 To M - 1
                    B(I, J) = CInt(SplStr(J))
                Next J
            Next I

            gStatus = "YES"

            For I = 0 To N - 1
                For J = 0 To M - 1



                    rowtest = True
                    coltest = True

                    ' test row

                    For K = 0 To M - 1
                        If B(I, K) > B(I, J) Then
                            rowtest = False
                        End If
                    Next K

                    ' test column

                    For K = 0 To N - 1
                        If B(K, J) > B(I, J) Then
                            coltest = False
                        End If
                    Next K

                    If Not (rowtest Or coltest) Then
                        gStatus = "NO"
                    End If



                Next J
            Next I

            outf.WriteLine("Case #" & CStr(C) & ": " & gStatus)
        Next C


        inf.Close()
        outf.Close()

    End Sub
    Sub R1C(ByVal InFile As String, ByVal OutFile As String)

        Dim inf As StreamReader = File.OpenText(InFile)
        Dim outf As StreamWriter = File.CreateText(OutFile)

        Dim numC As Integer = CInt(inf.ReadLine)
        Dim gCount As Integer
        Dim C As Integer
        Dim A As Long, B As Long

        Dim FaS As Long() = {1, 2, 3, 11, 22, 101, 111, 121, 202, 212, 1001, 1111, 2002, 10001, 10101, 10201, 11011, 11111, 11211, 20002, 20102, 100001, 101101, 110011, 111111, 200002}
        Dim T As Long
        Dim SplStr() As String

        For C = 1 To numC

            gCount = 0
            SplStr = inf.ReadLine.Split(" ")
            A = CLng(SplStr(0))
            B = CLng(SplStr(1))

            For Each T In FaS
                If T ^ 2 >= A And T ^ 2 <= B Then
                    gCount += 1
                End If
            Next



            outf.WriteLine("Case #" & CStr(C) & ": " & CStr(gCount))
        Next C


        inf.Close()
        outf.Close()

    End Sub
    Sub R1D(ByVal InFile As String, ByVal OutFile As String)

        Dim inf As StreamReader = File.OpenText(InFile)
        Dim outf As StreamWriter = File.CreateText(OutFile)

        Dim numC As Integer = CInt(inf.ReadLine)
        Dim gStatus As String = ""

        Dim C As Integer

        Dim I As Integer, J As Integer, L As Integer
        'Dim M As Integer, N As Integer
        Dim SplStr() As String
        Dim KeyCount() As Integer
        Dim KeysToVisit() As Integer
        Dim Visited() As Integer
        Dim KeyUnlock() As Integer
        Dim N As Integer, K As Integer
        Dim D(,) As Integer

        For C = 1 To numC

            gStatus = ""
            SplStr = inf.ReadLine.Split(" ")
            ReDim KeyCount(200)

            K = CInt(SplStr(0))
            N = CInt(SplStr(1))

            SplStr = inf.ReadLine.Split(" ")
            For I = 0 To K - 1
                KeyCount(CInt(splstr(I))) += 1
            Next I
            ReDim Visited(N)
            ReDim KeyUnlock(N)
            ReDim KeysToVisit(200)
            ReDim D(N, 200)

            For I = 1 To N
                SplStr = inf.ReadLine.Split(" ")
                KeyUnlock(I) = CInt(SplStr(0))
                KeysToVisit(KeyUnlock(I)) += 1
                For J = 1 To CInt(SplStr(1))
                    D(I, CInt(SplStr(1 + J))) = 1
                Next J
            Next I

            If C = 3 Then
                C = 3
            End If

            For I = 1 To N
                ' Find earliest non-stopper

                For J = 1 To N
                    If Visited(J) = 0 Then

                        If KeyCount(KeyUnlock(J)) > 1 Or (KeyCount(KeyUnlock(J)) = 1 And (D(J, KeyUnlock(J)) = 1 Or KeysToVisit(KeyUnlock(J)) = 1)) Then
                            Visited(J) = I
                            KeyCount(KeyUnlock(J)) -= 1
                            KeysToVisit(KeyUnlock(J)) -= 1
                            For L = 1 To 200
                                KeyCount(L) += D(J, L)
                            Next L
                            Exit For
                        End If

                    End If
                Next J

            Next I

           

            For I = 1 To N
                If Visited(I) = 0 Then
                    gStatus = " IMPOSSIBLE"
                    Exit For
                End If
                For J = 1 To N
                    If Visited(J) = I Then
                        gStatus = gStatus & " " & CStr(J)
                    End If

                Next J
            Next I


            outf.WriteLine("Case #" & CStr(C) & ":" & gStatus)
        Next C


        inf.Close()
        outf.Close()

    End Sub


    Function IsPalin(ByVal tstr As String) As Boolean

        IsPalin = True

        For I = 0 To tstr.Length - 1
            If tstr.Substring(I, 1) <> tstr.Substring(tstr.Length - 1 - I, 1) Then
                IsPalin = False
            End If
        Next

    End Function

    Sub R2A(ByVal InFile As String, ByVal OutFile As String)

        Dim I As Integer

        Dim inf As StreamReader = File.OpenText(InFile)
        Dim outf As StreamWriter = File.CreateText(OutFile)

        Dim numC As Integer = CInt(inf.ReadLine)
        Dim gStatus As String = ""

        Dim C As Integer
        Dim ans As Integer

        Dim A As Integer
        Dim N As Integer
        Dim Motes() As Integer
        Dim splstr() As String
        Dim dp_m() As Long
        Dim dp_c() As Long

        For C = 1 To numC

            splstr = inf.ReadLine.Split(" ")
            A = CLng(splstr(0))
            N = CLng(splstr(1))
            ReDim Motes(N)
            splstr = inf.ReadLine.Split(" ")
            For I = 0 To N - 1
                Motes(I + 1) = CInt(splstr(I))
            Next
            Array.Sort(Motes)

            ReDim dp_m(N)
            ReDim dp_c(N)

            dp_m(0) = A
            dp_c(0) = 0

            Dim tc As Integer
            Dim tm As Integer

            Debug.WriteLine(dp_m(0) & " " & dp_c(0))

            If dp_m(0) = 1 Then
                Debug.WriteLine("Case #" & CStr(C) & ": " & N)
                outf.WriteLine("Case #" & CStr(C) & ": " & N)
            Else

                For I = 1 To N

                    ' calculate cost to get over hump

                    tc = 0
                    tm = dp_m(I - 1)
                    Do Until tm > Motes(I)
                        tc += 1
                        tm += (tm - 1)
                    Loop

                    dp_m(I) = tm + Motes(I)
                    dp_c(I) = dp_c(I - 1) + tc

                    Debug.WriteLine(dp_m(I) & " " & dp_c(I))

                Next I

                ans = N

                For I = 1 To N
                    ans = Min(ans, dp_c(I) + (N - I))
                Next I

                Debug.WriteLine("Case #" & CStr(C) & ": " & Int(ans))
                outf.WriteLine("Case #" & CStr(C) & ": " & Int(ans))

            End If

        Next C


        inf.Close()
        outf.Close()

    End Sub
    Sub R2B(ByVal InFile As String, ByVal OutFile As String)

        Dim inf As StreamReader = File.OpenText(InFile)
        Dim outf As StreamWriter = File.CreateText(OutFile)

        Dim numC As Integer = CInt(inf.ReadLine)
        Dim gStatus As String = ""

        Dim C As Integer
        Dim ans As Double
        Dim splstr() As String
        Dim N As Integer
        Dim X As Integer
        Dim Y As Integer
        Dim BOT As Integer
        Dim DTF As Integer

        For C = 1 To numC

            splstr = inf.ReadLine.Split(" ")
            N = CInt(splstr(0))
            X = CInt(splstr(1))
            Y = CInt(splstr(2))



            BOT = Int((-3 + Sqrt(9 + 8 * (N - 1))) / 4)

            If Abs(X) + Y <= 2 * BOT Then
                Debug.WriteLine("N=" & N & " X=" & X & " Y=" & Y & " BOT=" & BOT)
                ans = 1
            ElseIf Abs(X) + Y > 2 * (BOT + 1) Or (X = 0 And Y = 2 * (BOT + 1)) Then
                Debug.WriteLine("N=" & N & " X=" & X & " Y=" & Y & " BOT=" & BOT)
                ans = 0
            Else

                ans = 0

                DTF = N - (2 * BOT + 1) * (BOT + 1) ' should be between 1 and 4 *(BOT + 1)

                Debug.WriteLine("N=" & N & " X=" & X & " Y=" & Y & " BOT=" & BOT & " DTF=" & DTF)

                For I = 0 To DTF

                    If Max(0, (DTF - 2 * (BOT + 1) - I)) + I >= (Y + 1) Then

                        ans += comb(DTF, I) / (2 ^ DTF)
                        Debug.WriteLine(I & " " & comb(DTF, I))
                    End If

                Next I

                Debug.WriteLine("Case #" & CStr(C) & ": " & CStr(ans * 2 ^ DTF))

            End If

            Debug.WriteLine("Case #" & CStr(C) & ": " & CStr(ans))
            outf.WriteLine("Case #" & CStr(C) & ": " & CStr(ans))

        Next C


        inf.Close()
        outf.Close()

    End Sub
    Sub R1A_2014(ByVal InFile As String, ByVal OutFile As String)

        Dim inf As StreamReader = File.OpenText(InFile)
        Dim outf As StreamWriter = File.CreateText(OutFile)

        Dim numC As Integer = CInt(inf.ReadLine)
        Dim gStatus As String = ""

        Dim C As Integer
        Dim ctr() As Integer
        Dim r1 As Integer
        Dim r2 As Integer
        Dim ts As String
        Dim ss() As String
        Dim n2 As Integer
        Dim i As Integer, j As Integer
        Dim t As Integer

        For C = 1 To numC

            ReDim ctr(16)
            r1 = CInt(inf.ReadLine)
            For i = 1 To 4

                ts = Trim(inf.ReadLine)
                If i = r1 Then
                    ss = ts.Split(" ")
                    For j = 0 To 3
                        ctr(CInt(ss(j))) += 1
                    Next j

                End If

            Next i
            r2 = CInt(inf.ReadLine)
            For i = 1 To 4

                ts = Trim(inf.ReadLine)
                If i = r2 Then
                    ss = ts.Split(" ")
                    For j = 0 To 3
                        ctr(CInt(ss(j))) += 1
                    Next j
                End If

            Next i

            n2 = 0
            t = 0
            For i = 1 To 16
                If ctr(i) = 2 Then
                    n2 += 1
                    t = i
                End If
            Next i

            Select Case n2
                Case 1
                    outf.WriteLine("Case #" & CStr(C) & ": " & t)
                Case 0
                    outf.WriteLine("Case #" & CStr(C) & ": Volunteer cheated!")
                Case Else
                    outf.WriteLine("Case #" & CStr(C) & ": Bad magician!")
            End Select

        Next C

        inf.Close()
        outf.Close()

    End Sub
    Sub R1B_2014(ByVal InFile As String, ByVal OutFile As String)

        Dim inf As StreamReader = File.OpenText(InFile)
        Dim outf As StreamWriter = File.CreateText(OutFile)

        Dim numC As Integer = CInt(inf.ReadLine)
        Dim nc As Integer

        Dim C As Double, F As Double, X As Double

        Dim lasttot As Double
        Dim nf As Double
        Dim tf As Double
        Dim xf As Double
        Dim ss() As String

        For nc = 1 To numC

            ss = inf.ReadLine.Split(" ")
            C = CDbl(ss(0))
            F = CDbl(ss(1))
            X = CDbl(ss(2))

            nf = 0
            tf = 0
            lasttot = X / 2

            Do
                nf = nf + 1
                tf += C / (2 + (nf - 1) * F)
                xf = X / (2 + nf * F)
                If lasttot > tf + xf Then
                    lasttot = tf + xf
                End If
            Loop Until lasttot < tf + xf

            outf.WriteLine("Case #" & CStr(nc) & ": " & CStr(lasttot))

        Next nc

        inf.Close()
        outf.Close()

    End Sub
    Function ArrToSwp(ByRef outf As StreamWriter, r As Integer, c As Integer, ByRef fill() As Integer, rflag As Boolean) As Integer

        Dim nf As Integer = fill.GetUpperBound(0)
        Dim lstr As String


        Dim ri As Integer, ci As Integer

        If rflag Then

            For ri = 1 To r

                lstr = ""
                For ci = 1 To c

                    If ri = 1 And ci = 1 Then
                        lstr = "c"
                    ElseIf ri <= nf AndAlso ci <= fill(ri) Then
                        lstr &= "."
                    Else
                        lstr &= "*"
                    End If




                Next ci

                outf.WriteLine(lstr)

            Next ri

        Else

            For ri = 1 To r

                lstr = ""
                For ci = 1 To c

                    If ri = 1 And ci = 1 Then
                        lstr = "c"
                    ElseIf ci <= nf AndAlso ri <= fill(ci) Then
                        lstr &= "."
                    Else
                        lstr &= "*"
                    End If




                Next ci

                outf.WriteLine(lstr)

            Next ri




        End If

        Return 0

    End Function

    Sub R1C_2014(ByVal InFile As String, ByVal OutFile As String)

        Dim inf As StreamReader = File.OpenText(InFile)
        Dim outf As StreamWriter = File.CreateText(OutFile)

        Dim numC As Integer = CInt(inf.ReadLine)
        Dim nc As Integer
        Dim r As Integer, c As Integer, m As Integer
        Dim os As Integer = r * c - m
        Dim ss() As String
        Dim nf() As Integer
        Dim a2s As Integer
        Dim i As Integer, j As Integer, n As Integer, k As Integer
        Dim flag As Boolean

        For nc = 1 To numC

            outf.WriteLine("Case #" & CStr(nc) & ":")


            ss = inf.ReadLine.Split(" ")
            r = CInt(ss(0))
            c = CInt(ss(1))
            m = CInt(ss(2))

            os = r * c - m

            ' take care of 1-row, 1-col cases and 1 os cases

            flag = True

            If r = 1 Or os = 1 Then

                ReDim nf(1)
                nf(1) = os
                a2s = ArrToSwp(outf, r, c, nf, True)
                flag = False

            ElseIf c = 1 Then
                ReDim nf(1)
                nf(1) = os
                a2s = ArrToSwp(outf, r, c, nf, False)
                flag = False

            ElseIf r = 2 Then

                If os Mod 2 = 1 Then
                    outf.WriteLine("Impossible")
                    flag = False
                ElseIf os / 2 >= 2 Then
                    ReDim nf(2)
                    nf(1) = os / 2
                    nf(2) = os / 2
                    a2s = ArrToSwp(outf, r, c, nf, True)
                    flag = False
                End If


            ElseIf c = 2 Then

                If os Mod 2 = 1 Then
                    outf.WriteLine("Impossible")
                    flag = False
                ElseIf os / 2 >= 2 Then
                    ReDim nf(2)
                    nf(1) = os / 2
                    nf(2) = os / 2
                    a2s = ArrToSwp(outf, r, c, nf, False)
                    flag = False
                End If


            Else ' r, c >= 3

                ' test if 2 x n or n x 2 case works, then go up to 3

                n = os \ 2
                k = os Mod 2


                If n <= c And n >= 2 And k = 0 Then ' 2 x n block 

                    ReDim nf(2)
                    nf(1) = os / 2
                    nf(2) = os / 2
                    a2s = ArrToSwp(outf, r, c, nf, True)
                    flag = False
                ElseIf n <= r And n >= 2 And k = 0 Then ' n x 2 block

                    ReDim nf(2)
                    nf(1) = os / 2
                    nf(2) = os / 2
                    a2s = ArrToSwp(outf, r, c, nf, False)
                    flag = False
                Else

                    For j = 3 To c

                        n = os \ j
                        k = os Mod j

                        If k = 0 And n <= r And n >= 2 Then ' n rows of j
                            ReDim nf(n)
                            For i = 1 To n
                                nf(i) = j
                            Next
                            a2s = ArrToSwp(outf, r, c, nf, True)
                            j = c + 1
                            flag = False
                        ElseIf k = 1 And n >= 3 And n < r Then ' n - 1 rows of j, 1 row of j - 1, 1 row of 2

                            ReDim nf(n + 1)
                            For i = 1 To n - 1
                                nf(i) = j
                            Next
                            nf(n) = j - 1
                            nf(n + 1) = 2
                            a2s = ArrToSwp(outf, r, c, nf, True)
                            j = c + 1
                            flag = False
                        ElseIf n < r And k > 1 And n >= 2 Then ' n rows of j, 1 row of k

                            ReDim nf(n + 1)
                            For i = 1 To n
                                nf(i) = j
                            Next
                            nf(n + 1) = k
                            a2s = ArrToSwp(outf, r, c, nf, True)
                            j = c + 1
                            flag = False
                        End If



                    Next j

                    If flag Then

                        For j = 3 To r

                            n = os \ j
                            k = os Mod j

                            If k = 0 And n <= c And n >= 2 Then ' n columns of j
                                ReDim nf(n)
                                For i = 1 To n
                                    nf(i) = j
                                Next
                                a2s = ArrToSwp(outf, r, c, nf, False)
                                j = r + 1
                                flag = False
                            ElseIf k = 1 And n >= 3 And n < c Then ' n - 1 columns of j, 1 column of j - 1, 1 column of 2

                                ReDim nf(n + 1)
                                For i = 1 To n - 1
                                    nf(i) = j
                                Next
                                nf(n) = j - 1
                                nf(n + 1) = 2
                                a2s = ArrToSwp(outf, r, c, nf, False)
                                j = r + 1
                                flag = False
                            ElseIf n < c And k > 1 And n >= 2 Then ' n columns of j, 1 column of k

                                ReDim nf(n + 1)
                                For i = 1 To n
                                    nf(i) = j
                                Next
                                nf(n + 1) = k
                                a2s = ArrToSwp(outf, r, c, nf, False)
                                j = r + 1
                                flag = False
                            End If


                        Next j

                    End If

                End If

            End If

            If flag Then
                outf.WriteLine("Impossible")
            End If


        Next nc

        inf.Close()
        outf.Close()

    End Sub
    Sub R1D_2014(ByVal InFile As String, ByVal OutFile As String)

        Dim inf As StreamReader = File.OpenText(InFile)
        Dim outf As StreamWriter = File.CreateText(OutFile)

        Dim numC As Integer = CInt(inf.ReadLine)
        Dim nc As Integer
        Dim numb As Integer
        Dim dpts As Integer
        Dim wpts As Integer
        Dim flag As Boolean

        Dim kb() As Double
        Dim nb() As Double
        Dim ku() As Integer
        Dim nu() As Integer
        Dim ss() As String
        Dim i As Integer, j As Integer

        For nc = 1 To numC

            numb = CInt(inf.ReadLine)

            ReDim kb(numb - 1)
            ReDim nb(numb - 1)

            ss = inf.ReadLine.Split(" ")

            For i = 0 To numb - 1

                nb(i) = CDbl(ss(i))

            Next i

            ss = inf.ReadLine.Split(" ")

            For i = 0 To numb - 1

                kb(i) = CDbl(ss(i))

            Next i

            Array.Sort(nb)
            Array.Sort(kb)

            

            ' calculate wpts

            wpts = 0

            ReDim ku(numb - 1)
            ReDim nu(numb - 1)

            'Ken Strategy - Play smallest that can beat Naomi, otherwise smallest
            'Naomi War Strategy - Play smallest to largest, doesn’t matter

            For i = 0 To numb - 1
                flag = True
                For j = 0 To numb - 1
                    If kb(j) > nb(i) And ku(j) = 0 Then
                        ku(j) = 1
                        flag = False
                        j = numb
                    End If
                Next j

                If flag Then
                    wpts += 1 ' naomi wins
                    For j = 0 To numb - 1 ' ken throws smallest
                        If ku(j) = 0 Then
                            ku(j) = 1
                            j = numb
                        End If
                    Next j
                End If


            Next i


            ' calculate dpts


            'Naomi Deceit Strategy - Play smallest, announce Ken largest - epsilon, ken plays largest, until Naomi block vector strictly larger than Ken's
            'at that point, Naomi wins all remaining: Naomi plays smallest, announces Ken largest + epsilon, ken plays smallest

            ' index on leftmost point of naomi block vector: is naomi(i to numb - 1) > ken(0 to numb - 1 - i) 

            dpts = 0

            For i = 0 To numb - 1

                flag = True

                For j = i To numb - 1
                    If nb(j) < kb(j - i) Then
                        flag = False
                    End If

                Next j

                If flag Then
                    dpts = numb - i
                    i = numb
                End If


            Next i


            outf.WriteLine("Case #" & CStr(nc) & ": " & CStr(dpts) & " " & CStr(wpts))

        Next nc

        inf.Close()
        outf.Close()

    End Sub
    Function digsum(ByVal x As Integer) As Integer

        If x = 0 Or x = 1 Then
            digsum = x
        Else
            digsum = (x And 1) + digsum(x >> 1)
        End If

    End Function

    Sub R2Asm_2014(ByVal InFile As String, ByVal OutFile As String)

        Dim inf As StreamReader = File.OpenText(InFile)
        Dim outf As StreamWriter = File.CreateText(OutFile)

        Dim numC As Integer = CInt(inf.ReadLine)
        Dim nc As Integer

        Dim N As Integer, L As Integer
        Dim i As Integer, j As Integer
        Dim flag As Boolean


        Dim ss() As String

        Dim flowin() As Integer
        Dim flowtp() As Integer
        Dim flowrq() As Integer

        Dim bestswp As Integer

        For nc = 1 To numC

            ss = inf.ReadLine.Split(" ")

            N = CInt(ss(0))
            L = CInt(ss(1))

            bestswp = L + 1

            ReDim flowin(N - 1)
            ReDim flowtp(N - 1)
            ReDim flowrq(N - 1)

            ss = inf.ReadLine.Split(" ")

            For i = 0 To N - 1

                For j = 0 To L - 1
                    flowin(i) = (flowin(i) << 1) Or CInt(ss(i).Substring(j, 1))
                Next j

            Next i

            ss = inf.ReadLine.Split(" ")

            For i = 0 To N - 1

                For j = 0 To L - 1
                    flowrq(i) = (flowrq(i) << 1) Or CInt(ss(i).Substring(j, 1))
                Next j

            Next i

            Array.Sort(flowrq)

            For i = 0 To 2 ^ L - 1
                If digsum(i) < bestswp Then

                    For j = 0 To N - 1
                        flowtp(j) = flowin(j) Xor i
                    Next j

                    Array.Sort(flowtp)
                    flag = True

                    For j = 0 To N - 1
                        If flowtp(j) <> flowrq(j) Then
                            flag = False
                        End If
                    Next j

                    If flag Then bestswp = digsum(i)

                End If




            Next i

            If bestswp = L + 1 Then
                outf.WriteLine("Case #" & CStr(nc) & ": NOT POSSIBLE")
            Else
                outf.WriteLine("Case #" & CStr(nc) & ": " & CStr(bestswp))
            End If
        Next nc

        inf.Close()
        outf.Close()

    End Sub


    Sub Main()

        Dim InFile As String, OutFile As String

        'InFile = "C:\Documents and Settings\dreyer\Desktop\GCJTest.in"
        'OutFile = "C:\Documents and Settings\dreyer\Desktop\GCJTest.out"

        InFile = "C:\Documents and Settings\dreyer\Desktop\A-small-attempt0.in"
        OutFile = "C:\Documents and Settings\dreyer\Desktop\A-small-attempt0.out"

        'InFile = "C:\Documents and Settings\dreyer\Desktop\D-large.in"
        'OutFile = "C:\Documents and Settings\dreyer\Desktop\D-large.out"

        R2Asm_2014(InFile, OutFile)

    End Sub




    Function numDerangements(ByVal n As Integer) As Long

        If n = 0 Then
            Return 1
        ElseIf n = 1 Then
            Return 0
        Else
            Return (n - 1) * (numDerangements(n - 1) + numDerangements(n - 2))
        End If

    End Function

    Public Function comb(ByVal N As Long, ByVal K As Long) As Long
        If Min(N, K) < 0 Or K > N Then
            Return 0
        ElseIf K = 0 Then
            Return 1
        Else
            Return (N - K + 1) / K * comb(N, K - 1)
        End If
    End Function

    Public Function Factorial(ByVal n As Integer) As Long
        Dim I As Integer, Count As Long
        If n = 0 Then
            Return 1
        Else
            Count = 1
            For I = 1 To n
                Count *= I
            Next I
            Return Count
        End If
    End Function




End Module


