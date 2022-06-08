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
    bool isSymmetric(TreeNode* root) {
        vector<TreeNode*> left;
        vector<TreeNode*> right;
        if (root->left && root->right) {
            if (root->left->val == root->right->val) {
                left.push_back(root->left);
                right.push_back(root->right);
            }
            else {
                return false;
            }
        }
        else if (!root->left && !root->right) {
            return true;
        }
        else {
            return false;
        }

        vector<TreeNode*> next_left, next_right;
        while (left.size() > 0) {

            if (left.size() == right.size()) {
                next_left.clear();
                next_right.clear();
                for (size_t i = 0; i < left.size(); ++i) {
                    if (left[i]->left && !right[i]->right) {
                        return false;
                    }
                    else if (right[i]->right && !left[i]->left) {
                        return false;

                    }
                    else if (right[i]->right && left[i]->left)
                    {
                        next_left.push_back(left[i]->left);
                        next_right.push_back(right[i]->right);

                        if (next_left.back()->val != next_right.back()->val) {
                            return false;
                        }
                    }
                    if (left[i]->right && !right[i]->left) {
                        return false;
                    }
                    else if (right[i]->left && !left[i]->right) {
                        return false;

                    }
                    else if (right[i]->left && left[i]->right)
                    {
                        next_left.push_back(left[i]->right);
                        next_right.push_back(right[i]->left);

                        if (next_left.back()->val != next_right.back()->val) {
                            return false;
                        }
                    }

                }
                left = next_left;
                right = next_right;
            }
            else {
                return false;
            }


        }
        return true;

    }
};




int main() {
    //int a[10] = { 12,9,8,22,46,4,32,7,11,50 };
    bool a = false;
    bool b = false;
    bool c = a == b;
    cout << c << endl;
   
   
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
