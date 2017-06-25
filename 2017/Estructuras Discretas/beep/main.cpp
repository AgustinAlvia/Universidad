#include <iostream>
#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <windows.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int notaSonido[]={1046, 1109, 1175, 1244, 1328, 1397,1480,1568,1661,1760,1865,1975,2093,2217,2349,2489,2637,2794,2960,3136,3322,3520,3729,3951};

int main(int argc, char** argv) {
	int i;
	for( i = 0; i < sizeof(notaSonido)/sizeof(int); i++){
		Beep(notaSonido[i], 1000);
	}
	return 0;
}
