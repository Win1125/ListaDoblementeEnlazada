/*******************************************************************************
Descripci�n: Menu lista doblemente enlazada: Adici�n, Busqueda, Inserci�n, Eliminaci�n, Actualizaci�n
Autor: Edwin Fandi�o Salazar
Fecha: 8/11/2022
Versi�n: 1.0.0
*******************************************************************************/

//LIBRER�AS A UTILIZAR
#include <iostream>
#include <stdlib.h>
#include <locale.h>

using namespace std;


//TDA
class ListaDoble{
	
	public: 
	
		int dato;
		ListaDoble *sig;
		ListaDoble *ant;
		
		ListaDoble(){
			this->dato = 0;
			this->sig=NULL;
			this->ant=NULL;
		}

};

ListaDoble *t, *i, *f;

//Capturar Nodos
ListaDoble *capturarNodo(){
	ListaDoble *ax=new ListaDoble();
	cout<<"\nCaptura de un nuevo nodo\n"
	 	<<"\nIngrese un n�mero: ";
	cin>> ax->dato;
	return ax;
}


//Capturar numeros
int capturarNumero(){
	int ax;
	cout<<"\nCaptura patron de busqueda\n"
		<<"\nIngrese un numero: ";
	cin>>ax;
	return ax;
}



//---------------------------- CREAR LA LISTA ------------------------------------------------------
void crearLista(ListaDoble **ls){
	
	char op='s';
	do{
		t=capturarNodo();
		if(*ls){
			i=*ls;
			while(i->sig){
				i=i->sig;
			}
			f->sig=t;
			t->ant=f;

		}else{
			*ls=t;
		}
		f=t;
		cout<<"\nDesea otro nodo s/n: ";
		cin>>op;
	}while(op!='n');
}
//---------------------------- FIN CREACI�N ---------------------------------------------------




//---------------------------- BUSQUEDA ---------------------------------------------------------------
bool buscarNodo(ListaDoble **ls, ListaDoble **nx, int nb){
	
	ListaDoble *p;
	bool sw=false;
	
	
	if(*ls){
		p=*ls;
		while(p){
			if(nb==p->dato){
				*nx=p; 
				sw=true; 
				break;
			}
			p=p->sig;
		}	
	}
	
	
	if(sw){
		return true;
	}else{
		return false;	
	} 
	
}
//---------------------------- FIN BUSQUEDA ---------------------------------------------------




//-------------------------- MENU ESTADO INSERCCI�N, ELIMINACI�N ---------------------------------

int menuEstado(int x){
	int op;
	system("cls");
	string s1;
	if(x==0){
		s1="Insertar";
	}else{
		s1="Eliminar";
	} 	
		
	cout<<"\nMenu de seleccion\n"
	    <<"1."<<s1<<" antes\n"
	    <<"2."<<s1<<" despues\n";
	    
	if(x==1){
		cout<<"3."<<s1<<" referencia\n";
	}
	
	cout<<"4.Salir\n"
	    <<"\nIngrese la opcion deseada: ";
	cin>>op;
	
	return op;
}

//-------------------------- FIN MENU ESTADO INSERCCI�N, ELIMINACI�N ---------------------------------




//------------------------------------------- INSERCI�N ------------------------------------------



//------------------------------------------ FIN INSERCI�N -----------------------------------------





//------------------------------------------ ELIMINACI�N -------------------------------------------



//------------------------------------------ FIN ELIMINACI�N -----------------------------------------





//------------------------------------------ ACTUALIZACI�N ------------------------------------------



//------------------------------------------ FIN ACTUALIZACI�N -----------------------------------------




//--------------------------------------------- RECORRIDO-----------------------------------------

void verLista_Siguiente(ListaDoble *ls){
	system("cls");
	if(ls){
		cout<<"Lista con siguiente: \n";
		cout<<"\nDatos de la lista\n";
		while(ls){
			cout<<"->"<<ls->dato<<endl;
			ls=ls->sig;
		}
	}else
		cout<<"\nLista vacia...";
	cout<<"\n";
	system("pause");
}

void verLista_Anterior(ListaDoble *ls){
	system("cls");
	
	ls = f;
	
	if(ls){
		cout<<"Lista con anterior: \n";
		cout<<"\nDatos de la lista\n";
		while(ls){
			cout<<"->"<<ls->dato<<endl;
			ls=ls->ant;
		}
	}else
		cout<<"\nLista vacia...";
	cout<<"\n";
	system("pause");
}

//------------------------------------------FIN RECORRIDO-----------------------------------------



// ------------------------------------------- MENUS ----------------------------------------------
//MENU DE SELECCI�N
int seleccionMenu(){
	int op;
	system("cls");	
	cout<<"\nMENU PRINCIPAL\n"
	    <<"1.Crear lista\n"
	    <<"2.Insertar elemento\n"
	    <<"3.Eliminar elemento\n"
		<<"4.Actualizar elemento\n"
		<<"5.Ver lista\n"
		<<"6.Salir\n"
	    <<"\nIngrese la opcion deseada: ";
	cin>>op;
	return op;
}

//VER MENU
int menu(ListaDoble **lista){	

	int opcion;	
	
	ListaDoble *p = *lista;
	
	do{
		opcion=seleccionMenu();
		
		switch(opcion){
			
			case 1:
				//Adici�n
				system("cls");	
				cout<<"Crear la lista\n";
				crearLista(&p);
				break;
			case 2:
				//Inserci�n
				system("cls");	
				cout<<"Insertar a la lista\n";
				
				break;
			case 3:
				//Eliminaci�n
				system("cls");	
				cout<<"Eliminar de la lista\n";
				
				break;
			case 4:
				//Actualizaci�n
				system("cls");	
				cout<<"Actualizar de la lista\n";
				
				break;
			case 5:
				//Visualizaci�n
				system("cls");	
				cout<<"Visualizar la lista\n";
				verLista_Siguiente(p);
				verLista_Anterior(p);
				break;
		}
		
	}while(opcion!=6);
}

//---------------------------------------- FIN MENUS ---------------------------------------------

int main(){

	setlocale(LC_ALL, "spanish");
	
	ListaDoble *lista = NULL;
	menu(&lista);
	
	cout<<"\n\n";
	return 0;
}
