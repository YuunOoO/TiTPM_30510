
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


vector<string> slownik_podstawowy;
vector<string> slownik_rozszerzony;

bool znajduje_sie(string cs) {
    for (int i = 0; i < slownik_rozszerzony.size()-1; i++) {
       
        if (slownik_rozszerzony[i] == cs) {
            return true;
        }
    }
    return false;

}

int main()
{
    int index = 0;
    vector<int> kod;
    string message;
    bool nowa_litera;
    string s, c;
    cout << "Podaj wiadomosc: ";
    cin >> message;


    //slownik podstawowy
    for (int i = 0; i < message.length();i++) {
        nowa_litera = true;
        bool add = true;
        string element;
        string nowy;
        nowy = message[i];
        for (int k = 0; k < slownik_podstawowy.size(); k++) {
             element = slownik_podstawowy[k];
             if (element == nowy) {
                 add = false;
             }
        }

        if (add) {
            slownik_podstawowy.push_back(nowy);
            add = true;
        }
    }
    std::sort(slownik_podstawowy.begin(), slownik_podstawowy.end());
    slownik_rozszerzony = slownik_podstawowy;

    //2
    c = message[0];
    cout << "Zakodowana wiadomosc: ";
    for (int i = 1; i < message.length(); i++) {
        s = message[i];
       //3
        if (znajduje_sie(c + s)) {
            //4
            c = c + s;
            
        }
        else {
            //5
            for (int i = 0; i < slownik_rozszerzony.size(); i++) {
                if (c == slownik_rozszerzony[i]) {
                    cout << i+1 << " ";
                }
            }
            string nowy = c + s;
            slownik_rozszerzony.push_back(nowy);
            c = s;
            index = i;
            if (i != message.length() - 1) {
                continue;
            }
        }

    }

    cout << endl;
    for (int i = 0; i < slownik_rozszerzony.size(); i++) {
        cout <<i+1<<" " << slownik_rozszerzony[i] << endl;
    }



  
}

