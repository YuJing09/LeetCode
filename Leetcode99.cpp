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

vector<TreeNode*> Inorder(TreeNode* root) {
    vector<TreeNode*> output;
    vector<TreeNode*> left, right;
    if (root->left) {
        left = Inorder(root->left);
        output.assign(left.begin(), left.end());
        output.push_back(root);
    }
    else {
        output.push_back(root);
    }


    if (root->right) {
        right = Inorder(root->right);
        output.insert(output.end(), right.begin(), right.end());

    }
    return output;



}

bool compareval(TreeNode* a, TreeNode* b) {
    return a->val < b->val;
}
class Solution {
public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> inor = Inorder(root);
        vector<TreeNode*> rightpos = inor;
        vector<int> temppre;
        sort(rightpos.begin(), rightpos.end(), compareval);
        for (size_t i = 0; i < rightpos.size(); ++i) {
            temppre.push_back(rightpos[i]->val);

        }
        for (size_t i = 0; i < inor.size(); ++i) {
            if (inor[i]->val == temppre[i]) {
                continue;
            }
            else {
                inor[i]->val = temppre[i];
            }
        }



    }

};
int main() {
    //int a[10] = { 12,9,8,22,46,4,32,7,11,50 };
    Solution sol;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2);
    vector<TreeNode*> temp;
    
    sol.recoverTree(root);
    temp = Inorder(root);
    for (size_t i = 0; i < temp.size(); ++i) {
        cout << temp[i]->val << endl;
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
