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
    vector<int> grayCode(int n) {
        vector<int> output;
        string temp="";
        
        temp.assign(n,'0');
        int p;
        int num;
        for (int i = 0; i < int(pow(2,n)); i++) {

            if (i == 0) {
                output.push_back(0);
                
            }
            else if (i % 2 != 0) {
                p = 0;
                num = 0;
                if (temp[temp.size()-1] == '0') {
                    temp[temp.size()-1] = '1';
                }
                else {
                    temp[temp.size()-1] = '0';
                }
    
                for (auto it = temp.rbegin(); it != temp.rend(); it++) {
                    if (*it == '1') {
                        num += (int)pow(2, p);
                    }
                    p++;
                }
               
                output.push_back(num);
            }
            else {
                for (auto it = temp.rbegin(); it!=temp.rend(); it++) {
                    if (*it != '1') {
                        continue;
                    }
                    else {
                        p = 0;
                        num = 0;
                        if (*(it + 1) == '0') {
                         
                            *(it + 1) = '1';
                            
                            for (auto itt = temp.rbegin(); itt != temp.rend(); itt++) {
                                
                                if (*itt == '1') {
                             
                                    num += (int)pow(2, p);
                           
                                }
                                p++;
                            }
                            
                            output.push_back(num);
                            break;
                        }
                        else {
                            *(it + 1) = '0';
                            for (auto itt = temp.rbegin(); itt != temp.rend(); itt++) {
                                if (*itt == '1') {
                                    num += (int)pow(2, p);
                                }
                                p++;
                               
                            }
                            output.push_back(num);
                            break;
                        }
                    }
                }
            }



        }
        return output;



    }

};
int main() {
    
    Solution sol;
    int n = 3;
    vector<int> o=sol.grayCode(n);
    for (int i = 0; i < o.size(); i++) {
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
