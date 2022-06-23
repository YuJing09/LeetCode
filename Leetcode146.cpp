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
class LRUCache {
public:
    LRUCache(int capacity);

    int get(int key);  
    void movefront(int key);
    void insert(int key, int value);
    void delback();
    void put(int key, int value);
private:
    DLNode* LRU;
    DLNode* last;
    int cap;
    unordered_map<int, DLNode*> dict;
    int size;
    
};
LRUCache::LRUCache(int capacity) {
    cap = capacity;
    size = 0;
    LRU = 0;
    last = 0;
    


}
void LRUCache::insert(int key, int value) {
    DLNode* insert = new DLNode(key, value);
    dict[key] = insert;
    if (LRU) {
        insert->next = LRU;
        insert->pre = 0;
        LRU->pre = insert;
        LRU = insert;
    }
    else {
        LRU = insert;
        last = insert;
        LRU->pre = 0;
    }

    size++;

}
void LRUCache::movefront(int key) {
    if (dict[key] != LRU) {


        DLNode* temp = dict[key];
        temp->pre->next = temp->next;
        if (temp->next) {
            temp->next->pre = temp->pre;
        }
        else {
            last = temp->pre;
        }

        temp->next = LRU;
        temp->pre = 0;
        LRU->pre = temp;
        LRU = temp;
    }
    
    

}
void LRUCache::delback() {
    last->pre->next = 0;
    dict[last->key] = 0;
    last = last->pre;
    size--;
    
    
}
void LRUCache::put(int key, int value) {
    if (!dict[key]&&size<cap) {
        insert(key, value);
    }
    else if (!dict[key]) {
        insert(key, value);
        delback();
    }
    else {
        dict[key]->val = value;
        movefront(key);
       
        
    }
}
int LRUCache::get(int key) {
    if (!dict[key]) {
        return -1;
    }
    else {
        movefront(key);
        return dict[key]->val;
    }

    
}


int main() {


    vector<int> root{ 1,NULL,2,3 };
    TreeNode* tree = constructTree(root);
    LRUCache l(2);
    l.put(1, 1);
    l.put(2, 2);
    cout<<l.get(1);
    l.put(3, 3);
    l.get(2);
    l.put(4, 4);
    cout << l.get(3);
  
    
    
    
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
