#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    string wyraz, klucz, klucz2;
    int dlugosc,x1,x2;
    cout << "Algorytm cezara ale z zmiennym przesunieciem" << endl;
    cout << "Podaj wyraz do zaszyfrowania:"<<endl;
       std::getline(std::cin, wyraz);

    cout << "Podaj klucz do szyfrowania(wyraz): ";
    cin >> klucz;
    dlugosc = wyraz.length();
    x1 = klucz.length();
    for(int i=0; i<dlugosc; i++)
    {
        int x=0;
        wyraz[i] = (int)wyraz[i]+((int)klucz[x]-96);
        x++;
        if(x>x1)x=0;
    }
    cout<<wyraz<<endl;
    cout<<"Zaszyfrowano wiadmosc! Podaj klucz do deszyfracji: "<<endl;
    cin >> klucz2;
    x2 = klucz2.length();
    for(int i=0; i<dlugosc; i++)
    {
        int x=0;
        wyraz[i] = (int)wyraz[i]-((int)klucz2[x]-96);
        x++;
        if(x>x2) x=0;
    }
    cout<<wyraz;
    return 0;
}
