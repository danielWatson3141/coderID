Imports System
Imports System.IO
Imports System.Text
Module Module1

    Sub Main()
        Dim path As String = "A-small-attempt2.in"

        Try
            Dim sr As StreamReader = New StreamReader(path)
            Dim sw As StreamWriter = New StreamWriter("output.in")
            Dim caseno As Integer = CInt(sr.ReadLine())

            Dim initial As Decimal = 2
            For zz As Integer = 1 To caseno
                Dim tmp As String() = sr.ReadLine().Split(" ")
                Dim deviceNo As Integer = CInt(tmp(0))
                Dim digit As Integer = CInt(tmp(1))
                Dim switch As String() = sr.ReadLine().Split(" ")
                Dim device As String() = sr.ReadLine().Split(" ")

                Array.Sort(switch)
                Array.Sort(device)
                Dim deviceString = Join(device, ",")


                Dim switchTimes As Integer = -1
                If Join(device, ",") = Join(switch, ",") Then
                    switchTimes = 0
                    GoTo result
                Else
                    For aa As Integer = 0 To digit - 1
                        Dim tmpswitch As String() = switch.Clone
                        For kk As Integer = 0 To deviceNo - 1
                            Dim charArr As Char() = tmpswitch(kk).ToCharArray
                            If charArr(aa).CompareTo("0"c) = 0 Then
                                charArr(aa) = "1"c
                            Else
                                charArr(aa) = "0"c
                            End If
                            tmpswitch(kk) = New String(charArr)
                        Next
                        Array.Sort(tmpswitch)

                        If deviceString = Join(tmpswitch, ",") Then
                            switchTimes = 1
                            GoTo result
                        End If
                    Next


                    For aa As Integer = 0 To digit - 1
                        For bb As Integer = 0 To digit - 1
                            If aa = bb Then Exit For
                            Dim tmpswitch As String() = switch.Clone
                            For kk As Integer = 0 To deviceNo - 1
                                Dim charArr As Char() = tmpswitch(kk).ToCharArray
                                If charArr(aa).CompareTo("0"c) = 0 Then
                                    charArr(aa) = "1"c
                                Else
                                    charArr(aa) = "0"c
                                End If
                                If charArr(bb).CompareTo("0"c) = 0 Then
                                    charArr(bb) = "1"c
                                Else
                                    charArr(bb) = "0"c
                                End If
                                tmpswitch(kk) = New String(charArr)
                            Next
                            Array.Sort(tmpswitch)

                            If deviceString = Join(tmpswitch, ",") Then
                                switchTimes = 2
                                GoTo result
                            End If
                        Next
                    Next

                    For aa As Integer = 0 To digit - 1
                        For bb As Integer = 0 To digit - 1
                            If aa = bb Then Exit For
                            For cc As Integer = 0 To digit - 1
                                If bb = cc Then Exit For
                                Dim tmpswitch As String() = switch.Clone
                                For kk As Integer = 0 To deviceNo - 1
                                    Dim charArr As Char() = tmpswitch(kk).ToCharArray
                                    If charArr(aa).CompareTo("0"c) = 0 Then
                                        charArr(aa) = "1"c
                                    Else
                                        charArr(aa) = "0"c
                                    End If
                                    If charArr(bb).CompareTo("0"c) = 0 Then
                                        charArr(bb) = "1"c
                                    Else
                                        charArr(bb) = "0"c
                                    End If

                                    If charArr(cc).CompareTo("0"c) = 0 Then
                                        charArr(cc) = "1"c
                                    Else
                                        charArr(cc) = "0"c
                                    End If
                                    tmpswitch(kk) = New String(charArr)
                                Next
                                Array.Sort(tmpswitch)

                                If deviceString = Join(tmpswitch, ",") Then
                                    switchTimes = 3
                                    GoTo result
                                End If
                            Next
                        Next
                    Next

                    For aa As Integer = 0 To digit - 1
                        For bb As Integer = 0 To digit - 1
                            If aa = bb Then Exit For
                            For cc As Integer = 0 To digit - 1
                                If bb = cc Then Exit For
                                For dd As Integer = 0 To digit - 1
                                    If cc = dd Then Exit For
                                    Dim tmpswitch As String() = switch.Clone
                                    For kk As Integer = 0 To deviceNo - 1
                                        Dim charArr As Char() = tmpswitch(kk).ToCharArray
                                        If charArr(aa).CompareTo("0"c) = 0 Then
                                            charArr(aa) = "1"c
                                        Else
                                            charArr(aa) = "0"c
                                        End If
                                        If charArr(bb).CompareTo("0"c) = 0 Then
                                            charArr(bb) = "1"c
                                        Else
                                            charArr(bb) = "0"c
                                        End If

                                        If charArr(cc).CompareTo("0"c) = 0 Then
                                            charArr(cc) = "1"c
                                        Else
                                            charArr(cc) = "0"c
                                        End If
                                        If charArr(dd).CompareTo("0"c) = 0 Then
                                            charArr(dd) = "1"c
                                        Else
                                            charArr(dd) = "0"c
                                        End If
                                        tmpswitch(kk) = New String(charArr)
                                    Next
                                    Array.Sort(tmpswitch)

                                    If deviceString = Join(tmpswitch, ",") Then
                                        switchTimes = 4
                                        GoTo result
                                    End If
                                Next
                            Next
                        Next
                    Next


                    For aa As Integer = 0 To digit - 1
                        For bb As Integer = 0 To digit - 1
                            If aa = bb Then Exit For
                            For cc As Integer = 0 To digit - 1
                                If bb = cc Then Exit For
                                For dd As Integer = 0 To digit - 1
                                    If cc = dd Then Exit For
                                    For ee As Integer = 0 To digit - 1
                                        If dd = ee Then Exit For
                                        Dim tmpswitch As String() = switch.Clone
                                        For kk As Integer = 0 To deviceNo - 1
                                            Dim charArr As Char() = tmpswitch(kk).ToCharArray
                                            If charArr(aa).CompareTo("0"c) = 0 Then
                                                charArr(aa) = "1"c
                                            Else
                                                charArr(aa) = "0"c
                                            End If
                                            If charArr(bb).CompareTo("0"c) = 0 Then
                                                charArr(bb) = "1"c
                                            Else
                                                charArr(bb) = "0"c
                                            End If

                                            If charArr(cc).CompareTo("0"c) = 0 Then
                                                charArr(cc) = "1"c
                                            Else
                                                charArr(cc) = "0"c
                                            End If
                                            If charArr(dd).CompareTo("0"c) = 0 Then
                                                charArr(dd) = "1"c
                                            Else
                                                charArr(dd) = "0"c
                                            End If
                                            If charArr(ee).CompareTo("0"c) = 0 Then
                                                charArr(ee) = "1"c
                                            Else
                                                charArr(ee) = "0"c
                                            End If
                                            tmpswitch(kk) = New String(charArr)
                                        Next
                                        Array.Sort(tmpswitch)

                                        If deviceString = Join(tmpswitch, ",") Then
                                            switchTimes = 5
                                            GoTo result
                                        End If
                                    Next
                                Next
                            Next
                        Next
                    Next


                    For aa As Integer = 0 To digit - 1
                        For bb As Integer = 0 To digit - 1
                            If aa = bb Then Exit For
                            For cc As Integer = 0 To digit - 1
                                If bb = cc Then Exit For
                                For dd As Integer = 0 To digit - 1
                                    If cc = dd Then Exit For
                                    For ee As Integer = 0 To digit - 1
                                        If dd = ee Then Exit For
                                        For ff As Integer = 0 To digit - 1
                                            If ee = ff Then Exit For
                                            Dim tmpswitch As String() = switch.Clone
                                            For kk As Integer = 0 To deviceNo - 1
                                                Dim charArr As Char() = tmpswitch(kk).ToCharArray
                                                If charArr(aa).CompareTo("0"c) = 0 Then
                                                    charArr(aa) = "1"c
                                                Else
                                                    charArr(aa) = "0"c
                                                End If
                                                If charArr(bb).CompareTo("0"c) = 0 Then
                                                    charArr(bb) = "1"c
                                                Else
                                                    charArr(bb) = "0"c
                                                End If

                                                If charArr(cc).CompareTo("0"c) = 0 Then
                                                    charArr(cc) = "1"c
                                                Else
                                                    charArr(cc) = "0"c
                                                End If
                                                If charArr(dd).CompareTo("0"c) = 0 Then
                                                    charArr(dd) = "1"c
                                                Else
                                                    charArr(dd) = "0"c
                                                End If
                                                If charArr(ee).CompareTo("0"c) = 0 Then
                                                    charArr(ee) = "1"c
                                                Else
                                                    charArr(ee) = "0"c
                                                End If
                                                If charArr(ff).CompareTo("0"c) = 0 Then
                                                    charArr(ff) = "1"c
                                                Else
                                                    charArr(ff) = "0"c
                                                End If
                                                tmpswitch(kk) = New String(charArr)
                                            Next
                                            Array.Sort(tmpswitch)

                                            If deviceString = Join(tmpswitch, ",") Then
                                                switchTimes = 6
                                                GoTo result
                                            End If
                                        Next
                                    Next
                                Next
                            Next
                        Next
                    Next

                    For aa As Integer = 0 To digit - 1
                        For bb As Integer = 0 To digit - 1
                            If aa = bb Then Exit For
                            For cc As Integer = 0 To digit - 1
                                If bb = cc Then Exit For
                                For dd As Integer = 0 To digit - 1
                                    If cc = dd Then Exit For
                                    For ee As Integer = 0 To digit - 1
                                        If dd = ee Then Exit For
                                        For ff As Integer = 0 To digit - 1
                                            If ee = ff Then Exit For
                                            For gg As Integer = 0 To digit - 1
                                                If ff = gg Then Exit For
                                                Dim tmpswitch As String() = switch.Clone
                                                For kk As Integer = 0 To deviceNo - 1
                                                    Dim charArr As Char() = tmpswitch(kk).ToCharArray
                                                    If charArr(aa).CompareTo("0"c) = 0 Then
                                                        charArr(aa) = "1"c
                                                    Else
                                                        charArr(aa) = "0"c
                                                    End If
                                                    If charArr(bb).CompareTo("0"c) = 0 Then
                                                        charArr(bb) = "1"c
                                                    Else
                                                        charArr(bb) = "0"c
                                                    End If

                                                    If charArr(cc).CompareTo("0"c) = 0 Then
                                                        charArr(cc) = "1"c
                                                    Else
                                                        charArr(cc) = "0"c
                                                    End If
                                                    If charArr(dd).CompareTo("0"c) = 0 Then
                                                        charArr(dd) = "1"c
                                                    Else
                                                        charArr(dd) = "0"c
                                                    End If
                                                    If charArr(ee).CompareTo("0"c) = 0 Then
                                                        charArr(ee) = "1"c
                                                    Else
                                                        charArr(ee) = "0"c
                                                    End If
                                                    If charArr(ff).CompareTo("0"c) = 0 Then
                                                        charArr(ff) = "1"c
                                                    Else
                                                        charArr(ff) = "0"c
                                                    End If
                                                    If charArr(gg).CompareTo("0"c) = 0 Then
                                                        charArr(gg) = "1"c
                                                    Else
                                                        charArr(gg) = "0"c
                                                    End If
                                                    tmpswitch(kk) = New String(charArr)
                                                Next
                                                Array.Sort(tmpswitch)

                                                If deviceString = Join(tmpswitch, ",") Then
                                                    switchTimes = 7
                                                    GoTo result
                                                End If
                                            Next
                                        Next
                                    Next
                                Next
                            Next
                        Next
                    Next


                    For aa As Integer = 0 To digit - 1
                        For bb As Integer = 0 To digit - 1
                            If aa = bb Then Exit For
                            For cc As Integer = 0 To digit - 1
                                If bb = cc Then Exit For
                                For dd As Integer = 0 To digit - 1
                                    If cc = dd Then Exit For
                                    For ee As Integer = 0 To digit - 1
                                        If dd = ee Then Exit For
                                        For ff As Integer = 0 To digit - 1
                                            If ee = ff Then Exit For
                                            For gg As Integer = 0 To digit - 1
                                                If ff = gg Then Exit For
                                                For hh As Integer = 0 To digit - 1
                                                    If gg = hh Then Exit For
                                                    Dim tmpswitch As String() = switch.Clone
                                                    For kk As Integer = 0 To deviceNo - 1
                                                        Dim charArr As Char() = tmpswitch(kk).ToCharArray
                                                        If charArr(aa).CompareTo("0"c) = 0 Then
                                                            charArr(aa) = "1"c
                                                        Else
                                                            charArr(aa) = "0"c
                                                        End If
                                                        If charArr(bb).CompareTo("0"c) = 0 Then
                                                            charArr(bb) = "1"c
                                                        Else
                                                            charArr(bb) = "0"c
                                                        End If

                                                        If charArr(cc).CompareTo("0"c) = 0 Then
                                                            charArr(cc) = "1"c
                                                        Else
                                                            charArr(cc) = "0"c
                                                        End If
                                                        If charArr(dd).CompareTo("0"c) = 0 Then
                                                            charArr(dd) = "1"c
                                                        Else
                                                            charArr(dd) = "0"c
                                                        End If
                                                        If charArr(ee).CompareTo("0"c) = 0 Then
                                                            charArr(ee) = "1"c
                                                        Else
                                                            charArr(ee) = "0"c
                                                        End If
                                                        If charArr(ff).CompareTo("0"c) = 0 Then
                                                            charArr(ff) = "1"c
                                                        Else
                                                            charArr(ff) = "0"c
                                                        End If
                                                        If charArr(gg).CompareTo("0"c) = 0 Then
                                                            charArr(gg) = "1"c
                                                        Else
                                                            charArr(gg) = "0"c
                                                        End If
                                                        If charArr(hh).CompareTo("0"c) = 0 Then
                                                            charArr(hh) = "1"c
                                                        Else
                                                            charArr(hh) = "0"c
                                                        End If
                                                        tmpswitch(kk) = New String(charArr)
                                                    Next
                                                    Array.Sort(tmpswitch)

                                                    If deviceString = Join(tmpswitch, ",") Then
                                                        switchTimes = 8
                                                        GoTo result
                                                    End If
                                                Next
                                            Next
                                        Next
                                    Next
                                Next
                            Next
                        Next
                    Next















                    For aa As Integer = 0 To digit - 1
                        For bb As Integer = 0 To digit - 1
                            If aa = bb Then Exit For
                            For cc As Integer = 0 To digit - 1
                                If bb = cc Then Exit For
                                For dd As Integer = 0 To digit - 1
                                    If cc = dd Then Exit For
                                    For ee As Integer = 0 To digit - 1
                                        If dd = ee Then Exit For
                                        For ff As Integer = 0 To digit - 1
                                            If ee = ff Then Exit For
                                            For gg As Integer = 0 To digit - 1
                                                If ff = gg Then Exit For
                                                For hh As Integer = 0 To digit - 1
                                                    If gg = hh Then Exit For
                                                    For ii As Integer = 0 To digit - 1
                                                        If hh = ii Then Exit For
                                                        Dim tmpswitch As String() = switch.Clone
                                                        For kk As Integer = 0 To deviceNo - 1
                                                            Dim charArr As Char() = tmpswitch(kk).ToCharArray
                                                            If charArr(aa).CompareTo("0"c) = 0 Then
                                                                charArr(aa) = "1"c
                                                            Else
                                                                charArr(aa) = "0"c
                                                            End If
                                                            If charArr(bb).CompareTo("0"c) = 0 Then
                                                                charArr(bb) = "1"c
                                                            Else
                                                                charArr(bb) = "0"c
                                                            End If

                                                            If charArr(cc).CompareTo("0"c) = 0 Then
                                                                charArr(cc) = "1"c
                                                            Else
                                                                charArr(cc) = "0"c
                                                            End If
                                                            If charArr(dd).CompareTo("0"c) = 0 Then
                                                                charArr(dd) = "1"c
                                                            Else
                                                                charArr(dd) = "0"c
                                                            End If
                                                            If charArr(ee).CompareTo("0"c) = 0 Then
                                                                charArr(ee) = "1"c
                                                            Else
                                                                charArr(ee) = "0"c
                                                            End If
                                                            If charArr(ff).CompareTo("0"c) = 0 Then
                                                                charArr(ff) = "1"c
                                                            Else
                                                                charArr(ff) = "0"c
                                                            End If
                                                            If charArr(gg).CompareTo("0"c) = 0 Then
                                                                charArr(gg) = "1"c
                                                            Else
                                                                charArr(gg) = "0"c
                                                            End If
                                                            If charArr(hh).CompareTo("0"c) = 0 Then
                                                                charArr(hh) = "1"c
                                                            Else
                                                                charArr(hh) = "0"c
                                                            End If
                                                            If charArr(ii).CompareTo("0"c) = 0 Then
                                                                charArr(ii) = "1"c
                                                            Else
                                                                charArr(ii) = "0"c
                                                            End If
                                                            tmpswitch(kk) = New String(charArr)
                                                        Next
                                                        Array.Sort(tmpswitch)

                                                        If deviceString = Join(tmpswitch, ",") Then
                                                            Console.WriteLine(deviceString)
                                                            Console.WriteLine(Join(tmpswitch, ","))
                                                            Console.WriteLine(Join(switch, ","))
                                                            switchTimes = 9
                                                            GoTo result
                                                        End If
                                                    Next
                                                Next
                                            Next
                                        Next
                                    Next
                                Next
                            Next
                        Next
                    Next



                    For aa As Integer = 0 To digit - 1
                        For bb As Integer = 0 To digit - 1
                            If aa = bb Then Exit For
                            For cc As Integer = 0 To digit - 1
                                If bb = cc Then Exit For
                                For dd As Integer = 0 To digit - 1
                                    If cc = dd Then Exit For
                                    For ee As Integer = 0 To digit - 1
                                        If dd = ee Then Exit For
                                        For ff As Integer = 0 To digit - 1
                                            If ee = ff Then Exit For
                                            For gg As Integer = 0 To digit - 1
                                                If ff = gg Then Exit For
                                                For hh As Integer = 0 To digit - 1
                                                    If gg = hh Then Exit For
                                                    For ii As Integer = 0 To digit - 1
                                                        If hh = ii Then Exit For
                                                        For jj As Integer = 0 To digit - 1
                                                            If ii = jj Then Exit For
                                                            Dim tmpswitch As String() = switch.Clone
                                                            For kk As Integer = 0 To deviceNo - 1
                                                                Dim charArr As Char() = tmpswitch(kk).ToCharArray
                                                                If charArr(aa).CompareTo("0"c) = 0 Then
                                                                    charArr(aa) = "1"c
                                                                Else
                                                                    charArr(aa) = "0"c
                                                                End If
                                                                If charArr(bb).CompareTo("0"c) = 0 Then
                                                                    charArr(bb) = "1"c
                                                                Else
                                                                    charArr(bb) = "0"c
                                                                End If

                                                                If charArr(cc).CompareTo("0"c) = 0 Then
                                                                    charArr(cc) = "1"c
                                                                Else
                                                                    charArr(cc) = "0"c
                                                                End If
                                                                If charArr(dd).CompareTo("0"c) = 0 Then
                                                                    charArr(dd) = "1"c
                                                                Else
                                                                    charArr(dd) = "0"c
                                                                End If
                                                                If charArr(ee).CompareTo("0"c) = 0 Then
                                                                    charArr(ee) = "1"c
                                                                Else
                                                                    charArr(ee) = "0"c
                                                                End If
                                                                If charArr(ff).CompareTo("0"c) = 0 Then
                                                                    charArr(ff) = "1"c
                                                                Else
                                                                    charArr(ff) = "0"c
                                                                End If
                                                                If charArr(gg).CompareTo("0"c) = 0 Then
                                                                    charArr(gg) = "1"c
                                                                Else
                                                                    charArr(gg) = "0"c
                                                                End If
                                                                If charArr(hh).CompareTo("0"c) = 0 Then
                                                                    charArr(hh) = "1"c
                                                                Else
                                                                    charArr(hh) = "0"c
                                                                End If
                                                                If charArr(ii).CompareTo("0"c) = 0 Then
                                                                    charArr(ii) = "1"c
                                                                Else
                                                                    charArr(ii) = "0"c
                                                                End If
                                                                If charArr(jj).CompareTo("0"c) = 0 Then
                                                                    charArr(jj) = "1"c
                                                                Else
                                                                    charArr(jj) = "0"c
                                                                End If
                                                                tmpswitch(kk) = New String(charArr)
                                                            Next
                                                            Array.Sort(tmpswitch)

                                                            If deviceString = Join(tmpswitch, ",") Then
                                                                switchTimes = 10
                                                                GoTo result
                                                            End If
                                                        Next
                                                    Next
                                                Next
                                            Next
                                        Next
                                    Next
                                Next
                            Next
                        Next
                    Next


                End If


result:
                sw.WriteLine("Case #" & zz & ": " & IIf(switchTimes = -1, "NOT POSSIBLE", switchTimes))

            Next

            sw.Close()
            sr.Close()

        Catch e As Exception
            Console.WriteLine("The process failed: {0}", e.ToString())
        End Try


    End Sub

End Module
