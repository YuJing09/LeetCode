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
bool bS(vector<int> t, int traget) {

    int left = 0;
    int right = t.size();
    int pivot = t.size() / 2;

    while (left != right) {
        //cout << pivot << endl;
        if (traget == t[pivot]) {
            return true;
        }
        else if (traget > t[pivot]) {
            if (pivot == left) {
                pivot++;
            }
            left = pivot;
            pivot = (left + right) / 2;

        }
        else if (traget < t[pivot]) {
            right = pivot;
            pivot = (left + right) / 2;

        }


    }

    return false;

}
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                return true;
            }
        }
        return false;
    }
};
int main() {
    vector<int> nums = nums = { 2, 5, 6, 0, 0, 1, 2
    };
    int target = 0;
    Solution sol;
    cout<<sol.search(nums,target);


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
