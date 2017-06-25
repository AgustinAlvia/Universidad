#include <iostream>
#include <windows.h>

	//conjunto de notas
	char  notas[12][2] = {{'C', '\0'}, {'C', '#'}, {'D', '\0'}, {'D', '#'}, {'E', '\0'},{'F', '\0'},{'F', '#'}, {'G'}, {'G', '#'},{'A', '\0'},{'A', '#'},{'B', '\0'}};
	int notaSonido[]={1046, 1109, 1175, 1244, 1328, 1397,1480,1568,1661,1760,1865,1975,2093,2217,2349,2489,2637,2794,2960,3136,3322,3520,3729,3951};

	//sucesiones
	int escalaMayor[] = {0, 2, 2, 1, 2, 2, 2, 1};
    int escalaPentatonica[] = {0, 2, 2, 3, 2, 3};
    int escalaBlues[] =  {0, 2, 1, 1, 3, 2, 3};
    int escalaMenor[] = {0, 2, 1, 2, 2, 1, 2, 2};


	void imprimirEscala(int notaBase, int  *escala, int cantidadDeNotas){
		int i, sucesion = notaBase;
    	for(i = 0; i < cantidadDeNotas ; i++){
    		sucesion = (sucesion + escala[i])%12;
    		Beep(notaSonido[sucesion], 500);
    		printf("%c%c ", notas[sucesion][0],notas[sucesion][1]);
		}
    	
	}  


int main(int argc, char** argv) {
		int notaBase;
		int escala;
	
   		printf("NOTAS BASE: \n");
   		printf(" 0 C\n 1 C#\n 2 D\n 3 D#\n 4 E\n 5 F\n 6 F#\n 7 G\n 8 G#\n 9 A\n10 A#\n11 B\n ");
   		printf("Ingrese la nota base:");
   		scanf("%i", &notaBase);
   		
   		
   		printf("\nESCALAS\n");
   		printf("0. ESCALA MAYOR\n");
   		printf("1. ESCALA MENOR\n");
   		printf("2. ESCALA PENTATONICA\n");
   		printf("3. ESCALA BLUES\n");
   		printf("Ingrese la escala: ");
   		scanf("%i", &escala);
   		printf("\n");
   		
   		switch(escala){
   			case 0: 
   			printf("ESCALA MAYOR DE %c%c", notas[notaBase][0], notas[notaBase][1]);
   			printf("\n");
   			imprimirEscala(notaBase, escalaMayor, sizeof(escalaMayor)/sizeof(int));
	    	printf("\n");
	    	break;
	    	case 1: 
   			printf("ESCALA MENOR DE %c%c", notas[notaBase][0], notas[notaBase][1]);
   			printf("\n");
	    	imprimirEscala(notaBase, escalaMenor, sizeof(escalaMenor)/sizeof(int));
	    	printf("\n");
	    	break;
	    	case 2: 
   			printf("ESCALA PENTATONICA DE %c%c", notas[notaBase][0], notas[notaBase][1]);
   			printf("\n");
	    	imprimirEscala(notaBase, escalaPentatonica, sizeof(escalaPentatonica)/sizeof(int));
	    	printf("\n");
	    	break;
	    	case 3: 
   			printf("ESCALA BLUES DE %c%c", notas[notaBase][0], notas[notaBase][1]);
   			printf("\n");
	    	imprimirEscala(notaBase, escalaBlues, sizeof(escalaBlues)/sizeof(int));
	    	printf("\n");
	    	break;

   			default:
   				printf("Opcion incorrecta");
   			
		   }
	    
	    
	    

	    
	      

	return 0;
}
