#include <stdio.h>

// ����ü ����
struct Point {
    int x;
    int y;
};

int main() {
    struct Point p1 = { 10, 20 };
    struct Point* p_ptr = &p1; // ����ü �����Ϳ� �ּ� ����

    // ����ü �����ͷ� ����� ����
    printf("x: %d, y: %d\n", p_ptr->x, p_ptr->y);

    // �����͸� ����Ͽ� �� ����
    p_ptr->x = 30;
    p_ptr->y = 40;

    printf("x: %d, y: %d\n", p_ptr->x, p_ptr->y);

    return 0;
}
