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

template <class T>
void clear(T q) {
        T empty;
        swap(empty, q);
    }
TreeNode* constructTree(vector<int> root) {
    TreeNode* output = 0;
    queue<TreeNode*> temp;
    int size;

    size = root.size();

    if (size == 0) {
        return output;
    }

    //int h = log2(size);
    output = new TreeNode(root[0]);
    temp.push(output);
    int m = 1;
    while (m < size) {

        if (root[m] != 0) {

            temp.front()->left = new TreeNode(root[m]);

            temp.push(temp.front()->left);
            ++m;
        }
        else {

            temp.front()->left = 0;
            ++m;
        }


        if (m < size) {

            if (root[m] != 0) {
                temp.front()->right = new TreeNode(root[m]);
                temp.push(temp.front()->right);
                ++m;
            }
            else {
                temp.front()->right = 0;
                ++m;
            }
        }


        temp.pop();

    }
    return output;



}
vector<vector<int>> levelorder(TreeNode* root) {
    vector<vector<int>> output;
    vector<int> temp;
    queue<TreeNode*> level;
    if (root) {
        temp.push_back(root->val);
        level.push(root);
        output.push_back(temp);

    }
    else {
        return output;
    }
    int size;
    while (level.size() >= 1) {
        
        temp.clear();
        size = level.size();
        for (size_t i = 0; i < size; ++i) {
            if (level.front()->left) {
                temp.push_back(level.front()->left->val);
                level.push(level.front()->left);
            }
            else {
                temp.push_back(NULL);

            }
            if (level.front()->right) {
                temp.push_back(level.front()->right->val);
                level.push(level.front()->right);
            }
            else {
                temp.push_back(NULL);

            }
            level.pop();
        }
        if (level.size() > 0) {
            output.push_back(temp);
        }
        

    }
    for (size_t i = 0; i < output.size(); ++i) {
        for (const auto l : output[i]) {
            cout << l << " ";
        }
        cout << endl;
    }
    return output;


}
TreeNode* rotatebst(TreeNode* root, int m) {
    if (m <= 2) {
        
        
        return root;
      }
      else {

        int rr;
        TreeNode* temp = 0;
        if ((m % 2) == 0) {
            rr = m / 2 - 1;
        }
        else {
            rr = m / 2;
        }
        int ini = 0;
        TreeNode* output = root;
        TreeNode* current = 0;
 
        for (size_t i = 0; i < rr;++i) {
            current = output->left;
            current->right = output->right;
         
            if (ini == 0) {

                current->right = new TreeNode(output->val);
                temp = current->right;
                ++ini;
            }
            else {
                temp->left = new TreeNode(output->val);
                temp = temp->left;
            }



            output = output->left;

            

        }
   
        int r = rr;
        int l = m - rr - 1;
 
        output->left=rotatebst(output->left,l);
        output->right=rotatebst(output->right, r); 
        return output;

    }
   
}
struct Status {
    int height;
    bool balance;
    Status() :height(0), balance(true) {};

};
Status getStatus(TreeNode* root) {
    Status output,leftStatus,rightStatus;
 
    if (!root) {
        return output;
    }

    if (root->left) {
        leftStatus = getStatus(root->left);
        if (leftStatus.balance == false) {
            output.balance = false;
            return output;
        }

    }
    else {
        leftStatus.height = 0;
    }
    if (root->right) {
        rightStatus = getStatus(root->right);
        if (rightStatus.balance == false) {
            output.balance = false;
            return output;
        }
    }
    else {
        rightStatus.height = 0;
    }
    
    
    if (!rightStatus.balance || !leftStatus.balance) {
        output.balance = false;
        return output;
    }
    
    else if (abs(rightStatus.height - leftStatus.height) <= 1) {
        output.balance = true;
        output.height = max(rightStatus.height, leftStatus.height)+1;
        
    }
    else {
        output.balance=false;
        return output;
    }
    return output;



}
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return getStatus(root).balance;

   }
};


int main() {
    vector<int> root{1, 2, 2, 3, 3, NULL,NULL, 4, 4
};
    TreeNode* tree = constructTree(root);
    Solution sol;
    cout << sol.isBalanced(tree) << endl;

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
