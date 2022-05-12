#include<iostream>
#include<fstream>
#include<stdlib.h>
#define Max 30
using namespace std;
int contar_datos(char nombre[20]);

int main ()
{
    int numero[Max], nd, i=0,menor;
    char nombre[20];
    ifstream f;
    system("cls");
    cout << "Ingrese nombre de archivo donde estan los datos:  "<<endl;
    cin >> nombre;
    //nd=contar_datos(nombre);
    f.open(nombre);
    if (f.fail())
    {
        cout<<"Archivo no existe "<<endl;
        system("PAUSE");
    }
    else
        while (!f.eof())
        {
            f>>numero[i];
            i++;
        }
    nd=i;
    cout<<nd<<endl;
    menor=numero[0];
    for(i=1;i<nd;i++)
        if(numero[i]<menor)
            menor=numero[i];
    cout<<"el numero menor del archivo es: "<<menor;

    f.close();
}

int contar_datos(char nombre[20])
{
    int cont=0;
    string num;
    ifstream f;
    f.open(nombre);
    if (f.fail())
    {
        cout<<"Archivo no existe "<<endl;
        system("PAUSE");
    }
    while (!f.eof())
    {
        f >> num;
        cont++;
    }
    f.close();
    return cont;
}
