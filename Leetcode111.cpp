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
class Solution {
public:
    int minDepth(TreeNode* root) {
        
        if (root) {
            queue<TreeNode*> temp;
            int min=1;
            int size;
            temp.push(root);
            while (temp.size() >= 1) {
                
           
              size = temp.size();
                    for (size_t i = 0; i < size; ++i) {
                        if (!temp.front()->left && !temp.front()->right) {
                            return min;
                        }
                        else {
                            if (temp.front()->left) {
                                temp.push(temp.front()->left);
                            }
                            if (temp.front()->right) {
                                temp.push(temp.front()->right);
                            }
                        }
                        temp.pop();
                    }
                    ++min;
                

            }
            return min;
        }
        else {
            return 0;
        }
        
   
        
    }
};


int main() {
    vector<int> root{ 2,NULL,3,NULL,4,NULL,5,NULL,6 };
    TreeNode* tree= constructTree(root);
    Solution sol;
    cout<<sol.minDepth(tree);
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
