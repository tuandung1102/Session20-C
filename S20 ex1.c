#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

typedef struct {
    char maSach[20];
    char tenSach[100];
    char tacGia[100];
    float giaTien;
    char theLoai[50];
} Book;

Book books[MAX_BOOKS];
int n = 0;

void nhapThongTinSach() {
    printf("Nhap so luong sach: ");
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        printf("\nNhap thong tin sach thu %d:\n", i + 1);
        printf("Ma sach: ");
        fgets(books[i].maSach, sizeof(books[i].maSach), stdin);
        strtok(books[i].maSach, "\n");

        printf("Ten sach: ");
        fgets(books[i].tenSach, sizeof(books[i].tenSach), stdin);
        strtok(books[i].tenSach, "\n");

        printf("Tac gia: ");
        fgets(books[i].tacGia, sizeof(books[i].tacGia), stdin);
        strtok(books[i].tacGia, "\n");

        printf("Gia tien: ");
        scanf("%f", &books[i].giaTien);
        getchar();

        printf("The loai: ");
        fgets(books[i].theLoai, sizeof(books[i].theLoai), stdin);
        strtok(books[i].theLoai, "\n");
    }
}

void hienThiThongTinSach() {
    printf("\nDanh sach cac cuon sach:\n");
    for (int i = 0; i < n; i++) {
        printf("\nSach thu %d:\n", i + 1);
        printf("Ma sach: %s\n", books[i].maSach);
        printf("Ten sach: %s\n", books[i].tenSach);
        printf("Tac gia: %s\n", books[i].tacGia);
        printf("Gia tien: %.2f\n", books[i].giaTien);
        printf("The loai: %s\n", books[i].theLoai);
    }
}

void themSachTaiViTri() {
    if (n >= MAX_BOOKS) {
        printf("\nKhong the them sach. Bo nho day!\n");
        return;
    }

    int viTri;
    printf("\nNhap vi tri can them (tu 0 den %d): ", n);
    scanf("%d", &viTri);
    getchar();

    if (viTri < 0 || viTri > n) {
        printf("\nVi tri khong hop le!\n");
        return;
    }

    for (int i = n; i > viTri; i--) {
        books[i] = books[i - 1];
    }

    printf("\nNhap thong tin sach moi:\n");
    printf("Ma sach: ");
    fgets(books[viTri].maSach, sizeof(books[viTri].maSach), stdin);
    strtok(books[viTri].maSach, "\n");

    printf("Ten sach: ");
    fgets(books[viTri].tenSach, sizeof(books[viTri].tenSach), stdin);
    strtok(books[viTri].tenSach, "\n");

    printf("Tac gia: ");
    fgets(books[viTri].tacGia, sizeof(books[viTri].tacGia), stdin);
    strtok(books[viTri].tacGia, "\n");

    printf("Gia tien: ");
    scanf("%f", &books[viTri].giaTien);
    getchar();

    printf("The loai: ");
    fgets(books[viTri].theLoai, sizeof(books[viTri].theLoai), stdin);
    strtok(books[viTri].theLoai, "\n");

    n++;
}

void xoaSachTheoMa() {
    char maSach[20];
    printf("\nNhap ma sach can xoa: ");
    getchar();
    fgets(maSach, sizeof(maSach), stdin);
    strtok(maSach, "\n");

    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(books[i].maSach, maSach) == 0) {
            for (int j = i; j < n - 1; j++) {
                books[j] = books[j + 1];
            }
            n--;
            found = 1;
            break;
        }
    }

    if (found) {
        printf("\nDa xoa sach co ma: %s\n", maSach);
    } else {
        printf("\nKhong tim thay ma sach!\n");
    }
}

void capNhatThongTinSach() {
    char maSach[20];
    printf("\nNhap ma sach can cap nhat: ");
    getchar();
    fgets(maSach, sizeof(maSach), stdin);
    strtok(maSach, "\n");

    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(books[i].maSach, maSach) == 0) {
            printf("\nNhap thong tin moi cho sach:\n");

            printf("Ten sach: ");
            fgets(books[i].tenSach, sizeof(books[i].tenSach), stdin);
            strtok(books[i].tenSach, "\n");

            printf("Tac gia: ");
            fgets(books[i].tacGia, sizeof(books[i].tacGia), stdin);
            strtok(books[i].tacGia, "\n");

            printf("Gia tien: ");
            scanf("%f", &books[i].giaTien);
            getchar();

            printf("The loai: ");
            fgets(books[i].theLoai, sizeof(books[i].theLoai), stdin);
            strtok(books[i].theLoai, "\n");

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nKhong tim thay ma sach!\n");
    } else {
        printf("\nDa cap nhat thong tin sach!\n");
    }
}

void sapXepSachTheoGia(int tangDan) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((tangDan && books[i].giaTien > books[j].giaTien) ||
                (!tangDan && books[i].giaTien < books[j].giaTien)) {
                Book temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }
    printf("\nDa sap xep sach theo gia!\n");
}

void timKiemSachTheoTen() {
    char tenSach[100];
    printf("\nNhap ten sach can tim: ");
    getchar();
    fgets(tenSach, sizeof(tenSach), stdin);
    strtok(tenSach, "\n");

    printf("\nKet qua tim kiem:\n");
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strstr(books[i].tenSach, tenSach) != NULL) {
            printf("\nMa sach: %s\n", books[i].maSach);
            printf("Ten sach: %s\n", books[i].tenSach);
            printf("Tac gia: %s\n", books[i].tacGia);
            printf("Gia tien: %.2f\n", books[i].giaTien);
            printf("The loai: %s\n", books[i].theLoai);
            found = 1;
        }
    }

    if (!found) {
        printf("\nKhong tim thay sach!\n");
    }
}

int main() {
    int choice;
    do {
        printf("\nMENU\n");
        printf("1. Nhap so luong va thong tin sach.\n");
        printf("2. Hien thi thong tin sach.\n");
        printf("3. Them sach vao vi tri.\n");
        printf("4. Xoa sach theo ma sach.\n");
        printf("5. Cap nhat thong tin sach theo ma sach.\n");
        printf("6. Sap xep sach theo gia (tang/giam).\n");
        printf("7. Tim kiem sach theo ten sach.\n");
        printf("8. Thoat.\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                nhapThongTinSach();
                break;
            case 2:
                hienThiThongTinSach();
                break;
            case 3:
                themSachTaiViTri();
                break;
            case 4:
                xoaSachTheoMa();
                break;
            case 5:
                capNhatThongTinSach();
                break;
            case 6: {
                int tangDan;
                printf("\nNhap 1 de sap xep tang dan, 0 de sap xep giam dan: ");
                scanf("%d", &tangDan);
                sapXepSachTheoGia(tangDan);
                break;
            }
            case 7:
                timKiemSachTheoTen();
                break;
            case 8:
                printf("\nThoat chuong trinh.\n");
                break;
            default:
                printf("\nLua chon khong hop le!\n");
        }
    } while (choice != 8);

    return 0;
}

