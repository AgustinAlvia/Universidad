<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()>
Partial Class Form1
    Inherits System.Windows.Forms.Form

    'Form reemplaza a Dispose para limpiar la lista de componentes.
    <System.Diagnostics.DebuggerNonUserCode()>
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Requerido por el Diseñador de Windows Forms
    Private components As System.ComponentModel.IContainer

    'NOTA: el Diseñador de Windows Forms necesita el siguiente procedimiento
    'Se puede modificar usando el Diseñador de Windows Forms.  
    'No lo modifique con el editor de código.
    <System.Diagnostics.DebuggerStepThrough()>
    Private Sub InitializeComponent()
        Me.txtVarn = New System.Windows.Forms.TextBox()
        Me.txtVarx = New System.Windows.Forms.TextBox()
        Me.lblVarn = New System.Windows.Forms.Label()
        Me.lblVarX = New System.Windows.Forms.Label()
        Me.btnCalcular = New System.Windows.Forms.Button()
        Me.SuspendLayout()
        '
        'txtVarn
        '
        Me.txtVarn.Location = New System.Drawing.Point(34, 51)
        Me.txtVarn.Name = "txtVarn"
        Me.txtVarn.Size = New System.Drawing.Size(100, 20)
        Me.txtVarn.TabIndex = 0
        '
        'txtVarx
        '
        Me.txtVarx.Location = New System.Drawing.Point(34, 77)
        Me.txtVarx.Name = "txtVarx"
        Me.txtVarx.Size = New System.Drawing.Size(100, 20)
        Me.txtVarx.TabIndex = 1
        '
        'lblVarn
        '
        Me.lblVarn.AutoSize = True
        Me.lblVarn.Location = New System.Drawing.Point(13, 51)
        Me.lblVarn.Name = "lblVarn"
        Me.lblVarn.Size = New System.Drawing.Size(16, 13)
        Me.lblVarn.TabIndex = 2
        Me.lblVarn.Text = "n:"
        '
        'lblVarX
        '
        Me.lblVarX.AutoSize = True
        Me.lblVarX.Location = New System.Drawing.Point(12, 80)
        Me.lblVarX.Name = "lblVarX"
        Me.lblVarX.Size = New System.Drawing.Size(15, 13)
        Me.lblVarX.TabIndex = 3
        Me.lblVarX.Text = "x:"
        '
        'btnCalcular
        '
        Me.btnCalcular.Location = New System.Drawing.Point(58, 124)
        Me.btnCalcular.Name = "btnCalcular"
        Me.btnCalcular.Size = New System.Drawing.Size(75, 23)
        Me.btnCalcular.TabIndex = 4
        Me.btnCalcular.Text = "Calcular"
        Me.btnCalcular.UseVisualStyleBackColor = True
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(284, 261)
        Me.Controls.Add(Me.btnCalcular)
        Me.Controls.Add(Me.lblVarX)
        Me.Controls.Add(Me.lblVarn)
        Me.Controls.Add(Me.txtVarx)
        Me.Controls.Add(Me.txtVarn)
        Me.Name = "Form1"
        Me.Text = "Form1"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

    Friend WithEvents txtVarn As TextBox
    Friend WithEvents txtVarx As TextBox
    Friend WithEvents lblVarn As Label
    Friend WithEvents lblVarX As Label



    Friend WithEvents btnCalcular As Button

    Private Sub btnCalcular_Click(sender As Object, e As EventArgs) Handles btnCalcular.Click
        calcular(txtVarx.Text, txtVarn.Text)
    End Sub
End Class
