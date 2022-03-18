#include <iostream>
using namespace std;

#define N 100
int n, k;
int hoanVi[N], toHop[N] = { 0 };
bool danhDauHoanVi[N] = { false }, danhDauToHop[N] = { false };

void XuatHoanVi()
{
    for (int i = 1; i <= n; i++)
        cout << hoanVi[i] << "\t";
    cout << endl;
}

void XuatToHop()
{
    for (int i = 1; i <= k; i++)
        cout << toHop[i] << "\t";
    cout << endl;
}

void LietKeHoanVi(int i)
{
    if (i > n)
        XuatHoanVi();
    for (int j = 1; j <= n; j++) {
        if (!danhDauHoanVi[j]) {
            danhDauHoanVi[j] = true;
            hoanVi[i] = j;
            LietKeHoanVi(i + 1);
            danhDauHoanVi[j] = false;
        }
    }
}

int main()
{
    cout << "Nhap n: ";
    cin >> n;
    /*cout << "Nhap k: ";
    cin >> k;*/
    LietKeHoanVi(1);

    return 0;
}