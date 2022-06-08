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

vector<TreeNode*> reTrees(int n, int offset) {
    vector<TreeNode*> output;
    TreeNode* first = 0;
    
    if (n == 1) {
        first = new TreeNode(n + offset);
        output.push_back(first);
        return output;
    }
    else if(n==2) {
        first = new TreeNode(1 + offset);
        first->right = new TreeNode(2 + offset);
        output.push_back(first);
        first = new TreeNode(2 + offset);
        first->left = new TreeNode(1 + offset);
        output.push_back(first);
        return output;
    
    }
    else if (n == 0) {
        return output;
    }
    else {
        vector<TreeNode*> left;
        vector<TreeNode*> right;
        TreeNode* temp;
        for (size_t i = 0; i < n; ++i) {

            
            
            left = reTrees(i - 0, 0);
            right = reTrees(n - i - 1, i + 1);
            if (left.size() == 0) {
                for (size_t r = 0; r < right.size(); ++r) {
                    first = new TreeNode(i + 1);
                    first->right = right[r];
                    output.push_back(first);
                }
                

            
            }
            else if (right.size() == 0) {
                for (size_t l = 0; l < left.size(); ++l) {
                    first = new TreeNode(i + 1);
                    first->left = left[l];
                    output.push_back(first);
                }

            }
            else {
                for (size_t l = 0; l < left.size(); l++) {
                    for (size_t r = 0; r < right.size(); r++) {
                        first = new TreeNode(i + 1);
        
                        first->left = left[l];
           
                        first->right = right[r];

                        
                        output.push_back(first);

                    }
                }
            }
            
        
        
        }
        return output;
    }

}
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {

        vector<TreeNode*> output;
        output = reTrees(n, 0);
        return output;

    }
};

int main() {
    
    
    Solution sol;
    vector<TreeNode*> output=sol.generateTrees(3);
    vector<TreeNode*> temp;
    vector<int> temp2;
    int m;
    TreeNode* zeronode;
    for (size_t i = 0; i < output.size(); ++i) {
        temp.push_back(output[i]);
        temp2.push_back(output[i]->val);
        m = 0;
        
        while (temp[m]->left||temp[m]->right||m<temp.size()) {

            if (temp[m]->left&&temp[m]->right) {
   
                zeronode = new TreeNode(0);
                temp.push_back(temp[m]->left);

                temp2.push_back(temp[m]->left->val);

                temp.push_back(temp[m]->right);
                temp2.push_back(temp[m]->right->val);
                ++m;

            }
            else if (temp[m]->left) {

                zeronode = new TreeNode(0);
  
                temp.push_back(temp[m]->left);
                temp2.push_back(temp[m]->left->val);
                temp.push_back(zeronode);
                temp2.push_back(0);
                ++m;


            }
            else if (temp[m]->right) {
               
                zeronode = new TreeNode(0);
                temp.push_back(zeronode);
                temp2.push_back(0);
                temp.push_back(temp[m]->right);
                temp2.push_back(temp[m]->right->val);
                ++m;


            }
            else {
                ++m;
                if (m >= temp.size()) {
                    break;
                }
            }
           
        }
        
        for (size_t j = 0; j < temp2.size(); j++) {
            cout << temp2[j] << " ";
        }
        cout << endl;
        temp.clear();
        temp2.clear();
    
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
