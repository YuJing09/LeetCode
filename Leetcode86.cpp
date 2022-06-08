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

using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() :val(0), next(0) {};
    ListNode(int x) :val(x), next(0) {};
    ListNode(int x, ListNode* next) :val(x), next(next) {};
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* left_first = 0;
        ListNode* current_l = 0;
        ListNode* right_first = 0;
        ListNode* current_r = 0;
        ListNode* current = head;
        while (current) {
            if (current->val < x) {
                if (left_first == 0) {
                    left_first = new ListNode(current->val);
                    current_l = left_first;
                }
                else {
                    current_l->next = new ListNode(current->val);
                    current_l = current_l->next;
                }
            }
            else if (current->val >= x) {
                if (right_first == 0) {
                    right_first = new ListNode(current->val);
                    current_r = right_first;
                }
                else {
                    current_r->next = new ListNode(current->val);
                    current_r = current_r->next;
                }

            }
            current = current->next;


        }
        current_l->next = right_first;
        return left_first;
    }
    vector<string> scramble(string s1) {
        vector<string> output;
        if (s1.size() == 1) {
            output.push_back(s1);

            return output;
        }
        else if (s1.size() == 2) {
            output.push_back(s1);
            s1.assign(s1.rbegin(), s1.rend());
            output.push_back(s1);
            return output;

        }
        else if (s1.size() > 2) {
            string x;
            string y;
            vector<string> scr_x;
            vector<string> scr_y;

            for (int i = 1; i < s1.size(); i++) {
                x.assign(s1.begin(), s1.begin() + i);
                y.assign(s1.begin() + i, s1.end());
                scr_x = scramble(x);
                scr_y = scramble(y);
                for (int nx = 0; nx < scr_x.size(); nx++) {
                    for (int ny = 0; ny < scr_y.size(); ny++) {
                        output.push_back(scr_x[nx] + scr_y[ny]);
                        output.push_back(scr_y[ny] + scr_x[nx]);
                    }
                }

            }
            return output;



        }




    }
};
int main() {
    int head[6] = { 1,4,3,2,5,2 };
    ListNode* first=0;
    ListNode* current=0;
    int x = 3;
    Solution sol;
    for (int i = 0; i < 6; i++) {
        if (i == 0) {
            first = new ListNode(head[0]);
            current = first;
        }
        else {
            current->next =new ListNode( head[i]);
            current = current->next;
        }
    }
    ListNode* out=sol.partition(first,x);
    while (out) {
        cout << out->val<<endl;
        out = out->next;
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
