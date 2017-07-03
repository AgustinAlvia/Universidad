	 import javax.swing.JOptionPane;
	 import javax.swing.JTable;
	 import javax.swing.table.DefaultTableModel;
	 import javax.swing.*;
	 import java.awt.*;
public class Proyecto2{



	public static void main(String[] args) {
		Viaje[][] objViaje = new Viaje[8][8];
		int opcion=0, subOpcion =0, valor = 0;
		double velocidad, tarifa;
		velocidad = 1200; //km/h
		tarifa = 1.56; //B./
		//distancia en millas
		double[][] distancia = new double[8][8];
		Object[][] auxArr = new Object[8][9];
		distancia[0][1] = 1500;
	    distancia[1][2] = 2000;
	    distancia[1][3] = 1500;
	    distancia[1][4] = 1500;
	    distancia[2][3] = 2000;
	    distancia[5][6] = 1500;
	    distancia[5][1] = 2400;
	    distancia[6][0] = 2000;
	    distancia[6][3] = 1000;
	    distancia[6][7] = 2300;

		int i, j;
		String[] lugar= {"Cocl\u00e9", "Veraguas", "Los Santos", "Chiriqu\u00ed", "Herrera", "Panam\u00e1 ", "Col\u00f3n", "Bocas del Toro"};
		String[] tableHeader = {"", "Cocl\u00e9", "Veraguas", "Los Santos", "Chiriqu\u00ed", "Herrera", "Panam\u00e1 ", "Col\u00f3n", "Bocas del Toro"};
		//inicializamos la matriz
		for (i=0; i<8; i++) {
			for (j=0; j<8; j++) {
				if(distancia[i][j] > 0 ){
					objViaje[i][j] = new Viaje(lugar[i], lugar[j], distancia[i][j], velocidad, tarifa);
				}
			}
		}


		//por aquí viene el menú
		do{
			opcion = Integer.parseInt(JOptionPane.showInputDialog("Aerolinea Saturno S.A.\n\n1. Distancia del viaje en km(menor, mayor o igual)\n2. Tiempo en minutos (menor, mayor o igual\n3.Precio del viaje(menor, mayor o igual)\n4.Todos los destinos y sus precios\n5.Salir"));
			auxArr = new Object[8][9];

			switch(opcion){
				case 1:
				case 2:
				case 3:
				case 4:
					if(opcion != 4){
						subOpcion = Integer.parseInt(JOptionPane.showInputDialog("Eliga\n\n1. Menor\n2. Mayor\n3. Igual"));
						valor = Integer.parseInt(JOptionPane.showInputDialog("Ingrese el valor"));
					}

					for (i=0; i<8; i++) {
						for (j=0; j<8; j++) {
						    if( j==0){
								auxArr[i][j] = lugar[i];
							}

							if(objViaje[i][j] != null){
								if(opcion == 1){
									if(objViaje[i][j].obtenerDistanciaKm() < valor && subOpcion == 1){
										auxArr[i][j+1] = new Double(objViaje[i][j].obtenerDistanciaKm());
									}else if(objViaje[i][j].obtenerDistanciaKm() > valor && subOpcion == 2){
										auxArr[i][j+1] = new Double(objViaje[i][j].obtenerDistanciaKm());
									}else if(objViaje[i][j].obtenerDistanciaKm() == valor && subOpcion == 3){
										auxArr[i][j+1] = new Double(objViaje[i][j].obtenerDistanciaKm());
									}
								}else if(opcion == 2){
									if(objViaje[i][j].obtenerTiempo() < valor && subOpcion == 1){
										auxArr[i][j+1] = new Double(objViaje[i][j].obtenerTiempo());
									}else if(objViaje[i][j].obtenerTiempo() > valor && subOpcion == 2){
										auxArr[i][j+1] = new Double(objViaje[i][j].obtenerTiempo());
									}else if(objViaje[i][j].obtenerTiempo() == valor && subOpcion == 3){
										auxArr[i][j+1] = new Double(objViaje[i][j].obtenerTiempo());
									}								
								}else if(opcion == 3){
									if(objViaje[i][j].obtenerPrecio() < valor && subOpcion == 1){
										auxArr[i][j+1] = new Double(objViaje[i][j].obtenerPrecio());
									}else if(objViaje[i][j].obtenerPrecio() > valor && subOpcion == 2){
										auxArr[i][j+1] = new Double(objViaje[i][j].obtenerPrecio());
									}else if(objViaje[i][j].obtenerPrecio() == valor && subOpcion == 3){
										auxArr[i][j+1] = new Double(objViaje[i][j].obtenerPrecio());
									}								
								}else if(opcion == 4){
									if(objViaje[i][j].obtenerDistanciaKm() > 0){
										auxArr[i][j+1] = new Double(objViaje[i][j].obtenerPrecio());
									}
								}
							}
						}
					}
					JTable table = new JTable(auxArr, tableHeader);
					JScrollPane scrollPane = new JScrollPane(table);
					JFrame frame = new JFrame();
	      			frame.add(scrollPane);
	      			frame.pack();
	      			frame.setVisible(true);		
				break;	
			}
		}while(opcion != 5);

	}
}

class Viaje{
	public String inicio;
	public String destino;
	public double distancia;
	private double velocidad;
	private double tarifa;


	//Constructor
	public Viaje(String inicio, String destino, double distancia, double velocidad, double tarifa){
		this.inicio = inicio;
		this.destino = destino;
		this.distancia = distancia;
		this.velocidad = velocidad;
		this.tarifa = tarifa;
	}


	//retorna la distancia en kilometros
	public double obtenerDistanciaKm(){
		return this.distancia * 1.60934;
	}


	//retorna el tiempo en minutos
	public double obtenerTiempo(){	
		return this.obtenerDistanciaKm() / this.velocidad * 60;
	}

	//retorna el precio;
	public double obtenerPrecio(){
		return this.obtenerTiempo() * this.tarifa;
	}


}