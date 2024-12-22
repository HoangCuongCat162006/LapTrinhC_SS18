#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
} Student;

void displayStudents(Student students[], int count) {
    printf("\nDanh sach sinh vien:\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Name: %s, Age: %d, Phone: %s\n",
               students[i].id, students[i].name, students[i].age, students[i].phoneNumber);
    }
}

int main() {
    Student students[50];
    int studentCount = 5;

    students[0] = (Student){1, "Hoang Cuong A", 20, "0123456789"};
    students[1] = (Student){2, "Hoang Cuong B", 21, "0987654321"};
    students[2] = (Student){3, "Hoang Cuong C", 19, "0912345678"};
    students[3] = (Student){4, "Hoang Cuong D", 22, "0945678123"};
    students[4] = (Student){5, "Hoang Cuong E", 20, "0932123456"};

    displayStudents(students, studentCount);

    if (studentCount < 50) {
        printf("\nNhap thong tin sinh vien can them:\n");
        Student newStudent;
        printf("ID: ");
        scanf("%d", &newStudent.id);
        printf("Name: ");
        scanf(" %s", &newStudent.name);
        printf("Age: ");
        scanf("%d", &newStudent.age);
        printf("Phone Number: ");
        scanf("%s", &newStudent.phoneNumber);

        students[studentCount] = newStudent;
        studentCount++;

        displayStudents(students, studentCount);
    } else {
        printf("Mang da day, không the them sinh vien moi!\n");
    }

    return 0;
}

