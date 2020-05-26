#ifndef PELICULA_H
#define PELICULA_H
#include "Autor.h"

class Pelicula{
    private:
        char nombre[100];
        int year;
        Autor autor;
        char genero[100];
        char productora[100];
        char minutos[100];
        int pres;
    public:
        Pelicula();
        Pelicula(char[],int,Autor,char[],char[],char[],int);
        void toStringA();
        void change();
        void estatus();
        void toString();
        void showN();
        int gete();
};

#endif // PELICULA_H
