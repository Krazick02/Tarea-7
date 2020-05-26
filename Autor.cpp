#include "Autor.h"
#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace std;
Autor::Autor(){

}

Autor::Autor(char nombre[100],char nacionalidad[100]){
    strcpy(this->nombre,nombre);
    strcpy(this->nacionalidad,nacionalidad);
}

void Autor::toString(){
    cout<<"=====INFORMACION DEL DIRECTOR=====\n";
    cout<<"Nombre :"<<this->nombre<<endl;
    cout<<"Nacionalidad :"<<this->nacionalidad<<endl;
    cout<<endl;
    cout<<endl;
}
