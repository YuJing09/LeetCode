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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) {

            return true;
        }
        else if (!(p && q)) {

            return false;
        }
        else if (p->val == q->val) {

            stack<TreeNode*> sp;
            stack<TreeNode*> sq;
            int m = 0;
            sp.push(p);
            sq.push(q);
            ++m;
            bool l;
            bool r;
            TreeNode* p1;
            TreeNode* q1;
            while (sp.size() >= 1 && sp.top()->val == sq.top()->val) {
                p1 = sp.top();
                q1 = sq.top();

                sp.pop();
                sq.pop();
                if (p1->left && q1->left) {

                    l = true;
                }
                else if (!p1->left && !q1->left) {
                    l = false;
                }
                else {

                    return false;
                }
                if (p1->right && q1->right) {

                    r = true;

                }
                else if (!p1->right && !q1->right) {
                    r = false;
                }
                else {

                    return false;
                }
                if (l) {
                    sp.push(p1->left);
                    sq.push(q1->left);


                }
                if (r) {
                    sp.push(p1->right);
                    sq.push(q1->right);

                }


            }
            if (sp.size() > 0) {
                return false;
            }
            return true;



        }
        else {

            return false;
        }



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
