Public Class Rectangulo
    Public ancho As Double
    Public altura As Double

    Public ReadOnly Property area As Double
        Get
            Return ancho * altura
        End Get
    End Property


    Public ReadOnly Property perimetro As Double
        Get
            Return ancho + altura
        End Get
    End Property

    Public ReadOnly Property diagonal
        Get
            Return Math.Sqrt(Math.Pow(ancho, 2) + Math.Pow(altura, 2))
        End Get
    End Property

    'Constructor
    Public Sub New(ByVal _ancho As Double, ByVal _altura As Double)
        ancho = _ancho
        altura = _altura

    End Sub
End Class

Public Class Form1


    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        Dim cantidad, acumulador As Integer
        Dim ancho, altura As Double
        cantidad = InputBox("Ingrese la cantidad de rectangulos")
        Dim objRectangulo(cantidad)


        For i = 1 To cantidad
            ancho = InputBox("Ingrese el ancho del rectangulo " & i)
            altura = InputBox("Ingrese el ancho del rectangulo " & i)
            objRectangulo(i) = New Rectangulo(ancho, altura)

        Next


        For i = 1 To cantidad
            MsgBox("Rectangulo " & i & vbCrLf & "Ancho: " & objRectangulo(i).ancho & vbCrLf & "Altura: " & objRectangulo(i).altura & vbCrLf & "Area: " & objRectangulo(i).area & vbCrLf & "Perímetro: " & objRectangulo(i).perimetro & vbCrLf & "Diagonal: " & objRectangulo(i).diagonal & vbCrLf)
            acumulador += objRectangulo(i).area
        Next

        MsgBox("Suma de las areas: " & acumulador)

    End Sub

    Private Sub Button2_Click(sender As Object, e As EventArgs)

    End Sub
End Class

