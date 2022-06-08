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
    int largestRectangleArea(vector<int> heights) {

        int max = 0;
        int maxheight;
        int minheight;
        for (int i = 1; i <= heights.size(); i++) {
            //cot << i << endl;
            maxheight = 0;
            if (i == heights.size()) {
                for (int ind = 0; ind < heights.size(); ind++) {
                    if (ind == 0) {
                        maxheight = heights[0];
                    }
                    else if (heights[ind] < maxheight) {
                        maxheight = heights[ind];
                    }
                }
            }
            else {
                for (int j = 0; j <= heights.size() - i; j++) {
                    //cout << j << endl;
                    minheight = INT_MAX;
                    for (int k = 0; k < i; k++) {
                        //printf("h:%d i:%d \n ", heights[j + k], i);
                        if (heights[j + k] < minheight) {
                            minheight = heights[k];
                        }
                    }
                    if (minheight > maxheight) {
                        maxheight = minheight;

                    }
                }
            }
            //printf("max:%d i:%d\n", maxheight, i);
            if (maxheight * i > max) {
                max = maxheight * i;
            }


        }
        return max;



    }
};
int main() {
    vector<int> heights = { 2, 1, 5, 6, 2, 3 };
    Solution sol;
    cout<<sol.largestRectangleArea(heights);

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
