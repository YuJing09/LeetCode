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
#include <unordered_set>


using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() :val(0), next(0) {};
    ListNode(int x) :val(x), next(0) {};
    ListNode(int x, ListNode* next) :val(x), next(next) {};
};
struct DLNode {
    int val;
    int key;
    DLNode* next;
    DLNode* pre;
    DLNode() :key(0),val(0), next(0) ,pre(0) {};
    DLNode(int x,int y) :key(x),val(y), next(0),pre(0) {};
    DLNode(int x,int y, DLNode* pre,DLNode* next) :key(x), val(y), next(next), pre(pre) {};
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
vector<int> findlad(string beginword, string endword, vector<string> wordList) {
    vector<int> output;
    int diff;
    for (size_t i = 0; i < wordList.size(); ++i) {
        diff = 0;
        for (size_t j = 0; j < beginword.size(); j++) {
            if (wordList[i][j] != beginword[j]) {
                diff++;
            }

        }
        if (diff == 1) {
            output.push_back(i);
        }
    }
    return output;


}
vector<string> part(string s) {
    vector<string> output;
    int left,right;
    bool ispart;
    for (size_t i = 0; i < s.size();++i) {
        ispart = true;
        
        if (i == 0) {
            output.push_back(s.substr(0, i+1));
        }
        else {

            left = 0;
            right = i;
            while (left < right) {
                if (s[left] == s[right]) {
                    left++;
                    right--;
                }
                else {
                    ispart = false;
                    break;
                }

            }
            if (ispart) {
                output.push_back(s.substr(0, i + 1));
            }


        


        }
    }
    return output;



}

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 /**
  * Definition for singly-linked list.
  * struct ListNode {
  *     int val;
  *     ListNode *next;
  *     ListNode() : val(0), next(nullptr) {}
  *     ListNode(int x) : val(x), next(nullptr) {}
  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
  * };
  */
void merge2(vector<int> input, vector<int> &output, int f, int n, int e) {
    int left = f;
    int right = n;
    int start = f;
    
    while(left<n&&right<=e) {
        
        if (input[left] <= input[right]) {
            output[start++] = input[left++];
        }
        else {
            output[start++]=input[right++];
        }
    }
    

      if (left >= n) {
          for (size_t i = 0; i < (e - right + 1); ++i) {
              output[start++]=input[right + i];
          }
          
        }
      else{
         
          for (size_t i = 0; i < (n-left); ++i) {
              output[start++]=input[left + i];
          }

    }


}
void Mergepass(vector<int> input, vector<int>& output,int n) {
    int i = 0;
    output.assign(input.begin(), input.end());

    while ((input.size() - i) >= (2 * n)) {

      
        merge2(input, output, i, i+n, (i + 2 * n - 1));
        i += 2 * n;
    }

    if ((input.size() - i + 1) > n) {
        merge2(input, output, i, i + n, input.size() - 1);
    }
   



}
void sw (int& a, int& b) {
    int temp = a ^ b;
    a = temp ^ a;
    b = temp ^ b;
}
void mergesort(vector<int> &input) {

    vector<int> temp;
    //int n = 1;
    for (size_t i = 1; input.size() > i; i *= 2) {

        Mergepass(input, temp, i);
        i *= 2;
        Mergepass(temp, input, i);


    }


}
int gcd(int m, int n) {
    int t = 1;
    while (t != 0) {
        t = m % n;
        m = n;
        n = t;
            
    }
    return m;
}
int gcdd(int &m, int& n) {
    int t;

    t = (m%n);
    
    m = n;
    n = t;
    if (t != 0) {
        
        
        return gcdd(m, n);
    }
    else {

        return m ;
    }
}
class Solution {
public:
    int romanToInt(string s) {

        unordered_map<char, int> dict;
        dict['I'] = 1;
        dict['V'] = 5;
        dict['X'] = 10;
        dict['L'] = 50;
        dict['C'] = 100;
        dict['D'] = 500;
        dict['M'] = 1000;
        int sum=0;
        sum += dict[s.size() - 1];
        int size = s.size();
        for (size_t i = size - 1; i > 0; --i) {
            
            if (dict[s[i - 1]] >= dict[s[i]]) {
                sum += dict[s[i - 1]];
            }
            else{
                sum -= dict[s[i - 1]];
            
            }

        }   
        return sum;

    }
};

typedef union {
    char c;
    int a;
    int b;

}demo;

int main() {
  
    string s = "MCMXCIV";
    Solution sol;
    cout<<sol.romanToInt(s);
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
