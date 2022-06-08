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





    class Solution {
    public:
        ListNode* reverseBetween(ListNode* head, int left, int right) {
            
            int l = left - 1;
            int r = right - 1;
            if (r > l) {
          
                ListNode* first = head;

                ListNode* c_first = 0;
                ListNode* end = 0;
                ListNode* pre = 0;
                ListNode* now = 0;
                ListNode* current = first;
                int n = 0;
                while (current) {
                    if (n == (l - 1)) {
                        c_first = current;
                        current = current->next;
                        ++n;
                    }
                    else if (n < l) {
                        current->next;
                        ++n;
                    }
                    else {
                        for (int i = 0; i < (right - left); ++i) {
                            
                            if (i == 0) {

                                pre = new ListNode(current->val);
                                end = pre;
                                now = new ListNode(current->next->val);
                                now->next = pre;
                                current = current->next;
                            }

                            else {
                                pre = now;
                                now = new ListNode(current->next->val);
                                now->next = pre;
                                current = current->next;
                            }
                           
                        }
                        if (c_first) {
                            
                            c_first->next = now;
                            end->next = current->next;
                            return first;
                        }
                        else {
                            
                            end->next = current->next;
                     
                         
                            return now;
                        }

                    }


                }
            }
            else {
                return head;
            }

        }
    };

int main() {
    
    
    Solution sol;
    int head[5] = { 1,2,3,4,5 };
    ListNode* first = 0;
    ListNode* current = 0;
    for (int i = 0; i < 5; ++i) {
        if (i == 0) {
            first = new ListNode(head[i]);
            current = first;
        }
        else {
            current->next = new ListNode(head[i]);
            current = current->next;
        }
    }
    ListNode* output=sol.reverseBetween(first, 1,5);
    current = output;
    while (current) {
        cout << current->val << endl;
        current = current->next;
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
