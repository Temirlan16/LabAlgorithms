#include <iostream>
#include <locale>

using namespace std;

// Функция для определения, является ли число простым
bool prostoeli(int number) {
    if (number <= 1) {
        return false;
    }
    for (int i = 2; i * i <= number; ++i) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

// Функция для удаления простых чисел из массива и возвращения нового массива
int* ubratprost(int* arr, int& size) {
    // Подсчитываем количество простых чисел в массиве
    int prostcolichestvo = 0;
    for (int i = 0; i < size; ++i) {
        if (prostoeli(arr[i])) {
            prostcolichestvo++;
        }
    }

    // Создаем новый массив, который будет меньше на количество простых чисел
    int newSize = size - prostcolichestvo;
    int* newArr = new int[newSize];
    int newIndex = 0;

    // Копируем элементы из старого массива в новый, исключая простые числа
    for (int i = 0; i < size; ++i) {
        if (!prostoeli(arr[i])) {
            newArr[newIndex++] = arr[i];
        }
    }

    // Освобождаем память, занятую старым массивом
    delete[] arr;

    // Обновляем размер и возвращаем новый массив
    size = newSize;
    return newArr;
}

int main() {
    setlocale(LC_ALL, "Russian");

    int size;
    cout << "Введите размер массива: ";
    cin >> size;

    if (size <= 0) {
        cout << "Размер массива должен быть положительным числом." << endl;
        return 1;
    }

    int* arr = new int[size];

    cout << "Введите элементы массива:" << endl;
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    // Вызываем функцию для удаления простых чисел
    arr = ubratprost(arr, size);

    // Выводим результат
    cout << "Массив после удаления простых чисел: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Освобождаем память, занятую новым массивом
    delete[] arr;

    return 0;
}
