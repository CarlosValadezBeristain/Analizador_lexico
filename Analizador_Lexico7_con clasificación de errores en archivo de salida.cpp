#include <windows.h>//libreria utilizada la limpieza de pantalla 
#include <iostream>  //libreria utlizada para imprimir y guardar datos 
#include <locale.h>//libreria utilizada para el idioma del programa 
#include <string.h>//libreria utilizada para  manipular cadenas
#include <conio.h>//libreria para utilizar getch
#include <regex> 
#include <stdio.h>	
//Creadores Jose de Jesus Araiza Rodriguez(Lider), Carlos Ernesto Valadez Beristain, 
//Bryan Josue Flores Gonzales, Julio Leonel Rubio Ramirez, 6°A MATUTINO

using namespace std;
regex esc("(esc|ESC|Esc|ESc|esC|eSC|eSc)");
regex expgen("[a-z0-9.,;:()'+''-''*'/<>=]{1}");//las comillas en el + - * son para que los accepte como caracter
regex palabra("si|no|repite|ir|mientras|para|hacer|esto|resultado|termina|inicio");
regex calfr("^[A-Z][a-z0-9]{1,6}[.]");
regex funcion("(si|no|repite|ir|mientras|para|hacer|esto|resultado|termina|inicio){1}\\s([A-Z][a-z0-9]{1,6}[.])\\s['('][a-z]+[')']");
regex digitoer("[0-9]|[0-9]{2}");
regex letraer("[A-Z]");
regex palabraer("SI|NO|REPITE|IR|MIENTRAS|PARA|HACER|ESTO|RESULTADO|TERMINA|INICIO");
regex calfrer("^[a-z][a-z0-9]{1,6}[.]"); 
regex simber("[.,;:()]{2}");
regex simbariter("['+''-''*'/]{2}");
regex simbreler("[<>=]{2}");
regex funcionMiner("(SI|NO|REPITE|IR|MIENTRAS|PARA|HACER|ESTO|RESULTADO|TERMINA|INICIO){1}\\s([A-Z][a-z0-9]{1,6}[.])\\s['('][a-z]+[')']");
regex funcionMayer("(si|no|repite|ir|mientras|para|hacer|esto|resultado|termina|inicio){1}\\s([a-z][a-z0-9]{1,6}[.])\\s['('][a-z]+[')']");
regex funcionPer("(si|no|repite|ir|mientras|para|hacer|esto|resultado|termina|inicio){1}\\s([A-Z][A-Z0-9]{1,6})\\s['('][a-z]+[')']");


char dato[100],digito[100],letra[100],especial[100],o_aritmetico[100],o_relacion[100],palabra_res[1000],invalido[1000],calf[1000],fun[1000],letrae[1000],palabrae[1000],digitoe[1000],calfe[1000],simbe[1000],simbae[1000],simbree[1000],funcionminee[1000],funcionmayee[1000],funcionpee[1000];
int i=0;
char a;

char menu(void);
void  crear();
void resultados();
void opcIngresar();
void borrarcadenas();
void leer();
void crearAR();
void crearARER();


	main()
	{//inicio main
	
	char opc;
	setlocale(LC_CTYPE,"");//para poner el programa en español

	#define CADENA 1000
	do
	{
	     
		opc=menu();
	
	
		switch(opc)
		{//inicio switch
			
			
			case 59://f1
			
					system("cls"); //limpiar pantalla 
					leer();
					
					break;
					
			
			case 60: //f2
					system("cls");
				    	
					opcIngresar();
					
					break;
					
				
			
			case 27: //ESC
			
				system("cls");
				   printf("Programa Terminado");
						                             
					exit(0);			
			
			default:
				if(opc !=27)
				{
				Beep(500,200);//Pusimos el beep, para evitar que saliera un mensaje de error 	
				}
					break;
			
			
	}//fin switch
		
		
		}while(opc!=27);
			
	return 0;
	
}//fin del main 


char menu()//Identifica la tecla que se presiono en el teclado 
{
	char opc1='\0';
	system("cls");
	printf("Menu\n");//Mostrara el menu 
	printf("[F1] Leer archivo con tokens\n");
	printf("[F2] Ingresar tokens desde consola\n");	
	printf("ESC. Salir\n");
	printf("Seleccione una opcion: ");

	opc1=getch();
	
	if(opc1==0)
	{
		opc1 = getch();
	}
	else if(opc1!=27)
	{
		opc1=-1;
	}
	return opc1;
}

void opcIngresar()	
{
	
	    FILE *archivo = fopen("sobre.txt","w+"); // Modo lectura
		fclose(archivo); 
		remove("resultado_analisis.txt");                    // borrar el original
 		rename("sobre.txt","resultado_analisis.txt");
 		
 		FILE *archivodos = fopen("ERsobre.txt","w+"); // Modo lectura
		fclose(archivodos); 
		remove("Error.txt");                    // borrar el original
 		rename("ERsobre.txt","Error.txt");
 		do{
 			
 			
 			
 			do
				{
					
					printf("\nIntroduce el dato: ");
					fflush(stdin);
					gets(dato);
				
					if(regex_match(dato,esc))
					{
						resultados();
					}
					
					
					if(!regex_match(dato,expgen)&&!regex_match(dato,palabra)&&!regex_match(dato,calfr)&&!regex_match(dato,funcion)&&!regex_match(dato,esc))
					{		

					if(regex_match(dato,digitoer))	
					{
					 strcat(digitoe,dato);  
				     strcat(digitoe," Error <digito>, tiene doble digito");
				     strcat(digitoe,"\n");	
					}
					
					if(regex_match(dato,letraer))	
					{
					 strcat(letrae,dato);  
				     strcat(letrae," Error <letra>, la letra esta en mayuscula");
				     strcat(letrae,"\n");	
					}
					
					if(regex_match(dato,palabraer))	
					{
					 strcat(palabrae,dato);  
				     strcat(palabrae," Error <palabra_res>, la palabra esta en mayuscula");
				     strcat(palabrae,"\n");	
					}
					
					if(regex_match(dato,calfrer))	
					{
					 strcat(calfe,dato);  
				     strcat(calfe," Error <identificador>, primer caracter esta con minuscula");
				     strcat(calfe,"\n");	
					}
					
					if(regex_match(dato,simber))	
					{
					 strcat(simbe,dato);  
				     strcat(simbe," Error <especial>, tiene doble caracter especial");
				     strcat(simbe,"\n");	
					}
					
					if(regex_match(dato,simbariter))	
					{
					 strcat(simbae,dato);  
				     strcat(simbae," Error <o_aritmetico>, tiene doble caracter aritmetico");
				     strcat(simbae,"\n");	
					}
					
					if(regex_match(dato,simbreler))	
					{
					 strcat(simbree,dato);  
				     strcat(simbree," Error <o_relacion>, tiene doble caracter de relacion");
				     strcat(simbree,"\n");	
					}
					
						if(regex_match(dato,funcionMiner))	
					{
					 strcat(funcionminee,dato);  
				     strcat(funcionminee," Error <funcion>, palabra esta en mayuscula");
				     strcat(funcionminee,"\n");	
					}
					
						if(regex_match(dato,funcionMayer))	
					{
					 strcat(funcionmayee,dato);  
				     strcat(funcionmayee," Error <funcion>, primer caracter del identificador esta en minuscula");
				     strcat(funcionmayee,"\n");	
					
					}
					
						if(regex_match(dato,funcionPer))	
					{
					 strcat(funcionpee,dato);  
				     strcat(funcionpee," Error <funcion>, todo el identificador esta en mayuscula ");
				     strcat(funcionpee,"\n");	
					}
					
					
					if(!regex_match(dato,digitoer)&&!regex_match(dato,letraer)&&!regex_match(dato,palabraer)&&!regex_match(dato,calfrer)&&!regex_match(dato,simber)&&!regex_match(dato,simbariter)&&!regex_match(dato,simbreler)&&!regex_match(dato,funcionMiner)&&!regex_match(dato,funcionMayer)&&!regex_match(dato,funcionPer))
					{
					 strcat(invalido,dato);  
				     strcat(invalido," Error desconocido");
				     strcat(invalido,"\n");	
					}		
					
					}
				}while(!regex_match(dato,expgen)&&!regex_match(dato,palabra)&&!regex_match(dato,calfr)&&!regex_match(dato,funcion));				

					 if(regex_match(dato,calfr))
					{
					 strcat(calf,dato);  
				     strcat(calf," <identificador>");
				     strcat(calf,"\n");	

					}
				
					
 				 if(regex_match(dato,palabra))
				{
				 strcat(palabra_res,dato);  
				  strcat(palabra_res," <palabra_res>");
				 strcat(palabra_res,"\n");
				}
				else
				{
							 if(regex_match(dato,funcion))
				{
				 strcat(fun,dato);  
				strcat(fun," <funcion>");
				 strcat(fun,"\n");
				}
				
				else
				{
				  if(dato[0]>=48&&dato[0]<=57)	
				  {
				  	strcat(digito,dato);
				  	strcat(digito," <digito>");
				  	strcat(digito,"\n");	
				  }
				  
				 
				  if(dato[0]>=97&&dato[0]<=122)	
				 {
				  	strcat(letra,dato);
				  	strcat(letra," <letra>");
				  	strcat(letra,"\n");
				  	
				  }
				 
				   if(dato[0]==58||dato[0]==59||dato[0]==44||dato[0]==46||dato[0]==41||dato[0]==40)	
				  {
				  	strcat(especial,dato);
				  	strcat(especial," <especial>");
				  	strcat(especial,"\n");
				  	
				  }
				  
				   if(dato[0]==42||dato[0]==43||dato[0]==45||dato[0]==47)
				   {
				  	strcat(o_aritmetico,dato);
				  	strcat(o_aritmetico," <o_aritmetico>");
				  	strcat(o_aritmetico,"\n");
				  	
				  }	
				  
				  
				   if(dato[0]>=60&&dato[0]<=62)	
				    {
				  	strcat(o_relacion,dato);
				  	strcat(o_relacion," <o_relacion>");
				  	strcat(o_relacion,"\n");
				  	
				  }	
				   	
				}
				}
		
			
				

		 }while(i!=27);
		 
}

void leer()
{
     FILE *archivo3 = fopen("sobre.txt","w+"); // Modo lectura
		fclose(archivo3); 
		remove("resultado_analisis.txt");                    // borrar el original
 		rename("sobre.txt","resultado_analisis.txt");
 		
 		FILE *archivodos = fopen("ERsobre.txt","w+"); // Modo lectura
		fclose(archivodos); 
		remove("Error.txt");                    // borrar el original
 		rename("ERsobre.txt","Error.txt");

		FILE *archivo = fopen("datos.txt", "r"); // Modo lectura
    char dato[CADENA];         // Aquí vamos a ir almacenando cada línea
    while (fgets(dato, CADENA, archivo))
    {
        // Aquí, justo ahora, tenemos ya la línea. Le vamos a remover el salto
        strtok(dato, "\n");
        // La imprimimos, pero realmente podríamos hacer cualquier otra cosa
        
        
        if(regex_match(dato,calfr))
					{
					 strcat(calf,dato);  
				     strcat(calf," <identificador>");
				     strcat(calf,"\n");	

					}
				
					
 				 if(regex_match(dato,palabra))
				{
					
				 strcat(palabra_res,dato);  
				  strcat(palabra_res," <palabra_res>");
				 strcat(palabra_res,"\n");
				}
				else
				{
					if(regex_match(dato,funcion))
				{
				 strcat(fun,dato);  
				  strcat(fun," <funcion>");
				 strcat(fun,"\n");
				}
				else
				{
					if(!regex_match(dato,expgen)&&!regex_match(dato,palabra)&&!regex_match(dato,calfr)&&!regex_match(dato,funcion)&&!regex_match(dato,esc))
					{
									
					 if(regex_match(dato,digitoer))	
					{
					 strcat(digitoe,dato);  
				     strcat(digitoe," Error <digito>, tiene doble digito");
				     strcat(digitoe,"\n");	
					}
					
					if(regex_match(dato,letraer))	
					{
					 strcat(letrae,dato);  
				     strcat(letrae," Error <letra>, la letra esta en mayuscula");
				     strcat(letrae,"\n");	
					}
					
					if(regex_match(dato,palabraer))	
					{
					 strcat(palabrae,dato);  
				     strcat(palabrae," Error <palabra_res>, la palabra esta en mayuscula");
				     strcat(palabrae,"\n");	
					}
					
					if(regex_match(dato,calfrer))	
					{
					 strcat(calfe,dato);  
				     strcat(calfe," Error <identificador>, primer caracter esta con minuscula");
				     strcat(calfe,"\n");	
					}
					
					if(regex_match(dato,simber))	
					{
					 strcat(simbe,dato);  
				     strcat(simbe," Error <especial>, tiene doble caracter especial");
				     strcat(simbe,"\n");	
					}
					
					if(regex_match(dato,simbariter))	
					{
					 strcat(simbae,dato);  
				     strcat(simbae," Error <o_aritmetico>, tiene doble caracter aritmetico");
				     strcat(simbae,"\n");	
					}
					
					if(regex_match(dato,simbreler))	
					{
					 strcat(simbree,dato);  
				     strcat(simbree," Error <o_relacion>, tiene doble caracter de relacion");
				     strcat(simbree,"\n");	
					}
					
						if(regex_match(dato,funcionMiner))	
					{
					 strcat(funcionminee,dato);  
				     strcat(funcionminee," Error <funcion>, palabra esta en mayuscula");
				     strcat(funcionminee,"\n");	
					}
					
						if(regex_match(dato,funcionMayer))	
					{
					 strcat(funcionmayee,dato);  
				     strcat(funcionmayee," Error <funcion>, primer caracter del identificador esta en minuscula");
				     strcat(funcionmayee,"\n");	
					
					}
					
						if(regex_match(dato,funcionPer))	
					{
					 strcat(funcionpee,dato);  
				     strcat(funcionpee," Error <funcion>, todo el identificador esta en mayuscula ");
				     strcat(funcionpee,"\n");	
					}
					
					
					if(!regex_match(dato,digitoer)&&!regex_match(dato,letraer)&&!regex_match(dato,palabraer)&&!regex_match(dato,calfrer)&&!regex_match(dato,simber)&&!regex_match(dato,simbariter)&&!regex_match(dato,simbreler)&&!regex_match(dato,funcionMiner)&&!regex_match(dato,funcionMayer)&&!regex_match(dato,funcionPer))
					{
					 strcat(invalido,dato);  
				     strcat(invalido," Error desconocido");
				     strcat(invalido,"\n");	
					}		
					
					 
					}	
				else
				{
				  if(dato[0]>=48&&dato[0]<=57)	
				  {
				  	strcat(digito,dato);
				  	strcat(digito," <digito>");
				  	strcat(digito,"\n");
				  	
				  }
				  
				 
				  if(dato[0]>=97&&dato[0]<=122)	
				 {
				  	strcat(letra,dato);
				  	strcat(letra," <letra>");
				  	strcat(letra,"\n");
				  	
				  }
				 
				   if(dato[0]==58||dato[0]==59||dato[0]==44||dato[0]==46||dato[0]==41||dato[0]==40)	
				  {
				  	strcat(especial,dato);
				  	strcat(especial," <especial>");
				  	strcat(especial,"\n");
				  	
				  }
				  
				   if(dato[0]==42||dato[0]==43||dato[0]==45||dato[0]==47)
				   {
				  	strcat(o_aritmetico,dato);
				  	strcat(o_aritmetico," <o_aritmetico>");
				  	strcat(o_aritmetico,"\n");
				  	
				  }	
				  
				  
				   if(dato[0]>=60&&dato[0]<=62)	
				    {
				  	strcat(o_relacion,dato);
				  	strcat(o_relacion," <o_relacion>");
				  	strcat(o_relacion,"\n");
				  	
				  }	
				   	
				}
				}
				}
				
    }
		
		
			
				resultados();	
}

void resultados()
{
crearAR(); 
crearARER();
	
SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7);
   printf("%s \n",digito);

SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),2);
   printf("%s \n",letra);
   
SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),8);
   printf("%s  \n",especial);
   
SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),6);
   printf("%s \n",o_aritmetico);

SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),3);
   printf("%s  \n",o_relacion);
  
SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),5); 
   printf("%s\n",palabra_res);
   
SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),9); 
   printf("%s\n",calf);   
   
SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),1); 
   printf("%s\n",fun);      
   
   
system("pause");     
borrarcadenas();
   
SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),15);
 main();

}


void crearAR()
{


		FILE *archivo = fopen("resultado_analisis.txt", "r+"); 
        
   		 fprintf(archivo,digito);
   		 fprintf(archivo,letra);
   		 fprintf(archivo,especial);
   		 fprintf(archivo,o_aritmetico);
   		 fprintf(archivo,o_relacion);
   		 fprintf(archivo,palabra_res);	
         fprintf(archivo,calf);
		 fprintf(archivo,fun);   
		 //fprintf(archivo,invalido);  
         fclose(archivo); 
        
       
}


void crearARER()
{

		FILE *archivodos = fopen("Error.txt", "r+"); 
      
   	
	   	 fprintf(archivodos,digitoe);
   		 fprintf(archivodos,letrae);
   		 fprintf(archivodos,palabrae);
   		 fprintf(archivodos,calfe);
   		 fprintf(archivodos,simbe);
   		 fprintf(archivodos,simbae);	
         fprintf(archivodos,simbree);
		 fprintf(archivodos,funcionminee); 	 
		 fprintf(archivodos,funcionmayee); 	 
		 fprintf(archivodos,funcionpee); 	 
		 fprintf(archivodos,invalido);  
         fclose(archivodos); 
        
       
}

void borrarcadenas()
{

             memset(digito, 0, 100);
             memset(letra, 0, 100);
             memset(especial, 0, 100);
             memset(o_aritmetico, 0, 100);
             memset(o_relacion, 0, 100);
             memset(palabra_res, 0, 1000);
             memset(invalido, 0, 1000);
             memset(calf, 0, 1000);
             memset(fun, 0, 1000);
}
