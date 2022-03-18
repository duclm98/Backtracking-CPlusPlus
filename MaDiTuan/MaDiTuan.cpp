#include <iostream>
using namespace std;

#define N 100
int A[N][N];
int X[8] = { -1,-2,-2,-1,1,2,2,1 }; // Hoành độ mà con mã có thể đi theo vị trí hiện tại (x=0)
int Y[8] = { -2,-1,1,2,2,1,-1,-2 }; // Tung độ mà con mã có thể đi theo vị trí hiện tại (y=0), mỗi Y[i] tương ứng với một X[i]
int n;
int dem = 0;

void Xuat() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << A[i][j] << "\t";
        cout << endl << endl << endl;
    }
}

void DiChuyen(int x, int y)
{
    ++dem; // Tăng giá trị bước đi
    A[x][y] = dem; // Đánh dấu đã đi

    // Duyệt đến 8 vì 1 con mã có tối đa 8 bước di chuyển theo các tọa độ như mảng X, Y
    for (int i = 0; i < 8; i++) { 
        // Nếu đã đi hết bàn cờ
        if (dem == n * n) {
            cout << "CAC BUOC DI CHUYEN LA: " << endl;
            Xuat();
            exit(0);
        }

        // Nếu chưa đi hết bàn cờ
        int xx = x + X[i]; // Tạo vị trí x mới
        int yy = y + Y[i]; // Tạo vị trí y mới
        if (xx >= 0 && xx < n && yy >= 0 && yy < n && A[xx][yy] == 0)
            DiChuyen(xx, yy);
    }

    // Nếu không tìm thấy bước đi thì quay lại bước cũ
    --dem;
    A[x][y] = 0;
}

int main()
{
    cout << "Nhap canh ban co: ";
    cin >> n;
    int x, y;
    do {
        cout << "Nhap toa do ban dau (x, y): " << endl << "x: "; cin >> x;
        cout << "y: "; cin >> y;
    } while (x >= n || y >= n);
    DiChuyen(x, y);
    cout << "KHONG TIM THAY DUONG DI" << endl;

    return 0;
}