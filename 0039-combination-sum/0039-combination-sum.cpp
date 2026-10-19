class Solution {
public:
    void combiantion(vector<int>& candidates , int target, vector<vector<int>>& ans, int idx, vector<int>& temp){


        if(target == 0){
            ans.push_back(temp);
            return;
        }

         if (idx == candidates.size()) {
            return;
        }


        if(target >= candidates[idx]){
            temp.push_back(candidates[idx]);
            combiantion(candidates, target - candidates[idx], ans, idx, temp);
            temp.pop_back();
        }

        combiantion(candidates, target, ans, idx + 1, temp);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> temp;

     combiantion(candidates, target, ans, 0, temp);

     return ans;
    }
};