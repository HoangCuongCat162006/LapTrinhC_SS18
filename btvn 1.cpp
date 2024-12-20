#include <stdio.h>

struct student {
        char Name[50];
        int age;
        char phoneNumber[10]; 
    };
    
int main() {
	struct student student1 = {"Nguyen Son Minh", 18, "2348456"};
	struct student student2 = {"Hoang Cuong Cat", 11, "24544869"};
		printf("Student 1: %s, Age: %d, Phone: %s\n", student1.Name, student1.age, student1.phoneNumber);
		printf("Student 2: %s, Age: %d, Phone: %s\n", student2.Name, student2.age, student2.phoneNumber);

    return 0;
}

