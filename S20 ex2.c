#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    char maSanPham[20];
    char tenSanPham[100];
    float giaNhap;
    float giaBan;
    int soLuong;
} Product;

Product products[MAX_PRODUCTS];
int n = 0;
float doanhThu = 0;

void nhapThongTinSanPham() {
    printf("Nhap so luong san pham: ");
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        printf("\nNhap thong tin san pham thu %d:\n", i + 1);
        printf("Ma san pham: ");
        fgets(products[i].maSanPham, sizeof(products[i].maSanPham), stdin);
        strtok(products[i].maSanPham, "\n");

        printf("Ten san pham: ");
        fgets(products[i].tenSanPham, sizeof(products[i].tenSanPham), stdin);
        strtok(products[i].tenSanPham, "\n");

        printf("Gia nhap: ");
        scanf("%f", &products[i].giaNhap);
        getchar();

        printf("Gia ban: ");
        scanf("%f", &products[i].giaBan);
        getchar();

        printf("So luong: ");
        scanf("%d", &products[i].soLuong);
        getchar();

        doanhThu -= products[i].soLuong * products[i].giaNhap;
    }
}

void hienThiDanhSachSanPham() {
    printf("\nDanh sach cac san pham:\n");
    for (int i = 0; i < n; i++) {
        printf("\nSan pham thu %d:\n", i + 1);
        printf("Ma san pham: %s\n", products[i].maSanPham);
        printf("Ten san pham: %s\n", products[i].tenSanPham);
        printf("Gia nhap: %.2f\n", products[i].giaNhap);
        printf("Gia ban: %.2f\n", products[i].giaBan);
        printf("So luong: %d\n", products[i].soLuong);
    }
}

void nhapSanPham() {
    char maSanPham[20];
    printf("\nNhap ma san pham can nhap: ");
    getchar();
    fgets(maSanPham, sizeof(maSanPham), stdin);
    strtok(maSanPham, "\n");

    int soLuong;
    printf("Nhap so luong nhap: ");
    scanf("%d", &soLuong);

    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(products[i].maSanPham, maSanPham) == 0) {
            products[i].soLuong += soLuong;
            doanhThu -= soLuong * products[i].giaNhap;
            found = 1;
            break;
        }
    }

    if (!found) {
        if (n >= MAX_PRODUCTS) {
            printf("\nKhong the nhap them san pham. Bo nho day!\n");
            return;
        }

        printf("San pham moi. Nhap thong tin:\n");
        strcpy(products[n].maSanPham, maSanPham);
        printf("Ten san pham: ");
        getchar();
        fgets(products[n].tenSanPham, sizeof(products[n].tenSanPham), stdin);
        strtok(products[n].tenSanPham, "\n");

        printf("Gia nhap: ");
        scanf("%f", &products[n].giaNhap);

        printf("Gia ban: ");
        scanf("%f", &products[n].giaBan);

        products[n].soLuong = soLuong;
        doanhThu -= soLuong * products[n].giaNhap;
        n++;
    }
}

void capNhatThongTinSanPham() {
    char maSanPham[20];
    printf("\nNhap ma san pham can cap nhat: ");
    getchar();
    fgets(maSanPham, sizeof(maSanPham), stdin);
    strtok(maSanPham, "\n");

    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(products[i].maSanPham, maSanPham) == 0) {
            printf("\nNhap thong tin moi cho san pham:\n");

            printf("Ten san pham: ");
            fgets(products[i].tenSanPham, sizeof(products[i].tenSanPham), stdin);
            strtok(products[i].tenSanPham, "\n");

            printf("Gia nhap: ");
            scanf("%f", &products[i].giaNhap);

            printf("Gia ban: ");
            scanf("%f", &products[i].giaBan);

            printf("So luong: ");
            scanf("%d", &products[i].soLuong);

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nKhong tim thay san pham!\n");
    }
}

void sapXepSanPhamTheoGia(int tangDan) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((tangDan && products[i].giaBan > products[j].giaBan) ||
                (!tangDan && products[i].giaBan < products[j].giaBan)) {
                Product temp = products[i];
                products[i] = products[j];
                products[j] = temp;
            }
        }
    }
    printf("\nDa sap xep san pham theo gia!\n");
}

void timKiemSanPham() {
    char tenSanPham[100];
    printf("\nNhap ten san pham can tim: ");
    getchar();
    fgets(tenSanPham, sizeof(tenSanPham), stdin);
    strtok(tenSanPham, "\n");

    printf("\nKet qua tim kiem:\n");
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strstr(products[i].tenSanPham, tenSanPham) != NULL) {
            printf("\nMa san pham: %s\n", products[i].maSanPham);
            printf("Ten san pham: %s\n", products[i].tenSanPham);
            printf("Gia nhap: %.2f\n", products[i].giaNhap);
            printf("Gia ban: %.2f\n", products[i].giaBan);
            printf("So luong: %d\n", products[i].soLuong);
            found = 1;
        }
    }

    if (!found) {
        printf("\nKhong tim thay san pham!\n");
    }
}

void banSanPham() {
    char maSanPham[20];
    printf("\nNhap ma san pham can ban: ");
    getchar();
    fgets(maSanPham, sizeof(maSanPham), stdin);
    strtok(maSanPham, "\n");

    int soLuong;
    printf("Nhap so luong can ban: ");
    scanf("%d", &soLuong);

    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(products[i].maSanPham, maSanPham) == 0) {
            if (products[i].soLuong == 0) {
                printf("\nHet hang!\n");
            } else if (products[i].soLuong < soLuong) {
                printf("\nKhong du hang!\n");
            } else {
                products[i].soLuong -= soLuong;
                doanhThu += soLuong * products[i].giaBan;
                printf("\nBan thanh cong!\n");
            }
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nKhong tim thay san pham!\n");
    }
}

void hienThiDoanhThu() {
    printf("\nDoanh thu hien tai: %.2f\n", doanhThu);
}

int main() {
    int choice;
    do {
        printf("\nMENU\n");
        printf("1. Nhap so luong va thong tin san pham.\n");
        printf("2. Hien thi danh sach san pham.\n");
        printf("3. Nhap san pham.\n");
        printf("4. Cap nhat thong tin san pham.\n");
        printf("5. Sap xep san pham theo gia (tang/giam).\n");
        printf("6. Tim kiem san pham.\n");
        printf("7. Ban san pham.\n");
        printf("8. Doanh thu hien tai.\n");
        printf("9. Thoat.\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                nhapThongTinSanPham();
                break;
            case 2:
                hienThiDanhSachSanPham();
                break;
            case 3:
                nhapSanPham();
                break;
            case 4:
                capNhatThongTinSanPham();
                break;
            case 5: {
                int tangDan;
                printf("\nNhap 1 de sap xep tang dan, 0 de sap xep giam dan: ");
                scanf("%d", &tangDan);
                sapXepSanPhamTheoGia(tangDan);
                break;
            }
            case 6:
                timKiemSanPham();
                break;
            case 7:
                banSanPham();
                break;
            case 8:
                hienThiDoanhThu();
                break;
            case 9:
                printf("\nThoat chuong trinh.\n");
                break;
            default:
                printf("\nLua chon khong hop le!\n");
        }
    } while (choice != 9);

    return 0;
}

