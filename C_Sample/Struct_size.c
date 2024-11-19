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

    // ����ü ũ�� ���
    printf("Size of struct MyStruct: %zu bytes\n", sizeof(s));

    // ����ü ũ�� ���
    printf("Size of union MyUnion: %zu bytes\n", sizeof(u));

    return 0;
}
