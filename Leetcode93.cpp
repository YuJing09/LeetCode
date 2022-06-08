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


bool valid(string s) {
    if (s[0] == '0'&&s.size()>1) {
        return false;
    }
    else {
 
        if (atoi(s.c_str()) >= 0 && atoi(s.c_str()) <= 255) {
            
            return true;
        }
        else {
            return false;
        }
    }
}


class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> output;
        if (s.size() > 12 || s.size() < 4) {
            return output;
        }
        else {
        
            string temp;
            string temp_o;
            int n1, n2, n3, n4;
            for (size_t i = 1; i <= 3; ++i) {
                for (size_t j = 1; j <= 3; ++j) {
                    for (size_t k = 1; k <= 3; ++k) {
                        //cout << k << endl;
                        temp_o.clear();
                        n1 = i;
                        n2 = j;
                        n3 = k;
                        n4 = s.size() - i - j - k;
                        //cout << n1 << n2 << n3 << n4 << endl;
                        if (n4 > 3 || n4 <= 0) {
                            continue;
                        }
                        temp = s.substr(0, n1);
                        if (valid(temp)) {
                            temp_o += temp;
                            temp_o += ".";

                        }
                        else { continue; }
                        temp = s.substr(n1, n2);
                        if (valid(temp)) {
                            temp_o += temp;
                            temp_o += ".";
                        }
                        else {
                            continue;
                        }
                        temp = s.substr(n1 + n2, n3);
                        if (valid(temp)) {
                            temp_o += temp;
                            temp_o += ".";
                        }
                        else {
                            continue;
                        }
                        temp = s.substr(n1 + n2 + n3, n4);
                        if (valid(temp)) {
                            temp_o += temp;
                        }
                        else {
                            continue;
                        }
                        output.push_back(temp_o);






                    }


                }
            }
                return output;


            
        }
    }
};

int main() {
    
    
    Solution sol;
    
    string s = "25525511135";
    vector<string> o=sol.restoreIpAddresses(s);
    for (size_t i = 0; i < o.size(); ++i) {
        cout << o[i] << endl;
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
