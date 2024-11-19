#include <stdio.h>
#include <string.h>

// 구조체 정의
struct Student {
    int id;              // 학생 ID
    char name[50];       // 학생 이름
    float grade;         // 학생 성적
};

int main() {
    // 구조체 변수 선언
    struct Student student1;

    // 구조체 멤버 초기화
    student1.id = 1;
    strcpy(student1.name, "홍길동");
    student1.grade = 90.5;

    // 구조체 내용 출력
    printf("학생 ID: %d\n", student1.id);
    printf("학생 이름: %s\n", student1.name);
    printf("학생 성적: %.2f\n", student1.grade);

    // 배열을 이용한 구조체 관리
    struct Student students[2] = {
        {2, "김철수", 85.0},
        {3, "이영희", 92.3}
    };

    for (int i = 0; i < 2; i++) {
        printf("\n학생 ID: %d\n", students[i].id);
        printf("학생 이름: %s\n", students[i].name);
        printf("학생 성적: %.2f\n", students[i].grade);
    }

    return 0;
}
