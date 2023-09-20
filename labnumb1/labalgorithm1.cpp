#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int M, N;

    // Вводим размеры массивов
    cout << "Введите размер массива A: ";
    cin >> M;
    cout << "Введите размер массива B: ";
    cin >> N;

    // Создаем массивы A и B
    int* A = new int[M];
    int* B = new int[N];

    // Вводим элементы массива A
    cout << "Введите элементы массива A:" << endl;
    for (int i = 0; i < M; i++) {
        cin >> A[i];
    }

    // Вводим элементы массива B
    cout << "Введите элементы массива B:" << endl;
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    // Создаем третий массив для общих элементов без повторений
    int* C = new int[M + N]; // Максимальный размер равен сумме размеров A и B
    int sizeC = 0; // Размер третьего массива

    // Поиск общих элементов
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (A[i] == B[j]) {
                // Проверяем, был ли элемент уже добавлен
                bool Duplicat = false;
                for (int k = 0; k < sizeC; k++) {
                    if (C[k] == A[i]) {
                        Duplicat = true;
                        break;
                    }
                }
                // Если элемент не был добавлен, добавляем его
                if (!Duplicat) {
                    C[sizeC++] = A[i];
                }
                break; // Выходим из внутреннего цикла после нахождения общего элемента
            }
        }
    }

    // Выводим общих элементов без повторений
    cout << "Общие элементы массивов A и B:" << endl;
    for (int i = 0; i < sizeC; i++) {
        cout << C[i] << " ";
    }
    cout << endl;

    // Освобождаем выделенную память
    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}
