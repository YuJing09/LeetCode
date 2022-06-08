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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> output;
        if (!root) {
            return output;
        }
        else {
            bool r = true;
            TreeNode* now = root;
            vector<TreeNode*> sr;
            while (now) {
                
                while (now->left&&r) {
                    sr.push_back(now);
                    now = now->left;
                }
                output.push_back(now->val);
                
                
                if (now->right) {
                    now = now->right;
                    r = true;
                    continue;

                }
                else {
                    if (sr.size() >= 1) {
                        now = sr.back();
                        sr.pop_back();
                        r = false;
                        continue;

                    }
                    else {
                        return output;
                    }

                }



            }
            return output;


        }


    }
};

int main() {
    
    
    Solution sol;
    int a[10] = { 12,9,8,22,46,4,32,7,11,50 };
    TreeNode* root = new TreeNode(a[0]);
    TreeNode* current=0;
    bool find;
    for (int i = 1; i < 10; ++i) {
        current = root;
        find = false;
        while (!find) {
            if (a[i] > current->val) {
                if (current->right == 0) {
                    //cout << a[i] << endl;
                    current->right = new TreeNode(a[i]);
                    find = true;
                }
                else {
                    current = current->right;
                }
            }
            else if (a[i] < current->val) {
                if (current->left == 0) {
                    current->left = new TreeNode(a[i]);
                    //cout << a[i] << endl;
                    find = true;

                }
                else {
                    current = current->left;
                }

            }

        }
    }
    
  
    vector<int> output=sol.inorderTraversal(root);
  
    for (size_t i = 0; i < output.size(); ++i) {
        
        cout << output[i] << endl;
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
