// Leecode.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
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
struct ListNode {
    int val;
    ListNode* next;
    ListNode() :val(0), next(0) {};
    ListNode(int x) :val(x), next(0) {};
    ListNode(int x, ListNode* next) :val(x), next(next) {};
};

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int h;
        int maxrec = 0;
        int maxheight;
        bool goodw;
        for (int i = 1; i <= matrix[0].size(); i++) {

            if (i == matrix[0].size()) {
                h = 0;
                maxheight = 0;
                for (int k = 0; k < matrix.size(); k++) {
                    goodw = true;
                    for (int w = 0; w < i; w++) {
                        if (matrix[k][w] != '1'); {
                            goodw = false;

                        }



                    }
                    if (goodw) {
                        h += 1;
                        if (h > maxheight) {
                            maxheight = h;
                        }
                    }
                    else {
                        h = 0;
                    }
                }
                if ((maxheight * i) > maxrec) {
                    maxrec = maxheight * i;
                }

            }

            for (int j = 0; j <= matrix[0].size() - i; j++) {
                h = 0;
                maxheight = 0;

                for (int k = 0; k < matrix.size(); k++) {
                    goodw = true;
                    for (int w = 0; w < i; w++) {
                        //printf("k:%d w:%d c:%c\n", k, w, matrix[k][w]);
                        if (matrix[k][j + w] != '1') {
                            goodw = false;

                        }



                    }

                    if (goodw) {
                        h += 1;

                        if (h > maxheight) {
                            maxheight = h;
                        }
                    }
                    else {
                        h = 0;
                    }

                }

                if ((maxheight * i) > maxrec) {
                    maxrec = maxheight * i;
                }


            }

        }
        return maxrec;






    }
};
int main() {
    vector<vector<char>> matrix = { {'1', '0', '1', '0', '0'},{'1', '0', '1', '1', '1'},{'1', '1', '1', '1', '1'},{'1', '0', '0', '1', '0'} };
    Solution sol;
    cout<<sol.maximalRectangle(matrix);

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
