#include <iostream>
#include <vector>
#include <string>
#include <windows.h>

using namespace std;

int main()
{
    // Українська
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    const int n = 14;

    // Список
    vector<string> people(n);

    cout << "Введіть імена 14 людей:" << endl;

    // Вводимо імена
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << ": ";
        getline(cin, people[i]);
    }

    // Створюємо таблицю для зберігання розкладу зустрічей
    vector<vector<string>> schedule(n, vector<string>(n - 1));

    // Створюємо список номерів людей
    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        a[i] = i;
    }

    // Створюємо 13 раундів зустрічей
    for (int round = 0; round < n - 1; round++)
    {
        // У кожному раунді створюємо 7 пар
        for (int i = 0; i < n / 2; i++)
        {
            int first = a[i];
            int second = a[n - 1 - i];

            // Записуємо, з ким зустрічається кожна людина
            schedule[first][round] = people[second];
            schedule[second][round] = people[first];
        }

        // Запам'ятовуємо останню людину
        int last = a[n - 1];

        // Зсуваємо людей для створення нових пар
        for (int i = n - 1; i > 1; i--)
        {
            a[i] = a[i - 1];
        }

        // Ставимо останню людину на друге місце
        a[1] = last;
    }

    cout << "          РОЗКЛАД ЗУСТРІЧЕЙ" << endl;

    // Виводимо розклад для кожної людини
    for (int i = 0; i < n; i++)
    {
        cout << "\n" << people[i] << ":" << endl;

        // Виводимо 13 зустрічей кожної людини
        for (int j = 0; j < n - 1; j++)
        {
            cout << "Зустріч на " << j + 1 <<" годину ->"
                << schedule[i][j] << endl;
        }
    }

    return 0;
}