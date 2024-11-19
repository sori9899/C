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

    // 파일 열기
    file = fopen(filename, "r");
    if (!file) {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

    // 파일 내용 읽기
    while (fgets(buffer, MAX_SIZE, file) != NULL) {
        for (int i = 0; buffer[i] != '\0'; i++) {
            if (isdigit(buffer[i])) {
                numbers[number_count++] = buffer[i] - '0'; // 숫자로 변환
            }
            else if (isalpha(buffer[i])) {
                letters[letter_count++] = buffer[i];
            }
        }
    }

    fclose(file);

    // 숫자와 문자 정렬
    qsort(numbers, number_count, sizeof(int), compare_int);
    qsort(letters, letter_count, sizeof(char), compare_char);

    // 결과 출력
    printf("정렬된 숫자: ");
    for (int i = 0; i < number_count; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    printf("정렬된 문자: ");
    for (int i = 0; i < letter_count; i++) {
        printf("%c ", letters[i]);
    }
    printf("\n");

    return 0;
}
