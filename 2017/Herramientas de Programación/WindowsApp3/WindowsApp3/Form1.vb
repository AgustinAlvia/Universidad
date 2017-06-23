
Public Class Form1
    Private Sub btnEjecutar_Click(sender As Object, e As EventArgs) Handles btnEjecutar.Click
        Dim inicio As Integer
        Dim fin As Integer
        Dim ultNum As Integer
        Dim contador As Integer
        Dim acumulador As Integer

        inicio = InputBox("Ingrese el Inicio")
        fin = InputBox("Ingrese el Fin")

        acumulador = inicio
        ultNum = acumulador
        contador = 1
        While (2 * acumulador + 1) < fin
            ultNum = (acumulador + 1)
            acumulador += acumulador + 1
            contador = contador + 1
        End While

        MsgBox("Inicia en: " & inicio & vbCrLf & "Último Número: " & ultNum & vbCrLf & "Para cuando la suma es mayor o igual a: " & fin & vbCrLf & "Sumatoria: " & acumulador & vbCrLf & "Promedio: " & acumulador / contador)



    End Sub
End Class
