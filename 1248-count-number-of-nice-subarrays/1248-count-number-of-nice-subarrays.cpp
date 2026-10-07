class Solution {
public:
    int answer(vector<int>& nums, int k){
        int l = 0, r = 0, sum = 0, count = 0;

        if(k < 0) return 0;

        while(r < nums.size()){
            sum += nums[r] % 2;

            while(sum > k){
                sum = sum - nums[l] % 2;
                l++;
            }
            count += r - l + 1;
            r++;
        }
        return count;
    }


    int numberOfSubarrays(vector<int>& nums, int k) {
        return answer(nums,k) - answer(nums,k-1);
    }
};