
/**/

          /*Bal Szymon-165880-Algorytmy i Strukury Danych-Projekt 1

            Zadanie 15. ZnajdŸ liczbê trójelementowych kombinacji liczb z zadanego ci¹gu, których suma jest równa zadanej lizcbie M.
            Przyk³ad.
            Wejœcie: [ 1, 2, 5, 1, 2, 1, 2, 4 ]
            M = 6
            Wyjœcie:
            Liczba kombinacji wynosi 3: [ 1 2 3 ], [ 2 2 2 ], [ 1 1 4 ]
*/

/*Biblioteki użyte podczas programowania 
iostream = operacje wejścia, wyjścia,obliczenia
cstdlib/time.h = losowanie danych do ciągu
*/
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <fstream>


using namespace std;



void wypelnij(int tablica[], int rozmiar); 
void znajdz_kombinacje(int tablica[], int rozmiar, int suma);


int main()
{/*Zmienne występujące w programie 
 suma = maksymalna liczba losowa możliwa do wczytywana do ciągu
 rozmiar = ilośc elementów z których składa się tablica
 tablica = ciąg liczbowy w którym funkcja wyszukuje kombinacji
 */
    int suma;
    int rozmiar;
    int* tablica;

    /*Wprowadzamy ilość elementów ciągu*/

    cout << "Podaj rozmiar tablicy: "; cin >> rozmiar;
    tablica = new int[rozmiar];
    wypelnij(tablica, rozmiar);



    for (int i = 0; i < rozmiar; i++)
    {
        cout << tablica[i] << "\n\n";
    }

    // Wprowadzamy wartosc sumy

    cout << "wprowadz wartosc sumy: ";
    cin >> suma;
    cout << "kombinacje: " << endl;


    // Wywolujemy funkcje void

    znajdz_kombinacje(tablica, rozmiar, suma);

    return 0;
}

void wypelnij(int tablica[], int rozmiar)/*losowanie generujące liczby do ciągu posiadającego ilość elemenetów (rozmiar)*/
{
    srand(time(NULL));
    for (int i = 0; i < rozmiar; i++)
    {
        tablica[i] = rand() % rozmiar + 1;


    }
}

void znajdz_kombinacje(int tablica[], int rozmiar, int suma) /*głowna funkcja której zadaniem jest znajdowanie trójelementowych ekombinacji.
                                                              Za pomocą 3 pętli funkcja sprawdza wszystkie liczby.Jezeli elementy spelniaja odpowiedni warunek
                                                              (ich suma jest równa zadanej przez uzytkownka M) to wyswietl je na ekranie.*/
{


    int i, j, k;
    double czas;

    ofstream zapis;
    zapis.open("dane.txt", ios::app); /*kolejne uruchomienia programu*/

    clock_t start, stop;

    start = clock(); /*początek odliczania czasu w jakim zostaje wykonana funkcja*/

    int licz_wystapienia = 0;

    for (int i = 0; i < rozmiar - 2; i++)
    {
        for (int j = i + 1; j < rozmiar - 1; j++)
        {
            for (int k = j + 1; k < rozmiar; k++)
            {
                if (tablica[i] + tablica[j] + tablica[k] == suma)
                {
                    cout << tablica[i] << " ," << tablica[j] << " ," << tablica[k] << endl << endl;
                    licz_wystapienia++;
                    zapis << tablica[i] << ", " << tablica[j] << "," << tablica[k] << endl;
                }

            }
        }
    }

    /*zapis otrzymanych danych, wyświetlona zostaje:
      - ilość znalezionych kombinacji
      - wsyzskie znalezione kombinacje liczbowe
      - czas potrzebny na wykonanie algorytmu
      - parametry dla których otrzymane zostały dane wyniki (ilość liczb w ciągu,zakres*/

    cout << endl << "znaleziono: " << licz_wystapienia << " kombinacji" << endl; // <-- i tu jest nowe

    stop = clock(); /*koniec odliczania czasu w jakim zostaje wykonana funkcja*/
    czas = ((stop - start) * 1000) / (CLOCKS_PER_SEC);


    zapis << "czas wykonywania algorytmu = " << czas << " " << "dla sumy rownej = " << suma << " i liczby elementow rownej = " << rozmiar;
    zapis << " znaleziono = " << licz_wystapienia << " kombinacji \n";
    zapis << "-----------------------------------------------------------\n ";

    zapis.close(); //obowiązkowo należy zamknąć plik

}



