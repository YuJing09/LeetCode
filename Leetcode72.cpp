﻿// Project6.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
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
int mindistance1(string a, string b, int n1, int n2, int m) {
    string inserts = a;
    string deletes = a;
    string replaces = a;



    if (n2 <= b.size() - 1) {

        char dst = b[n2];
        if (a[n1] != dst) {

            if (n1 <= ((int)a.size() - 1)) {

                inserts = inserts.insert(n1, 1, dst);
                deletes = deletes.erase(n1, 1);
                replaces[n1] = dst;


                return min({ mindistance1(inserts,b,n1 + 1,n2 + 1,m + 1),mindistance1(deletes,b,n1,n2,m + 1),mindistance1(replaces,b,n1 + 1,n2 + 1,m + 1) });
            }
            else {

                inserts = inserts.insert(n1, 1, dst);
                return mindistance1(inserts, b, n1 + 1, n2 + 1, m + 1);
            }




        }
        else if (a[n1] == dst) {
            return mindistance1(a, b, n1 + 1, n2 + 1, m);
        }
    }
    else {
        if (n1 <= (a.size() - 1)) {
            deletes = deletes.erase(n1, 1);

            return mindistance1(deletes, b, n1, n2, m + 1);


        }
        else {

            return m;

        }
    }
}

class Solution {
public:
    int mindistance(string word1, string word2) {
        int l = 0;
        int r = 0;
        int m = 0;
        return mindistance1(word1, word2, l, r, m);


    }
};

int main()
{
    string word1 = "intention";
    string word2 = "execution";
    Solution sol;
    cout << sol.mindistance(word1, word2);
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
