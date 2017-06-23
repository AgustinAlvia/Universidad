Module Module1

    Sub calcular(ByVal x As Integer, ByVal n As Integer)
        Dim sumatoria As Double

        If (n < 5 Or n > 15) Then
            MsgBox("n es un número entre 5 y 15")
        End If

        If (x < 1 Or x > 5) Then
            MsgBox("x es un número entre 1 y 5")
        End If

        If (x >= 1 And x <= 5 And n >= 5 And n <= 15) Then
            For i = 1 To n
                sumatoria += Math.Pow(x, i) / (2 * i + 10)

            Next
            MsgBox(sumatoria)
        End If




    End Sub







End Module
