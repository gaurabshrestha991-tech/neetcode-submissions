class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> groups;

        for (string str : strs) {

            array<int, 26> count = {};

            for (char c : str) {
                count[c - 'a']++;
            }

            string key = "";

            for (int num : count) {
                key += to_string(num) + "#";
            }

            groups[key].push_back(str);
        }

        vector<vector<string>> result;

        for (auto pair : groups) {
            result.push_back(pair.second);
        }

        return result;
    }
};