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

void Quicksort(vector<int>& nums, int l, int r) {
    if (r > l) {
        int pivot = nums[l];
        int left = l + 1;
        int right = r;
        while (right >= left) {
            while (left<=right&&nums[left] <= pivot) { left++; };
            while (nums[right] > pivot) { right--; };
            if (right > left) {
                swap(nums[left],nums[right]);
            }
        }
        swap(nums[l], nums[right]);
        Quicksort(nums, l, right - 1);
        Quicksort(nums, right + 1, r);
    
    
    }




}
string decode(string s) {
    char temp[2];
    int A_asc = toascii('A');
    temp[0] = A_asc + atoi(s.c_str()) - 1;
    temp[1] = '\0';
    return temp;
}
vector<string> decoding(string s) {
    vector<string> output;
   
    
    vector<string> front;
    vector<string> back;
  
    if (s.size() ==1) {
        
        
        if (atoi(s.c_str()) > 0) {
            output.push_back(decode(s));
        }
        return output;
    }
    else if (s.size() == 2) {
        if (s.back() != '0' && s.front() != '0') {
  
            output.push_back(decode(s.substr(0, 1)) + decode(s.substr(1, 2)));
        }
        if(s.front()!='0'&&atoi(s.c_str())<=26&&atoi(s.c_str())>0){

            output.push_back(decode(s.c_str()));
        
        }
        return output;



    }
    else  {
        for (int i = 1; i <= 2;i++) {
             
              front = decoding(s.substr(0, i));
              back = decoding(s.substr(i, s.size()));
              for (int j = 0; j < front.size(); j++) {
                  for (int k = 0; k < back.size(); k++) {
                      output.push_back(front[j] + back[k]);
                  }
              }
            
            
        }
        return output;
        
    }
    
    

    
}
class Solution {
public:
    int numDecodings(string s) {
        vector<string> temp = decoding(s);
        set<string> sset; 
        for (int i = 0; i < temp.size(); i++) {
            cout << temp[i] << endl;
            sset.insert(temp[i]);
        }
        return (int)sset.size();

    }

};
int main() {
    
    
    Solution sol;
    string s = "26726";
    cout<<sol.numDecodings(s);

   
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
