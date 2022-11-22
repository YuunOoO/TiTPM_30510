#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main()
{
    string tablica[5];
    string wyjscie[10][3];
    cout << "LZ77 - Kodowanie\n";
    string text = "ababcbababaaaaaa";
    int n = 4; //rozmiar bufora
    int m = 4; //rozmiar s³ownika
    string slownik = "____"; //ci¹g znaków w postaci braku tekstu
    string bufor = text.substr(0, 4); //wype³nienie bufora
    int przesuniecie = 0;
    int calosc = 0;

    int zerowy = 0;
    int dlugosc = 0;
    int index = 0;
    int lz = 0;
    while (calosc <= text.length()) //pêtla szukaj¹ca najd³u¿szego ci¹gu znaków
    {
        cout << " Slownik: " << slownik << " Bufor " << bufor << endl;
        int przesuniecie = 0;

        int flaga = 0;

        for (int i = n; i > 0; i = i - 1) //pêtla szukaj¹ca dopasowania
        {
            string bufor2 = bufor.substr(0, i);
            int found = slownik.find(bufor2);
            if (found != string::npos) //warunek jeœli nie znajdzie to ma przerwaæ dzia³anie i przesun¹æ siê o 1 w lewo
            {

                index = found;

                dlugosc = bufor2.length();
                flaga = 1;
                break;
            }
        }

        if (flaga == 1) //warunek jeœli znajdzie to ma zapisaæ wartoœci
        {
            wyjscie[lz][0] = to_string(index);
            wyjscie[lz][1] = to_string(dlugosc);
            wyjscie[lz][2] = bufor[dlugosc];


            string stary_slownik = slownik + text.substr(calosc, text.length());

            przesuniecie = przesuniecie + dlugosc;
            calosc = calosc + przesuniecie + 1;
            for (int y = 0; y < n; y++)
                slownik[y] = stary_slownik[y + przesuniecie + 1];
            if (calosc < text.length())
                bufor = text.substr(calosc, 4);
        }
        if (flaga == 0) //warunek jeœli nie znajdzie dopasowania
        {

            wyjscie[lz][0] = "0";
            wyjscie[lz][1] = "0";
            wyjscie[lz][2] = bufor[0];
            string stary_slownik = slownik + text.substr(calosc, text.length());
            przesuniecie++;
            calosc = calosc + przesuniecie;
            for (int y = 0; y < n; y++)
                slownik[y] = stary_slownik[y + 1];
            if (calosc < text.length())
                bufor = text.substr(calosc, 4);

        }
        lz++;

    }

    for (int i = 0; i < 10; i++)
    {
        cout << wyjscie[i][0] << " " << wyjscie[i][1] << " " << wyjscie[i][2];
    }
   
    cout << endl;
    cout << "LZ77 - Dekodowanie\n";
    string tekst = "";
    string wejscie[10][3];
    ifstream plik("plik.txt");
    string linia;
    int aaa = 0;
    int i = 0, j = 0;
    string a, b, c;
    string k = "";
    slownik = "";
    while (getline(plik, linia))  //zczytywanie wartoœci z pliku
    {
        a = linia[0];
        b = linia[2];
        k = linia[4];
        i = stoi(a);
        j = stoi(b);
        slownik = linia.substr(6, 4);

        string wycinamy = slownik.substr(i, j);
        tekst = tekst + wycinamy + k;
        cout << i << " " << j << " " << k << " " << slownik << endl;

        aaa++;
    }
    cout << "Tekst po odkodowaniu: " << tekst << endl;
    plik.close();

}