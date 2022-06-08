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
#include <queue>
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


void clear(queue<TreeNode*>& q) {
    queue<TreeNode*> empty;
    swap(empty, q);
}
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        queue<TreeNode*> q2;
        vector<vector<int>> output;
        if (!root) {
            return output;
        }
        q.push(root);
        vector<int> temp;
        temp.push_back(root->val);
        output.push_back(temp);
        int n;
        while (q.size() > 0) {
            clear(q2);
            temp.clear();
            n = q.size();
            for (size_t i = 0; i < n; ++i) {

                if (q.front()->left) {
                    q2.push(q.front()->left);
                    temp.push_back(q.front()->left->val);
                }

                if (q.front()->right) {
                    q2.push(q.front()->right);
                    temp.push_back(q.front()->right->val);
                }
                q.pop();

            }
            if (q2.size() > 0) {
                q = q2;
                output.push_back(temp);
            }
            else {
                return output;
            }


        }
        return output;


    }
};


int main() {
    //int a[10] = { 12,9,8,22,46,4,32,7,11,50 };
    
    
   
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
