#include <stdio.h>

struct student{
	int id;
	char name[50];
	int age;
	char phoneNumber[11];
};
struct student sv[50];
void strStudent();
void priStudent();

int main(){
	strStudent();
	priStudent();
return 0;
}

void strStudent(){
	for(int i=0; i<5; i++){
		sv[i].id++;
		printf("Moi ban nhap vao ten cua sinh vien %d: ",i+1);
		fgets(sv[i].name,sizeof(sv[i].name),stdin);
		printf("Moi ban nhap vao nam sinh cua sinh vien %d: ",i+1);
		scanf("%d", &sv[i].age);
		getchar();
		printf("Moi ban nhap vao so dien thoai cua sinh vien %d: ",i+1);
		fgets(sv[i].phoneNumber,sizeof(sv[i].phoneNumber),stdin);
	}
}

void priStudent(){
	for(int i=0; i<5; i++){
		printf("id sinh vien: %d\n",sv[i].id);
		printf("ten sin vien %d: %s",i+1,sv[i].name);
		printf("tuoi sinh vien %d: %d\n",i+1,sv[i].age);
		printf("so dien thoai cua sinh vien %d: %s\n",i+1,sv[i].phoneNumber);
	}
	
}
