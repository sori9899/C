#include <stdio.h>

struct MyStruct {
    char a;       // 1 byte
    int b;        // 4 bytes
    double c;     // 8 bytes
};

union MyUnion {
    char a;       // 1 byte
    int b;        // 4 bytes
    double c;     // 8 bytes
};

int main() {
    struct MyStruct s;
    union MyUnion u;

    // 구조체 크기 출력
    printf("Size of struct MyStruct: %zu bytes\n", sizeof(s));

    // 공용체 크기 출력
    printf("Size of union MyUnion: %zu bytes\n", sizeof(u));

    return 0;
}
