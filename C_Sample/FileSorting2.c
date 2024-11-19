#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �� �Լ� (������ ����)
int compare_words(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

int main() {
    FILE* inputFile, * outputFile;
    char buffer[1024];
    char* words[100]; // �ִ� 100���� �ܾ� ����
    int wordCount = 0;

    // �Է� ���� ����
    inputFile = fopen("filesorting2.txt", "r");
    if (inputFile == NULL) {
        perror("Failed to open input file");
        return 1;
    }

    // �ܾ� �б�
    while (fscanf(inputFile, "%1023s", buffer) == 1) { // �ܾ� ������ �б�
        words[wordCount] = malloc(strlen(buffer) + 1); // ���� �޸� �Ҵ�
        if (words[wordCount] == NULL) {
            perror("Memory allocation failed");
            fclose(inputFile);
            return 1;
        }
        strcpy(words[wordCount], buffer);
        wordCount++;
    }
    fclose(inputFile);

    // �ܾ� ����
    qsort(words, wordCount, sizeof(char*), compare_words);

    // ��� ���� ����
    outputFile = fopen("output_sorting2.txt", "w");
    if (outputFile == NULL) {
        perror("Failed to open output file");
        for (int i = 0; i < wordCount; i++) {
            free(words[i]); // �޸� ����
        }
        return 1;
    }

    // ���ĵ� �ܾ� ���
    for (int i = 0; i < wordCount; i++) {
        fprintf(outputFile, "%s\n", words[i]);
        free(words[i]); // �޸� ����
    }
    fclose(outputFile);

    printf("Words have been sorted and written to output_sorting2.txt.\n");
    return 0;
}


//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//// ���������� �����ϱ� ���� �� �Լ�
//int compare_words(const char* a, const char* b) {
//    return strcmp(a, b);
//}
//
//int main() {
//    FILE* inputFile, * outputFile;
//    char buffer[1024];
//    char* words[100]; // �ִ� 100���� �ܾ� ����
//    int wordCount = 0;
//
//    // �Է� ���� ����
//    inputFile = fopen("filesorting2.txt", "r");
//    if (inputFile == NULL) {
//        perror("Failed to open input file");
//        return 1;
//    }
//
//    // �ܾ� �б�
//    while (fscanf(inputFile, "%1023s", buffer) == 1) { // �ܾ� ������ �б�
//        words[wordCount] = malloc(strlen(buffer) + 1); // ���� �޸� �Ҵ�
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
//    // ���� ���ķ� �ܾ� ����
//    for (int i = 0; i < wordCount - 1; i++) {
//        for (int j = 0; j < wordCount - 1 - i; j++) {
//            if (compare_words(words[j], words[j + 1]) > 0) {
//                // �� �ܾ ���������� �߸� ���ĵǾ� ������ ��ȯ
//                char* temp = words[j];
//                words[j] = words[j + 1];
//                words[j + 1] = temp;
//            }
//        }
//    }
//
//    // ��� ���� ����
//    outputFile = fopen("output_sorting2.txt", "w");
//    if (outputFile == NULL) {
//        perror("Failed to open output file");
//        for (int i = 0; i < wordCount; i++) {
//            free(words[i]); // �޸� ����
//        }
//        return 1;
//    }
//
//    // ���ĵ� �ܾ� ���
//    for (int i = 0; i < wordCount; i++) {
//        fprintf(outputFile, "%s\n", words[i]);
//        free(words[i]); // �޸� ����
//    }
//    fclose(outputFile);
//
//    printf("Words have been sorted and written to output_sorting2.txt.\n");
//    return 0;
//}
