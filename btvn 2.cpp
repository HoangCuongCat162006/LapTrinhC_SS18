#include <stdio.h>

struct student {
        char Name[50];
        int age;
        char phoneNumber[11]; 
    };
int main(){
	struct student sv1;
	printf("Moi ban nhap ten sinh vien: ");
	fgets(sv1.Name,sizeof(sv1.Name),stdin);
	printf("Moi ban nhap tuoi sinh vien: ");	
	scanf("%d",&sv1.age);
	fflush(stdin);
	printf("Moi ban nhap so dien thoai: ");	
	fgets(sv1.phoneNumber,sizeof(sv1.phoneNumber),stdin);
	printf("ten sinh vien : %s",sv1.Name);
	printf("tuoi sinh vien : %d\n",sv1.age);
	printf("so dien thoai sinh vien : %s",sv1.phoneNumber);
return 0;
}

