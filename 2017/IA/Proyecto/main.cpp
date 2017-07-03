// Plantilla de Arbol Binario de Búsqueda en C++
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







//Árbol
class ArbolABB {
  private:

   // Punteros de la lista, para cabeza y nodo actual:
   Nodo *raiz;
   Nodo *actual;
   int contador;
   int altura;
	friend class pila;
  public:
   // Constructor y destructor básicos:
   ArbolABB() : raiz(NULL), actual(NULL) {}
   ~ArbolABB() { Podar(raiz); }
   // Insertar en árbol ordenado:
   void Insertar(const int dat);
   // Borrar un elemento del árbol:
   void Borrar(const int dat);
   // Función de búsqueda:
   bool Buscar(const int dat);
   //Functión Búsqueda iterativa
   void busquedaIterativa(int dato);
   // Comprobar si el árbol está vacío:
   bool Vacio(Nodo *r) { return r==NULL; }
   // Comprobar si es un nodo hoja:
   bool EsHoja(Nodo *r) { return !r->derecho && !r->izquierdo; }
   // Contar número de nodos:
   const int NumeroNodos();
   const int AlturaArbol();
   // Calcular altura de un int:
   int Altura(const int dat);
   // Devolver referencia al int del nodo actual:
   int &ValorActual() { return actual->dato; }
   // Moverse al nodo raiz:
   void Raiz() { actual = raiz; }
   // Aplicar una función a cada elemento del árbol:
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

// Insertar un int en el árbol ABB
void ArbolABB::Insertar(const int dat)
{
   Nodo *padre = NULL;

   actual = raiz;
   // Buscar el int en el árbol, manteniendo un puntero al nodo padre
   while(!Vacio(actual) && dat != actual->dato) {
      padre = actual;
      if(dat > actual->dato) actual = actual->derecho;
      else if(dat < actual->dato) actual = actual->izquierdo;
   }

   // Si se ha encontrado el elemento, regresar sin insertar
   if(!Vacio(actual)) return;
   // Si padre es NULL, entonces el árbol estaba vacío, el nuevo nodo será
   // el nodo raiz
   if(Vacio(padre)) raiz = new Nodo(dat);
   // Si el int es menor que el que contiene el nodo padre, lo insertamos
   // en la rama izquierda
   else if(dat < padre->dato) padre->izquierdo = new Nodo(dat);
   // Si el int es mayor que el que contiene el nodo padre, lo insertamos
   // en la rama derecha
   else if(dat > padre->dato) padre->derecho = new Nodo(dat);
}

// Eliminar un elemento de un árbol ABB
void ArbolABB::Borrar(const int dat)
{
   Nodo *padre = NULL;
   Nodo *nodo;
   int aux;

   actual = raiz;
   // Mientras sea posible que el valor esté en el árbol
   while(!Vacio(actual)) {
      if(dat == actual->dato) { // Si el valor está en el nodo actual
         if(EsHoja(actual)) { // Y si además es un nodo hoja: lo borramos
            if(padre) // Si tiene padre (no es el nodo raiz)
               // Anulamos el puntero que le hace referencia
               if(padre->derecho == actual) padre->derecho = NULL;
               else if(padre->izquierdo == actual) padre->izquierdo = NULL;
            delete actual; // Borrar el nodo
            actual = NULL;
            return;
         }
         else { // Si el valor está en el nodo actual, pero no es hoja
            // Buscar nodo
            padre = actual;
            // Buscar nodo más izquierdo de rama derecha
            if(actual->derecho) {
               nodo = actual->derecho;
               while(nodo->izquierdo) {
                  padre = nodo;
                  nodo = nodo->izquierdo;
               }
            }
            // O buscar nodo más derecho de rama izquierda
            else {
               nodo = actual->izquierdo;
               while(nodo->derecho) {
                  padre = nodo;
                  nodo = nodo->derecho;
               }
            }
            // Intercambiar valores de no a borrar u nodo encontrado
            // y continuar, cerrando el bucle. El nodo encontrado no tiene
            // por qué ser un nodo hoja, cerrando el bucle nos aseguramos
            // de que sólo se eliminan nodos hoja.
            aux = actual->dato;
            actual->dato = nodo->dato;
            nodo->dato = aux;
            actual = nodo;
         }
      }
      else { // Todavía no hemos encontrado el valor, seguir buscándolo
         padre = actual;
         if(dat > actual->dato) actual = actual->derecho;
         else if(dat < actual->dato) actual = actual->izquierdo;
      }
   }
}

// Recorrido de árbol en inorden, aplicamos la función func, que tiene
// el prototipo:
// void func(int&);
void ArbolABB::InOrden(void (*func)(int&) , Nodo *nodo, bool r)
{
   if(r) nodo = raiz;
   if(nodo->izquierdo) InOrden(func, nodo->izquierdo, false);
   func(nodo->dato);
   if(nodo->derecho) InOrden(func, nodo->derecho, false);
}

// Recorrido de árbol en preorden, aplicamos la función func, que tiene
// el prototipo:
// void func(int&);
void ArbolABB::PreOrden(void (*func)(int&), Nodo *nodo, bool r)
{
   if(r) nodo = raiz;
   func(nodo->dato);
   if(nodo->izquierdo) PreOrden(func, nodo->izquierdo, false);
   if(nodo->derecho) PreOrden(func, nodo->derecho, false);
}

// Recorrido de árbol en postorden, aplicamos la función func, que tiene
// el prototipo:
// void func(int&);
void ArbolABB::PostOrden(void (*func)(int&), Nodo *nodo, bool r)
{
   if(r) nodo = raiz;
   if(nodo->izquierdo) PostOrden(func, nodo->izquierdo, false);
   if(nodo->derecho) PostOrden(func, nodo->derecho, false);
   func(nodo->dato);
}

// Buscar un valor en el árbol
bool ArbolABB::Buscar(const int dat)
{
   actual = raiz;

   // Todavía puede aparecer, ya que quedan nodos por mirar
   while(!Vacio(actual)) {
      if(dat == actual->dato) return true; // int encontrado
      else if(dat > actual->dato) actual = actual->derecho; // Seguir
      else if(dat < actual->dato) actual = actual->izquierdo;
   }
   return false; // No está en árbol
}

// Calcular la altura del nodo que contiene el int dat
int ArbolABB::Altura(const int dat)
{
   int altura = 0;
   actual = raiz;

   // Todavía puede aparecer, ya que quedan nodos por mirar
   while(!Vacio(actual)) {
      if(dat == actual->dato) return altura; // int encontrado
      else {
         altura++; // Incrementamos la altura, seguimos buscando
         if(dat > actual->dato) actual = actual->derecho;
         else if(dat < actual->dato) actual = actual->izquierdo;
      }
   }
   return -1; // No está en árbol
}

// Contar el número de nodos
const int ArbolABB::NumeroNodos()
{
   contador = 0;

   auxContador(raiz); // FUnción auxiliar
   return contador;
}

// Función auxiliar para contar nodos. Función recursiva de recorrido en
//   preorden, el proceso es aumentar el contador
void ArbolABB::auxContador(Nodo *nodo)
{
   contador++;  // Otro nodo
   // Continuar recorrido
   if(nodo->izquierdo) auxContador(nodo->izquierdo);
   if(nodo->derecho)   auxContador(nodo->derecho);
}

// Calcular la altura del árbol, que es la altura del nodo de mayor altura.
const int ArbolABB::AlturaArbol()
{
   altura = 0;

   auxAltura(raiz, 0); // Función auxiliar
   return altura;
}

// Función auxiliar para calcular altura. Función recursiva de recorrido en
// postorden, el proceso es actualizar la altura sólo en nodos hojas de mayor
// altura de la máxima actual
void ArbolABB::auxAltura(Nodo *nodo, int a)
{
   // Recorrido postorden
   if(nodo->izquierdo) auxAltura(nodo->izquierdo, a+1);
   if(nodo->derecho)   auxAltura(nodo->derecho, a+1);
   // Proceso, si es un nodo hoja, y su altura es mayor que la actual del
   // árbol, actualizamos la altura actual del árbol
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




// Función de prueba para recorridos del árbol
void Mostrar(int &d)
{
   cout << d << ",";
}

int main()
{
   // Un árbol de enteros
   ArbolABB ArbolInt;

   // Inserción de nodos en árbol:
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

   // Mostrar el árbol en tres ordenes distintos:
   cout << "InOrden: ";
   ArbolInt.InOrden(Mostrar);
   cout << endl;
   cout << "PreOrden: ";
   ArbolInt.PreOrden(Mostrar);
   cout << endl;
   cout << "PostOrden: ";
   ArbolInt.PostOrden(Mostrar);
   cout << endl;
	

   // Veamos algunos parámetros
   cout << "N nodos: " << ArbolInt.NumeroNodos() << endl;
   cout << "Altura de 1 " << ArbolInt.Altura(75) << endl;
   cout << "Altura de 10 " << ArbolInt.Altura(10) << endl;
   cout << "Altura de arbol " << ArbolInt.AlturaArbol() << endl;
   ArbolInt.busquedaIterativa(95);
   

   cin.get();
   return 0;
}
