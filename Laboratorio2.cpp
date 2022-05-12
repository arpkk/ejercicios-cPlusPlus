#include <iostream>
#include <string.h>
#include <stdlib.h>
//Nombre: Gina Ozimisa
//sistema: windows 7
//Compilador codeblocks 16.01
using namespace std;
struct persona
{
    char nombre[50];
    int edad;
    persona *sig;
};

class lista
{
private:
    persona *p;

public:
    lista();
    ~lista();
    void ingreso(int n,char *c);
    void mostrar ();
    void eliminar(char *c);
    void menu();
};

lista::lista()
{
    p=NULL;
}

lista::~lista()
{
    persona *q;
    while (p)
    {
        q=p;
        p=p->sig;
        delete q;
    }
}

void lista::mostrar()
{
    persona *q;
    q=p;
    while(q)
    {
        cout<<q->nombre<<"\t";
        q=q->sig;
    }
}

void lista::ingreso( int n, char *c )
{
    persona *q, *r;
    q = new persona;
    if (!q)
        cout <<"No hay Espacio de Memoria suficiente";
    strcpy(q -> nombre,c);
    q -> edad   = n;
    q -> sig = p;
    if ( !p || strcmp(q ->  nombre,c) >=0 )
        p = q;
    else
    {
        r = p -> sig;
        while ( r && r -> nombre < q -> nombre )
        {
            q -> sig = r;
            r = r -> sig;
        }
        q -> sig -> sig = q;
        q -> sig = r;
    }
}


void lista::eliminar( char *c )
{
    persona *r, *q;
    if ( p == NULL ) // eq. if (!p
        cout<<"sin contactos"<<endl;
    else
    {
        q = p;
        if (!strcmp( p -> nombre, c ))
        {
            p = p -> sig;
            delete q ;
        }
        else
        {
            do
            {
                r = q;
                q = q -> sig;
            }
            while ( q && strcmp( p -> nombre, c  ));
            if ( q )
            {
                r -> sig = q -> sig;
                delete q;
            }
            else
                cout<<endl<<" El nombre "<<c<<" No esta en la lista"<<endl;
        }
    }
}

void lista::menu()
{
    cout<<"ingrese 1 para agregar un contacto"<<endl;
    cout<<"ingrese 2 para eliminar un contacto"<<endl;
    cout<<"ingrese 3 para ver todos los contactos"<<endl;
    cout<<"ingrese 0 para salir"<<endl;
}

int main()
{
    int n,e;
    char c[50];
    lista L;
    do
    {
        L.menu();
        cin>>n;
        switch(n)
        {
        case 1:
            L.ingreso(e,c);
            cout<<"Contacto agregado"<<endl;
            break;
        case 2:
            cout<<"Ingrese el nombre del contacto"<<endl;
            L.eliminar(c);
            cout<<"Contacto eliminado"<<endl;
            break;
        case 3:
            L.mostrar();
            system("pause");
            break;
        }
    }
    while(n!=0);

    return 0;
}


