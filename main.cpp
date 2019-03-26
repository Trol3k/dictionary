#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <ctime>

using namespace std;

char option;
vector <pair <string, string> > vect;

void test();
void showDictionary();
void addverb();
void delverb();


int menu()
{
    system("CLS");

    cout << "|------------------------|" << endl;
    cout << "|  DICTIONARY - SLOWNIK  |" << endl;
    cout << "|   BY MACIEJ & KONRAD   |" << endl;
    cout << "|------------------------|" << endl;
    cout << endl;
    cout << "1. TEST" << endl;
    cout << "2. Przeglad slownika" << endl;
    cout << "3. Dodaj wyraz" << endl;
    cout << "4. Usun wyraz" << endl;
    cout << "0. Zakoncz" << endl;

    cin >> option;

    switch(option)
    {
    case '1':
        test();
        break;
    case '2':
        showDictionary();
        break;
    case '3':
        addverb();
        break;
    case '4':
        delverb();
        break;
    case '0':
        return 0;
    }
}

bool fileRead()
{
    ifstream file("dictionary.txt");
    if( !file.good() )
        return false;

    while( true )
    {
        string english, polish;
        file >> english >> polish;
        if( !file.fail() )
        {
            vect.push_back(make_pair(english, polish));
        }
        else
            break;
    }

    file.close();

    return true;
}

bool fileSave()
{
    ofstream file("dictionary.txt");
    if( !file.good() )
        return false;

    for(int i=0; i<vect.size(); i++)
    {
        file << vect[i].first << " " << vect[i].second << endl;
    }

    file.close();

    return true;
}

void test()
{
    system("CLS");
    cout << "Wprowadz 0 by wrocic do menu." << endl << endl;

    int n;
    string str;
    srand(time(NULL));

    while(true)
    {
        n = rand() %vect.size();

        do{
            cout << vect[n].first << " ";
            cin >> str;

            if(str != vect[n].second)
                cout << "Zla odpowiedz!" << endl;

            if (str == "0")
                menu();
        }while(str != vect[n].second);

        cout << "Poprawna odpowiedz!" << endl << endl;
    }
}

void showDictionary()
{
    system("CLS");

    cout << "Wprowadz 0 by wrocic do menu." << endl << endl;

    for(int i=0; i<vect.size(); i++)
        cout << vect[i].first << " " << vect[i].second << endl;

    cin >> option;
    if (option=='0')
        menu();
}

void addverb()
{
    system("CLS");

    string english, polish;
    cout << "Wprowadz 0 by wrocic do menu." << endl;
    cout << "Aby dodac wyraz do slownika wprowadz go najpierw po angielsku a nastepnie po polsku." << endl << endl;


    do
    {
        cin >> english;

        if (english == "0")
        {

            sort(vect.begin(), vect.end());
            fileSave();
            menu();
        }
        cin >> polish;

        vect.push_back(make_pair(english, polish));

    }
    while(english != "0");
}

void delverb()
{
    system("CLS");

    string english, polish;
    cout << "Wprowadz 0 by wrocic do menu." << endl;
    cout << "Aby usunac wyraz ze slownika wprowadz go najpierw po angielsku a nastepnie po polsku." << endl << endl;


    do
    {
        cin >> english;

        if (english == "0")
        {

            sort(vect.begin(), vect.end());
            fileSave();
            menu();
        }
        cin >> polish;

        for (int i=0; i<vect.size(); i++)
        {
            if (vect[i].first == english && vect[i].second == polish)
            {
                vect.erase(vect.begin() + i);
            }
        }
    }
    while(english != "0");
}


int main()
{
    fileRead();
    menu();
}
