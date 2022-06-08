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
struct Node {
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() :val(0), left(NULL), right(NULL), next(NULL) {};
    Node(int _val) :val(_val), left(NULL), right(NULL), next(NULL) {};
    Node(int _val, Node* _left, Node* _right, Node* _next) :val(_val), left(_left), right(_right), next(_next) {};
};
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
struct vertex {
    int x;
    int y;
};
bool Issurround(vertex o, vector<vector<char>>& board, unordered_set<int>& set) {

    vector<vertex> output;
    output.push_back(o);

    set.insert(o.x + o.y);
    vertex temp;
    int colum = board[0].size();
    int index = 0;
    bool good = true;
    while (index < output.size()) {

        int x = output[index].x;
        int y = output[index].y;


        if (board[y][x - 1] != 'X' && (x - 1) != 0) {
            temp.x = x - 1; temp.y = y;

            if (!set.count(temp.x + temp.y * colum)) {
                output.push_back(temp);
                set.insert(temp.x + temp.y * colum);
            }
        }
        else if (board[y][x - 1] != 'X' && (x - 1) == 0) {
            good = false;
        }
        if (board[y - 1][x] != 'X' && (y - 1) != 0) {
            temp.x = x; temp.y = y - 1;

            if (!set.count(temp.y * colum + temp.x)) {
                output.push_back(temp);
                set.insert(temp.x + temp.y * colum);
            }


        }
        else if (board[y - 1][x] != 'X' && (y - 1) == 0) {
            good = false;
        }
        if (board[y][x + 1] != 'X' && (x + 1) != (board[y].size() - 1)) {
            temp.x = x + 1; temp.y = y;

            if (!set.count(temp.y * colum + temp.x)) {
                output.push_back(temp);
                set.insert(temp.x + temp.y * colum);
            }

        }
        else if (board[y][x + 1] != 'X' && (x + 1) == (board[y].size()) - 1) {
            good = false;
        }
        if (board[y + 1][x] != 'X' && (y + 1) != (board.size() - 1)) {
            temp.x = x; temp.y = y + 1;

            if (!set.count(temp.y * colum + temp.x)) {
                output.push_back(temp);
                set.insert(temp.x + temp.y * colum);
            }

        }
        else if (board[y + 1][x] != 'X' && (y + 1) == (board.size() - 1)) {
            good = false;
        }
        index++;



    }
    if (good) {
        for (size_t i = 0; i < output.size(); ++i) {
            temp = output[i];
            board[temp.y][temp.x] = 'X';


        }
        return true;
    }
    else {
        return false;
    }



}

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        char X = 'X';
        char O = 'O';
        vertex current;
        bool issur;
        unordered_set<int> set;
        int colum = board[0].size();
        for (size_t i = 1; i < board.size() - 1; ++i) {
            for (size_t j = 1; j < board[i].size() - 1; ++j) {
                if (board[i][j] == 'O') {
                    current.x = j;
                    current.y = i;
                    if ((i * colum + j) == 26) {
                        cout << board[i][j] << endl;
                    }
                    if (!set.count(i * colum + j)) {
                        issur = Issurround(current, board, set);
                    }
                    if ((i * colum + j) == 26) {
                        cout << board[i][j] << endl;
                    }

                }

            }
        }
    }
};
int main() {
    unordered_map<int,vector<int>> a;
    vector<int> b{ 2,4 };
    a[1] = b;
   

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
