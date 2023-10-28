#include "test.h"

//输入，1和20，输出 3组  【3，4,5 ; 5,12,13; 8,15,17】
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

void od64() {
    int n, m;
    while (cin >> n >> m) {
        int found = 0;
        for (int i = n; i <= m; i++) {
            for (int j = i + 1; j <= m; j++) {
                int k = (int)sqrt(i * i + j * j);
                if (k > m) {
                    break;
                }
                if (k * k == i * i + j * j) {
                    if (gcd(i, j) == 1 && gcd(j, k) == 1) {
                        cout << i << " " << j << " " << k << endl;
                        found = 1;
                    }
                }
            }
        }
        if (!found) {
            cout << "Na" << endl;
        }
    }
}

//https://wiki.amoscloud.com/zh/ProgramingPractice/NowCoder/Adecco/Topic0001