//#include <stdio.h>
//#include <stdlib.h>
//
//int main() {
//    FILE* inputFile;
//    int integer;
//    float decimal;
//    char word[50];
//
//    // 파일 열기
//    inputFile = fopen("Read_Num.txt", "r");
//    if (inputFile == NULL) {
//        perror("Failed to open input file");
//        return 1;
//    }
//
//    // 파일에서 정수, 실수, 문자열 읽기
//    while (fscanf(inputFile, "%d %f %s", &integer, &decimal, word) == 3) {
//        printf("Integer: %d, Decimal: %.2f, Word: %s\n", integer, decimal, word);
//    }
//
//    // 파일 닫기
//    fclose(inputFile);
//
//    return 0;
//}

#include <stdio.h>
#include<stdlib.h>

void main() {
	int* data = NULL, size = 0;
	int index, key = 1;
	char temp[20];

	int n;

	const char* file = "C:\\Users\\hyun9\\source\\repos\\C_Sample\\C_Sample\\File_input.txt";

	FILE* fp = fopen(file, "r");

	if (fp != NULL) {
		fscanf(fp, "%s %d", temp, &size);
		if (size != 0) {
			data = (int*)malloc(sizeof(int) * size);
			for (n = 0; n < size; n++) {
				fscanf(fp, "%d", &data[n]);
			}
		}
		fclose(fp);
	}

	for (n = 0; n < size; n++) {
		printf("%3d ", data[n]);
		if ((n + 1) % 10 == 0) {
			puts("\n");
		}
	}

	return 0;
}