#include <iostream>
#include <locale.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    int M, N;

    // вводим массивы
    cout << "Введите размер массива A: ";
    cin >> M;
    cout << "Введите размер массива B: ";
    cin >> N;

    // Создаем два массива A и B и используем динам память
    int* A = new int[M];
    int* B = new int[N];

    // Вводим массив а
    cout << "Введите элементы массива A:" << endl;
    for (int i = 0; i < M; i++) {
        cin >> A[i];
    }

    // Вводим массив в
    cout << "Введите элементы массива B:" << endl;
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    // Вычисляем третий массив
    int maxSize = M + N;

    // Создаем третий массив C с макс размером
    int* C = new int[maxSize];
    int sizeC = 0; // Размер третьего массива

    // Ищем элементы, которые есть в A, но отсутствуют в B, и добавляем их в C 
    for (int i = 0; i < M; i++) {
        bool esliB = false;
        for (int j = 0; j < N; j++) {
            if (A[i] == B[j]) {
                esliB = true;
                break;
            }
        }
        // Если элемент не найден в B, добавляем его в C 
        if (!esliB) {
            bool Duplicat = false;
            for (int k = 0; k < sizeC; k++) {
                if (C[k] == A[i]) {
                    Duplicat = true;
                    break;
                }
            }
            if (!Duplicat) {
                C[sizeC++] = A[i];
            }
        }
    }

    // Ищем элементы, которые есть в B, но отсутствуют в A, и добавляем их в C 
    for (int i = 0; i < N; i++) {
        bool esliA = false;
        for (int j = 0; j < M; j++) {
            if (B[i] == A[j]) {
                esliA = true;
                break;
            }
        }
        // Если элемент не найден в A, добавляем его в C 
        if (!esliA) {
            bool Duplicat = false;
            for (int k = 0; k < sizeC; k++) {
                if (C[k] == B[i]) {
                    Duplicat = true;
                    break;
                }
            }
            if (!Duplicat) {
                C[sizeC++] = B[i];
            }
        }
    }

    // Выводим элементы из A и B, которые не являются общими
    cout << "Элементы, которые не являются общими для массивов A и B:" << endl;
    for (int i = 0; i < sizeC; i++) {
        cout << C[i] << " ";
    }
    cout << endl;

    // Освобождаем память
    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}
