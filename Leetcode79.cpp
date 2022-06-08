#include <iostream>
#include <string.h>
#include <bitset>
#include <algorithm>
#include <typeinfo>
#include <vector>
#include  <set>
#include <unordered_map>
using namespace std;
bool findpath(vector<vector<char>> b, int* pos, string word, int now) {
    vector<vector<char>> temp;
    char find;
    int poss[2];
    //printf("x:%d y:%d\n", pos[1], pos[0]);
    if (now >= word.size()) {
        return true;
    }

    else if (now < word.size()) {
        find = word[now];
        temp = b;
        temp[pos[0]][pos[1]] = -1;
        //cout << 2 << endl;
        if (pos[0] > 0 && b[pos[0] - 1][pos[1]] > 0 && b[pos[0] - 1][pos[1]] == word[now]) {
            //temp = b;
            //temp[pos[0]][pos[1]] = -1;
            poss[0] = pos[0] - 1;
            poss[1] = pos[1];
            if (findpath(temp, poss, word, now + 1)) { return true; };

        }
        if (pos[0] < b.size() - 1 && b[pos[0] + 1][pos[1]]>0 && b[pos[0] + 1][pos[1]] == word[now]) {
            //temp = b;
            //temp[pos[0]][pos[1]] = -1;
            poss[0] = pos[0] + 1;
            poss[1] = pos[1];
            if (findpath(temp, poss, word, now + 1)) { return true; };
        }
        if (pos[1] > 0 && b[pos[0]][pos[1] - 1] > 0 && b[pos[0]][pos[1] - 1] == word[now]) {
            //temp = b;
            //temp[pos[0]][pos[]]
            poss[0] = pos[0];
            poss[1] = pos[1] - 1;
            if (findpath(temp, poss, word, now + 1)) { return true; };
        }
        if (pos[1] < b[pos[0]].size() - 1 && b[pos[0]][pos[1] + 1]>0 && b[pos[0]][pos[1] + 1] == word[now]) {
            poss[0] = pos[0];
            poss[1] = pos[1] + 1;
            if (findpath(temp, poss, word, now + 1)) { return true; };
        }
    }
    return false;
}
class Solution {
public:
    bool exict(vector<vector<char>> board, string word) {


        //vector<vector<char>> temp;
        //bool go = true;
        char start = word[0];
        int pos[2];
        bool search;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == start) {
                    pos[0] = i;
                    pos[1] = j;
                    //cout << i << j << endl;
                    search = findpath(board, pos, word, 1);
                    if (search) {
                        return true;
                    }

                }
            }

        }
        return false;
    }
};
int main() {
    Solution sol;
    vector<vector<char>> board = { {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'},{'A','D','E','E'} };
    string word = "ABCCED";
    cout<<sol.exict(board, word);


}