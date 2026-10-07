class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int maxElem = 0;
        int count0 = 0;

        for(int right = 0; right < nums.size(); right++){
            if(nums[right] == 0){
                count0++;
            }
            while(count0 > k){
                if(nums[left] == 0){
                    count0--;
                }
                left++;
            }
            
            maxElem = max(maxElem , right - left + 1);
        }
        return maxElem;
    }
};