#include <iostream>
#include <cstdlib>
#include "funciones2.h"
using namespace std;

int main()
{

    FILE *F = NULL;
    FILE *F1 = NULL;
    FILE *F2 = NULL;
    char archivo[] = "Discos";
    char modowb[] = "wb";
    char modorb[] = "rb";
    for (;;)
    {
        switch (menuPrincipal())
        {
        case '1':
            inicializar(F, archivo, modowb);
            system("cls");
            break;
        case '2':
            (ingresar(F));
            system("cls");
            break;
        case '3':
            switch (menuBusqueda())
            {
            case '1':
                system("cls");
                consulta(F);
                system("cls");
                break;
            case '2':
                break;
            case '3':
                system("cls");
                consultaC(F);
                system("cls");
                break;
            case '0':
                menuPrincipal();
            }
            system("cls");
            break;
        case '4':
            consulta_total(F, archivo, modorb);
            system("cls");
            break;
        case '5':
            modificar(F);
            system("cls");
            break;
        case '0':
            exit(0);
        }
    }
    return 0;
}

