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
    void setZeros(vector<vector<int>> input) {


        set<int> row;
        set<int> col;
        for (int i = 0; i < input.size(); i++) {
            for (int j = 0; j < input[i].size(); j++) {
                if (input[i][j] == 0) {
                    col.insert(i);
                    row.insert(j);
                }
                else {
                    continue;
                }
            }
        }
        for (const auto& s : col) {
            input[s].assign(input[s].size(), 0);
        }
        int m = 0;
        for (int i = 0; i < input.size(); i++) {
            if (col.count(i)) {
                input[i].assign(input[i].size(), 0);
            }
            else {
                for (const auto& r : row) {
                    input[i][r] = 0;
                }
            }
        }
        for (int i = 0; i < input.size(); i++) {
            for (int j = 0; j < input[i].size(); j++) {
                cout << input[i][j] << "  ";
            }
            cout << endl;
        }

    }

};

int main()
{
    Solution sol;
    vector<vector<int>> matrix = { {1,1,1},{1,0,1},{1,1,1} };
    sol.setZeros(matrix);
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
