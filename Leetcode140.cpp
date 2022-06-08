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

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, int> dict1;
        unordered_map<char, vector<string>> dict2;
        vector<string> output;
        for (size_t i = 0; i < wordDict.size(); ++i) {
            dict1[wordDict[i]] = i;
            dict2[wordDict[i].front()].push_back(wordDict[i]);


        }
        vector < vector<int>> cand;
        vector<vector<int>> clone;
        vector<int> temp;
        unordered_map<int, vector<int>> comb;
        for (size_t i = 0; i < s.size(); ++i) {
            cout << i << endl;
            if (i == 0) {
                
                for (size_t j = 0; j < dict2[s[i]].size(); ++j) {
                    temp.clear();
                    if (dict2[s[i]][j].size() > 1) {
                        temp.push_back(dict1[dict2[s[i]][j]]);
                        temp.push_back(1);
                        
                        cand.push_back(temp);
                    }
                    else {
                        comb[i].push_back(dict1[dict2[s[i]][j]]);
                    }


                }


            }
            else {
                clone = cand;
                int del = 0;
                for (size_t j = 0; j < clone.size(); ++j) {
                    
                    if (wordDict[clone[j][0]][clone[j][1]] == s[i]) {
                        
                       
                        clone[j][1] += 1;
                       
                        cand[j - del][1] += 1;
                        if (clone[j][1] >= wordDict[clone[j][0]].size()) {
                            cand.erase(cand.begin()+( j - del));
                            comb[i - clone[j][1] + 1].push_back(clone[j][0]);
                            del += 1;
                        }

                    }
                    else {
                       
                       
                        cand.erase(cand.begin()+(j-del));
                        
                        del += 1;
                    }
                }
                
                for (size_t j = 0; j < dict2[s[i]].size(); ++j) {
                    temp.clear();
                    if (dict2[s[i]][j].size() > 1) {
                        temp.push_back(dict1[dict2[s[i]][j]]);
                        temp.push_back(1);
                        cand.push_back(temp);
                    }
                    else {
                        comb[i].push_back(dict1[dict2[s[i]][j]]);
                    }


                }



            }



        }
       
        queue<string> combin;
        queue<int> index;
        for (size_t i = 0; i < comb[0].size(); ++i) {
            combin.push(wordDict[comb[0][i]]);
            index.push(wordDict[comb[0][i]].size());
        }
        string current;
        int now;
        while (!combin.empty()) {
            current = combin.front();
            now = index.front();
            if (now == s.size()) {
                output.push_back(current);
            }
            combin.pop();
            index.pop();
            for (size_t j = 0; j < comb[now].size(); ++j) {
                index.push(now+wordDict[comb[now][j]].size());
                combin.push(current +" "+ wordDict[comb[now][j]]);
                
            }


        }
        return output;
    }

        
};
int least_significant_1_bit(int x)
{
    return (x &-1*x);
}
int main() {



    string s = "a";

    vector<string> wordDict{ "b" };
    
    Solution sol;
    vector<string> out= sol.wordBreak(s, wordDict);
    for (size_t i = 0; i < out.size(); ++i) {
        cout << out[i] << endl;
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
