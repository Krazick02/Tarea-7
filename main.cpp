#include "Autor.h"
#include "Usuario.h"
#include "Pelicula.h"
#include "Prestamo.h"
#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;
int prest(){
    int u;
    cout<<"\nIngrese su numero de prestamo :\n==>";
    cin>>u;
    cout<<"\n\n";
    return u;
}

int menu(){
    int o;
    cout<<"==========MENU PRINCIPAL==========\n";
    cout<<"1.Administrar usuarios\n2.Administrar peliculas\n3.Administrar prestamos\n4.Salir\n==>";
    cin>>o;
    system("cls");
    return o;
}
int menuuser(){
    int o;
    cout<<"===========MENU USUARIOS==========\n";
    cout<<"1.Registrar\n2.Editar\n3.Informacion\n4.Eliminar\n5.Salir\n==>";
    cin>>o;
    system("cls");
    return o;
}
int menupres(){
    int o;
    cout<<"===========MENU PRESTAMOS==========\n";
    cout<<"1.Realizar prestamo\n2.Devolver\n3.Informacion de prestamo\n4.Salir\n==>";
    cin>>o;
    system("cls");
    return o;
}
int menupeli(){
    int o;
    cout<<"==========MENU PELICULAS==========\n";
    cout<<"1.Registrar\n2.Editar\n3.Eliminar\n4.Consultar director\n5.Informacion\n6.Historial de prestamos\n7.Menu Principal\n==>";
    cin>>o;
    system("cls");
    return o;
}
int show(Pelicula p[10],int pC){
    int o;
    for(int x=0;x<pC;x++){
        cout<<x;
        p[x].showN();
        cout<<endl;
    }
    cout<<"Seleccione el numero de pelicula"<<endl;
    cin>>o;
    system("cls");
    return o;
}
int showU(Usuario u[10],int uC){
    int o;
    for(int x=0;x<uC;x++){
        cout<<x;
        u[x].no();
        cout<<endl;
    }
    cout<<"Seleccione el numero de usuario"<<endl;
    cin>>o;
    system("cls");
    return o;
}
Usuario registrarU(){
    char nombre[100];
    char apellido[100];
    int edad;
    int act=0;
    cout<<"\n========REGISTRAR USUARIO========\n";
    cout<<"Ingrese el nombre :\n";
    cin>>nombre;
    cout<<"Ingrese apellido :\n";
    cin>>apellido;
    cout<<"Ingrese la edad :\n";
    cin>>edad;

    return Usuario(nombre,apellido,edad,act);
}
Autor regAutor(){
    char nombre[100];
    char nacionalidad[100];
    cout<<"\n========REGISTRAR DIRECTOR========\n";
    cout<<"Ingrese el nombre :\n";
    cin>>nombre;
    cout<<"Ingrese la nacionalidad :\n";
    cin>>nacionalidad;

    return Autor(nombre,nacionalidad);
}

Pelicula registrar(){
    char nombre[100];
    int year;
    Autor autor;
    char genero[100];
    char productora[100];
    char minutos[100];
    int estatus =0;
    cout<<"========REGISTRAR PELICULA========\n\n";
    cout<<"Ingrese el nombre :\n";
    cin>>nombre;
    cout<<"Ingrese el anio ;\n";
    cin>>year;
    cout<<"Ingrese el genero :\n";
    cin>>genero;
    cout<<"Ingrese la productora :\n";
    cin>>productora;
    cout<<"Ingrese la duracion en minutos :\n";
    cin>>minutos;
    autor=regAutor();

    return Pelicula(nombre,year,autor,genero,productora,minutos,estatus);
}
Prestamo salida(Usuario u[10],Pelicula p[10],int uC,int pC){
    char fecha1[100],fecha2[]="Pendiente";
    int a,e,nu,np;
    int pr;
    a=showU(u,uC);
    e=show(p,pC);
    nu=a;
    np=e;
    pr=p[e].gete();
    while(pr!=0){
        cout<<"Por el momento, no contamos con esta pelicula, prueba con otra :)\n";
        a=showU(u,uC);
        e=show(p,pC);
    }
    cout<<"\nIngrese la fecha de salida :\n";
    cin>>fecha1;
    p[e].estatus();
    u[a].mas();
    return Prestamo(u[a],p[e],fecha1,fecha2,a,e);
}
int main()
{
    int can;
    cout<<"Antes de proceder, es necesario registrar las peliculas de\nlas cuales se dispondra en este videocentro\n\nCon cuantas peliculas se va a contar?\n";
    cin>>can;
    bool vuelta=true;
    Pelicula p[can];
    for(int x=0;x<can;x++){
        cout<<"\n\tPelicula numero "<<x<<endl;
        p[x]=registrar();
    }
    Usuario u[10];
    Prestamo pre[10];
    int pC=can,no,uC=0,prC=0,h;

    while(vuelta==true){
        switch(menu()){
            case 1:
                switch(menuuser()){
                    case 1:
                        u[uC]=registrarU();
                        cout<<"\nNumero de usuario :"<<uC<<endl;
                        cout<<endl;
                        cout<<endl;
                        uC++;
                        break;
                    case 2:
                        no=showU(u,uC);
                        u[no].toString();
                        cout<<"===NUEVOS DATOS DEL USUARIO====\n";
                        u[no]=registrarU();
                        cout<<endl;
                        cout<<endl;
                        break;
                    case 3:
                        no=showU(u,uC);
                        u[no].toString();
                        break;
                    case 4:
                        no=showU(u,uC);
                        if(u[no].gete()==0){
                            u[no]=Usuario();
                            cout<<"Usuario eliminado"<<endl;
                            break;
                        }
                        cout<<"\n\tNo es posible eliminar este usuario ya que tene prestamos activos"<<endl;
                        break;
                    case 5:
                        menu();
                        break;
                }
                break;
            case 2:
                switch (menupeli()){
                    case 1:
                        p[pC]=registrar();
                        cout<<"\nNumero de pelicula :"<<pC<<endl;
                        cout<<endl;
                        cout<<endl;
                        pC++;
                        break;
                    case 2:
                        no=show(p,pC);
                        p[no].toString();
                        cout<<"===NUEVOS DATOS DE LA PELICULA====\n";
                        p[no].change();
                        cout<<endl;
                        cout<<endl;
                        break;
                    case 3:
                        no=show(p,pC);
                        if(p[no].gete()==0){
                            p[no]=Pelicula();
                            cout<<"Pelicula borrada "<<endl;
                            cout<<endl;
                            cout<<endl;
                            pC--;
                            break;
                        }
                        cout<<"\n\tLa pelicula no puede ser borrada devido a que se encuentra en prestamo.\n"<<endl;
                        cout<<endl;
                        cout<<endl;
                        break;
                    case 4:
                        p[show(p,pC)].toStringA();
                        cout<<endl;
                        cout<<endl;
                        break;
                    case 5:
                        p[show(p,pC)].toString();
                        cout<<endl;
                        cout<<endl;
                        break;
                    case 6:
                        h=0;
                        no=prest();
                        for(int x=0;x<prC;x++){
                            if(pre[x].pelic()==no){
                                cout<<"\n\tPrestamo "<<h<<"\n\n";
                                pre[x].toString();
                                cout<<endl;
                            }
                        }
                    case 7:
                        menu();
                        break;
                }
                break;
            case 3:
                switch(menupres()){
                    case 1:
                        pre[prC]=salida(u,p,uC,pC);
                        cout<<"\nNumero de prestamo :"<<prC<<endl;
                        cout<<endl;
                        cout<<endl;
                        prC++;
                        break;
                    case 2:
                        h=prest();
                        no=pre[h].pelic();
                        pre[h].alterna(p,no);
                        u[pre[h].usua()].menos();
                        break;
                    case 3:
                        pre[prest()].toString();
                        break;
                    default:
                        break;
                }
                break;
            default:
                vuelta=false;

        }
    }
    return 0;
}
