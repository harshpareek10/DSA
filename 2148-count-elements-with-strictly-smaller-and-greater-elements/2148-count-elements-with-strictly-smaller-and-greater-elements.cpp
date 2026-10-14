class Solution {
public:
    int countElements(vector<int>& nums) {

        if(nums.size() <= 2){
            return 0;
        }

        int count = 0;
        int mini = *min_element(nums.begin(),nums.end());
        int maxi = *max_element(nums.begin(),nums.end());
        for(int x : nums){
            if(x > mini && x < maxi){
                count++;
            }
        }
        return count;
    }
};