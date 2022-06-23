// Leetcode2.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
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
    DLNode() :key(0), val(0), next(0), pre(0) {};
    DLNode(int x, int y) :key(x), val(y), next(0), pre(0) {};
    DLNode(int x, int y, DLNode* pre, DLNode* next) :key(x), val(y), next(next), pre(pre) {};
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
    int left, right;
    bool ispart;
    for (size_t i = 0; i < s.size(); ++i) {
        ispart = true;

        if (i == 0) {
            output.push_back(s.substr(0, i + 1));
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
void merge2(vector<int> input, vector<int>& output, int f, int n, int e) {
    int left = f;
    int right = n;
    int start = f;

    while (left < n && right <= e) {

        if (input[left] <= input[right]) {
            output[start++] = input[left++];
        }
        else {
            output[start++] = input[right++];
        }
    }


    if (left >= n) {
        for (size_t i = 0; i < (e - right + 1); ++i) {
            output[start++] = input[right + i];
        }

    }
    else {

        for (size_t i = 0; i < (n - left); ++i) {
            output[start++] = input[left + i];
        }

    }


}
void Mergepass(vector<int> input, vector<int>& output, int n) {
    int i = 0;
    output.assign(input.begin(), input.end());

    while ((input.size() - i) >= (2 * n)) {


        merge2(input, output, i, i + n, (i + 2 * n - 1));
i += 2 * n;
    }

    if ((input.size() - i + 1) > n) {
        merge2(input, output, i, i + n, input.size() - 1);
    }




}
void mergesort(vector<int>& input) {

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
int gcdd(int& m, int& n) {
    int t;

    t = (m % n);

    m = n;
    n = t;
    if (t != 0) {


        return gcdd(m, n);
    }
    else {

        return m;
    }
}
struct simplepairhash {
    size_t operator()(const pair<int, int>& p)const {


        return p.first ^ p.second;
    }


};
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);

        if (hash1 != hash2) {
            return hash1 ^ hash2;
        }

        // If hash1 == hash2, their XOR is zero.
        return hash1;
    }
};

pair<float, float > computelin(pair<int, int> v1, pair<int, int> v2) {
    float sl, xd, yd;
    float b;
    pair<float, float> output;
    yd = v2.second - v1.second;
    xd = v2.first - v1.first;
    if (abs(yd) <= pow(10, -4)) {
        sl = 0;
        b = v1.second;

    }
    else if (abs(xd) <= pow(10, -4)) {
        sl = pow(10, 5);
        b = v1.first;
    }
    else {
        sl = yd / xd;

        b = v1.second - v1.first * sl;
        if (abs(floor(b) - b) <= pow(10, -4)) {
            b = floor(b);
        }
        else if (abs(ceil(b) - b) <= pow(10, -4)) {
            b = ceil(b);
        }


    }
    output.first = sl;
    output.second = b;
    return output;


}
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if (tokens.size() == 1) {
            const char* temp;
            temp = tokens[0].c_str();
            return atoi(temp);
        }
        stack<int> cs;
        int be_num, num;
        const char* temp;
        int out;
        for (size_t i = 0; i < tokens.size(); ++i) {
            if (isalnum(tokens[i][0]) || tokens[i].size() > 1) {
                temp = tokens[i].c_str();
                cs.push(atoi(temp));
            }
            else {
                num = cs.top();
                cs.pop();
                be_num = cs.top();
                cs.pop();
                if (tokens[i] == "*") {
                    out = be_num * num;
                }
                else if (tokens[i] == "+") {
                    out = be_num + num;
                }
                else if (tokens[i] == "-") {
                    out = be_num - num;
                }
                else {
                    out = be_num / num;
                }
                cs.push(out);



            }

        }
        return out;


    }
};
int main()
{
 
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
