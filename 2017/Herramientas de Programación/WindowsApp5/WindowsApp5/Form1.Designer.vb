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
        Me.btnIngresarFor = New System.Windows.Forms.Button()
        Me.lblPar = New System.Windows.Forms.Label()
        Me.lblImpar = New System.Windows.Forms.Label()
        Me.lbxPar = New System.Windows.Forms.ListBox()
        Me.lbxImpar = New System.Windows.Forms.ListBox()
        Me.lblMayorImpar = New System.Windows.Forms.Label()
        Me.lblMenorPar = New System.Windows.Forms.Label()
        Me.lblMenorImpar = New System.Windows.Forms.Label()
        Me.lblSumaPar = New System.Windows.Forms.Label()
        Me.lblSumaImpar = New System.Windows.Forms.Label()
        Me.btnIngresarWhile = New System.Windows.Forms.Button()
        Me.btnIngresarDo = New System.Windows.Forms.Button()
        Me.lblMayorPar = New System.Windows.Forms.Label()
        Me.SuspendLayout()
        '
        'btnIngresarFor
        '
        Me.btnIngresarFor.Location = New System.Drawing.Point(47, 14)
        Me.btnIngresarFor.Name = "btnIngresarFor"
        Me.btnIngresarFor.Size = New System.Drawing.Size(75, 23)
        Me.btnIngresarFor.TabIndex = 1
        Me.btnIngresarFor.Text = "Ingresar(For)"
        Me.btnIngresarFor.UseVisualStyleBackColor = True
        '
        'lblPar
        '
        Me.lblPar.AutoSize = True
        Me.lblPar.Location = New System.Drawing.Point(27, 61)
        Me.lblPar.Name = "lblPar"
        Me.lblPar.Size = New System.Drawing.Size(34, 13)
        Me.lblPar.TabIndex = 2
        Me.lblPar.Text = "Pares"
        '
        'lblImpar
        '
        Me.lblImpar.AutoSize = True
        Me.lblImpar.Location = New System.Drawing.Point(242, 61)
        Me.lblImpar.Name = "lblImpar"
        Me.lblImpar.Size = New System.Drawing.Size(44, 13)
        Me.lblImpar.TabIndex = 3
        Me.lblImpar.Text = "Impares"
        '
        'lbxPar
        '
        Me.lbxPar.FormattingEnabled = True
        Me.lbxPar.Location = New System.Drawing.Point(27, 86)
        Me.lbxPar.Name = "lbxPar"
        Me.lbxPar.Size = New System.Drawing.Size(120, 95)
        Me.lbxPar.TabIndex = 4
        '
        'lbxImpar
        '
        Me.lbxImpar.FormattingEnabled = True
        Me.lbxImpar.Location = New System.Drawing.Point(212, 86)
        Me.lbxImpar.Name = "lbxImpar"
        Me.lbxImpar.Size = New System.Drawing.Size(120, 95)
        Me.lbxImpar.TabIndex = 5
        '
        'lblMayorImpar
        '
        Me.lblMayorImpar.AutoSize = True
        Me.lblMayorImpar.Location = New System.Drawing.Point(212, 188)
        Me.lblMayorImpar.Name = "lblMayorImpar"
        Me.lblMayorImpar.Size = New System.Drawing.Size(36, 13)
        Me.lblMayorImpar.TabIndex = 6
        Me.lblMayorImpar.Text = "Mayor"
        '
        'lblMenorPar
        '
        Me.lblMenorPar.AutoSize = True
        Me.lblMenorPar.Location = New System.Drawing.Point(27, 214)
        Me.lblMenorPar.Name = "lblMenorPar"
        Me.lblMenorPar.Size = New System.Drawing.Size(40, 13)
        Me.lblMenorPar.TabIndex = 8
        Me.lblMenorPar.Text = "Menor:"
        '
        'lblMenorImpar
        '
        Me.lblMenorImpar.AutoSize = True
        Me.lblMenorImpar.Location = New System.Drawing.Point(212, 214)
        Me.lblMenorImpar.Name = "lblMenorImpar"
        Me.lblMenorImpar.Size = New System.Drawing.Size(40, 13)
        Me.lblMenorImpar.TabIndex = 9
        Me.lblMenorImpar.Text = "Menor:"
        '
        'lblSumaPar
        '
        Me.lblSumaPar.AutoSize = True
        Me.lblSumaPar.Location = New System.Drawing.Point(24, 239)
        Me.lblSumaPar.Name = "lblSumaPar"
        Me.lblSumaPar.Size = New System.Drawing.Size(37, 13)
        Me.lblSumaPar.TabIndex = 10
        Me.lblSumaPar.Text = "Suma:"
        '
        'lblSumaImpar
        '
        Me.lblSumaImpar.AutoSize = True
        Me.lblSumaImpar.Location = New System.Drawing.Point(215, 239)
        Me.lblSumaImpar.Name = "lblSumaImpar"
        Me.lblSumaImpar.Size = New System.Drawing.Size(37, 13)
        Me.lblSumaImpar.TabIndex = 11
        Me.lblSumaImpar.Text = "Suma:"
        '
        'btnIngresarWhile
        '
        Me.btnIngresarWhile.Location = New System.Drawing.Point(139, 14)
        Me.btnIngresarWhile.Name = "btnIngresarWhile"
        Me.btnIngresarWhile.Size = New System.Drawing.Size(89, 23)
        Me.btnIngresarWhile.TabIndex = 12
        Me.btnIngresarWhile.Text = "Ingresar(While)"
        Me.btnIngresarWhile.UseVisualStyleBackColor = True
        '
        'btnIngresarDo
        '
        Me.btnIngresarDo.Location = New System.Drawing.Point(245, 14)
        Me.btnIngresarDo.Name = "btnIngresarDo"
        Me.btnIngresarDo.Size = New System.Drawing.Size(75, 23)
        Me.btnIngresarDo.TabIndex = 13
        Me.btnIngresarDo.Text = "Ingresar(Do)"
        Me.btnIngresarDo.UseVisualStyleBackColor = True
        '
        'lblMayorPar
        '
        Me.lblMayorPar.AutoSize = True
        Me.lblMayorPar.Location = New System.Drawing.Point(27, 188)
        Me.lblMayorPar.Name = "lblMayorPar"
        Me.lblMayorPar.Size = New System.Drawing.Size(39, 13)
        Me.lblMayorPar.TabIndex = 7
        Me.lblMayorPar.Text = "Mayor:"
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(397, 261)
        Me.Controls.Add(Me.btnIngresarDo)
        Me.Controls.Add(Me.btnIngresarWhile)
        Me.Controls.Add(Me.lblSumaImpar)
        Me.Controls.Add(Me.lblSumaPar)
        Me.Controls.Add(Me.lblMenorImpar)
        Me.Controls.Add(Me.lblMenorPar)
        Me.Controls.Add(Me.lblMayorPar)
        Me.Controls.Add(Me.lblMayorImpar)
        Me.Controls.Add(Me.lbxImpar)
        Me.Controls.Add(Me.lbxPar)
        Me.Controls.Add(Me.lblImpar)
        Me.Controls.Add(Me.lblPar)
        Me.Controls.Add(Me.btnIngresarFor)
        Me.Name = "Form1"
        Me.Text = "Form1"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents btnIngresarFor As Button
    Friend WithEvents lblPar As Label
    Friend WithEvents lblImpar As Label
    Friend WithEvents lbxPar As ListBox
    Friend WithEvents lbxImpar As ListBox
    Friend WithEvents lblMayorImpar As Label
    Friend WithEvents lblMenorPar As Label
    Friend WithEvents lblMenorImpar As Label
    Friend WithEvents lblSumaPar As Label
    Friend WithEvents lblSumaImpar As Label
    Friend WithEvents btnIngresarWhile As Button
    Friend WithEvents btnIngresarDo As Button
    Friend WithEvents lblMayorPar As Label
End Class
