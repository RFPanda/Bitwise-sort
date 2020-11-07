#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <locale.h>
#include <conio.h>
using namespace std;
const int n = 10, col_razr = 3;
int velich_razr(int chislo, int razr)
{
  while (razr > 1)
  {
    chislo /= 10;
    razr--;
  }
  return chislo % 10;
}

void sort_razr(int dop_mas[n][n], int mas[n], int razr)
{
  int mas_col[n], i, j, temp = 0;
  for (i = 0; i < n; i++)
    mas_col[i] = 0;
  for (i = 0; i < n; i++)
  {
    int a = velich_razr(mas[i], razr);
    dop_mas[mas_col[a]][a] = mas[i];
    mas_col[a]++;
  }
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < mas_col[i]; j++)
    {
      mas[temp] = dop_mas[j][i];
      temp++; // Khasanov A
    }
  }
}
int main() {
  setlocale(LC_ALL, "RUS");
  int dop_mas[n][n], razr;
  int N, mas[150];
  cout << "Введите кол-во эл-ов массива(до 150): ";
  cin >> N;
  cout << "Введите элементы массива: ";
  for (int i = 0; i < N; i++)
    cin >> mas[i];
  for (razr = 1; razr < 4; razr++)
  sort_razr(dop_mas, mas, razr);
  cout << "Отсортированный массив: ";
  for (int i = 0; i < N; i++)
    cout << mas[i] << ";";
  _getch();
  return 0;
}
