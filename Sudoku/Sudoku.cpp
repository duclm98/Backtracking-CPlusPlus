#include <iostream>
using namespace std;

#define N 9

void NhapCauDo(int a[][9]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> a[i][j];
}

void XuatKetQua(int a[][9]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << a[i][j];

            if (j != N - 1 && (j + 1) % 3 == 0)
                cout << "   ||   ";
            else
                cout << "\t";
        }

        if (i != N - 1 && (i + 1) % 3 == 0) {
            cout << endl << endl;
            cout << "=================================================================";
            cout << endl << endl;
        }
        else {
            cout << endl << endl << endl;
        }
    }
}

bool CheckValid(int S[][9], int row, int col, int num) {
    for (int i = 0; i < 9; i++) {
        if (S[row][i] == num) return false;
    }
    for (int i = 0; i < 9; i++) {
        if (S[i][col] == num) return false;
    }
    int a = row / 3, b = col / 3;
    for (int i = 3 * a; i < 3 * a + 3; i++) {
        for (int j = 3 * b; j < 3 * b + 3; j++) {
            if (S[i][j] == num) return false;
        }
    }
    return true;
}

bool SolveSudoku(int S[][9], int row, int col) {
    if (row == N - 1 && col == N)
        return true;

    if (col == N) {
        row++;
        col = 0;
    }

    if (S[row][col] > 0)
        return SolveSudoku(S, row, col + 1);

    for (int num = 1; num <= N; num++)
    {
        if (CheckValid(S, row, col, num))
        {
            S[row][col] = num;
            if (SolveSudoku(S, row, col + 1))
                return true;
        }
        S[row][col] = 0;
    }
    return false;
}

int main()
{
    int S[N][N];
    FILE* inp = freopen("INPUT.TXT", "rt", stdin);
    NhapCauDo(S);
    cout << "CAU DO LA: " << endl << endl;
    XuatKetQua(S);

    if (SolveSudoku(S, 0, 0)) {
        cout << "KET QUA GIAI CAU DO: " << endl << endl;
        XuatKetQua(S);
    }
    else
        cout << "KHONG GIAI DUOC!!!" << endl;

    return 0;
}