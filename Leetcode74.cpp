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


class Solution {
public:
    bool searchmatrix(vector<vector<int>> mat, int tra) {
        int col;
        for (int i = 0; i < mat.size() - 1; i++) {
            if (i == 0 && tra < mat[0].front()) {
                return false;
            }
            else if (mat[i].front() < tra && mat[i + 1].front() > tra) {
                col = i;
            }
            else if (i == mat.size() - 2 && mat[i + 1].front() < tra) {
                col = i + 1;
            }
        }
        if (tra > mat[col].back()) {
            return false;
        }
        else if (tra == mat[col].back()) {
            return true;
        }


        for (int j = 0; j < mat[col].size() - 1; j++) {
            if (mat[col][j] == tra) {
                return true;
            }

            else if (mat[col][j]<tra && mat[col][j + 1]>tra) {
                return false;
            }

        }
    }

};

int main()
{
    Solution sol;
    vector<vector<int>> matrix = { {1, 3, 5, 7},{10, 11, 16, 20},{23, 30, 34, 60} };
    int target = 3;
    cout<<sol.searchmatrix(matrix, target);
    
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
