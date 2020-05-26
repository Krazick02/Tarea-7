#include "Usuario.h"
# include <iostream>
# include <cstring>
using namespace std;
Usuario::Usuario(){
    //ctor
}

Usuario::Usuario(char nombre[100],char apellido[100],int edad,int act){
    strcpy(this->nombre,nombre);
    strcpy(this->apellido,apellido);
    this->edad=edad;
    this->act=act;
}

void Usuario::toString(){
    cout<<"======INFORMACION DEL USUARIO======\n\n";
    cout<<"Nombre :"<<this->nombre;
    cout<<"\nApellido :"<<this->apellido;
    cout<<"\nEdad :"<<this->edad<<endl;
}

void Usuario::no(){
    cout<<".-"<<this->nombre<<endl;
}

void Usuario::mas(){
    this->act++;
}
void Usuario::menos(){
    this->act--;
}
int Usuario::gete(){
    return this->act;
}
