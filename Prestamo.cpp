#include "Usuario.h"
#include "Pelicula.h"
#include "Prestamo.h"
#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;

Prestamo::Prestamo(){

}

Prestamo::Prestamo(Usuario usuario,Pelicula obra,char fecha1[100]){
    this->usuario=usuario;
    this->obra=obra;
    strcpy(this->fecha1,fecha1);
}
Prestamo::Prestamo(Usuario usuario,Pelicula obra,char fecha1[100],char fecha2[100],int nu,int np){
    this->usuario=usuario;
    this->obra=obra;
    strcpy(this->fecha1,fecha1);
    strcpy(this->fecha2,fecha2);
    this->nu=nu;
    this->np=np;
}
void Prestamo::alterna(Pelicula p[10],int no){
    char fecha2[100];
    cout<<"Ingrese la fecha de entrega :\n";
    cin>>fecha2;
    p[no].estatus();
    this->obra=p[no];
    strcpy(this->fecha2,fecha2);

}
void Prestamo::toString(){
    cout<<"======== INFORMACION ========\n\n";
    this->usuario.toString();
    this->obra.toString();
    cout<<"Fecha de salida :"<<this->fecha1<<endl;
    cout<<"Fecha de entrega :"<<this->fecha2<<endl;
}
int Prestamo::pelic(){
    return this->np;
}
int Prestamo::usua(){
    return this->nu;
}
