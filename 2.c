#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 1. Функція для ініціалізації масиву випадковими числами [-100; 100]
void initializeArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        *(arr + i) = rand() % 201 - 100;
    }
}

// 2. Функція для виведення масиву на екран
void printArray(int *arr, int n) {
    printf("Елементи масиву: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

// 3. Показник 1: Добуток додатних елементів
long long calculateProductOfPositives(int *arr, int n) {
    long long product = 1;
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (*(arr + i) > 0) {
            product *= *(arr + i);
            found = 1;
        }
    }
    return found ? product : 0;
}

// 4. Показник 2: Сума елементів до останнього додатного
int calculateSumBeforeLastPositive(int *arr, int n) {
    int lastPositiveIndex = -1;
    int sum = 0;

    // Шукаємо індекс останнього додатного
    for (int i = 0; i < n; i++) {
        if (*(arr + i) > 0) {
            lastPositiveIndex = i;
        }
    }

    if (lastPositiveIndex == -1) return 0;

    // Сумуємо елементи до цього індексу
    for (int i = 0; i < lastPositiveIndex; i++) {
        sum += *(arr + i);
    }
    return sum;
}

// Головна програма: лише виклики функцій
int main() {
    int choice;
    int n;
    srand(time(NULL)); // Ініціалізація генератора випадкових чисел

    do {
        printf("\n--- МЕНЮ ---\n");
        printf("1. Згенерувати масив та обчислити показники\n");
        printf("0. Вийти з програми\n");
        printf("Ваш вибір: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Введіть розмір масиву (n): ");
            scanf("%d", &n);

            if (n <= 0) {
                printf("Помилка: n має бути додатним числом!\n");
                continue;
            }

            // Динамічне виділення пам'яті
            int *arr = (int *)malloc(n * sizeof(int));

            // Виклик функцій
            initializeArray(arr, n);
            printArray(arr, n);

            long long product = calculateProductOfPositives(arr, n);
            int sum = calculateSumBeforeLastPositive(arr, n);

            // Виведення результатів
            printf("\nРезультати:\n");
            if (product == 0) printf("1. Додатних елементів не знайдено.\n");
            else printf("1. Добуток додатних: %lld\n", product);
            
            printf("2. Сума до останнього додатного: %d\n", sum);

            free(arr); // Звільнення пам'яті
        }
    } while (choice != 0);

    printf("Роботу завершено.\n");
    return 0;
}