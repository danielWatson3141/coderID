Module Module1

    Sub Main()
        Dim oReader As New System.IO.StreamReader("C-small-attempt0.in")
        Dim oWriter As New System.IO.StreamWriter("C-small.out")

        Dim T As Integer = Integer.Parse(oReader.ReadLine())

        Dim N As Integer = 1000
        Dim probDensity(N - 1, N - 1) As Double
        Dim probDensityG(N - 1, N - 1) As Double
        For i As Integer = 0 To N - 1
            probDensity(i, i) = 1.0
        Next
        For i As Integer = 0 To N - 1
            For j As Integer = 0 To N - 1
                Dim temp As Double = probDensity(i, j)
                For k As Integer = 0 To N - 1
                    If k <> i Then
                        probDensity(k, j) = probDensity(k, j) * (N - 1) / N + temp / N
                    Else
                        probDensity(i, j) = 1 / N
                    End If
                Next

                probDensityG(i, j) = 1 / N
            Next
        Next

        Dim probGood(T - 1) As Double
        Dim index(T - 1) As Double
        For caseNum As Integer = 1 To T
            Dim pgood As Double = 0.5
            
            Dim strline() As String = oReader.ReadLine().Split(New Char() {" "c}, StringSplitOptions.RemoveEmptyEntries)
            strline = oReader.ReadLine().Split(New Char() {" "c}, StringSplitOptions.RemoveEmptyEntries)
            For i As Integer = 0 To N - 1
                Dim number As Integer = Integer.Parse(strline(i))
                Dim pbad As Double = 1 - pgood

                pgood = probDensityG(i, number) * pgood / (probDensityG(i, number) * pgood + probDensity(i, number) * pbad)
            Next

            probGood(caseNum - 1) = pgood
            index(caseNum - 1) = caseNum

            If pgood > 0.5 Then
                oWriter.WriteLine("Case #" & caseNum & ": GOOD")
            Else
                oWriter.WriteLine("Case #" & caseNum & ": BAD")
            End If

        Next

        oReader.Close()
        oWriter.Close()

        MsgBox("End!")
    End Sub

End Module
