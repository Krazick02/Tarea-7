#ifndef PRESTAMO_H
#define PRESTAMO_H
#include "Usuario.h"
#include "Pelicula.h"

class Prestamo
{
    private:
        Usuario usuario;
        Pelicula obra;
        char fecha1[100];
        char fecha2[100];
        int nu;
        int np;
    public:
        Prestamo();
        Prestamo(Usuario,Pelicula,char[]);
        Prestamo(Usuario,Pelicula,char[],char[],int,int);
        void alterna(Pelicula[],int);
        int usua();
        int pelic();
        void toString();
};

#endif // PRESTAMO_H
