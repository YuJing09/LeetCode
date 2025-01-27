﻿// Project6.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
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


class Solution {
public:
    string minWindow(string s, string t) {
        string res = "";
        unordered_map<char, int> letterCnt;
        int left = 0, cnt = 0, minLen = INT_MAX, minLeft = -1;
        for (char c : t) letterCnt[c]++;
        for (int i = 0; i < s.size(); i++) {
            if (letterCnt[s[i]] > 0)
            {
                letterCnt[s[i]]--;
                cnt++;
            }
            else {
                letterCnt[s[i]]--;
            }

            while (cnt == t.size()) {
                if (minLen > i - left + 1) {
                    minLen = i - left + 1;
                    minLeft = left;
                }

                if (letterCnt[s[left]] == 0) {
                    letterCnt[s[left]]++;
                    cnt--;
                }
                else {
                    letterCnt[s[left]]++;
                }
                left++;
            }
        }
        if (minLen == INT_MAX) {
            return res;
        }
        else {
            res = s.substr(minLeft, minLen);
            return res;
        }

    }
};

int main()
{
    Solution sol;
    
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout<<sol.minWindow(s, t);
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
