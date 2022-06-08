// Leecode69.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) {
            return x;
        }
        else {
            int now = 1;
            while (true) {
                if (x >now * now&&x>(now+1)*(now+1)) {
                    now++;
                }
                else if (x > now * now && x < (now + 1) * (now + 1)) {
                    return now;
                }
                else {
                    return now + 1;
                }
            }
        }

    }
};


int main()
{
    Solution sol;
    for (int i = 0; i < 100; i++) {
        printf("x:%d sqrt:%d\n", i, sol.mySqrt(i));
    }
}

