#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
} Student;

int main() {
    Student students[50] = {
        {1, "Nguyen Son Minh", 20, "0123456789"},
        {2, "Hoang Cuong Cat", 21, "0987654321"},
        {3, "Le Van Luyen", 22, "0345678901"},
        {4, "Tran Minh Cuong", 23, "0567890123"},
        {5, "Hoang Van anh", 24, "0789012345"}
    };
    int numStudents = 5;
    int idToFind, i, found = 0;

    printf("Nhap ID cua sinh vien can chinh sua: ");
    scanf("%d", &idToFind);

    for (i = 0; i < numStudents; i++) {
        if (students[i].id == idToFind) {
            found = 1;

            printf("Thong tin hien tai cua sinh vien:\n");
            printf("ID: %d\n", students[i].id);
            printf("Ten: %s\n", students[i].name);
            printf("Tuoi: %d\n", students[i].age);
            printf("So dien thoai: %s\n", students[i].phoneNumber);

            printf("\nNhap ten moi: ");
            getchar();
            fgets(students[i].name, sizeof(students[i].name), stdin);
            students[i].name[strcspn(students[i].name, "\n")] = '\0';

            printf("Nhap tuoi moi: ");
            scanf("%d", &students[i].age);

            break;
        }
    }

    if (!found) {
        printf("Khong tim thay sinh vien voi ID: %d\n", idToFind);
    }

    printf("\nDanh sach sinh vien sau khi chinh sua:\n");
    for (i = 0; i < numStudents; i++) {
        printf("ID: %d\n", students[i].id);
        printf("Ten: %s\n", students[i].name);
        printf("Tuoi: %d\n", students[i].age);
        printf("So dien thoai: %s\n", students[i].phoneNumber);
        printf("-------------------------\n");
    }

    return 0;
}

