Public Class Form1
    Dim numeros As New List(Of Integer)

    Sub actualizar()
        Dim mayor As Integer
        Dim menor As Integer
        Dim medio As Double

        numeros.Sort()

        mayor = numeros.Max()
        menor = numeros.Min()

        medio = numeros.Count / 2
        'MsgBox(Math.Floor(medio))

        lblMayor.Text = "Mayor: " & mayor
        lblMenor.Text = "Menor: " & menor

        If (numeros.Count Mod 2 <> 0 And numeros.Count > 1) Then

            lblMedio.Text = "Medio: " & numeros.Item(Math.Floor(medio))


            'lblMedio.Text = "Medio : " & lbxNumeros.Items.Item(Math.Floor(medio))
        Else
            lblMedio.Text = "No tiene medio:"

        End If


    End Sub

    Private Sub btnEjecutar_Click(sender As Object, e As EventArgs) Handles btnEjecutar.Click
        Dim numero As Integer
        numero = 1

        While (numero <> 0)
            numero = InputBox("Ingrese un número: ")
            If (numero < 0) Then
                MsgBox("Ingreso un número negativo: ")
            End If

            If (numero <> 0) Then
                numeros.Add(numero)

                actualizar()

                lbxNumeros.DataSource = {}
                lbxNumeros.DataSource = numeros

            End If
        End While


    End Sub

    Private Sub Form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load

    End Sub
End Class
