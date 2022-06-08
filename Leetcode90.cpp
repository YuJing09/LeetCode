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
#include <math.h>

using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() :val(0), next(0) {};
    ListNode(int x) :val(x), next(0) {};
    ListNode(int x, ListNode* next) :val(x), next(next) {};
};

void Quicksort(vector<int>& nums, int l, int r) {
    if (r > l) {
        int pivot = nums[l];
        int left = l + 1;
        int right = r;
        while (right >= left) {
            while (left<=right&&nums[left] <= pivot) { left++; };
            while (nums[right] > pivot) { right--; };
            if (right > left) {
                swap(nums[left],nums[right]);
            }
        }
        swap(nums[l], nums[right]);
        Quicksort(nums, l, right - 1);
        Quicksort(nums, right + 1, r);
    
    
    }




}
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        Quicksort(nums, 0, nums.size() - 1);
        vector<vector<int>> output;
        vector<int> temp;
        for (int i = 0; i <= nums.size();i++) {
           
            if (i == 0) {
                output.push_back(temp);
            }
            else if (i == nums.size()) {
                temp.clear();
                for (int l = 0; l < nums.size(); l++) {
                    temp.push_back(nums[l]);
                }
                output.push_back(temp);
            }
            else {
                for (int j = 0; j <= nums.size()-i; j++) {
                    temp.clear();
                    for (int k = 0; k < i; k++) {
                        temp.push_back(nums[j+k]);
                    }
                    if (j == 0) {
                        output.push_back(temp);
                    }
                    else {
                        for (int l = 0; l < temp.size(); l++) {
                          
                            if (temp[l] != output.back()[l]) {
                                output.push_back(temp);
                                break;
                            }
                        }
                    }
                }


            }
        }
        return output;
    
    
    }


};
int main() {
    

    Solution sol;
    vector<int> nums{ 1,2,2 };
    vector<vector<int>> output = sol.subsetsWithDup(nums);
        for (int i = 0; i < output.size(); i++) {
            for (int j = 0; j < output[i].size(); j++) {
                cout << output[i][j] << " ";
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
