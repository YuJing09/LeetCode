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
    bool isInterleave(string s1, string s2, string s3) {

        if (s2.size() == 0) {
            if (s1 == s3) {
                return true;
            }
        }
        else if (s1.size() == 0) {
            if (s2 == s3) {
                return true;
            }
        }
        else if (s3.size() == 2) {
            if (s1[0] == s3[0] && s2[0] == s3[1]) {
                return true;
            }
            else if (s1[0] == s3[1] && s2[0] == s3[0]) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            if (s3[0] == s1[0]&&s3[0]!=s2[0]) {
                return isInterleave(s1.substr(1, s1.size()-1),s2,s3.substr(1,s3.size()-1));
            }
            else if (s3[0] == s2[0] && s3[0] != s1[0]) {
                return isInterleave(s1, s2.substr(1, s2.size() - 1), s3.substr(1, s3.size() - 1));
            }
            else {
                return (isInterleave(s1.substr(1, s1.size() - 1), s2, s3.substr(1, s3.size() - 1)) && isInterleave(s1, s2.substr(1, s2.size() - 1), s3.substr(1, s3.size() - 1)));
            }


        }





    }
};

int main() {
    
    
    Solution sol;
    string s1 = "aabcc";
    string s2 = "abbca";
    string s3 = "aadbbbaccc";
    cout<<sol.isInterleave(s1, s2, s3);
    

   
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
