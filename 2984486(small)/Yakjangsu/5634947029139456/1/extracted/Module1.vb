Module Module1

    Sub Main()
        Dim oReader As New System.IO.StreamReader("A-large.in")
        Dim oWriter As New System.IO.StreamWriter("A-large.out")

        Dim T As Integer = Integer.Parse(oReader.ReadLine())

        For caseNum As Integer = 1 To T
            Dim strline() As String = oReader.ReadLine().Split(New Char() {" "c}, StringSplitOptions.RemoveEmptyEntries)
            Dim N As Integer = Integer.Parse(strline(0))
            Dim L As Integer = Integer.Parse(strline(1))
            'Dim electric(N - 1, L - 1) As Boolean
            'Dim onsElectric(L - 1) As Integer
            'strline = oReader.ReadLine().Split(New Char() {" "c}, StringSplitOptions.RemoveEmptyEntries)
            'For i As Integer = 0 To N - 1
            '    For j As Integer = 0 To L - 1
            '        If strline(i).Substring(j, 1) = 1 Then
            '            electric(i, j) = True
            '            onsElectric(j) += 1
            '        End If
            '    Next
            'Next
            'Dim device(N - 1, L - 1) As Boolean
            'Dim onsDevice(L - 1) As Integer
            'strline = oReader.ReadLine().Split(New Char() {" "c}, StringSplitOptions.RemoveEmptyEntries)
            'For i As Integer = 0 To N - 1
            '    For j As Integer = 0 To L - 1
            '        If strline(i).Substring(j, 1) = 1 Then
            '            device(i, j) = True
            '            onsDevice(j) += 1
            '        End If
            '    Next
            'Next

            Dim twototheN(L) As Long
            twototheN(0) = 1
            For j As Integer = 1 To L
                twototheN(j) = twototheN(j - 1) * 2
            Next
            Dim electric(N - 1) As Long
            strline = oReader.ReadLine().Split(New Char() {" "c}, StringSplitOptions.RemoveEmptyEntries)
            For i As Integer = 0 To N - 1
                For j As Integer = 0 To L - 1
                    If strline(i).Substring(j, 1) = 1 Then
                        electric(i) += twototheN(L - 1 - j)
                    End If
                Next
            Next
            Dim device(N - 1) As Long
            strline = oReader.ReadLine().Split(New Char() {" "c}, StringSplitOptions.RemoveEmptyEntries)
            For i As Integer = 0 To N - 1
                For j As Integer = 0 To L - 1
                    If strline(i).Substring(j, 1) = 1 Then
                        device(i) += twototheN(L - 1 - j)
                    End If
                Next
            Next

            'Dim switch(L - 1) As Integer
            'Dim NumberToFlip As Integer = 0
            'Dim stillOK As Boolean = True

            ''갯수만 check
            'For j As Integer = 0 To L - 1
            '    If onsDevice(j) = onsElectric(j) Then
            '        If (N Mod 2) = 0 AndAlso onsDevice(j) = N \ 2 Then
            '            'same
            '            switch(j) = -1
            '        Else
            '            switch(j) = 0
            '        End If
            '    Else
            '        If onsDevice(j) = N - onsElectric(j) Then
            '            switch(j) = 1
            '            NumberToFlip += 1
            '        Else
            '            stillOK = False
            '        End If
            '    End If
            'Next
            'If Not stillOK Then
            '    oWriter.WriteLine("Case #" & caseNum & ": NOT POSSIBLE")
            '    Continue For
            'End If

            'For j As Integer = 0 To L - 1
            '    Switch(j) = -1
            'Next
            
            Array.Sort(device)
            'Array.Sort(electric)
            Dim minimumNumberToFilp As Integer = 50
            For match As Integer = 0 To N - 1
                Dim NumberToFlip As Integer = 0
                Dim newElectric(N - 1) As Long
                Array.Copy(electric, newElectric, N)
                For j As Integer = 0 To L - 1
                    If (device(0) Mod twototheN(j + 1)) \ twototheN(j) <> (electric(match) Mod twototheN(j + 1)) \ twototheN(j) Then
                        'flip
                        NumberToFlip += 1
                        For i As Integer = 0 To N - 1
                            If (newElectric(i) Mod twototheN(j + 1)) \ twototheN(j) = 0 Then
                                newElectric(i) += twototheN(j)
                            Else
                                newElectric(i) -= twototheN(j)
                            End If
                        Next
                    End If
                Next
                Array.Sort(newElectric)
                Dim clear As Boolean = True
                For i As Integer = 0 To N - 1
                    If device(i) <> newElectric(i) Then clear = False
                Next
                If clear AndAlso NumberToFlip < minimumNumberToFilp Then
                    minimumNumberToFilp = NumberToFlip
                End If
            Next

            If minimumNumberToFilp = 50 Then
                oWriter.WriteLine("Case #" & caseNum & ": NOT POSSIBLE")
            Else
                oWriter.WriteLine("Case #" & caseNum & ": " & minimumNumberToFilp)
            End If

        Next

        oReader.Close()
        oWriter.Close()

        MsgBox("End!")
    End Sub

End Module
