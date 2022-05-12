#include <fstream> // Biblioteca para el manejo de ficheros
#include <iostream> // Biblioteca para la entrada-salida estándar
#include <stdlib.h>
#include <string.h>
using namespace std;
// Ejemplo de datos de personas

struct menuaux
{
    char nomb[30];
    int costo;
    int tipo;
    int bebestible;
};

struct restauranteaux
{
    char nom[30];
    int prestigio;
    int descuentos;
    int ambiente;
    int fumadores;
    int popularidad;
    int cantidad;
};


int main()
{
    ifstream re1;
    ofstream re,me;
    int i,j,n;
    restauranteaux x,y;
    menuaux h;
    re.open("restaurantes.txt", ios::binary);
    me.open("menu.txt", ios::binary);
    cout<<"Ingrese la cantidad de restaurantes "<<endl;
    cin>>n;
    for(i=0; i<n; i++)
    {
        cout<<"Nombre del restaurante: ";
        cin>>x.nom;
        cout<<endl<<"Prestigio:  (1. Alto, 2. Medio, 3. Bajo) ";
        cin>>x.prestigio;
        cout<<endl<<"Descuentos: (1. Si, 2. No) ";
        cin>>x.descuentos;
        cout<<endl<<"Ambiente: (1. Familiar, 2. Infantil, 3. Elegante) ";
        cin>>x.ambiente;
        cout<<endl<<"Fumadores: (1. Si, 2. No) ";
        cin>>x.fumadores;
        cout<<endl<<"Popularidad: (1. Alto, 2. Medio, 3. Bajo) ";
        cin>>x.popularidad;
        cout<<endl<<"Cantidad de menus: ";
        cin>>x.cantidad;
        re.write((char *)(&x),sizeof(restauranteaux));
        for(j=0; j<x.cantidad; j++)
        {
            cout<<"Nombre del Menu: ";
            cin>>h.nomb;
            cout<<endl<<"Costo: ";
            cin>>h.costo;
            cout<<endl<<"Tipo: (1.chatarra, 2.dietética, 3.vegetariana, 4.postre, 5.extranjera) ";
            cin>>h.tipo;
            cout<<endl<<"Bebestible: (1. Si, 2. No) ";
            cin>>h.bebestible;
            me.write((char *)(&h),sizeof(menuaux));
        }
    }
    re.close();
    me.close();
    return 0;
}
