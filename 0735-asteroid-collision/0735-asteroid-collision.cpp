class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        stack<int> st;
        vector<int> answer;

        for(int i = 0; i < nums.size(); i++){
            bool insert = true;
            while(!st.empty() && st.top() > 0 && nums[i] < 0){

               if(st.top() < abs(nums[i])){
                st.pop();
               }
               else if(st.top() == abs(nums[i])){
                insert = false;
                st.pop();
                break;
               }else{
                insert = false;
                break;
               }

            }
            if(insert){
                st.push(nums[i]);
            }
        }

        while(!st.empty()){
            answer.push_back(st.top());
            st.pop();
        }
        reverse(answer.begin(),answer.end());
        return answer;
    }
};