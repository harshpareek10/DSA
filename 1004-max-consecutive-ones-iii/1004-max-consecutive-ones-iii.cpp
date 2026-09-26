class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int maxElem = 0;
        int freq[9] = {0};

        for(int right = 0; right < nums.size(); right++){
            if(nums[right] == 0){
                freq[0]++;
            }
            while(freq[0] > k){
                if(nums[left] == 0){
                    freq[0]--;
                }
                left++;
            }
            
            maxElem = max(maxElem , right - left + 1);
        }
        return maxElem;
    }
};