class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
         deque<int> DQ;
         vector<int> ans;

         for(int i = 0; i < nums.size(); i++){

            while(!DQ.empty() && DQ.front() <= i - k){
                DQ.pop_front();
            }

            while(!DQ.empty() && nums[DQ.back()] <= nums[i]){
                DQ.pop_back();
            }
            DQ.push_back(i);

            if(i >= k - 1){
                ans.push_back(nums[DQ.front()]);
            }
         }

         return ans;
    }
};