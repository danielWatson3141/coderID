Module Solution
	Dim N As Integer
	Dim provided, wanted As String()
	Dim flippable As List(Of Integer)
	
	Function Flip(flow As String, i As Integer) As String
		Dim c = flow(i)
		If c = "0"C
			c = "1"C
		Else
			c = "0"C
		End If
		Return flow.Substring(0, i) + c + flow.Substring(i + 1)
	End Function
	
	Sub Main()
		Dim T = Convert.ToInt32(Console.ReadLine())
		For iT = 1 To T
			Dim line = (From word In Console.ReadLine().Split()
			            Select Convert.ToInt32(word)).ToArray()
			N = line(0)
			Dim L = line(1)
			
			provided = Console.ReadLine().Split()
			wanted = Console.ReadLine().Split()
			Array.Sort(wanted)
			
			Dim flips = 0, possible = True
			flippable = New List(Of Integer)
			For i = 0 To L - 1
				Dim zerosProvided = 0, zerosWanted = 0
				For Each flow In provided
					If flow.Chars(i) = "0"C Then zerosProvided += 1
				Next
				For Each flow In wanted
					If flow.Chars(i) = "0"C Then zerosWanted += 1
				Next
				
				If zerosProvided = zerosWanted
					If zerosProvided * 2 = N
						flippable.Add(i)
					End If
				ElseIf N - zerosProvided = zerosWanted
					flips += 1
					For j = 0 To N - 1
						provided(j) = Flip(provided(j), i)
					Next
				Else
					possible = False
					Exit For
				End If
			Next
			
			If possible
				Dim newFlips = TryFlip(0)
				If Not newFlips.HasValue
					possible = False
				Else
					flips += newFlips
				End If
			End If
			
			If Not possible
				Console.WriteLine("Case #{0}: NOT POSSIBLE", iT)
			Else
				Console.WriteLine("Case #{0}: {1}", iT, flips)
			End If
		Next
	End Sub
	
	Function TryFlip(i As Integer) As Integer?
		If i < flippable.Count
			Dim try1 = TryFlip(i + 1)
			For j = 0 To N - 1
				provided(j) = Flip(provided(j), flippable(i))
			Next
			
			Dim try2 = 1 + TryFlip(i + 1)
			For j = 0 To N - 1
				provided(j) = Flip(provided(j), flippable(i))
			Next
			
			If try1.HasValue And try2.HasValue
				Return Math.Min(try1.Value, try2.Value)
			ElseIf try1.HasValue
				Return try1
			Else
				Return try2
			End If
		Else
			Array.Sort(provided)
			If provided.SequenceEqual(wanted)
				Return 0
			Else
				Return Nothing
			End If
		End If
	End Function
End Module