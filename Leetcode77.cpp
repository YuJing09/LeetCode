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
    vector<vector<int>> combine(int k, int n) {



        vector<vector<int>> out;
        vector<int> temp;
        if (k == n) {
            for (int i = 1; i <= n; i++) {
                temp.push_back(i);
            }
            out.push_back(temp);
            return out;
        }
        else if (k == 1) {
            for (int i = 1; i <= n; i++) {

                temp.push_back(i);
                out.push_back(temp);
                temp.clear();
            }
            return out;

        }
        else {
            vector<vector<int>> re;

            for (int i = 1; i <= (n - k + 1); i++) {



                re = combine(k - 1, n - i);
                for (int j = 0; j < re.size(); j++) {
                    temp.push_back(i);

                    for (int g = 0; g < re[j].size(); g++) {


                        temp.push_back(re[j][g] + i);


                    }

                    out.push_back(temp);
                    temp.clear();
                }


            }
            return out;
        }
    }
};

int main()
{
    Solution sol;

    int n = 4;
    int k = 2;
    vector<vector<int>> out = sol.combine(2, 4);
    for (int i = 0; i<out.size(); i++) {
        for (int j = 0; j < out[i].size(); j++) {
            cout << out[i][j] << " ";
        }
        cout << endl;
    }
   
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
