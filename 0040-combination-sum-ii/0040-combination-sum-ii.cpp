
class Solution {
public:
    void combiantion(vector<int>& candidates, int target,
                     vector<vector<int>>& ans, int idx,
                     vector<int>& temp) {

        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {

            if (i > idx && candidates[i] == candidates[i - 1]) {
                continue;
            }

            if (candidates[i] > target) {
                break;
            }

            temp.push_back(candidates[i]);

            combiantion(candidates, target - candidates[i],
                        ans, i + 1, temp);

            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;

        sort(candidates.begin(), candidates.end());

        combiantion(candidates, target, ans, 0, temp);

        return ans;
    }
};
