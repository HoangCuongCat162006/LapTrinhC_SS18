#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[100];
    int age;
    char phoneNumber[15];
};

void displayStudents(struct Student students[], int n) {
    printf("\nDanh sach sinh vien:\n");
    for (int i = 0; i < n; i++) {
        printf("Sinh vien %d:\n", i + 1);
        printf("ID: %d\n", students[i].id);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("Phone Number: %s\n", students[i].phoneNumber);
        printf("-----------------------------\n");
    }
}

int main() {
    struct Student students[50];
    int numStudents = 5;

    // Kh?i t?o 5 sinh viên ban d?u
    students[0] = (struct Student){1, "Hoang Cuong A", 20, "0123456789"};
    students[1] = (struct Student){2, "Hoang Cuong B", 21, "0987654321"};
    students[2] = (struct Student){3, "Hoang Cuong C", 22, "0912345678"};
    students[3] = (struct Student){4, "Hoang Cuong D", 23, "0837625412"};
    students[4] = (struct Student){5, "Hoang Cuong E", 24, "0918765432"};

    displayStudents(students, numStudents);

    int position;
    struct Student newStudent;

    printf("\nNhap vi tri (0-%d) de chen sinh vien moi: ", numStudents);
    scanf("%d", &position);

    if (position < 0 || position > numStudents) {
        printf("Vi tri khong hop le.\n");
        return 1;
    }

    printf("Nhap thong tin sinh vien moi:\n");
    printf("ID: ");
    scanf("%d", &newStudent.id);
    getchar();
    printf("Name: ");
    fgets(newStudent.name, sizeof(newStudent.name), stdin);
    newStudent.name[strcspn(newStudent.name, "\n")] = '\0';
    printf("Age: ");
    scanf("%d", &newStudent.age);
    getchar();
    printf("Phone Number: ");
    fgets(newStudent.phoneNumber, sizeof(newStudent.phoneNumber), stdin);
    newStudent.phoneNumber[strcspn(newStudent.phoneNumber, "\n")] = '\0';

    for (int i = numStudents; i > position; i--) {
        students[i] = students[i - 1];
    }

    students[position] = newStudent;
    numStudents++;

    displayStudents(students, numStudents);

    return 0;
}

