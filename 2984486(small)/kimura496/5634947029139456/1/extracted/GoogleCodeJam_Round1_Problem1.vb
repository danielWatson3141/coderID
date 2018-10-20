Module GoogleCodeJam_Round1_Problem1

    Public Function resolveProblem(ByVal sProblem) As String

        Dim sResult As String = ""

        Dim arrTestLines As Array
        arrTestLines = sProblem.Split(vbLf) ' 行ごとに配列格納

        Dim nTestCaseCount As Integer
        nTestCaseCount = Integer.Parse(arrTestLines(0)) ' テストケース数の取得

        For i = 1 To nTestCaseCount
            Dim arrTmp As Array

            Dim nValueN As Integer ' 端末数
            Dim nValueL As Integer ' ビット桁数

            arrTmp = arrTestLines(i * 3 - 2).Trim().Split(" ")
            nValueN = arrTmp(0)
            nValueL = arrTmp(1)

            Dim arrBaseDevices As New ArrayList ' 各端末の通電タイプ
            arrTmp = arrTestLines(i * 3 - 1).Trim().Split(" ")
            For h As Integer = 0 To arrTmp.Length - 1
                arrBaseDevices.Add(getLongValueFromBitString(arrTmp(h)))
            Next

            Dim arrBaseOutlets As New ArrayList ' 各コンセントの通電タイプ
            arrTmp = arrTestLines(i * 3 - 0).Trim().Split(" ")
            For h As Integer = 0 To arrTmp.Length - 1
                arrBaseOutlets.Add(getLongValueFromBitString(arrTmp(h)))
            Next

            Dim bCorrect As Boolean = False
            Dim nTargetValue As Long = 0
            Dim nResult As Integer = nValueL

            For nLoop1 As Integer = 0 To nValueN - 1
                Dim arrDevices As ArrayList = New ArrayList(arrBaseDevices)
                Dim arrOutlets As ArrayList = New ArrayList(arrBaseOutlets)

                nTargetValue = arrOutlets(0) Xor arrDevices(nLoop1)
                arrDevices.RemoveAt(nLoop1)

                bCorrect = True

                For nLoop2 As Integer = 1 To nValueN - 1
                    Dim bFlag As Boolean = False

                    For nLoop3 As Integer = 0 To arrDevices.Count - 1
                        Dim nBufValue As Long = arrOutlets(nLoop2) Xor arrDevices(nLoop3)
                        If nBufValue = nTargetValue Then
                            arrDevices.RemoveAt(nLoop3)
                            bFlag = True
                            Exit For
                        End If
                    Next

                    If bFlag = False Then
                        bCorrect = False
                        Exit For

                    End If

                Next

                If bCorrect Then
                    Dim nResultBuf As Integer = 0
                    Dim sTarget As String = Convert.ToString(nTargetValue, 2)
                    For h = 0 To sTarget.Length - 1
                        If sTarget.Substring(h, 1) = "1" Then
                            nResultBuf = nResultBuf + 1
                        End If
                    Next

                    If nResult > nResultBuf Then
                        nResult = nResultBuf
                    End If
                End If

            Next


            Dim sAnswer As String = "Case #" & i & ": "

            If nResult <> nValueL Then
                ' 可能な場合
                sAnswer = sAnswer & nResult

            Else
                ' 不可能な場合
                sAnswer = sAnswer & "NOT POSSIBLE"

            End If

            sResult = sResult & sAnswer & vbLf
        Next


        Return sResult

    End Function

    Function getLongValueFromBitString(ByVal sValue As String) As Long
        Dim nResult As Long = 0
        Dim nRate As Long = 1

        For i As Integer = sValue.Length - 1 To 0 Step -1
            nResult = nResult + Integer.Parse(sValue.Substring(i, 1)) * nRate
            nRate = nRate * 2
        Next

        Return nResult
    End Function


End Module




'    and  論理積
'    or   論理和
'    not  反転
'    xor  排他論理和
'
'Dim a As Long
'
'    a = &H0f and &Hf3         '** 00001111B and 11110011B = 00000011B
'    a = &H0f or &Hf3          '** 00001111B or  11110011B = 11111111B
'    a = not &H0f              '** not 00001111B           = 11110000B
'    a = &H0f xor &Hf3         '** 00001111B xor 11110011B = 11111100B
'
'  ・通常の integer、long 型では、byte 上位のビットが影響を受ける。
'    例えば、ビット反転では、次のように &HFF の and ビットマスクで、
'    byte 値にすると良い。
'
'Dim a As Integer
'
'  a = &HC6
'  a = (Not a) And &HFF
'  msgbox a


'Dim arrTmp As Array
'
'Dim nAnswerRow1 As Integer
'nAnswerRow1 = Integer.Parse(arrTestLines(nLineIndex)) ' 1回目の回答
'
'Dim arrTargetCards1 As ArrayList
'arrTmp = arrTestLines(nLineIndex + nAnswerRow1).Trim().Split(" ")
'arrTargetCards1 = New ArrayList(arrTmp) ' 対象行のカードを格納
'
'nLineIndex = nLineIndex + 5
'
'Dim nAnswerRow2 As Integer
'nAnswerRow2 = Integer.Parse(arrTestLines(nLineIndex)) ' 1回目の回答
'
'Dim arrTargetCards2 As ArrayList
'arrTmp = arrTestLines(nLineIndex + nAnswerRow2).Trim().Split(" ")
'arrTargetCards2 = New ArrayList(arrTmp)  ' 対象行のカードを格納
'
'nLineIndex = nLineIndex + 5
'
'Dim arrAnswers As New ArrayList
'For h = 1 To 16
'    If arrTargetCards1.Contains(h.ToString) And arrTargetCards2.Contains(h.ToString) Then
'        arrAnswers.Add(h)
'
'    End If
'Next
'
'Dim sAnswer As String = "Case #" & i & ": "
'Select Case arrAnswers.Count
'    Case 1
'        sAnswer = sAnswer & arrAnswers(0)
'    Case 0
'        sAnswer = sAnswer & "Volunteer cheated!"
'    Case Else
'        sAnswer = sAnswer & "Bad magician!"
'
'End Select
'
'sResult = sResult & sAnswer & vbLf