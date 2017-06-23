

Public Class Form1
    Sub actualizar()
        Dim mayor As Integer
        Dim menor As Integer
        Dim suma As Integer

        For i = 0 To lbxImpar.Items.Count - 1
            suma += lbxImpar.Items.Item(i)
            If (i = 0) Then
                mayor = lbxImpar.Items.Item(i)
            ElseIf (mayor <= lbxImpar.Items.Item(i)) Then
                mayor = lbxImpar.Items.Item(i)
            End If

            If (i = 0) Then
                menor = lbxImpar.Items.Item(i)
            ElseIf (menor >= lbxImpar.Items.Item(i)) Then
                menor = lbxImpar.Items.Item(i)
            End If

        Next

        lblMayorImpar.Text = "Mayor: " & mayor
        lblMenorImpar.Text = "Menor: " & menor
        lblSumaImpar.Text = "Suma; " & suma
        lblImpar.Text = "Impares: " & lbxImpar.Items.Count
        suma = 0
        mayor = 0
        menor = 0

        For i = 0 To lbxPar.Items.Count - 1
            suma += lbxPar.Items.Item(i)
            If (i = 0) Then
                mayor = lbxPar.Items.Item(i)
            ElseIf (mayor <= lbxpar.Items.Item(i)) Then
                mayor = lbxPar.Items.Item(i)
            End If

            If (i = 0) Then
                menor = lbxPar.Items.Item(i)
            ElseIf (menor >= lbxpar.Items.Item(i)) Then
                menor = lbxPar.Items.Item(i)
            End If

        Next

        lblMayorPar.Text = "Mayor: " & mayor
        lblMenorPar.Text = "Menor: " & menor
        lblSumaPar.Text = "Suma; " & suma
        lblPar.Text = "Pares: " & lbxPar.Items.Count


    End Sub

    Private Sub btnIngresar_Click(sender As Object, e As EventArgs) Handles btnIngresarFor.Click
        Dim numero As Integer
        Dim cantidad As Integer

        lbxImpar.Items.Clear()
        lbxPar.Items.Clear()
        actualizar()

        cantidad = InputBox("Ingrese la cantidad de números")
        For i = 1 To cantidad
            numero = InputBox("Ingrese el número " & i & " De " & cantidad)
            If (esPar(numero)) Then
                lbxPar.Items.Add(numero)
            Else
                lbxImpar.Items.Add(numero)
            End If
            actualizar()
        Next


    End Sub

    Private Sub btnIngresarWhile_Click(sender As Object, e As EventArgs) Handles btnIngresarWhile.Click
        Dim numero As Integer
        Dim cantidad As Integer
        lbxImpar.Items.Clear()
        lbxPar.Items.Clear()
        actualizar()


        Dim i As Integer
        cantidad = InputBox("Ingrese la cantidad de numeros: ")
        While (i < cantidad)
            numero = InputBox("Ingrese el número " & i + 1 & " De " & cantidad)
            If (esPar(numero)) Then
                lbxPar.Items.Add(numero)
            Else
                lbxImpar.Items.Add(numero)
            End If
            actualizar()
            i = i + 1
        End While



    End Sub

    Private Sub btnIngresarDo_Click(sender As Object, e As EventArgs) Handles btnIngresarDo.Click
        Dim numero As Integer
        Dim cantidad As Integer
        Dim i As Integer
        lbxImpar.Items.Clear()
        lbxPar.Items.Clear()
        actualizar()

        cantidad = InputBox("Ingrese la cantidad de numeros: ")
        Do While (i < cantidad)
            numero = InputBox("Ingrese el número " & i + 1 & " De " & cantidad)
            If (esPar(numero)) Then
                lbxPar.Items.Add(numero)
            Else
                lbxImpar.Items.Add(numero)
            End If
            actualizar()
            i = i + 1
        Loop

    End Sub
End Class
