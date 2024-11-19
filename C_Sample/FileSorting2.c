#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 비교 함수 (사전순 정렬)
int compare_words(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

int main() {
    FILE* inputFile, * outputFile;
    char buffer[1024];
    char* words[100]; // 최대 100개의 단어 저장
    int wordCount = 0;

    // 입력 파일 열기
    inputFile = fopen("filesorting2.txt", "r");
    if (inputFile == NULL) {
        perror("Failed to open input file");
        return 1;
    }

    // 단어 읽기
    while (fscanf(inputFile, "%1023s", buffer) == 1) { // 단어 단위로 읽기
        words[wordCount] = malloc(strlen(buffer) + 1); // 동적 메모리 할당
        if (words[wordCount] == NULL) {
            perror("Memory allocation failed");
            fclose(inputFile);
            return 1;
        }
        strcpy(words[wordCount], buffer);
        wordCount++;
    }
    fclose(inputFile);

    // 단어 정렬
    qsort(words, wordCount, sizeof(char*), compare_words);

    // 출력 파일 열기
    outputFile = fopen("output_sorting2.txt", "w");
    if (outputFile == NULL) {
        perror("Failed to open output file");
        for (int i = 0; i < wordCount; i++) {
            free(words[i]); // 메모리 해제
        }
        return 1;
    }

    // 정렬된 단어 출력
    for (int i = 0; i < wordCount; i++) {
        fprintf(outputFile, "%s\n", words[i]);
        free(words[i]); // 메모리 해제
    }
    fclose(outputFile);

    printf("Words have been sorted and written to output_sorting2.txt.\n");
    return 0;
}


//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//// 사전순으로 정렬하기 위한 비교 함수
//int compare_words(const char* a, const char* b) {
//    return strcmp(a, b);
//}
//
//int main() {
//    FILE* inputFile, * outputFile;
//    char buffer[1024];
//    char* words[100]; // 최대 100개의 단어 저장
//    int wordCount = 0;
//
//    // 입력 파일 열기
//    inputFile = fopen("filesorting2.txt", "r");
//    if (inputFile == NULL) {
//        perror("Failed to open input file");
//        return 1;
//    }
//
//    // 단어 읽기
//    while (fscanf(inputFile, "%1023s", buffer) == 1) { // 단어 단위로 읽기
//        words[wordCount] = malloc(strlen(buffer) + 1); // 동적 메모리 할당
//        if (words[wordCount] == NULL) {
//            perror("Memory allocation failed");
//            fclose(inputFile);
//            return 1;
//        }
//        strcpy(words[wordCount], buffer);
//        wordCount++;
//    }
//    fclose(inputFile);
//
//    // 버블 정렬로 단어 정렬
//    for (int i = 0; i < wordCount - 1; i++) {
//        for (int j = 0; j < wordCount - 1 - i; j++) {
//            if (compare_words(words[j], words[j + 1]) > 0) {
//                // 두 단어가 사전순으로 잘못 정렬되어 있으면 교환
//                char* temp = words[j];
//                words[j] = words[j + 1];
//                words[j + 1] = temp;
//            }
//        }
//    }
//
//    // 출력 파일 열기
//    outputFile = fopen("output_sorting2.txt", "w");
//    if (outputFile == NULL) {
//        perror("Failed to open output file");
//        for (int i = 0; i < wordCount; i++) {
//            free(words[i]); // 메모리 해제
//        }
//        return 1;
//    }
//
//    // 정렬된 단어 출력
//    for (int i = 0; i < wordCount; i++) {
//        fprintf(outputFile, "%s\n", words[i]);
//        free(words[i]); // 메모리 해제
//    }
//    fclose(outputFile);
//
//    printf("Words have been sorted and written to output_sorting2.txt.\n");
//    return 0;
//}
