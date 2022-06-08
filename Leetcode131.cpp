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
class Solution {
public:
    vector<vector<string>> partition(string s) {

        unordered_map<int, vector<string>> dict;
        vector<string> ini = part(s);
        dict[0] = ini;
        vector<string> temp;
        queue<vector<string>> myq;
        for (size_t i = 0; i < ini.size(); ++i) {
            temp.clear();
            temp.push_back(ini[i]);
            myq.push(temp);
        }
        vector<vector<string>> output;
        int size;
        while (myq.size() > 0) {
            size = 0;
            temp = myq.front();
            myq.pop();
            for (size_t i = 0; i < temp.size(); ++i) {
                size += temp[i].size();
            }
            if (size == s.size()) {
                output.push_back(temp);
                continue;
            }
            vector<string> nextstring;
            if (!dict[size].size()) {
                ini = part(s.substr(size, s.size()));

            }
            else {
                ini = dict[size];
            }
            for (size_t i = 0; i < ini.size(); ++i) {
                nextstring = temp;
                nextstring.push_back(ini[i]);
                myq.push(nextstring);
            }





        }

        return output;

    }
};