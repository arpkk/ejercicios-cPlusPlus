#include <iostream>
#include <string.h>
#include <fstream>
#include <stdlib.h>

using namespace std;
int archivo(); //abre un archivo
int menu(); //da a elegir al usuario
void mayusculas(); //cambia las letras minusculas a mayusculas

int main()
{
    int a, b, c;
    char letra;
    system("cls");
    a=menu();
    if (a==1)
        {
            if(archivo()==1)
                mayusculas();
        }
    if (a==2)
        {
            cout<< "quetal";
        }
    if (a==3)
        {
            cout<<"adios";
            system("PAUSE");
        }
return 0;
}


int archivo()
{
    char nombre[200],letra;
    ifstream f;
    system("cls");
    cout <<"-----------------------------------------------------"<<endl;
    cout <<"Ingrese nombre de archivo donde estan los datos:  " << endl;
    cout <<"-----------------------------------------------------"<<endl;
    cin >> nombre;
    f.open(nombre);
    if (f.fail())
    {
        cout<<"Archivo no existe "<<endl;
        system("PAUSE");
    }
    else
    {
        while (f.get(letra))
            return 1;
    }
return 0;
}


int menu()
{
    int d, a, b , c;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"ingrese 1 si quiere cambiar las letras a mayusculas"<<endl;
    cout<<"ingrese 2 para jugar a adivinar las palabras"<<endl;
    cout<<"ingrese 3 para salir"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cin>> d;
    system("cls");
    return d;
}


void mayusculas()
{
    char letra,letraaux=letra;
    if (letraaux>= 'a' && letraaux<='z')
    {
        letraaux-='a'-'A';
        cout<<letraaux;
    }

    else
        cout<< " ";

}
