#include <stdio.h>
#include <stdlib.h>

// Функція для введення масиву за допомогою вказівників
void inputArray(int *arr, int n) {
    printf("Введіть %d елементів масиву:\n", n);
    for (int i = 0; i < n; i++) {
        printf("[%d]: ", i);
        // (arr + i) - це адреса i-го елемента
        scanf("%d", (arr + i)); 
    }
}

// Функція для виведення масиву за допомогою вказівників
void printArray(int *arr, int n) {
    printf("Масив: [ ");
    for (int i = 0; i < n; i++) {
        // *(arr + i) - розіменування вказівника для отримання значення
        printf("%d ", *(arr + i));
    }
    printf("]\n");
}

// Функція для пошуку максимального додатного та заміни від'ємних
void processArray(int *arr, int n) {
    int maxPos = -1;
    int foundPos = 0;

    // 1. Шукаємо максимальний серед додатних (> 0)
    for (int i = 0; i < n; i++) {
        int val = *(arr + i);
        if (val > 0) {
            if (!foundPos || val > maxPos) {
                maxPos = val;
                foundPos = 1;
            }
        }
    }

    // 2. Якщо знайшли хоча б одне додатне, замінюємо від'ємні
    if (foundPos) {
        printf("\nМаксимальний додатний елемент: %d\n", maxPos);
        for (int i = 0; i < n; i++) {
            if (*(arr + i) < 0) {
                *(arr + i) = maxPos;
            }
        }
        printf("Заміна виконана.\n");
    } else {
        printf("\nДодатних елементів не знайдено, заміна неможлива.\n");
    }
}

int main() {
    int choice, n;

    do {
        printf("\n=== МЕНЮ (Вказівники) ===\n");
        printf("1. Ввести масив та виконати заміну\n");
        printf("0. Вийти\n");
        printf("Ваш вибір: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Введіть кількість елементів n: ");
            scanf("%d", &n);

            if (n <= 0) {
                printf("Розмір має бути додатним!\n");
                continue;
            }

            // Динамічне виділення пам'яті
            int *a = (int *)malloc(n * sizeof(int));

            inputArray(a, n);
            printf("\nПочатковий ");
            printArray(a, n);

            processArray(a, n);

            printf("Оновлений ");
            printArray(a, n);

            free(a); // Звільнення пам'яті
            printf("\nНатисніть Enter...");
            getchar(); getchar();
        }
    } while (choice != 0);

    printf("Бувай!\n");
    return 0;
}