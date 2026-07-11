class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> count;

    for (int num : nums) {
        count[num]++;
    }

    vector<vector<int>> freq(nums.size() + 1);

    for (auto pair : count) {
        freq[pair.second].push_back(pair.first);
    }

    vector<int> result;

    for (int i = freq.size() - 1; i >= 0; i--) {
        for ( int num : freq[i]) {
            result.push_back(num);

            if(result.size() == k) {
                return result;
            }
        }
    }
    return result;
}

};
