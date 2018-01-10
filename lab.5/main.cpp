//Удалить все нечетные элементы
//Добавить К строк в начало матрицы

//1. Сформировать динамический одномерный массив, заполнить его случайными числами и вывести на печать.
//2. Выполнить указанное в варианте задание и вывести полученный массив на печать.
//3. Сформировать динамический двумерный массив, заполнить его случайными числами и вывести на печать.
//4. Выполнить указанное в варианте задание и вывести полученный массив на печать.

#include <iostream>

#define FORM_MAS  1
#define COUT_MAS  2
#define DEL_MAS   3
#define FORM_MATR 4
#define COUT_MATR 5
#define ADD_LINES 6
#define EXIT      7

using namespace std;

void fill_mas(int8_t mas[], int n)
{
    for (int i = 0; i < n; i++)
    {
        mas[i] = rand();
    }
}

void cout_mas(int8_t mas[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << (int) mas[i] << " ";
    }
    cout << "\n\n";
}

int del_odd (int8_t mas_a[], int8_t mas_b[], int n)
{
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (mas_a[i] % 2 == 0)
        {
            mas_b[j++] = mas_a[i];
        }
    }
    return j;
}

void new_matr (int8_t** matr, int n)
{
   for (int i = 0; i < n; i++)
   {
       matr[i] = new int8_t [n];
   }
}

void fill_matr (int8_t** matr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matr[i][j] = rand();
        }
    }
}

void cout_matr (int8_t** matr, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
           cout << (int) matr[i][j] << "\t";
        }
        cout << endl;
    }
}

void del_matr (int8_t** matr, int n)
{
    for (int i = 0; i < 2; i++)
    {
        delete []matr[i];
    }
}

void add_lines_matr (int8_t** matr_a, int8_t** matr_b, int num, int new_num)
{
    int k = new_num - num;
    for (int i = 0; i < new_num; i++)
    {

        matr_b[i] = new int8_t [num];
    }
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            matr_b[i + k][j] = matr_a[i][j];
        }
    }
}
int menu()
{
    int k = 0;
    cout << FORM_MAS << ". Формирование массива\n"
        << COUT_MAS << ". Печать массива\n"
        << DEL_MAS << ". Удаление из массива\n"
        << FORM_MATR << ". Формирование матрицы\n"
        << COUT_MATR << ". Печать матрицы\n"
        << ADD_LINES << ". Добавление строк\n"
        << EXIT << ". Выход\n";
    cin >> k;
    return k;
}

int num, k, new_num;
int mas_ready = 0;
int matr_ready = 0;
int8_t *mas;
int8_t *mas_b;
int8_t **matr;
int8_t **matr_b;

int main()
{
    int action = 0;
    do
    {
        action = menu();
        switch (action)
        {
        case FORM_MAS:
            cout << "Введите размерность массива: ";
            cin >> num;
            mas = new int8_t[num];
            fill_mas(mas, num);
            mas_ready = 1;
            break;
        case COUT_MAS:
            if (mas_ready)
            {
                cout_mas(mas, num);
            }
            break;
        case DEL_MAS:
            if (mas_ready)
            {
                mas_b = new int8_t[num];
                new_num = del_odd(mas, mas_b, num);
                cout_mas(mas_b, new_num);
                delete [] mas_b;
                delete [] mas;
                mas_ready = 0;
            }
            break;
        case FORM_MATR:
            cout << "Введите размерность матрицы: ";
            cin >> num;
            matr = new int8_t* [num];
            new_matr(matr, num);
            fill_matr(matr, num);
            matr_ready = 1;
            break;
        case COUT_MATR:
            if (matr_ready)
            {
                cout_matr(matr, num, num);
            }
            break;
        case ADD_LINES:
            if (matr_ready)
            {
                cout << "\n Введите K: ";
                cin >> k;
                new_num = num + k;
                matr_b = new int8_t* [new_num];
                add_lines_matr (matr, matr_b, num, new_num);
                cout_matr(matr_b, new_num, num);
                del_matr(matr_b, new_num);
                del_matr(matr, num);
                matr_ready = 0;
            }

            break;
        }
    }
    while (action != EXIT);

    return 0;
}
