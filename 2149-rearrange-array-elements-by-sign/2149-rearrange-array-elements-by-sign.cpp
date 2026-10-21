class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        queue<int> q1,q2;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] >= 0 ){
                q1.push(nums[i]);
            }else{
                q2.push(nums[i]);
            }
        }

        int i = 0;
        while(!q1.empty() && !q2.empty()){
            nums[i] = q1.front();
            q1.pop();
            i++;
            nums[i] = q2.front();
            q2.pop();
            i++;
        }

        while(!q1.empty()){
            nums[i] = q1.front();
            q1.pop();
            i++;
        }

        while(!q2.empty()){
            
            nums[i] = q2.front();
            q2.pop();
            i++;
        }
        return nums;
    }
};