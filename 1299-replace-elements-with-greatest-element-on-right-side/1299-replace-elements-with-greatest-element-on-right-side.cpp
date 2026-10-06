class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
         int n = arr.size();
        vector<int> ans(arr.size(), -1);
        int rightmax = arr[n-1];

        for(int i = n-2; i >= 0; i--){
            ans[i] = rightmax;

            if(arr[i] > rightmax){
                rightmax = arr[i];
            }
        }

        return ans;
    }
};