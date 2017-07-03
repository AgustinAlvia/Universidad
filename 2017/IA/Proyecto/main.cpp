// Plantilla de Arbol Binario de B�squeda en C++
// (C) Abril 2002, Salvador Pozo
// C con Clase: http://c.conclase.net

#include <iostream>
using namespace std;

   //// Clase local de Lista para Nodo de ArbolBinario:
class Nodo {
     public:
      // Constructor:
      Nodo(const int dat, Nodo *izq=NULL, Nodo *der=NULL) :
        dato(dat), izquierdo(izq), derecho(der) {}
      // Miembros:
      int dato;
      int nivel;
      Nodo *izquierdo;
      Nodo *derecho;
};




//Pila
class nodox {
   public:
    nodox(Nodo *v, nodox *sig = NULL){
       valor = v;
       siguiente = sig;
    }

   private:
    Nodo  *valor;
    nodox *siguiente;
        
   friend class pila;
};
 
typedef nodox *pnodox;
 
class pila {
   public:
    pila() : ultimo(NULL) {}
    ~pila();
    
    void Push(Nodo *v);
    Nodo *Pop();

   //private:
    pnodox ultimo;
};
 
pila::~pila()
{
   pnodox aux;
   
   while(ultimo) {
      aux = ultimo;
      ultimo = ultimo->siguiente;
      delete aux;
   }
}

void pila::Push(Nodo *v){
   pnodox nuevo;
 
   /* Crear un nodox nuevo */
   nuevo = new nodox(v, ultimo);
   /* Ahora, el comienzo de nuestra pila es en nuevo nodox */
   ultimo = nuevo;
}

Nodo *pila::Pop(){

   pnodox nodox; /* variable auxiliar para manipular nodox */
   Nodo *v;      /* variable auxiliar para retorno */
   
   if(!ultimo) return 0; /* Si no hay nodoxs en la pila retornamos 0 */
   /* nodox apunta al primer elemento de la pila */
   nodox = ultimo;
   /* Asignamos a pila toda la pila menos el primer elemento */
   ultimo = nodox->siguiente;
   /* Guardamos el valor de retorno */
   v = nodox->valor; 
   /* Borrar el nodox */
   delete nodox;
   return v;
}







//�rbol
class ArbolABB {
  private:

   // Punteros de la lista, para cabeza y nodo actual:
   Nodo *raiz;
   Nodo *actual;
   int contador;
   int altura;
	friend class pila;
  public:
   // Constructor y destructor b�sicos:
   ArbolABB() : raiz(NULL), actual(NULL) {}
   ~ArbolABB() { Podar(raiz); }
   // Insertar en �rbol ordenado:
   void Insertar(const int dat);
   // Borrar un elemento del �rbol:
   void Borrar(const int dat);
   // Funci�n de b�squeda:
   bool Buscar(const int dat);
   //Functi�n B�squeda iterativa
   void busquedaIterativa(int dato);
   // Comprobar si el �rbol est� vac�o:
   bool Vacio(Nodo *r) { return r==NULL; }
   // Comprobar si es un nodo hoja:
   bool EsHoja(Nodo *r) { return !r->derecho && !r->izquierdo; }
   // Contar n�mero de nodos:
   const int NumeroNodos();
   const int AlturaArbol();
   // Calcular altura de un int:
   int Altura(const int dat);
   // Devolver referencia al int del nodo actual:
   int &ValorActual() { return actual->dato; }
   // Moverse al nodo raiz:
   void Raiz() { actual = raiz; }
   // Aplicar una funci�n a cada elemento del �rbol:
   void InOrden(void (*func)(int&) , Nodo *nodo=NULL, bool r=true);
   void PreOrden(void (*func)(int&) , Nodo *nodo=NULL, bool r=true);
   void PostOrden(void (*func)(int&) , Nodo *nodo=NULL, bool r=true);
  private:
   // Funciones auxiliares
   void Podar(Nodo* &);
   void auxContador(Nodo*);
   void auxAltura(Nodo*, int);
};

// Poda: borrar todos los nodos a partir de uno, incluido
void ArbolABB::Podar(Nodo* &nodo)
{
   // Algoritmo recursivo, recorrido en postorden
   if(nodo) {
      Podar(nodo->izquierdo); // Podar izquierdo
      Podar(nodo->derecho);   // Podar derecho
      delete nodo;            // Eliminar nodo
      nodo = NULL;
   }
}

// Insertar un int en el �rbol ABB
void ArbolABB::Insertar(const int dat)
{
   Nodo *padre = NULL;

   actual = raiz;
   // Buscar el int en el �rbol, manteniendo un puntero al nodo padre
   while(!Vacio(actual) && dat != actual->dato) {
      padre = actual;
      if(dat > actual->dato) actual = actual->derecho;
      else if(dat < actual->dato) actual = actual->izquierdo;
   }

   // Si se ha encontrado el elemento, regresar sin insertar
   if(!Vacio(actual)) return;
   // Si padre es NULL, entonces el �rbol estaba vac�o, el nuevo nodo ser�
   // el nodo raiz
   if(Vacio(padre)) raiz = new Nodo(dat);
   // Si el int es menor que el que contiene el nodo padre, lo insertamos
   // en la rama izquierda
   else if(dat < padre->dato) padre->izquierdo = new Nodo(dat);
   // Si el int es mayor que el que contiene el nodo padre, lo insertamos
   // en la rama derecha
   else if(dat > padre->dato) padre->derecho = new Nodo(dat);
}

// Eliminar un elemento de un �rbol ABB
void ArbolABB::Borrar(const int dat)
{
   Nodo *padre = NULL;
   Nodo *nodo;
   int aux;

   actual = raiz;
   // Mientras sea posible que el valor est� en el �rbol
   while(!Vacio(actual)) {
      if(dat == actual->dato) { // Si el valor est� en el nodo actual
         if(EsHoja(actual)) { // Y si adem�s es un nodo hoja: lo borramos
            if(padre) // Si tiene padre (no es el nodo raiz)
               // Anulamos el puntero que le hace referencia
               if(padre->derecho == actual) padre->derecho = NULL;
               else if(padre->izquierdo == actual) padre->izquierdo = NULL;
            delete actual; // Borrar el nodo
            actual = NULL;
            return;
         }
         else { // Si el valor est� en el nodo actual, pero no es hoja
            // Buscar nodo
            padre = actual;
            // Buscar nodo m�s izquierdo de rama derecha
            if(actual->derecho) {
               nodo = actual->derecho;
               while(nodo->izquierdo) {
                  padre = nodo;
                  nodo = nodo->izquierdo;
               }
            }
            // O buscar nodo m�s derecho de rama izquierda
            else {
               nodo = actual->izquierdo;
               while(nodo->derecho) {
                  padre = nodo;
                  nodo = nodo->derecho;
               }
            }
            // Intercambiar valores de no a borrar u nodo encontrado
            // y continuar, cerrando el bucle. El nodo encontrado no tiene
            // por qu� ser un nodo hoja, cerrando el bucle nos aseguramos
            // de que s�lo se eliminan nodos hoja.
            aux = actual->dato;
            actual->dato = nodo->dato;
            nodo->dato = aux;
            actual = nodo;
         }
      }
      else { // Todav�a no hemos encontrado el valor, seguir busc�ndolo
         padre = actual;
         if(dat > actual->dato) actual = actual->derecho;
         else if(dat < actual->dato) actual = actual->izquierdo;
      }
   }
}

// Recorrido de �rbol en inorden, aplicamos la funci�n func, que tiene
// el prototipo:
// void func(int&);
void ArbolABB::InOrden(void (*func)(int&) , Nodo *nodo, bool r)
{
   if(r) nodo = raiz;
   if(nodo->izquierdo) InOrden(func, nodo->izquierdo, false);
   func(nodo->dato);
   if(nodo->derecho) InOrden(func, nodo->derecho, false);
}

// Recorrido de �rbol en preorden, aplicamos la funci�n func, que tiene
// el prototipo:
// void func(int&);
void ArbolABB::PreOrden(void (*func)(int&), Nodo *nodo, bool r)
{
   if(r) nodo = raiz;
   func(nodo->dato);
   if(nodo->izquierdo) PreOrden(func, nodo->izquierdo, false);
   if(nodo->derecho) PreOrden(func, nodo->derecho, false);
}

// Recorrido de �rbol en postorden, aplicamos la funci�n func, que tiene
// el prototipo:
// void func(int&);
void ArbolABB::PostOrden(void (*func)(int&), Nodo *nodo, bool r)
{
   if(r) nodo = raiz;
   if(nodo->izquierdo) PostOrden(func, nodo->izquierdo, false);
   if(nodo->derecho) PostOrden(func, nodo->derecho, false);
   func(nodo->dato);
}

// Buscar un valor en el �rbol
bool ArbolABB::Buscar(const int dat)
{
   actual = raiz;

   // Todav�a puede aparecer, ya que quedan nodos por mirar
   while(!Vacio(actual)) {
      if(dat == actual->dato) return true; // int encontrado
      else if(dat > actual->dato) actual = actual->derecho; // Seguir
      else if(dat < actual->dato) actual = actual->izquierdo;
   }
   return false; // No est� en �rbol
}

// Calcular la altura del nodo que contiene el int dat
int ArbolABB::Altura(const int dat)
{
   int altura = 0;
   actual = raiz;

   // Todav�a puede aparecer, ya que quedan nodos por mirar
   while(!Vacio(actual)) {
      if(dat == actual->dato) return altura; // int encontrado
      else {
         altura++; // Incrementamos la altura, seguimos buscando
         if(dat > actual->dato) actual = actual->derecho;
         else if(dat < actual->dato) actual = actual->izquierdo;
      }
   }
   return -1; // No est� en �rbol
}

// Contar el n�mero de nodos
const int ArbolABB::NumeroNodos()
{
   contador = 0;

   auxContador(raiz); // FUnci�n auxiliar
   return contador;
}

// Funci�n auxiliar para contar nodos. Funci�n recursiva de recorrido en
//   preorden, el proceso es aumentar el contador
void ArbolABB::auxContador(Nodo *nodo)
{
   contador++;  // Otro nodo
   // Continuar recorrido
   if(nodo->izquierdo) auxContador(nodo->izquierdo);
   if(nodo->derecho)   auxContador(nodo->derecho);
}

// Calcular la altura del �rbol, que es la altura del nodo de mayor altura.
const int ArbolABB::AlturaArbol()
{
   altura = 0;

   auxAltura(raiz, 0); // Funci�n auxiliar
   return altura;
}

// Funci�n auxiliar para calcular altura. Funci�n recursiva de recorrido en
// postorden, el proceso es actualizar la altura s�lo en nodos hojas de mayor
// altura de la m�xima actual
void ArbolABB::auxAltura(Nodo *nodo, int a)
{
   // Recorrido postorden
   if(nodo->izquierdo) auxAltura(nodo->izquierdo, a+1);
   if(nodo->derecho)   auxAltura(nodo->derecho, a+1);
   // Proceso, si es un nodo hoja, y su altura es mayor que la actual del
   // �rbol, actualizamos la altura actual del �rbol
   if(EsHoja(nodo) && a > altura) altura = a;
}


void ArbolABB::busquedaIterativa(int dato){
	Nodo *Aux;
	pila Pila;
	int encontrado = 0;
	int nivel = 1;
	float contarNivel = 0;
	
	
  	

	do{
		Pila.Push(raiz);
  	
		printf("\n\nInteration:  %i\n", nivel);
		printf("Se agrega la raiz del arbol a la pila: %i\n", raiz->dato);
		while((encontrado==0 && (Pila.ultimo)) && nivel > contarNivel){
			Aux =Pila.Pop();
			
			printf("\nSe revisa: %i\n", Aux->dato);
			
			if(Aux->dato == dato){
				encontrado = 1;
				printf("El dato %i ha sido encontrado.", dato);
			}else{
				if(!Vacio(Aux->derecho) ){
					printf("Se agrega el hijo derecho de %i a la pila: %i\n", Aux->dato,  Aux->derecho->dato);
					Pila.Push(Aux->derecho);
				}
		
				if(!Vacio(Aux->izquierdo)){
					printf("Se agrega el hijo izquierdo de %i a la pila: %i\n", Aux->dato, Aux->izquierdo->dato);
					Pila.Push(Aux->izquierdo);
				}
				
				
				if(!Vacio(Aux->derecho) || !Vacio(Aux->izquierdo)){
					contarNivel++;	
				}
			}
			
	
			
		}
		contarNivel = 0;
		nivel++;
	}while(encontrado==0 && (Pila.ultimo)); 
	
	if(encontrado ==0){
		printf("Dato %i no encontrado", dato);
	}
		
}




// Funci�n de prueba para recorridos del �rbol
void Mostrar(int &d)
{
   cout << d << ",";
}

int main()
{
   // Un �rbol de enteros
   ArbolABB ArbolInt;

   // Inserci�n de nodos en �rbol:
	ArbolInt.Insertar(75);
	ArbolInt.Insertar(60);	
	ArbolInt.Insertar(87);
	ArbolInt.Insertar(56);
	ArbolInt.Insertar(64);
	ArbolInt.Insertar(58);
	ArbolInt.Insertar(87);
	ArbolInt.Insertar(89);
	ArbolInt.Insertar(95);
	
	
	
   cout << "Altura de arbol " << ArbolInt.AlturaArbol() << endl;

   // Mostrar el �rbol en tres ordenes distintos:
   cout << "InOrden: ";
   ArbolInt.InOrden(Mostrar);
   cout << endl;
   cout << "PreOrden: ";
   ArbolInt.PreOrden(Mostrar);
   cout << endl;
   cout << "PostOrden: ";
   ArbolInt.PostOrden(Mostrar);
   cout << endl;
	

   // Veamos algunos par�metros
   cout << "N nodos: " << ArbolInt.NumeroNodos() << endl;
   cout << "Altura de 1 " << ArbolInt.Altura(75) << endl;
   cout << "Altura de 10 " << ArbolInt.Altura(10) << endl;
   cout << "Altura de arbol " << ArbolInt.AlturaArbol() << endl;
   ArbolInt.busquedaIterativa(95);
   

   cin.get();
   return 0;
}
