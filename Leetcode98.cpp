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
#include<stack>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() :val(0), next(0) {};
    ListNode(int x) :val(x), next(0) {};
    ListNode(int x, ListNode* next) :val(x), next(next) {};
};


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(0), right(0) {};
    TreeNode(int x) : val(x), left(0), right(0) {};
    TreeNode(int x, TreeNode* left, TreeNode* right) :val(x), left(left), right(right) {};
};



    class Solution {
    public:
        bool isValidBST(TreeNode* root) {
            stack<TreeNode*> temp;
            temp.push(root);
            int value;
            TreeNode* top;
            bool right, left;
            while (temp.size()>0 ) {
                right = false;
                left = false;
                top = temp.top();
                if (top->right) {
                    if (top->val < top->right->val) {
                        right = true;
                    }
                    else {
                        return false;
                    }
                }
                
                if (top->left ) {
                    if (top->left) {
                        if (top->val > top->left->val) {
                            left = true;
                        }
                        else {
                            return false;
                        }
                    }

                }
                temp.pop();
                if (right) {
                    temp.push(top->right);
                }
                if (left) {
                    temp.push(top->left);
                }


            }
            return true;
            
        
        
        }
    
};

int main() {
    TreeNode* first = new TreeNode(5);
    TreeNode* current = first;
    first->left = new TreeNode(1);
    first->right = new TreeNode(6);
    current = first->right;
    current->left = new TreeNode(3);
    current->right = new TreeNode(7);
    Solution sol;
    cout<<sol.isValidBST(first);
    


   
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
