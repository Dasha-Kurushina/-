#include <iostream>
#include <stdlib.h>
using namespace std;

const int MAX_SIZE=100;

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

int del_from_mas(int8_t mas_a[], int8_t mas_b[], int n)
{
    float avg = 0;
    for (int i = 0; i < n; i++)
    {
        avg += mas_a[i];
    }
    avg /= n;
    cout << "1)Средрее арифметические = " << avg << endl;
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (mas_a[i] < avg) mas_b[j++] = mas_a[i];
    }
    cout << "Числа, которые меньше ср.ар. " << avg << ":" << endl;
    return j;
}

int add_to_mas(int8_t mas_a[], int8_t mas_b[], int n, int k)
{
    cout << "2)Введите число, которое меньше количества чисел в массиве" << endl;
    cin >> k;
    fill_mas(mas_b, k);
    int j = k;
    for (int i = 0; i < n; i++)

    {
        mas_b[j++] = mas_a[i];
    }
    return j;
}

void sort_mas(int8_t a[], int n)
{
    int i, j, x;
    cout << "5)Сортировка: " << endl;
    for(i = 1; i < n; i++)
    {
        x = a[i];//запомнили элемент, который будем вставлять
        j = i - 1;
        while(x < a[j] && j>=0)//поиск подходящего места
        {
            a[j+1] = a[j];//сдвиг вправо
            j--;
        }
        a[j+1] = x;//вставка элемента
    }
}

void shift_mas(int8_t mas_a[], int8_t mas_b[], int n)
{
    int j;
    cout << "3)Введите число, на которое будем сдвигать: " << endl;
    cin >> j;
    cout << "3)Числа циклически сдвинуты: " << endl;
    for (int i = 0; i < n; i++)
    {
        if (j < n)

        {
            mas_b[j] = mas_a[i];
            j++;
        }
        else
        {
            mas_b[j - n] = mas_a[i];
            j++;
        }
    }
}



int first_even (int8_t mas[], int n)
{
    int i = -1;
    int x = 1;
    do {
        i++;
        x = mas[i] % 2;
    } while (x != 0);
    return mas[i];
}

int sorted_search ( int8_t mas[], int n)
{
    int left = 0;
    int right = n-1;
    int middle;
    int j = 0;
    int x;
    cout << "13)Введите число для поиска: " << endl;
    cin >> x;
    do
    {
        middle = (left + right) / 2;
        if(mas[middle] < x & ++j)
        {
            left = middle + 1;
        }
        else
        {
            right = middle;
        }
    }while(left != right);
    if(mas[left] == x)
    {
        cout << "Найден элемент " << x << " под номером " << left << endl;
    }
    else
    {
        cout << "Элемент " << x << " не найден" << endl;
    }
    return j;
}

int unsorted_search ( int8_t mas[], int n)
{
    int i = 0;
    int x = 0;
    int k = 0;
    int j = 0;
    cout << "9)Введите число для поиска: " << endl;
    cin >> x;
    for ( i = 0; i < n; i++)
    {
        if (mas[i] == x & ++j)
        {
            k = i;
            break;
        }
    }
    if ( k == i )
    {
        cout << "Найден элемент " << x << " под номером " << k << endl;
    }
    else
    {
        cout << "Элемент " << x << " не найден" << endl;
    }
    return j;
}


int main()
{
    int n;
    cout << "Введите размерность массива (<" << MAX_SIZE << "):";
    cin >> n;

    int8_t mas_a[MAX_SIZE];
    int8_t mas_b[MAX_SIZE];
    int8_t mas_c[MAX_SIZE];
    int8_t mas_d[MAX_SIZE];

    fill_mas(mas_a, n);
    cout_mas(mas_a, n);
    int m = del_from_mas(mas_a, mas_b, n);
    cout_mas(mas_b, m);
    m = add_to_mas(mas_a, mas_c, n, 10);
    cout_mas(mas_c, m);
    shift_mas(mas_a, mas_d, n);
    cout_mas(mas_d, n);
    cout << "4)Первый четный= " << first_even(mas_a, n) << endl;
    m = unsorted_search(mas_a, n);
    cout << "Выполнено " << m << " сравнений" << endl;
    sort_mas(mas_a, n);
    cout_mas(mas_a, n);
    m = sorted_search(mas_a, n);
    cout << "Выполнено " << m << " сравнений" << endl;

    return 0;
}