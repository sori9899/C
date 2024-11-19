#include <stdio.h>

int main() {
    FILE* file = fopen("user_data.txt", "r");
    if (file == NULL) {
        perror("파일을 열 수 없습니다.");
        return 1;
    }

    char buffer[100];
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }

    fclose(file);
    return 0;
}


