#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
} Student;

void displayStudents(Student students[], int count) {
    printf("\nSinh vien hien tai :\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Name: %s, Age: %d, Phone: %s\n",
               students[i].id, students[i].name, students[i].age, students[i].phoneNumber);
    }
}

int findStudentByName(Student students[], int count, const char *name) {
    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void deleteStudentByName(Student students[], int *count, const char *name) {
    int index = findStudentByName(students, *count, name);
    if (index == -1) {
        printf("\nSinh vien co ten '%s' khong ton tai.\n", name);
        return;
    }

    for (int i = index; i < *count - 1; i++) {
        students[i] = students[i + 1];
    }
    (*count)--;
    printf("Sinh vien co ten '%s' da bi xoa.\n", name);
}

int main() {
    Student students[50] = {
        {1, "Hoang Cuong A", 20, "1234567890"},
        {2, "Hoang Cuong B", 22, "0987654321"},
        {3, "Hoang Cuong C", 19, "1122334455"},
        {4, "Hoang Cuong D", 21, "5566778899"},
        {5, "Hoang Cuong E", 23, "6677889900"}
    };

    int studentCount = 5;

    printf("Danh sach sinh vien ban dau :\n");
    displayStudents(students, studentCount);

    char nameToDelete[50];
    printf("\nNhap ten sinh vien can xoa: ");
    fgets(nameToDelete, sizeof(nameToDelete), stdin);
    nameToDelete[strcspn(nameToDelete, "\n")] = 0;  // Lo?i b? kı t? newline

    deleteStudentByName(students, &studentCount, nameToDelete);

    displayStudents(students, studentCount);

    return 0;
}

