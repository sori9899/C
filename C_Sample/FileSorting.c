#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 1000

int compare_int(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int compare_char(const void* a, const void* b) {
    return (*(char*)a - *(char*)b);
}

int main() {
    FILE* file;
    char filename[] = "input.txt";
    char buffer[MAX_SIZE];
    char letters[MAX_SIZE];
    int numbers[MAX_SIZE];
    int letter_count = 0, number_count = 0;

    // ���� ����
    file = fopen(filename, "r");
    if (!file) {
        printf("������ �� �� �����ϴ�.\n");
        return 1;
    }

    // ���� ���� �б�
    while (fgets(buffer, MAX_SIZE, file) != NULL) {
        for (int i = 0; buffer[i] != '\0'; i++) {
            if (isdigit(buffer[i])) {
                numbers[number_count++] = buffer[i] - '0'; // ���ڷ� ��ȯ
            }
            else if (isalpha(buffer[i])) {
                letters[letter_count++] = buffer[i];
            }
        }
    }

    fclose(file);

    // ���ڿ� ���� ����
    qsort(numbers, number_count, sizeof(int), compare_int);
    qsort(letters, letter_count, sizeof(char), compare_char);

    // ��� ���
    printf("���ĵ� ����: ");
    for (int i = 0; i < number_count; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    printf("���ĵ� ����: ");
    for (int i = 0; i < letter_count; i++) {
        printf("%c ", letters[i]);
    }
    printf("\n");

    return 0;
}
