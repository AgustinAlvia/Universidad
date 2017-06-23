<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Form1
    Inherits System.Windows.Forms.Form

    'Form reemplaza a Dispose para limpiar la lista de componentes.
    <System.Diagnostics.DebuggerNonUserCode()> _
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
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.lbxNumeros = New System.Windows.Forms.ListBox()
        Me.btnEjecutar = New System.Windows.Forms.Button()
        Me.lblMayor = New System.Windows.Forms.Label()
        Me.lblMenor = New System.Windows.Forms.Label()
        Me.lblMedio = New System.Windows.Forms.Label()
        Me.SuspendLayout()
        '
        'lbxNumeros
        '
        Me.lbxNumeros.FormattingEnabled = True
        Me.lbxNumeros.Location = New System.Drawing.Point(74, 71)
        Me.lbxNumeros.Name = "lbxNumeros"
        Me.lbxNumeros.Size = New System.Drawing.Size(120, 95)
        Me.lbxNumeros.TabIndex = 0
        '
        'btnEjecutar
        '
        Me.btnEjecutar.Location = New System.Drawing.Point(12, 12)
        Me.btnEjecutar.Name = "btnEjecutar"
        Me.btnEjecutar.Size = New System.Drawing.Size(75, 23)
        Me.btnEjecutar.TabIndex = 1
        Me.btnEjecutar.Text = "Ejecutar"
        Me.btnEjecutar.UseVisualStyleBackColor = True
        '
        'lblMayor
        '
        Me.lblMayor.AutoSize = True
        Me.lblMayor.Location = New System.Drawing.Point(12, 181)
        Me.lblMayor.Name = "lblMayor"
        Me.lblMayor.Size = New System.Drawing.Size(39, 13)
        Me.lblMayor.TabIndex = 2
        Me.lblMayor.Text = "Label1"
        '
        'lblMenor
        '
        Me.lblMenor.AutoSize = True
        Me.lblMenor.Location = New System.Drawing.Point(71, 181)
        Me.lblMenor.Name = "lblMenor"
        Me.lblMenor.Size = New System.Drawing.Size(39, 13)
        Me.lblMenor.TabIndex = 3
        Me.lblMenor.Text = "Label2"
        '
        'lblMedio
        '
        Me.lblMedio.AutoSize = True
        Me.lblMedio.Location = New System.Drawing.Point(128, 181)
        Me.lblMedio.Name = "lblMedio"
        Me.lblMedio.Size = New System.Drawing.Size(39, 13)
        Me.lblMedio.TabIndex = 4
        Me.lblMedio.Text = "Label3"
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(284, 261)
        Me.Controls.Add(Me.lblMedio)
        Me.Controls.Add(Me.lblMenor)
        Me.Controls.Add(Me.lblMayor)
        Me.Controls.Add(Me.btnEjecutar)
        Me.Controls.Add(Me.lbxNumeros)
        Me.Name = "Form1"
        Me.Text = "Form1"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

    Friend WithEvents lbxNumeros As ListBox
    Friend WithEvents btnEjecutar As Button
    Friend WithEvents lblMayor As Label
    Friend WithEvents lblMenor As Label
    Friend WithEvents lblMedio As Label
End Class
