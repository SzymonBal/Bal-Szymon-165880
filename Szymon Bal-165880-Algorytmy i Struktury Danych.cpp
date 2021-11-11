/* Zadanie 15. ZnajdŸ liczbê trójelementowych kombinacji liczb z zadanego ci¹gu, których suma jest równa zadanej lizcbie M.
    Przyk³ad.
        Wejœcie: [ 1, 2, 5, 1, 2, 1, 2, 4 ]
                M = 6
                Wyjœcie:
                Liczba kombinacji wynosi 3: [ 1 2 3 ], [ 2 2 2 ], [ 1 1 4 ]
*/
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <fstream>
#include <iomanip>

using namespace std;

void wypelnij(int tablica[], int rozmiar);
void znajdz_kombinacje(int tablica[], int rozmiar, int suma);

/*  Dla czytelnosci programu tworzymy funkcje void ktorej zadaniem jest znalezienie wszystkich trojelementowych kombinacji,
  wykonujemy w niej 3 petle ktore pokolei sprawdzaja liczby, pierwsza petla zaczyna sie od indeksu 0 i konczy na 5 w tabeli,
  druga od indeksu 1 i konczy na 6, a trz od miejsca 2 i konczy na 7. Jezeli elementy spelniaja odpowiedni warunek
  (ich suma jest równa zadanej przez uzytkownka M) to wyswietl je na ekranie.

*/


int main()
{
    int suma;
    int rozmiar;
    int* tablica;

    double czas;

    clock_t start, stop;

    cout << "Podaj rozmiar tablicy: "; cin >> rozmiar;
    tablica = new int[rozmiar];
    wypelnij(tablica, rozmiar);



    for (int i = 0; i < rozmiar; i++)
    {
        cout << tablica[i] << "\n\n";
    }

    // Do wypisania potrzebna jest petla ktora bedzie wykonywac sie n-krotnie




    // Wprowadzamy wartosc sumy

    cout << "wprowadz wartosc sumy: ";
    cin >> suma;
    cout << "kombinacje: " << endl;
    // Wywolujemy funkcje void

    start = clock();

    znajdz_kombinacje(tablica, rozmiar, suma);

    stop = clock();
    czas = ((stop - start) * 1000) / (CLOCKS_PER_SEC);

    cout << "czas wykonywania programu wynosi = " << czas << " ms";

   
   

    return 0;



}

void wypelnij(int tablica[], int rozmiar)
{
    srand(time(NULL));
    for (int i = 0; i < rozmiar; i++)
    {
        tablica[i] = rand() % rozmiar + 1;


    }
}

void znajdz_kombinacje(int tablica[], int rozmiar, int suma)
{
    int i, j, k;

    double czas;

    clock_t start, stop;

    start = clock();

    int licz_wystapienia = 0; // <-- tu jest nowe

    for (int i = 0; i < rozmiar - 2; i++)
    {
        for (int j = i + 1; j < rozmiar - 1; j++)
        {
            for (int k = j + 1; k < rozmiar; k++)
            {
                if (tablica[i] + tablica[j] + tablica[k] == suma)
                {
                    cout << tablica[i] << " ," << tablica[j] << " ," << tablica[k] << endl << endl;
                    licz_wystapienia++; // <-- i tu jest nowe
                }

            }
        }
    }
   

  
    cout << endl << "znaleziono: " << licz_wystapienia << " kombinacji" << endl; // <-- i tu jest nowe
    ofstream zapis("dane.txt");
    stop = clock();
    czas = ((stop - start) * 1000) / (CLOCKS_PER_SEC);


    zapis << "czas wykonywania algorytmu = " <<czas<<  " " << "dla sumy rownej = " << suma << " i liczby elementow rownej = " << rozmiar;
    zapis << " znaleziono = " << licz_wystapienia<<" kombinacji";
   
    zapis.close(); //obowiązkowo należy zamknąć plik

}



