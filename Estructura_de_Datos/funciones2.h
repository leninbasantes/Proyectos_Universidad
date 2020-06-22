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

struct  genero {
	char gene1[20] = "Rock";
	char gene2[20] = "Salsa";
	char gene3[20] = "Bachata";
	char gene4[20] = "Romantica";
	char gene5[20] = "Merengue";
	char gene6[20] = "Pop";
	char gene7[30] = "Rock Indie";
	char gene8[20] = "Cumbia";
	
};

struct  discos {
    char artista[50];
    char titulo[50];
    char disquera[50];
    int numCanciones;
    int anio;
    int codigo;
    char tipo_de_genero[50];
};

char validarMenuPr(char opc){
	while((opc!='1')&&(opc!='2')&&(opc!='3')&&(opc!='4')&&(opc!='5')&&(opc!='6')&&(opc!='0')){
		printf("Opcion incorrecta ingrese nuevamente : \n");
		fflush(stdin);
		scanf("%c",&opc);
	}
	return opc;
}

char menuPrincipal(){
	char opc;
	printf("\nBienvenido a la Tienda de Musica Cesarin");
	printf("\n1.- INICIALIZAR ARCHIVO");
	printf("\n2.- INSERTAR DISCO");
	printf("\n3.- BUSCAR DISCO");
	printf("\n4.- IMPRIMIR DISCOS");
	printf("\n5.- MODIFICAR DISCO");
	printf("\n6.- ORDENAMIENTO DE GENERO");
	printf("\n0.- SALIR \n");
	fflush(stdin);
	scanf("%c",&opc);
	opc=validarMenuPr(opc);
	return (opc);
}
int menuGenero(){

	int opc;
	printf("Ingrese el genero que pertencer: ");
        printf("\n1.- Rock : ");
        printf("\n2.- Salsa:"); 
        printf("\n3.- Bachata : ");
        printf("\n4.- Romantica : ");
        printf("\n5.- Merengue : ");
        printf("\n6.- Pop : ");
        printf("\n7.- Rock Indie : ");
        printf("\n8.- Cumbia : ");
		
	fflush(stdin);
	scanf("%d",&opc);
	return (opc);
}

bool buscar(FILE* F, char * artista, discos* datos)
{
    discos aux_datos;
    
    bool esta = false;

    rewind(F);
    if (fread(&aux_datos, sizeof(discos), 1, F) != 1)
        if (!feof(F))
            printf("ERROR de lectura en el archivo.\n");
    while (!feof(F)) {
		if (!strcmp(artista, aux_datos.artista)) {
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
bool buscarG(FILE* F, char * genero, discos* datos)
{
    discos aux_datos;
    
    bool esta = false;

    rewind(F);
    if (fread(&aux_datos, sizeof(discos), 1, F) != 1)
        if (!feof(F))
            printf("ERROR de lectura en el archivo.\n");
    while (!feof(F)) {
    	if (genero!=aux_datos.tipo_de_genero){
       // if (!strcmp(genero, aux_datos.tipo_de_genero)) {
            *datos = aux_datos;
            esta = true;
            break;
        }
        if (fread(&aux_datos, sizeof(genero), 1, F) != 1)
            if (!feof(F))
                printf("ERROR de lectura en el archivo.\n");
    
}

    return esta;
}
bool buscar(FILE* F, int codigo , discos* datos)///////////////////////arregha
{
    discos aux_datos;
    
    bool esta = false;

    rewind(F);
    if (fread(&aux_datos, sizeof(discos), 1, F) != 1)
        if (!feof(F))
            printf("ERROR de lectura en el archivo.\n");
    while (!feof(F)) {
        if (codigo == aux_datos.codigo) {
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
    while ((c != 's') && (c != 'n') && (c != 'S') && (c != 'N')) {
        printf("Incorrecto, ingrese de nuevo: ");
        fflush(stdin);
        scanf("%c", &c);
    }
    return c;
}
FILE* abrir_archivo(char *nom_archivo, char *modo)
{
    FILE* F;
    F=fopen(nom_archivo, modo);

    if (F == NULL) {
        printf("No se puede abrir el archivo %s %s.\n",nom_archivo);
        exit(1);
    }
    return F;
}
void inicializarOrd(FILE* F, char* archivo, char* modo)
{
    
   F = abrir_archivo(archivo, modo);
   fclose(F);
   
}
void inicializar(FILE* F,char *archivo, char *modo)//crear archivos o si existe se borar y se regenera
{
    char c;
	printf("\n\nCrea el archivo %s.\n",archivo);
    printf("La informacion se pierde.\n");
    cout<<"Desea continuar (S/N)? . ";
    fflush(stdin);
	scanf("%c",&c);
	validarSN(c);
	if((c=='s')||(c=='S')){
		F=abrir_archivo(archivo, modo);
	}else{
		fclose(F);
	}	
}
int continuar()
{
    char c;
        printf("\nModificar:\n");
		cout<<"Desea continuar (S/N)? . ";
		fflush(stdin);
		scanf("%c",&c);
	while((c!='s')&&(c!='n')&&(c!='S')&&(c!='N')){
		printf("Incorrecto, ingrese de nuevo: ");
		fflush(stdin);
		scanf("%c",&c);
	}
	if((c=='S')||(c=='s')){
		return 1;
	}
}
int validarFecha(int fecha){
	while((fecha<1900)||(fecha>=2020)){
		printf("Incorrecto ingrese nuevamente :");
		fflush(stdin);
        cin>>fecha;	
	}
	return fecha;
}
int codigoRepetido (FILE* F){
	int aux=1;
	discos datos;
    char archivo[] = "Discos";
    char modo[] = "rb+";
	 F = abrir_archivo(archivo, modo);
	 
	 while(buscar(F,aux,&datos)){
	 	aux=datos.codigo;
	 	aux++;
	 }
	 return aux;
}
void ingresar(FILE* F)
{
    discos datos;
    genero gene;
    char archivo[] = "Discos";
    char modo[] = "rb+";
    printf("\n\nIngreso de datos\n");
    F = abrir_archivo(archivo, modo);
    do {
    	
    	datos.codigo=codigoRepetido(F);
    		  		
    	printf("\nIngrese el Titulo: ");
    	fflush(stdin);
       	cin>>datos.titulo;
        printf("Ingrese la Artista: ");
        fflush(stdin);
        cin>>datos.artista;
        printf("Ingrese la Disquera: ");
        fflush(stdin);
        cin>>datos.disquera;
        printf("Ingrese un anio superio a 1900 y inferior a 2020 : ");
        cin>>datos.anio;
        validarFecha(datos.anio);
        printf("Ingrese el N. de canciones: ");
        fflush(stdin);
        cin>>datos.numCanciones;
            
			switch (menuGenero()) {
		        case 1:
					gene.gene1;
					strcpy(datos.tipo_de_genero,gene.gene1);
		            break;
				case 2:
					gene.gene2;
					strcpy(datos.tipo_de_genero,gene.gene2);
		            break;
		        case 3:
					gene.gene3;
					strcpy(datos.tipo_de_genero,gene.gene3);
					
		            break;
		        case 4:
					gene.gene4;
					strcpy(datos.tipo_de_genero,gene.gene4);
		            break;
		        case 5:
					gene.gene5;
					strcpy(datos.tipo_de_genero,gene.gene5);
		            break;
		        case 6:
					gene.gene6;
					strcpy(datos.tipo_de_genero,gene.gene6);
					
		            break;
		        case 7:
					gene.gene7;
					strcpy(datos.tipo_de_genero,gene.gene7);
		            break;
		        case 8:
					gene.gene8;
					strcpy(datos.tipo_de_genero,gene.gene8);
		            break;
			}
        	
            fseek(F, 0, SEEK_END);
            if (fwrite(&datos, sizeof(discos), 1, F) != 1)
                printf("ERROR de escritura en el archivo.\n");
         
    } while ((continuar)== !true); 
    
    printf("Ingrese el nombre con <ENTER> termina: ");
    
    fclose(F);
}
void mostrar_datos(discos datos)
{
    printf("\nTitulo : %s\n", datos.titulo);
    printf("Artista : %s\n", datos.artista);
    printf("Disquera: %s\n", datos.disquera);
 	printf("Genero: %s\n", datos.tipo_de_genero);
	printf("Anio   : %d\n", datos.anio);
    printf("Numero de canciones: %d\n", datos.numCanciones);
 	printf("Codigo : %d\n", datos.codigo);
 
}
void consulta(FILE* F)
{
    discos datos;
    char Artista[31];
    char archivo[] = "Discos";
    char modo[] = "rb";
    printf("\n\nConsulta de una estructura.\n\n");
    F = abrir_archivo(archivo, modo);
    printf("Ingrese el Artista: ");
    cin>>Artista;
    
    if (buscar(F, Artista , &datos))
        mostrar_datos(datos);
    else
        printf("\nNo se encuentra este artista.\n");
    fclose(F);
    system("pause");
    menuBusqueda();
}
void consultaG(FILE* F)
{
    discos datos;
    char Genero[31];
    char archivo[] = "Discos";
    char modo[] = "rb";
    printf("\n\nConsulta de una estructura.\n\n");
    F = abrir_archivo(archivo, modo);
    printf("Ingrese el Genero: ");
    cin>>Genero;
    
    if (buscarG(F, Genero , &datos))
			mostrar_datos(datos);
    else
        printf("\nNo se encuentra este artista.\n");
    fclose(F);
    system("pause");
    menuBusqueda();
}
void consultaC(FILE* F)
{
    discos datos;
    int codigo;
    char archivo[] = "Discos";
    char modo[] = "rb";
    printf("\n\nConsulta de una estructura.\n\n");
    F = abrir_archivo(archivo, modo);
    printf("Ingrese el Codigo: ");
    cin>>codigo;
    
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
	cin>>opc;
    while((opc!='1')&&(opc!='2')&&(opc!='3')&&(opc!='0')){
    	printf("no valido ingresa de nuevo");
    	fflush(stdin);
		cin>>opc;
	}
	if(opc=='0'){
		menuPrincipal();
	}else
    return opc;   
}
void consulta_total(FILE* F,char *archivo,char *modo)
{
    discos datos;
    int ord = 0;
    printf("\n\nConsulta total de la lista de discos.\n\n");
    F = abrir_archivo(archivo,modo);
    puts("OR titulo         Artista          DISQUERA       ANIO   N. DE CANCIONES   COD		GENERO");
    
    if (fread(&datos, sizeof(discos), 1, F) != 1)
        if (!feof(F))
            printf("ERROR de lectura en el archivo.\n");
    while (!feof(F)) {
        printf("%02d %-15s %-15s %-14s %-14d %-10d %-9d %-8s\n",
            ++ord, datos.titulo, datos.artista, datos.disquera, datos.anio,
            datos.numCanciones,datos.codigo,datos.tipo_de_genero);

        if (ord % 20 == 0) {
            system("pause");
            puts("OR titulo         Artista          DISQUERA       ANIO   N. DE CANCIONES   COD		GENERO");
        }
        if (fread(&datos, sizeof(discos), 1, F) != 1)
            if (!feof(F))
                printf("ERROR de lectura en el archivo.\n");
    }
    fclose(F);
    system("pause");
}
char opcion(char* opciones)
{	
    char s,t;

    printf("Elija una opcion. ");
    do {
        cin>>s;
        s=toupper(s);
    } while (!strchr(opciones, s));
    cout<<s<<endl;
    return s;
}
int validarfecha(FILE* F){
	discos datos;
	char archivo[] = "Discos";
    char modo[] = "rb";
    F = abrir_archivo(archivo, modo);
    printf("\nIngrese un anio  ");
     cin>>datos.anio;
    do {
		if (datos.anio < 1900||datos.anio >=2020) {// revisar 
           
        printf("Ingrese un anio superio a 1900 y inferior a 2020 : ");
        cin>>datos.anio;
        }
        else {
            printf("\nAnio correcto\n\n");
            system("pause");
        }

    } while (datos.anio<1900 ||datos.anio >=2020); 	
	 fclose(F);
	 return datos.anio;
}
void modificar(FILE* F)
{
    int veri;
    genero gene;
	discos datos;
    char artista[31];
    char archivo[] = "Discos";
    char modo[] = "rb+";
    printf("\n\nModifica una estructura.\n\n");
    F = abrir_archivo(archivo, modo);
    printf("Ingrese el Artista: ");
    cin>>artista;

    if (buscar(F, artista, &datos))
        for (;;) {                            /* Para cambiar varios campos. */
            mostrar_datos(datos);
			veri=continuar();
			int opc;
            if (veri==1) {
            	system("cls");
            	printf("\nT : titulo \n");
			    printf("A : artista \n");
			    printf("D : disquera  \n");
			    printf("N : anio  \n");
			    printf("S : numero de canciones \n");
			 	printf("G : genero \n");
                char opciones[] = "TADNSCG";
                switch (opcion(opciones)) {
                case 'T': printf("Ingrese el Titulo   : ");
                    cin>>datos.titulo;
                    break;
                case 'A': printf("Ingrese la artista    : ");
                    cin >>datos.artista;
                    break;
                case 'D': printf("Ingrese la disquera  : ");
                    cin >> datos.disquera;
                    break;
                case 'N':  datos.anio=validarfecha(F);
                    break;
                case 'S': printf("Ingrese el numero de canciones   : ");
                    cin >> datos.numCanciones;
                    break;
                case 'G': 
								
				switch (menuGenero()) {
		        case 1:
					gene.gene1;
					strcpy(datos.tipo_de_genero,gene.gene1);
		            break;
				case 2:
					gene.gene2;
					strcpy(datos.tipo_de_genero,gene.gene2);
		            break;
		        case 3:
					gene.gene3;
					strcpy(datos.tipo_de_genero,gene.gene3);
					
		            break;
		        case 4:
					gene.gene4;
					strcpy(datos.tipo_de_genero,gene.gene4);
		            break;
		        case 5:
					gene.gene5;
					strcpy(datos.tipo_de_genero,gene.gene5);
		            break;
		        case 6:
					gene.gene6;
					strcpy(datos.tipo_de_genero,gene.gene6);
					
		            break;
		        case 7:
					gene.gene7;
					strcpy(datos.tipo_de_genero,gene.gene7);
		            break;
		        case 8:
					gene.gene8;
					strcpy(datos.tipo_de_genero,gene.gene8);
		            break;
			}
                    break;
                }
            }
            else {
                if (fseek(F, ftell(F) - sizeof(discos), SEEK_SET))
                    printf("ERROR de posicionamiento del indicador de posicion.\n");
                if (fwrite(&datos, sizeof(discos), 1, F) != 1)
                    printf("ERROR de lectura en el archivo.\n");
                break;
            }
        }
    else {
        printf("\nNo se encuentra el Artista.\n");
        system("pause");
    }
    fclose(F);
}





////////////////////////////////////////////////////////////////////////////////////////////////////////////////



void ordMezclaDirecta(FILE* F, FILE* F1, FILE* F2, int n) {
    int i, j, lgtud;
    bool sw, fin1, fin2;
    char archivo[] = "Discos";
    char archivo1[] = "F1";
    char archivo2[] = "F2";
    char modo[] = "rb";
    char modo1[] = "wb";
    char modo2[] = "rb+";
    discos datos, datos1, datos2;
    cout << "\nInicia el proceso de ordenamiento: \n";
    system("pause");
    lgtud = 1;
    while (lgtud < n) {
        //PARTICION
        F = abrir_archivo(archivo, modo);
        inicializarOrd(F1, archivo1, modo1);
        inicializarOrd(F2, archivo2, modo1);
        F1 = abrir_archivo(archivo1, modo2);
        F2 = abrir_archivo(archivo2, modo2);
        i = 0;
        sw = true;
        
        if (fread(&datos, sizeof(discos), 1, F) != 1)
            if (!feof(F))
                printf("ERROR de lectura en el archivo.\n");
        while (!feof(F)) {
            if (sw) {
                fseek(F1, 0, SEEK_END);
                if (fwrite(&datos, sizeof(discos), 1, F1) != 1)
                    printf("ERROR de escritura en el archivo.\n");
            }
            else
            {
                fseek(F2, 0, SEEK_END);
                if (fwrite(&datos, sizeof(discos), 1, F2) != 1)
                    printf("ERROR de escritura en el archivo.\n");
            }
            i++;
            if (i == lgtud) {
                sw = !sw;
                i = 0;
            }
            if (fread(&datos, sizeof(discos), 1, F) != 1)
                if (!feof(F))
                    printf("ERROR de lectura en el archivo.\n");
        }
        fclose(F);
        fclose(F1);
        fclose(F2);
        //FUSION
        inicializarOrd(F, archivo, modo1);
        F = abrir_archivo(archivo, modo2);
        F1 = abrir_archivo(archivo1, modo);
        F2 = abrir_archivo(archivo2, modo);
        i = 0;
        j = 0;
        fin1 = false;
        fin2 = false;
        if (fread(&datos1, sizeof(discos), 1, F1) != 1) {
            if (!feof(F1))
                printf("ERROR de lectura en el archivo.\n");
            fin1 = true;
        }
        if (fread(&datos2, sizeof(discos), 1, F2) != 1) {
            if (!feof(F2))
                printf("ERROR de lectura en el archivo.\n");
            fin2 = true;
        }

        while (!fin1 || !fin2) {
            while (!fin1 && !fin2 && i < lgtud && j < lgtud) {
                if (strcmp(datos1.tipo_de_genero,datos2.tipo_de_genero)<0) {
                    if (fwrite(&datos1, sizeof(discos), 1, F) != 1)
                        printf("ERROR de escritura en el archivo.\n");
                    if (fread(&datos1, sizeof(discos), 1, F1) != 1) {
                        if (!feof(F1))
                            printf("ERROR de lectura en el archivo.\n");
                        fin1 = true;
                    }
                    i++; //F2
                }
                else {
                    if (fwrite(&datos2, sizeof(discos), 1, F) != 1)
                        printf("ERROR de escritura en el archivo.\n");
                    if (fread(&datos2, sizeof(discos), 1, F2) != 1) {
                        if (!feof(F2))
                            printf("ERROR de lectura en el archivo.\n");
                        fin2 = true;
                    }
                    j++; //F2
                }
            }
            while (!fin1 && i < lgtud) {
                if (fwrite(&datos1, sizeof(discos), 1, F) != 1)
                    printf("ERROR de escritura en el archivo.\n");
                if (fread(&datos1, sizeof(discos), 1, F1) != 1) {
                    if (!feof(F1))
                        printf("ERROR de lectura en el archivo.\n");
                    fin1 = true;
                }
                i++;
            }
            while (!fin2 && j < lgtud) {
                if (fwrite(&datos2, sizeof(discos), 1, F) != 1)
                    printf("ERROR de escritura en el archivo.\n");
                if (fread(&datos2, sizeof(discos), 1, F2) != 1) {
                    if (!feof(F2))
                        printf("ERROR de lectura en el archivo.\n");
                    fin2 = true;
                }
                j++;
            }
            i = 0;
            j = 0;
        }
        fclose(F);
        fclose(F1);
        fclose(F2);
        lgtud = lgtud * 2;
    }
    cout << "\nProceso de ordenamiento Finalizado. \n";
}


int contarRegistros(FILE* F,char *archivo) {
    discos datos;
    int i = -1;
    char modo[] = "rb";
    F = abrir_archivo(archivo, modo);
    do {
        if (fread(&datos, sizeof(discos), 1, F) != 1)
            if (!feof(F))
                printf("ERROR de lectura en el archivo.\n");
        i++;
    } while (!feof(F));
    fclose(F);
    return i;
}
