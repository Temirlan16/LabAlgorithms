#include <iostream>
#include <locale.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian"); 
    int M, N;

    // Запрашиваем у пользователя размеры двух массивов
    cout << "Введите размер массива A: ";
    cin >> M;
    cout << "Введите размер массива B: ";
    cin >> N;

    // Создаем два массива A и B с учетом введенных размеров (с использованием динамического выделения памяти)
    int* A = new int[M];
    int* B = new int[N];

    // Вводим  массив A
    cout << "Введите элементы массива A:" << endl;
    for (int i = 0; i < M; i++) {
        cin >> A[i];
    }

    // Вводим  массив B
    cout << "Введите элементы массива B:" << endl;
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    // Создаем третий массив C для хранения элементов из A, которых нет в B (также с динамическим выделением памяти)
    int* C = new int[M]; //размер
    int sizeC = 0; // Размер третьего массива

    // Ищем элементы, которые есть в A, но отсутствуют в B
    for (int i = 0; i < M; i++) {
        bool isFoundInB = false;
        for (int j = 0; j < N; j++) {
            if (A[i] == B[j]) {
                isFoundInB = true;
                break;
            }
        }
        // Если элемент не найден в B, добавляем его в C 
        if (!isFoundInB) {
            bool isDuplicate = false;
            for (int k = 0; k < sizeC; k++) {
                if (C[k] == A[i]) {
                    isDuplicate = true;
                    break;
                }
            }
            if (!isDuplicate) {
                C[sizeC++] = A[i];
            }
        }
    }

    // Выводим элементы из A, которых нет в B
    cout << "Элементы массива A, которых нет в B:" << endl;
    for (int i = 0; i < sizeC; i++) {
        cout << C[i] << " ";
    }
    cout << endl;

    // Освобождаем выделенную память, чтобы избежать утечек памяти
    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}
