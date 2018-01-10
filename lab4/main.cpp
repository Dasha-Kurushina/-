//Отсортировать по возрастанию только те элементы массива, которые являются простыми числами.
//Все четные строки матрицы сдвинуть циклически на К элементов вправо.
//Подсчитать количество слов в строке.

#include <iostream>
#include <string.h>
#include <stdio.h>
#define MAX_SIZE 100

using namespace std;

int is_prime(int num, int i)
{
    if (num == 1)
    {
        return 1;
    }
    if (i == 1)
    {
        return 1;
    }
    else
    {
        if(num % i == 0)
        {
           return 0;
        }
        else
        {
           is_prime(num, i - 1);
        }
    }
}

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

void sort_prime(int8_t a[], int n)
{
    int i, j, x;
    int m = 0;
    int8_t prime[MAX_SIZE];
    for (i = 0; i < n; i++)
    {
        x = abs(a[i]);
        if (is_prime(x, x - 1))
        {
            prime[m++] = i;
        }
    }
    for(i = 1; i < m; i++)
    {
        x = a[prime[i]];//запомнили элемент, который будем вставлять
        j = i - 1;
        while(x < a[prime[j]] && j>=0)//поиск подходящего места
        {
            a[prime[j+1]] = a[prime[j]];//сдвиг впр
            j--;
        }
        a[prime[j+1]] = x;
    }
}

void fill_matr(int8_t matr[][MAX_SIZE], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
           matr[i][j] = rand();
        }
    }
}

void cout_matr (int8_t matr[][MAX_SIZE], int n, int m)
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

void matr_shift(int8_t matr_a[][MAX_SIZE], int n, int m)
{
    int K;
    int8_t matr_b[MAX_SIZE][MAX_SIZE];
    cout << "\n Введите число, на которое будем сдвигать: " << endl;
    cin >> K;

    for (int i = 0; i < n; i++)
    {
        int k = K;
        for (int j = 0; j < m; j++)
        {
            if (i % 2 != 0)
            {
                if (k < m)
                {
                   matr_b[i][k++] = matr_a[i][j];
                }
                else
                {
                   matr_b[i][k++ - m] = matr_a[i][j];
                }
            }
            else
            {
                matr_b[i][j] = matr_a[i][j];
            }
        }
    }
    cout_matr(matr_b, n, m);
}

int word_count (char *str)
{
    int res = 1;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == ' ' )
        {
            res++;
        }
    }
    return res;
}

int main()
{
    char str[MAX_SIZE];
    cout << "Введите строку, разделенную пробелами (латиницей)" << endl;
    fgets(str, MAX_SIZE, stdin);
    cout << word_count(str);
    int n;
    cout << "\nВведите размерность массива (<" << MAX_SIZE << "):";
    cin >> n;
    int8_t mas[MAX_SIZE];
    fill_mas(mas, n);
    cout_mas(mas, n);
    sort_prime(mas, n);
    cout_mas(mas, n);
    cout << "\nВведите размерность матрицы (<" << MAX_SIZE << "):";
    cin >> n;
    int8_t matr[MAX_SIZE][MAX_SIZE];
    fill_matr(matr, n, n);
    cout_matr(matr, n, n);
    matr_shift(matr, n, n);

    return 0;
}
