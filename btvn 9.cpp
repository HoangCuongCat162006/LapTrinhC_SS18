#include <stdio.h>
#include <string.h>

struct Dish {
    int id;
    char name[100];
    float price;
};

void printMenu(struct Dish menu[], int n) {
    printf("\nDanh sach menu:\n");
    for (int i = 0; i < n; i++) {
        printf("%d. ID: %d, Name: %s, Price: %.2f\n", i + 1, menu[i].id, menu[i].name, menu[i].price);
    }
}

void addDish(struct Dish menu[], int *n, int position) {
    struct Dish newDish;
    if (position < 0 || position > *n) {
        printf("Vi tri khong hop le.\n");
        return;
    }
    printf("\nNhap thong tin mon an moi:\n");
    printf("ID: ");
    scanf("%d", &newDish.id);
    getchar();
    printf("Name: ");
    fgets(newDish.name, sizeof(newDish.name), stdin);
    newDish.name[strcspn(newDish.name, "\n")] = '\0';
    printf("Price: ");
    scanf("%f", &newDish.price);

    for (int i = *n; i > position; i--) {
        menu[i] = menu[i - 1];
    }
    menu[position] = newDish;
    (*n)++;
}

void updateDish(struct Dish menu[], int n, int position) {
    if (position < 0 || position >= n) {
        printf("Vi tri khong hop le.\n");
        return;
    }
    printf("\nNhap thong tin mon an can sua:\n");
    printf("ID: ");
    scanf("%d", &menu[position].id);
    getchar();
    printf("Name: ");
    fgets(menu[position].name, sizeof(menu[position].name), stdin);
    menu[position].name[strcspn(menu[position].name, "\n")] = '\0';
    printf("Price: ");
    scanf("%f", &menu[position].price);
}

void deleteDish(struct Dish menu[], int *n, int position) {
    if (position < 0 || position >= *n) {
        printf("Vi tri khong hop le.\n");
        return;
    }
    for (int i = position; i < *n - 1; i++) {
        menu[i] = menu[i + 1];
    }
    (*n)--;
}

void sortMenuByPrice(struct Dish menu[], int n, int ascending) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((ascending && menu[i].price > menu[j].price) || (!ascending && menu[i].price < menu[j].price)) {
                struct Dish temp = menu[i];
                menu[i] = menu[j];
                menu[j] = temp;
            }
        }
    }
}

int linearSearch(struct Dish menu[], int n, const char *name) {
    for (int i = 0; i < n; i++) {
        if (strcmp(menu[i].name, name) == 0) {
            return i;  // Tr? v? v? trí tìm th?y
        }
    }
    return -1;
}

int binarySearch(struct Dish menu[], int n, const char *name) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int cmp = strcmp(menu[mid].name, name);
        if (cmp == 0) {
            return mid;
        } else if (cmp < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    struct Dish menu[100] = {
        {1, "Pho", 50.0},
        {2, "Bun Rieu", 45.0},
        {3, "Com tam", 30.0},
        {4, "Banh Mi", 20.0},
        {5, "Hu Tieu", 40.0}
    };
    int n = 5;
    int choice, position;
    char searchName[100];

    while (1) {
        printf("\nMENU\n");
        printf("1. In ra gia tri cac phan tu trong menu\n");
        printf("2. Them mot mon an vao vi tri chi dinh\n");
        printf("3. Sua mot mon an o vi tri chi dinh\n");
        printf("4. Xoa mot mon an o vi tri chi dinh\n");
        printf("5. Sap xep cac mon an\n");
        printf("6. Tim kiem mon an theo name\n");
        printf("7. Thoat\n");
        printf("Chon chuc nang (1-7): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printMenu(menu, n);
                break;
            case 2:
                printf("\nNhap vi tri chen mon an (0-%d): ", n);
                scanf("%d", &position);
                addDish(menu, &n, position);
                break;
            case 3:
                printf("\nNhap vi tri mon an can sua (0-%d): ", n - 1);
                scanf("%d", &position);
                updateDish(menu, n, position);
                break;
            case 4:
                printf("\nNhap vi tri mon an can xoa (0-%d): ", n - 1);
                scanf("%d", &position);
                deleteDish(menu, &n, position);
                break;
            case 5:
                printf("\nMENU SAP XEP\n");
                printf("a. Giam dan theo gia\n");
                printf("b. Tang dan theo gia\n");
                printf("Chon chuc nang sap xep (a/b): ");
                char sortChoice;
                getchar();
                scanf("%c", &sortChoice);
                if (sortChoice == 'a') {
                    sortMenuByPrice(menu, n, 0);
                } else if (sortChoice == 'b') {
                    sortMenuByPrice(menu, n, 1);
                }
                printMenu(menu, n);
                break;
            case 6:
                printf("\nNhap ten mon an can tim: ");
                getchar();
                fgets(searchName, sizeof(searchName), stdin);
                searchName[strcspn(searchName, "\n")] = '\0';
                printf("\nMENU TIM KIEM\n");
                printf("a. Tim kiem tuyen tinh\n");
                printf("b. Tim kiem nhi phan\n");
                printf("Chon chuc nang tim kiem (a/b): ");
                char searchChoice;
                scanf("%c", &searchChoice);
                int result;
                if (searchChoice == 'a') {
                    result = linearSearch(menu, n, searchName);
                } else if (searchChoice == 'b') {
                    result = binarySearch(menu, n, searchName);
                }
                if (result != -1) {
                    printf("Mon an '%s' tim thay tai vi tri: %d\n", searchName, result);
                } else {
                    printf("Mon an '%s' khong tim thay.\n", searchName);
                }
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                return 0;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    }
}

