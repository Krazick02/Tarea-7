#ifndef USUARIO_H
#define USUARIO_H


class Usuario{
    private:
        char nombre[100];
        char apellido[100];
        int edad;
        int act;
    public:
        Usuario();
        Usuario(char[],char[],int,int);
        void no();
        void mas();
        void menos();
        int gete();
        void toString();
};

#endif // USUARIO_H
