// Project6.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//



#include <iostream>
#include <string.h>
#include <bitset>
#include <algorithm>
#include <typeinfo>
#include <vector>
#include  <set>
#include <unordered_map>
using namespace std;
char* deletelast(char* a) {
    char* out;
    char slash = '/';
    int len = strlen(a);
    bool finds = false;
    for (int i = (len - 1); i >= 0; i--) {
        if (a[i] != slash && !finds) {
            continue;
        }
        else if (i == 0) {
            out = (char*)malloc(sizeof(char) * 2);
            out[0] = '/';
            out[1] = '\0';
            return out;

        }
        else if (a[i] == slash && i != 0) {
            finds = true;
            if (a[i - 1] != slash) {
                out = (char*)malloc(sizeof(char) * (i + 1));
                memcpy(out, a, sizeof(char) * i);
                out[i] = '\0';
                return out;

            }
        }
    }

}

class Solution {
public:
    string simplifypath(string path) {
        const char* a = path.c_str();
        int len = strlen(a);
        char* name = (char*)malloc(sizeof(char) * len);
        int num = 0;
        char slash = '/';

        char* out = (char*)malloc(sizeof(char) * (len));
        char previous;
        int m = 0;
        for (int i = 0; i < len; i++) {
           // printf("%d %c %d\n", i, a[i], len - 1);

            if (i == 0) {
                out[m++] = a[i];
                previous = a[i];
            }
            else if (previous == slash && a[i] == slash && i != len - 1) {

                continue;

            }
            else if (a[i] != slash && i != (len - 1)) {

                name[num++] = a[i];
                previous = a[i];

            }
            else if (a[i] == slash && previous != slash && i != (len - 1)) {

                if (num > 2) {
                    name[num++] = a[i];
                    memcpy(out + m, name, sizeof(char) * num);
                    m += num;
                    num = 0;
                    previous = a[i];
                    continue;
                }
                else if ((num == 2) && name[0] == '.' && name[1] == '.') {
                    out = deletelast(out);
                    out = deletelast(out);
                    m = strlen(out);
                    if (m != 1) {
                        out[m++] = '/';
                    }
                    out = (char*)realloc(out, sizeof(char) * len);
                    previous = a[i];
                    num = 0;
                    continue;

                }
                else if (num == 1 && name[0] == '.') {
                    previous = a[i];
                    num = 0;
                    continue;
                }



            }
            else if (i == (len - 1)) {
               // cout << 1 << endl;
                if (a[i] != slash) {
                    cout << 1 << endl;
                    name[num++] = a[i];
                    memcpy(out + m, name, sizeof(char) * num);
                    out[m] = '\0';
                }
                else if (a[i] == slash && previous != slash) {
                 //   cout << 2 << endl;
                    memcpy(out + m, name, sizeof(char) * num);
                    m += num;
                    out[m] = '\0';
                }
                else if (a[i] == slash && previous == slash) {
                    cout << 3 << endl;
                    out = deletelast(out);
                }
            }
        }
        return out;

    }
};


int main()
{
    Solution sol;
    string path = "/home/";
    cout << sol.simplifypath(path) << endl;
}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
