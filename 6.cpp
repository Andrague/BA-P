#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

int main()
{
    int n = 0, f = 0;
    int max = 0;
    cout << "Enter n: ";
    cin >> n;
    int** MAS = new int* [n];
    do {
        cout << endl << "Choose manual filling (1) or random (2): " << endl;
        cin >> f;
    } while (f < 1 || f > 2);
    switch (f) {
    case 1: {
        // Ввод элементов массива
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << "[" << i << "][" << j << "] : " << MAS[i][j];
            }
            cout << endl;

        }
        break;
    }
    case 2: {
        // Заполнение случайными числами элементов массива
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                MAS[i][j] = 10 - rand() % 21;
                cout << setw(4) << MAS[i][j];
            }
            cout << endl;
        }
        break;
    }
    }
    cout << endl;
    for (int i = 0; i < n; i++)
        MAS[i] = new int[n];
    cout << "Matrix: " << endl;

    for (int i = 1; i < n; i++) {
        for (int j = n - 1; j > n - i - 1; j--) {
            cout << MAS[i][j] << " ";
            if (max < MAS[i][j])  max = MAS[i][j];
        }
        cout << endl;
    }
    cout << endl << "Max value is " << max << endl;
    for (int i = 0; i < n; i++)
        delete[i]MAS[i];
    delete[]MAS;
    return 0;
}





