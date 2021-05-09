#include <iostream>
#include <Windows.h>
#include <time.h>

using namespace std;

typedef int Info;

struct Elem
{
    Elem* link;
    Info info;
};

void create(Elem*& L, Info num);
void remove(Elem*& L);
void process(Elem*& L, Elem*& T, Elem*& first, Info k, Info j);
void print(Elem*& T, Elem* start);
Elem* lastElem(Elem*& L, Elem*& T);
void count_elem(Elem* L, Elem* first, Info& k);
void to_elem(Elem*& L, Info l, Info temp);
void insert(Elem*& L, Info value);

int main()
{
    SetConsoleCP(1251); // встановленн€ стор≥нки win-cp1251 в пот≥к вводу
    SetConsoleOutputCP(1251); // встановленн€ стор≥нки win-cp1251 в пот≥к виводу

    srand((unsigned)time(NULL));
    Elem* L = NULL; // оголошенн€ списку

    create(L, 0); // створенн€ списку з 10 елемент≥в

    Elem* T = NULL; // допом≥жний елемент T
    Elem* first = L; // початковий елемент cписку
    Info k = 1;
    count_elem(L, first, k); // визначенн€ к≥лькост≥ елемент≥в
    process(L, T, first, k, 0);
    cout << "ќбернений список: " << endl << endl;
    Elem* start = T;
    print(T, start);
    cout << endl << endl;
    cout << "ќриг≥нальний список: " << endl << endl;
    remove(L);

    cout << endl;
}

void create(Elem*& L, Info num) // додаванн€ елементу у список
{
    Info value = 1 + rand() % 100;
    Elem* tmp = new Elem;
    tmp->info = value;
    if (L != NULL) // якщо список не порожн≥й
    {
        Elem* T = L;
        T = lastElem(L, T);
        T->link = tmp;
    }
    else // якщо список порожн≥й
    {
        L = tmp;
    }
    tmp->link = L;

    if (num < 9) {
        num++;
        create(L, num);
    }
}

Elem* lastElem(Elem*& L, Elem*& T) { // функц≥€ пошуку останнього елементку у списку
    if (T->link != L) {
        T = T->link;
        return lastElem(L, T);
    }
    else {
        return T;
    }
}

void remove(Elem*& L) // видаленн€ елементу з≥ списку 
{
    Elem* T = L;
    T = lastElem(L, T);
    Info value = L->info;
    if (T != L)
    {
        Elem* tmp = L->link;
        delete L;
        L = tmp;
        T->link = L;
    }
    else
    {
        delete L;
        L = NULL;
    }

    cout << value << " ";

    if (L != NULL) {
        remove(L);
    }
}

void print(Elem*& T, Elem* start) {
    if (T == NULL)
        return;
    if (T->link != start)
    {
        cout << T->info << " ";
        T = T->link;
        print(T, start);
    }
    else {
        cout << T->info << " ";
        return;
    }
}

void process(Elem*& L, Elem*& T, Elem*& first, Info k, Info j)
{
    if (L == NULL)
        return;
    L = first; // встановленн€ L в початкову позиц≥ю
    if (j < k) {
        Info l = k - j - 1; // визначенн€ елементу 
        j++; // зб≥льшенн€ показника вствлених елемент≥в
        Info temp = 0;
        to_elem(L, l, temp);
        Info value = L->info;
        L = first; // поверненн€ на початок
        insert(T, value);
        process(L, T, first, k, j);
    }
}

void count_elem(Elem* L, Elem* first, Info& k) { // функц≥€ рахунку елемент≥в у списку
    if (L->link != first) // перев≥рка до останнього
    {
        k++; // л≥чильник к≥лькост≥ елемент≥в
        L = L->link; // перех≥д дал≥
        count_elem(L, first, k);
    }

}

void to_elem(Elem*& L, Info l, Info temp) { // функц≥€ переходу до потр≥бного елементу
    if (temp < l) {
        L = L->link;
        temp++;
        to_elem(L, l, temp);
    }
}

void insert(Elem*& L, Info value) // додаванн€ елементу у список
{
    Elem* tmp = new Elem; // створенн€ допом≥жного елемента 
    tmp->info = value;
    if (L != NULL) // якщо список не порожн≥й
    {
        Elem* T = L; // ще один допомом≥жий елемент
        T = lastElem(L, T); // пошук останнього елементу
        T->link = tmp;
    }
    else // якщо список порожн≥й
    {
        L = tmp;
    }
    tmp->link = L;
}