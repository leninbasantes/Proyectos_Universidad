#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <conio.h>
#include <cstdlib>

using namespace std;
char menuBusqueda();

struct genero
{
    string gene1 = "Rock";
    string gene2 = "Salsa";
    string gene3 = "Bachata";
    string gene4 = "Romantica";
    string gene5 = "Merengue";
    string gene6 = "Pop";
    string gene7 = "Rock Indie";
    string gene8 = "Cumbia";
    string gene9 = "Otros";
};

struct discos
{
    char artista[50];
    char titulo[50];
    char disquera[50];
    int numCanciones;
    int anio;
    int codigo;
    genero tipo_de_genero;
};

char validarMenuPr(char opc)
{
    while ((opc != '1') && (opc != '2') && (opc != '3') && (opc != '4') && (opc != '5') && (opc != '0'))
    {
        printf("Opcion incorrecta ingrese nuevamente :");
        fflush(stdin);
        scanf("%c", &opc);
    }
    return opc;
}

char menuPrincipal()
{
    char opc;
    printf("\nBienvenido a la Tienda de Musica Cesarin");
    printf("\n1.- INICIALIZAR ARCHIVO");
    printf("\n2.- INSERTAR DISCO");
    printf("\n3.- BUSCAR DISCO");
    printf("\n4.- IMPRIMIR DISCOS");
    printf("\n5.- MODIFICAR DISCO");
    printf("\n0.- SALIR");
    fflush(stdin);
    scanf("%c", &opc);
    opc = validarMenuPr(opc);
    return (opc);
}
bool buscar(FILE *F, char *artista, discos *datos)
{
    discos aux_datos;

    bool esta = false;

    rewind(F);
    if (fread(&aux_datos, sizeof(discos), 1, F) != 1)
        if (!feof(F))
            printf("ERROR de lectura en el archivo.\n");
    while (!feof(F))
    {
        if (!strcmp(artista, aux_datos.artista))
        {
            *datos = aux_datos;
            esta = true;
            break;
        }
        if (fread(&aux_datos, sizeof(discos), 1, F) != 1)
            if (!feof(F))
                printf("ERROR de lectura en el archivo.\n");
    }

    return esta;
}
char validarSN(char c)
{
    while ((c != 's') && (c != 'n') && (c != 'S') && (c != 'N'))
    {
        printf("Incorrecto, ingrese de nuevo: ");
        fflush(stdin);
        scanf("%c", &c);
    }
    return c;
}
FILE *abrir_archivo(char *nom_archivo, char *modo)
{
    FILE *F;
    F = fopen(nom_archivo, modo);

    if (F == NULL)
    {
        printf("No se puede abrir el archivo %s %s.\n", nom_archivo);
        exit(1);
    }
    return F;
}
void inicializar(FILE *F, char *archivo, char *modo) //crear archivos o si existe se borar y se regenera
{
    char c;
    printf("\n\nArchivo Generado %s.\n", archivo);
    // printf("La informacion se pierde.\n");
    cout << "Desea continuar (S/N)? . ";
    fflush(stdin);
    scanf("%c", &c);
    validarSN(c);
    if ((c == 's') || (c == 'S'))
    {
        F = abrir_archivo(archivo, modo);
    }
    else
    {
        fclose(F);
    }
}
bool buscar(FILE *F, int codigo, discos *datos) ///////////////////////arregha
{
    discos aux_datos;

    bool esta = false;

    rewind(F);
    if (fread(&aux_datos, sizeof(discos), 1, F) != 1)
        if (!feof(F))
            printf("ERROR de lectura en el archivo.\n");
    while (!feof(F))
    {
        if (codigo == aux_datos.codigo)
        {
            *datos = aux_datos;
            esta = true;
            break;
        }
        if (fread(&aux_datos, sizeof(discos), 1, F) != 1)
            if (!feof(F))
                printf("ERROR de lectura en el archivo.\n");
    }

    return esta;
}
int continuar()
{
    char c;
    printf("\nModificar:\n");
    cout << "Desea continuar (S/N)? . ";
    fflush(stdin);
    scanf("%c", &c);
    while ((c != 's') && (c != 'n') && (c != 'S') && (c != 'N'))
    {
        printf("Incorrecto, ingrese de nuevo: ");
        fflush(stdin);
        scanf("%c", &c);
    }
    if ((c == 'S') || (c == 's'))
    {
        return 1;
    }
}
int validarFecha(int fecha)
{
    while ((fecha < 1900) || (fecha >= 2020))
    {
        printf("Incorrecto ingrese nuevamente :");
        fflush(stdin);
        cin >> fecha;
    }
    return fecha;
}

void ingresar(FILE *F)
{
    int cod = 1;
    int opc;
    discos datos;
    char archivo[] = "Discos";
    char modo[] = "rb+";
    printf("\n\nIngreso de datos\n");
    F = abrir_archivo(archivo, modo);
    do
    {
        datos.codigo = cod++;
        printf("\nIngrese el Titulo: ");
        fflush(stdin);
        cin >> datos.titulo;
        printf("Ingrese la Artista: ");
        fflush(stdin);
        cin >> datos.artista;
        printf("Ingrese la Disquera: ");
        fflush(stdin);
        cin >> datos.disquera;
        printf("Ingrese un anio superio a 1900 y inferior a 2020 : ");
        cin >> datos.anio;
        validarFecha(datos.anio);
        printf("Ingrese el N. de canciones: ");
        fflush(stdin);
        cin >> datos.numCanciones;

        printf("Ingrese el genero que pertencer: ");
        printf("\n1.- Rock : ");
        printf("\n2.- Bachata : ");
        printf("\n3.- Romantica : ");
        printf("\n4.- Merengue : ");
        printf("\n5.- Pop : ");
        printf("\n6.- Rock Indie : ");
        printf("\n7.- Cumbia : ");
        printf("\n8.- Otros : ");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            cin >> datos.tipo_de_genero.gene1;
            break;
        case 2:
            cin >> datos.tipo_de_genero.gene2;
            break;
        case 3:
            cin >> datos.tipo_de_genero.gene3;
            break;
        case 4:
            cin >> datos.tipo_de_genero.gene4;
            break;
        case 5:
            cin >> datos.tipo_de_genero.gene5;
            break;
        case 6:
            cin >> datos.tipo_de_genero.gene6;
            break;
        case 7:
            cin >> datos.tipo_de_genero.gene7;
            break;
        case 8:
            cin >> datos.tipo_de_genero.gene8;
            break;
        }

        fseek(F, 0, SEEK_END);
        if (fwrite(&datos, sizeof(discos), 1, F) != 1)
            printf("ERROR de escritura en el archivo.\n");

    } while ((continuar) == !true); // arreglar

    printf("Ingrese el nombre con <ENTER> termina: ");

    fclose(F);
}
void mostrar_datos(discos datos)
{
    printf("\nTitulo : %s\n", datos.titulo);
    printf("Artista : %s\n", datos.artista);
    printf("Disquera: %s\n", datos.disquera);
    printf("Anio   : %d\n", datos.anio);
    printf("Numero de canciones: %d\n", datos.numCanciones);
    printf("Codigo : %d\n", datos.codigo);
}
void consulta(FILE *F)
{
    discos datos;
    char Artista[31];
    char archivo[] = "Discos";
    char modo[] = "rb";
    printf("\n\nConsulta de una estructura.\n\n");
    F = abrir_archivo(archivo, modo);
    printf("Ingrese el Artista: ");
    cin >> Artista;

    if (buscar(F, Artista, &datos))
        mostrar_datos(datos);
    else
        printf("\nNo se encuentra este artista.\n");
    fclose(F);
    system("pause");
    menuBusqueda();
}
void consultaC(FILE *F)
{
    discos datos;
    int codigo;
    char archivo[] = "Discos";
    char modo[] = "rb";
    printf("\n\nConsulta de una estructura.\n\n");
    F = abrir_archivo(archivo, modo);
    printf("Ingrese el Codigo: ");
    cin >> codigo;

    if (buscar(F, codigo, &datos))
        mostrar_datos(datos);
    else
        printf("\nNo se encuentra este codigo.\n");
    fclose(F);
    system("pause");
}
char menuBusqueda()
{
    char opc;
    fflush(stdin);
    printf("Busqueda de discos\n\n\n");
    printf("(1) Artista .\n");
    printf("(2) Genero.\n");
    printf("(3) Codigo.\n");
    printf("(0) regresar.\n");

    printf("Elija una opcion. ");
    fflush(stdin);
    scanf("%c", &opc);
    while ((opc != '1') && (opc != '2') && (opc != '3') && (opc != '0'))
    {
        printf("no valido ingresa de nuevo");
        fflush(stdin);
        scanf("%c", &opc);
    }
    if (opc == '0')
    {
        menuPrincipal();
    }
    return opc;
}
void consulta_total(FILE *F, char *archivo, char *modo)
{
    discos datos;
    int ord = 0;
    printf("\n\nConsulta total de la lista de discos.\n\n");
    F = abrir_archivo(archivo, modo);
    puts("OR titulo         Artista          DISQUERA       ANIO   N. DE CANCIONES   COD");

    if (fread(&datos, sizeof(discos), 1, F) != 1)
        if (!feof(F))
            printf("ERROR de lectura en el archivo.\n");
    while (!feof(F))
    {
        printf("%02d %-15s %-15s %-14s %-14d %-10d %-9d\n",
               ++ord, datos.titulo, datos.artista, datos.disquera, datos.anio,
               datos.numCanciones, datos.codigo);

        if (ord % 18 == 0)
        {
            system("pause");
            puts("OR titulo         Artista          DISQUERA       ANIO   N. DE CANCIONES   COD");
        }
        if (fread(&datos, sizeof(discos), 1, F) != 1)
            if (!feof(F))
                printf("ERROR de lectura en el archivo.\n");
    }
    fclose(F);
    system("pause");
}
char opcion(char *opciones)
{
    char s, t;

    printf("Elija una opcion. ");
    do
    {
        cin >> s;
        s = toupper(s);
    } while (!strchr(opciones, s));
    cout << s << endl;
    return s;
}
int validarfecha(FILE *F)
{
    discos datos;
    char archivo[] = "Discos";
    char modo[] = "rb";
    F = abrir_archivo(archivo, modo);
    printf("\nIngrese un anio  ");
    cin >> datos.anio;
    do
    {
        if (datos.anio < 1900 || datos.anio >= 2020)
        { // revisar

            printf("Ingrese un anio superio a 1900 y inferior a 2020 : ");
            cin >> datos.anio;
        }
        else
        {
            printf("\nAnio correcto\n\n");
            system("pause");
        }

    } while (datos.anio < 1900 || datos.anio >= 2020);
    fclose(F);
    return datos.anio;
}
void modificar(FILE *F)
{
    int veri;
    discos datos;
    char artista[31];
    char archivo[] = "Discos";
    char modo[] = "rb+";
    printf("\n\nModifica una estructura.\n\n");
    F = abrir_archivo(archivo, modo);
    printf("Ingrese el Artista: ");
    cin >> artista;

    if (buscar(F, artista, &datos))
        for (;;)
        { /* Para cambiar varios campos. */
            mostrar_datos(datos);
            veri = continuar();
            if (veri == 1)
            {
                system("cls");
                printf("\nT : titulo \n");
                printf("A : artista \n");
                printf("D : disquera  \n");
                printf("N : anio  \n");
                printf("S : numero de canciones \n");
                printf("C : codigo \n");
                char opciones[] = "TADNSC";
                switch (opcion(opciones))
                {
                case 'T':
                    printf("Ingrese el Titulo   : ");
                    cin >> datos.titulo;
                    break;
                case 'A':
                    printf("Ingrese la artista    : ");
                    cin >> datos.artista;
                    break;
                case 'D':
                    printf("Ingrese la disquera  : ");
                    cin >> datos.disquera;
                    break;
                case 'N':
                    datos.anio = validarfecha(F);
                    break;
                case 'S':
                    printf("Ingrese el numero de canciones   : ");
                    cin >> datos.numCanciones;
                    break;
                case 'C':
                    printf("Ingrese el codigo  : ");
                    cin >> datos.codigo;
                    break;
                }
            }
            else
            {
                if (fseek(F, ftell(F) - sizeof(discos), SEEK_SET))
                    printf("ERROR de posicionamiento del indicador de posicion.\n");
                if (fwrite(&datos, sizeof(discos), 1, F) != 1)
                    printf("ERROR de lectura en el archivo.\n");
                break;
            }
        }
    else
    {
        printf("\nNo se encuentra el Artista.\n");
        system("pause");
    }
    fclose(F);
}
