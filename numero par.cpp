#include<iostream>
#include<fstream>
#include<stdlib.h>

using namespace std;

int main ()
{
    int num;
    char nombre[30];
    ifstream p;
    system("cls");
    cout << "Ingrese nombre de archivo donde estan los datos:  ";
    cin >> nombre;
    p.open(nombre);
    if (p.fail())
    {
        cout<<"Archivo no existe "<<endl;
        system("PAUSE");
    }
    else
    {
    while (!p.eof())
    {
        p>>num;
        if (num%2==0)
        cout << num <<endl;
    }
    }
p.close();
return 0;
}
