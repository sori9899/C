#include <stdio.h>
#include <string.h>

// ����ü ����
struct Student {
    int id;              // �л� ID
    char name[50];       // �л� �̸�
    float grade;         // �л� ����
};

int main() {
    // ����ü ���� ����
    struct Student student1;

    // ����ü ��� �ʱ�ȭ
    student1.id = 1;
    strcpy(student1.name, "ȫ�浿");
    student1.grade = 90.5;

    // ����ü ���� ���
    printf("�л� ID: %d\n", student1.id);
    printf("�л� �̸�: %s\n", student1.name);
    printf("�л� ����: %.2f\n", student1.grade);

    // �迭�� �̿��� ����ü ����
    struct Student students[2] = {
        {2, "��ö��", 85.0},
        {3, "�̿���", 92.3}
    };

    for (int i = 0; i < 2; i++) {
        printf("\n�л� ID: %d\n", students[i].id);
        printf("�л� �̸�: %s\n", students[i].name);
        printf("�л� ����: %.2f\n", students[i].grade);
    }

    return 0;
}
