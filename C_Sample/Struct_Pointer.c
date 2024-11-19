#include <stdio.h>

// 구조체 정의
struct Point {
    int x;
    int y;
};

int main() {
    struct Point p1 = { 10, 20 };
    struct Point* p_ptr = &p1; // 구조체 포인터에 주소 저장

    // 구조체 포인터로 멤버에 접근
    printf("x: %d, y: %d\n", p_ptr->x, p_ptr->y);

    // 포인터를 사용하여 값 변경
    p_ptr->x = 30;
    p_ptr->y = 40;

    printf("x: %d, y: %d\n", p_ptr->x, p_ptr->y);

    return 0;
}
