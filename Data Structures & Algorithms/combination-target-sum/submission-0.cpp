class Solution {
public:
    vector<vector<int>> result;
    vector<int> current;

    void dfs(vector<int>& candidates, int target, int index) {

        if (target == 0) {
            result.push_back(current);
            return;
        }

        if (target < 0 || index == candidates.size())
            return;

        current.push_back(candidates[index]);
        dfs(candidates, target - candidates[index], index);

        current.pop_back();

        dfs(candidates, target, index + 1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, target, 0);
        return result;
    }
};