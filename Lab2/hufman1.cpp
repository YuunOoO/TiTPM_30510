#include <iostream>
#include <string>
using namespace std;

void zliczanie(string tekst)
{
	char znak;
	int dlugosc = tekst.length();
	int licznik;
	for(int i = 0; i < dlugosc; i++)
	{
		licznik = 0;
		znak = tekst[i];
		for(int j = 0; j < dlugosc; j++)
		{
			if(znak == tekst[j])
			{
				licznik++;
				for(int k = j; k < dlugosc - 1; k++)
				{
					tekst[k] = tekst[k+1];
				}
				dlugosc--;
				tekst[dlugosc] = '\0';
				j--;
			}
		}		
			cout << znak << " - " << licznik << endl;			
			i--;
		}	
}

int main()
{
	string tekst;
	cout << "Podaj wiadomosc do zakodowania: " << endl;
	cin >> tekst;
	
	zliczanie(tekst);
	
	return 0;
}
