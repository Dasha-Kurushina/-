//Удаление Все элементы больше среднего арифметического элементов массива
//Добавление К элементов в начало массива
//Сдвинуть циклически на M элементов вправо
//Поиск Первый четный
//Сортировка Простое включение

//При решении задач использовать псевдодинамические  массивы. Псевдодинамические массивы реализуются следующим образом:
//1) при определении массива выделяется достаточно большое количество памяти:
//const int MAX_SIZE=100;//именованная константа
//int mas[MAX_SIZE];
//2) пользователь вводит реальное количество элементов массива меньшее N.
//int n;
//cout <<”\nEnter the size of array<”<<MAX_SIZE<<”:”;cin>>n;
//3) дальнейшая работа с массивом ограничивается заданной пользователем размерностью n.
//2. Формирование массива осуществляется с помощью датчика случайных чисел.
//Для этого можно использовать функцию  int rand(), которая возвращает псевдослучайное
//число из диапазона 0..RAND_MAX=32767, описание функции находится в файле <stdlib.h>.
//В массиве должны быть записаны и положительные и отрицательные элементы. Например,
//оператор a[I]=rand()%100-50; формирует псевдослучайное число из диапазона [-50;49].
//3. Вывод результатов должен выполняться после выполнения каждого задания.
//Элементы массива рекомендуется выводить в строчку, разделяя их между собой пробелом.
//1
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
    cout << "\n 1)Средрее арифметические = " << avg << endl;
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
    cout << "\n 2)Введите число, которое меньше количества чисел в массиве" << endl;
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
    cout << "\n 5)Сортировка: " << endl;
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
    cout << "\n 3)Введите число, на которое будем сдвигать: " << endl;
    cin >> j;
    cout << "\n 3)Числа циклически сдвинуты: " << endl;
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
    cout << "\n 13)Введите число для поиска: " << endl;
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
    cout << "\n 9)Введите число для поиска: " << endl;
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
    cout << "\nВведите размерность массива (<" << MAX_SIZE << "):";
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
    cout << "\n 4)Первый четный= " << first_even(mas_a, n) << endl;
    m = unsorted_search(mas_a, n);
    cout << "Выполнено " << m << " сравнений" << endl;
    sort_mas(mas_a, n);
    cout_mas(mas_a, n);
    m = sorted_search(mas_a, n);
    cout << "Выполнено " << m << " сравнений" << endl;

    return 0;
}
