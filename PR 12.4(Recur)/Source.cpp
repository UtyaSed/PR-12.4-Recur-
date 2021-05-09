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
    SetConsoleCP(1251); // ������������ ������� win-cp1251 � ���� �����
    SetConsoleOutputCP(1251); // ������������ ������� win-cp1251 � ���� ������

    srand((unsigned)time(NULL));
    Elem* L = NULL; // ���������� ������

    create(L, 0); // ��������� ������ � 10 ��������

    Elem* T = NULL; // ��������� ������� T
    Elem* first = L; // ���������� ������� c�����
    Info k = 1;
    count_elem(L, first, k); // ���������� ������� ��������
    process(L, T, first, k, 0);
    cout << "��������� ������: " << endl << endl;
    Elem* start = T;
    print(T, start);
    cout << endl << endl;
    cout << "����������� ������: " << endl << endl;
    remove(L);

    cout << endl;
}

void create(Elem*& L, Info num) // ��������� �������� � ������
{
    Info value = 1 + rand() % 100;
    Elem* tmp = new Elem;
    tmp->info = value;
    if (L != NULL) // ���� ������ �� �������
    {
        Elem* T = L;
        T = lastElem(L, T);
        T->link = tmp;
    }
    else // ���� ������ �������
    {
        L = tmp;
    }
    tmp->link = L;

    if (num < 9) {
        num++;
        create(L, num);
    }
}

Elem* lastElem(Elem*& L, Elem*& T) { // ������� ������ ���������� ��������� � ������
    if (T->link != L) {
        T = T->link;
        return lastElem(L, T);
    }
    else {
        return T;
    }
}

void remove(Elem*& L) // ��������� �������� � ������ 
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
    L = first; // ������������ L � ��������� �������
    if (j < k) {
        Info l = k - j - 1; // ���������� �������� 
        j++; // ��������� ��������� ��������� ��������
        Info temp = 0;
        to_elem(L, l, temp);
        Info value = L->info;
        L = first; // ���������� �� �������
        insert(T, value);
        process(L, T, first, k, j);
    }
}

void count_elem(Elem* L, Elem* first, Info& k) { // ������� ������� �������� � ������
    if (L->link != first) // �������� �� ����������
    {
        k++; // �������� ������� ��������
        L = L->link; // ������� ���
        count_elem(L, first, k);
    }

}

void to_elem(Elem*& L, Info l, Info temp) { // ������� �������� �� ��������� ��������
    if (temp < l) {
        L = L->link;
        temp++;
        to_elem(L, l, temp);
    }
}

void insert(Elem*& L, Info value) // ��������� �������� � ������
{
    Elem* tmp = new Elem; // ��������� ���������� �������� 
    tmp->info = value;
    if (L != NULL) // ���� ������ �� �������
    {
        Elem* T = L; // �� ���� ���������� �������
        T = lastElem(L, T); // ����� ���������� ��������
        T->link = tmp;
    }
    else // ���� ������ �������
    {
        L = tmp;
    }
    tmp->link = L;
}