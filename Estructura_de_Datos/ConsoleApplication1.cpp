#include <iostream>
#include <cstdlib>
#include "funciones2.h"
using namespace std;

int main(){
 
 	FILE* F=NULL;
    FILE* F1 = NULL;
    FILE* F2 = NULL;
    char archivo[] = "Discos";
    char modowb[] = "wb"; 
    char modorb[] = "rb";
	int n;	
    for (;;) {
        switch (menuPrincipal()) {
        case '1':inicializar(F, archivo, modowb);
            system("cls");
            break;	
        case '2': (ingresar(F));
        	system("cls");
            break;
        case '3': 					
			switch (menuBusqueda()){
        		case '1': 
					system("cls");
					consulta(F);
		            system("cls");
		           	break;
		        case '2': 
		        	consultaG(F);
		        	system("cls");
		           	break;
		        case '3': 
					consultaC(F);
			        system("cls");
		            break;
		        case '0': exit(0);
		        system("cls");
					}
				system("cls");	  
            break;
        case '4': consulta_total(F,archivo,modorb);
        	system("cls");
            break;
        case '5': modificar(F);
        	system("cls");
        
            break;
        case'6':
			n=contarRegistros(F,archivo);
        	ordMezclaDirecta(F, F1, F2, n); //Joyanes
	        system("pause");
	        system("cls");
	        break;
        case '0': exit(0);
        }
    }
    return 0;
}





