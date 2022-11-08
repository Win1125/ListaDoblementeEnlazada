/*******************************************************************************
Descripción: Menu lista doblemente enlazada: Adición, Busqueda, Inserción, Eliminación, Actualización
Autor: Edwin Fandiño Salazar
Fecha: 8/11/2022
Versión: 1.0.0
*******************************************************************************/

//LIBRERÍAS A UTILIZAR
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
	 	<<"\nIngrese un número: ";
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
//---------------------------- FIN CREACIÓN ---------------------------------------------------




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




//-------------------------- MENU ESTADO INSERCCIÓN, ELIMINACIÓN ---------------------------------

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

//-------------------------- FIN MENU ESTADO INSERCCIÓN, ELIMINACIÓN ---------------------------------




//------------------------------------------- INSERCIÓN ------------------------------------------

//Insertar Antes
void insertarAntes(ListaDoble **ls, ListaDoble **nx){
	
	ListaDoble *q=capturarNodo(), *p=NULL, *r=*nx;
	p=*ls;
	
	if(p!=r){
		while(p->sig!=r){
			p=p->sig;
		}
		q->sig=r;
		p->sig=q;
	}else{
		q->sig=p;
		*ls=q;
	}		
}


//Insertar Despues
void insertarDespues(ListaDoble **ls, ListaDoble **nx){
	
	ListaDoble *q=capturarNodo(),*p=NULL, *r=*nx;
	p=*ls;
	
	while(p!=r){
		p=p->sig;
	}
	
	if(p->sig){
		q->sig=p->sig;
	}
		
	p->sig=q;		
}

//Insertar
void insertar(ListaDoble **ls){
	int op=0;
	int nx;
	ListaDoble *dn=NULL, *p=NULL;
	p=*ls;
	do{		
		op=menuEstado(0);
		if(op==1||op==2){
			nx=capturarNumero();
			if(buscarNodo(&p, &dn, nx))
				switch(op){
					case 1: insertarAntes(&p,&dn);break;
					case 2:	insertarDespues(&p,&dn);
				}
		}		
	}while(op!=4);
	*ls=p;
}

//------------------------------------------ FIN INSERCIÓN -----------------------------------------





//------------------------------------------ ELIMINACIÓN -------------------------------------------

void eliminarAntes(ListaDoble **ls, ListaDoble **nx){
	
	ListaDoble *s=NULL, *p=NULL, *r=NULL;
	p=*ls;
	r=*nx;
	
	if(p!=r){	
		if(p->sig==r)			
			*ls=r;						
		else{  
			while(p->sig!=r){		
				s=p;
				p=p->sig;
			}
			s->sig=p->sig;					
		}
		delete p; 
	}else{
		cout<<"No se puede elimianr antes de la cabeza...";
	}
	
	cout<<"\n";
	system("pause");	
}

void eliminarDespues(ListaDoble **ls, ListaDoble **nx){
	
	ListaDoble *q,*p=*ls, *r=*nx;
	
	if(r->sig){
		q=r->sig;
		r->sig=q->sig;
		delete q;
	}else{
		cout<<"\nNo se puede elimianr despues de la cola...";
	}
		
	cout<<"\n";system("pause");	
}

void eliminarRefencia(ListaDoble **ls, ListaDoble **nx){
	
	ListaDoble *p=*ls, *r=*nx;
	
	if(p!=r){
		while(p->sig!=r)p=p->sig;
		p->sig=r->sig;			
	}else{
		*ls=p->sig;	
	}
		
	delete r;
}

void eliminar(ListaDoble **ls){
	
	int op=0;
	int nx;
	ListaDoble *dn=NULL, *p;
	p=*ls;
	
	do{		
		op=menu(1);
		if(op==1||op==2||op==3){
			nx=capNbr();
			if(buscar(&p, &dn, nx)){
				switch(op){
					case 1: 
						eliminarAntes(&p,&dn);
						break;
					case 2:	
						eliminarDespues(&p,&dn);
						break;
					case 3: 
						eliminarReferencia(&p,&dn);
						break;
				}
			}
		}		
	}while(op!=4);
	
	*ls=p;
}

//------------------------------------------ FIN ELIMINACIÓN -----------------------------------------





//------------------------------------------ ACTUALIZACIÓN ------------------------------------------



//------------------------------------------ FIN ACTUALIZACIÓN -----------------------------------------





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
//MENU DE SELECCIÓN
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
int menu(ListaDoble **ls){	

	int opcion;	
	
	ListaDoble *p = *ls;
	
	do{
		opcion=seleccionMenu();
		
		switch(opcion){
			
			case 1:
				//Adición
				system("cls");	
				cout<<"Crear la lista\n";
				crearLista(&p);
				break;
			case 2:
				//Inserción
				system("cls");	
				cout<<"Insertar a la lista\n";
				insertar(&p);
				break;
			case 3:
				//Eliminación
				system("cls");	
				cout<<"Eliminar de la lista\n";
				eliminar(&p);
				break;
			case 4:
				//Actualización
				system("cls");	
				cout<<"Actualizar de la lista\n";
				
				break;
			case 5:
				//Visualización
				system("cls");	
				cout<<"Visualizar la lista\n";
				verLista_Siguiente(p);
				verLista_Anterior(p);
				break;
		}
		
	}while(opcion!=6);
	*ls=p;
}

//---------------------------------------- FIN MENUS ---------------------------------------------





int main(){

	setlocale(LC_ALL, "spanish");
	
	ListaDoble *ls = NULL;
	menu(&ls);
	
	cout<<"\n\n";
	return 0;
}

