#include <stdio.h>
#include <string.h>

// Функция для проверки, можно ли одно слово получить из другого циклическим сдвигом символов
int isCyclicShift(char *word1, char *word2) {
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    if (len1 != len2) {
        return 0; // Если длины слов не совпадают, они не могут быть циклическими сдвигами друг друга
    }
    char temp[2 * len1 + 1];
    strcpy(temp, word1);
    strcat(temp, word1); // Дописываем word1 к самому себе
    if (strstr(temp, word2) != NULL) {
        return 1; // Нашли сдвиг, возвращаем истину
    }
    return 0; // Если ни один из циклических сдвигов не совпал, возвращаем ложь
}

int main() {
    char text[1000]; // Предполагаем, что текст не превышает 1000 символов
    printf("Введите текст: ");
    fgets(text, sizeof(text), stdin);

    // Получаем отдельные слова из текста и удаляем лишние пробелы
    char *token = strtok(text, " \n");
    char prev_word[100] = ""; // Переменная для хранения предыдущего слова
    while (token != NULL) {
        char current_word[100]; // Предполагаем, что длина слова не превышает 100 символов
        strcpy(current_word, token);

        // Проверяем, можно ли одно слово получить из другого циклическим сдвигом символов
        if (strcmp(prev_word, "") != 0 && isCyclicShift(prev_word, current_word)) {
            // Если можно, пропускаем вывод предыдущего слова и текущего слова
            strcpy(prev_word, ""); // Очищаем prev_word
        } else {
            // Если нельзя, выводим предыдущее слово (если оно есть) и обновляем prev_word
            if (strcmp(prev_word, "") != 0) {
                printf("%s ", prev_word);
            }
            strcpy(prev_word, current_word);
        }

        // Получаем следующее слово
        token = strtok(NULL, " \n");
    }

    // Выводим последнее слово (если оно есть)
    if (strcmp(prev_word, "") != 0) {
        printf("%s ", prev_word);
    }

    return 0;
}
