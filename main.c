/*
    Студент: Мареева Ангелина Ильинична
    Группа: ПИ 11
    Домашнее задание 1. Обработка одномерного массива на языке C.
    Вариант 11: фильтрация по диапазону.
*/

#include <stdio.h>

#define MAX_SIZE 100

//Прототипы функций
void inputArray(int array[], int size);
void printArray(const int array[], int size);
int findMinIndex(const int array[], int size);
int findMaxIndex(const int array[], int size);
long long calculateSum(const int array[], int size);
double calculateAverage(const int array[], int size);
void countSigns(const int array[], int size, int *positive, int *negative, int *zero);
void countParity(const int array[], int size, int *even, int *odd);
void printRange(const int array[], int size, int a, int b);
void performIndividualTask(const int array[], int size, int a, int b);

//Ввод массива
void inputArray(int array[], int size)
{
    for (int i = 0; i < size; i++) {
        while (scanf("%d", &array[i]) != 1) {
            if (feof(stdin)) {
                printf("\nОшибка: неожиданный конец ввода.\n");
                return;
            }
            printf("Некорректное значение. Повторите ввод элемента %d: ", i + 1);
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) {
            }
        }
    }
}

//Печать массива
void printArray(const int array[], int size)
{
    for (int i = 0; i < size; i++) {
        printf("%d", array[i]);
        if (i != size - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

//Минимум (индекс первого)
int findMinIndex(const int array[], int size)
{
    int index = 0;
    for (int i = 1; i < size; i++) {
        if (array[i] < array[index]) {
            index = i;
        }
    }
    return index;
}

//Максимум (индекс первого)
int findMaxIndex(const int array[], int size)
{
    int index = 0;
    for (int i = 1; i < size; i++) {
        if (array[i] > array[index]) {
            index = i;
        }
    }
    return index;
}

//Сумма
long long calculateSum(const int array[], int size)
{
    long long sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum;
}

//Среднее арифметическое
double calculateAverage(const int array[], int size)
{
    if (size <= 0) {
        return 0.0;
    }
    return (double)calculateSum(array, size) / (double)size;
}

//Подсчёт положительных/отрицательных/нулевых
void countSigns(const int array[], int size, int *positive, int *negative, int *zero)
{
    *positive = 0;
    *negative = 0;
    *zero     = 0;

    for (int i = 0; i < size; i++) {
        if (array[i] > 0) {
            (*positive)++;
        } else if (array[i] < 0) {
            (*negative)++;
        } else {
            (*zero)++;
        }
    }
}

//Подсчёт чётных/нечётных
void countParity(const int array[], int size, int *even, int *odd)
{
    *even = 0;
    *odd  = 0;

    for (int i = 0; i < size; i++) {
        if (array[i] % 2 == 0) {
            (*even)++;
        } else {
            (*odd)++;
        }
    }
}

//Печать элементов диапазона [a, b]
void printRange(const int array[], int size, int a, int b)
{
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] >= a && array[i] <= b) {
            printf("Индекс %d: значение %d\n", i, array[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("Элементов в диапазоне [%d, %d] нет.\n", a, b);
    }
}

//Индивидуальное задание (вариант 11)
void performIndividualTask(const int array[], int size, int a, int b)
{
    int filtered[MAX_SIZE];
    int filteredSize = 0;

    for (int i = 0; i < size; i++) {
        if (array[i] >= a && array[i] <= b) {
            filtered[filteredSize] = array[i];
            filteredSize++;
        }
    }

    if (filteredSize == 0) {
        printf("В диапазоне [%d, %d] нет элементов — новый массив пуст.\n", a, b);
        return;
    }

    printf("Новый массив (%d элемент(ов)) из диапазона [%d, %d]:\n",
           filteredSize, a, b);
    printArray(filtered, filteredSize);

    printf("Минимум нового массива: %d\n", filtered[findMinIndex(filtered, filteredSize)]);
    printf("Максимум нового массива: %d\n", filtered[findMaxIndex(filtered, filteredSize)]);
    printf("Сумма нового массива: %lld\n", calculateSum(filtered, filteredSize));
}

//main
int main(void)
{
    int array[MAX_SIZE];
    int size;

    printf("Введите размер массива от 1 до %d: ", MAX_SIZE);
    if (scanf("%d", &size) != 1) {
        printf("Ошибка: размер массива должен быть целым числом.\n");
        return 1;
    }
    if (size < 1 || size > MAX_SIZE) {
        printf("Ошибка: недопустимый размер массива. Допустимо от 1 до %d.\n", MAX_SIZE);
        return 1;
    }

    printf("Введите %d целых чисел через пробел:\n", size);
    inputArray(array, size);

    printf("\nИсходный массив:\n");
    printArray(array, size);

    int minIndex = findMinIndex(array, size);
    int maxIndex = findMaxIndex(array, size);

    printf("\n--- Основные характеристики ---\n");
    printf("Минимальный элемент: %d (первый индекс: %d)\n", array[minIndex], minIndex);
    printf("Максимальный элемент: %d (первый индекс: %d)\n", array[maxIndex], maxIndex);

    long long sum = calculateSum(array, size);
    double average = calculateAverage(array, size);
    printf("Сумма элементов: %lld\n", sum);
    printf("Среднее арифметическое: %.2f\n", average);

    int positive = 0, negative = 0, zero = 0;
    countSigns(array, size, &positive, &negative, &zero);
    printf("Положительных: %d\n", positive);
    printf("Отрицательных: %d\n", negative);
    printf("Нулевых: %d\n", zero);

    int even = 0, odd = 0;
    countParity(array, size, &even, &odd);
    printf("Чётных: %d\n", even);
    printf("Нечётных: %d\n", odd);

    int a, b;
    printf("\nВведите границы диапазона a и b: ");
    if (scanf("%d %d", &a, &b) != 2) {
        printf("Ошибка: границы диапазона должны быть целыми числами.\n");
        return 1;
    }
    if (a > b) {
        int tmp = a;
        a = b;
        b = tmp;
        printf("Границы переставлены: [%d, %d]\n", a, b);
    }

    printf("\nЭлементы в диапазоне [%d, %d]:\n", a, b);
    printRange(array, size, a, b);

    printf("\n--- Индивидуальное задание (вариант 11) ---\n");
    performIndividualTask(array, size, a, b);

    return 0;
}