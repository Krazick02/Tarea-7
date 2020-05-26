#ifndef AUTOR_H
#define AUTOR_H


class Autor{
    private:
        char nombre[100];
        char nacionalidad[100];
    public:
        Autor();
        Autor(char[],char[]);
        void toString();
};

#endif // AUTOR_H
