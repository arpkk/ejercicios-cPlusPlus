#include <iostream>
#include <string.h>

using namespace std;

int main ()
{
    int n;
    cout << "Introduzca una letra minuscula : ";
    char minuscula[20];
    cin >> minuscula;
    n=strlen(minuscula);
    for(int i=0;i!=n;i++)
    {
        minuscula[i]-=('a'-'A');
    }
    cout << minuscula << endl;
    return 0;
}
