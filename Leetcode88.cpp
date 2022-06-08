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
    void merge(vector<int>& nums, int m, vector<int>& nums2, int n) {
        vector<int> output;
        int left = 0;
        int right = 0;
        int outputlen = m + n;
        while (outputlen > 0) {
            if (left < m && right < n) {
                if (nums[left] <= nums2[right]) {
                    output.push_back(nums[left++]);
                    outputlen--;
                }
                else {
                    output.push_back(nums2[right++]);
                    outputlen--;
                }
            }
            else if (left >= m) {
                output.push_back(nums2[right++]);
                outputlen--;
            }
            else {
                output.push_back(nums[left++]);
                outputlen--;
            }
        }
        nums = output;

    }

};
int main() {
    vector<int> nums1 = { 1, 2, 3, 0, 0, 0 };
    int m = 3; 
    vector<int> nums2 = { 2, 5, 6 };
    int n = 3;
    Solution sol;
    sol.merge(nums1,m,nums2,n);
    for (int i = 0; i < nums1.size(); i++) {
        printf("%d \n", nums1[i]);
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
