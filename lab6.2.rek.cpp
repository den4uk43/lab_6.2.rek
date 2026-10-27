#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Рекурсивне формування масиву
void F(int* a, const int size, const int Low, const int High, int i = 0) {
    if (i >= size) {
        return;
    }
    a[i] = Low + rand() % (High - Low + 1);
    F(a, size, Low, High, i + 1);
}

// Рекурсивне форматне виведення масиву
void out(const int* a, const int size, int i = 0) {
    if (i >= size) {
        cout << endl;
        return;
    }
    cout << setw(6) << a[i];
    out(a, size, i + 1);
}

// Рекурсивний пошук максимального елемента
int FindMax(const int* a, const int size, int i = 1, int max = 0) {
    if (i == 1) {
        max = a[0];
    }
    if (i >= size) {
        return max;
    }
    if (a[i] > max) {
        max = a[i];
    }
    return FindMax(a, size, i + 1, max);
}

// Рекурсивний пошук мінімального елемента
int FindMin(const int* a, const int size, int i = 1, int min = 0) {
    if (i == 1) {
        min = a[0];
    }
    if (i >= size) {
        return min;
    }
    if (a[i] < min) {
        min = a[i];
    }
    return FindMin(a, size, i + 1, min);
}

// Обчислення суми за допомогою рекурсивних функцій
int Sum(const int* a, const int size) {
    return FindMax(a, size) + FindMin(a, size);
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    int n;
    cout << "count elements n: ";
    cin >> n;

    if (n <= 0) {
        cout << "massive size can be > 0." << endl;
        return 1;
    }

    int* a = new int[n];
    int Low = -50, High = 50;

    F(a, n, Low, High);

    cout << "massive:" << endl;
    out(a, n);

    int maximal = FindMax(a, n);
    cout << "max= " << maximal << endl;

    int minimal = FindMin(a, n);
    cout << "min= " << minimal << endl;

    int sum = Sum(a, n);
    cout << "sum (max+min) = " << sum << endl;

    delete[] a;
    return 0;
}