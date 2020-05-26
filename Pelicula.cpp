#include "Pelicula.h"
#include "Autor.h"
#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace std;
Pelicula::Pelicula(){

}

Pelicula::Pelicula(char nombre[100],int year,Autor autor,char genero[100],char productora[100],char minutos[100],int pres){
    strcpy(this->nombre,nombre);
    this->year=year;
    this->autor=autor;
    strcpy(this->genero,genero);
    strcpy(this->productora,productora);
    strcpy(this->minutos,minutos);
    this->pres=pres;
}

void Pelicula::toString(){
    cout<<"====INFORMACION DE LA PELICULA====\n";
    cout<<endl;
    cout<<"Nombre :"<<this->nombre<<endl;
    cout<<"Anio :"<<this->year<<endl;
    cout<<"Genero :"<<this->genero<<endl;
    cout<<"Productora :"<<this->productora<<endl;
    cout<<"Duracion :"<<this->minutos<<endl;
    cout<<"Estatus : ";

    if (this->pres==1){
        cout<<"Prestado\n";
    }
    else{
        cout<<"Libre\n";
    }
    cout<<endl;
    autor.toString();
}
void Pelicula::change(){
    char nombre[100];
    int year,op;
    char genero[100];
    char productora[100];
    char minutos[100];
    cout<<"Datos editables \n1.Nombre\n2.Anio\n3.Genero\n4.Productora\n5.Minutos\n";
    cin>>op;
    switch(op){
        case 1:
            cout<<"Ingrese el nuevo nombre de la pelicula\n";
            cin>>nombre;
            strcpy(this->nombre,nombre);
            break;
        case 2:
            cout<<"Ingrese el nuevo anio de la pelicula\n";
            cin>>year;
            this->year=year;
            break;
        case 3:
            cout<<"Ingrese el nuevo genero de la pelicula\n";
            cin>>genero;
            strcpy(this->genero,genero);
            break;
        case 4:
            cout<<"Ingrese la nueva productora de la pelicula\n";
            cin>>productora;
            strcpy(this->productora,productora);
            break;
        case 5:
            cout<<"Ingrese la nueva duracion de la pelicula\n";
            cin>>minutos;
            strcpy(this->minutos,minutos);
            break;
    }
    cout<<"\nCambio realizado con exito "<<endl;
}
void Pelicula::toStringA(){
    autor.toString();
}
void Pelicula::estatus(){
    int c=1,p=0;
    if (this->pres==0){
        this->pres=c;
    }
    else{
        this->pres=p;
    }
}
void Pelicula::showN(){
    cout<<".-"<<this->nombre<<endl;
}
int Pelicula::gete(){
    return this->pres;
}
