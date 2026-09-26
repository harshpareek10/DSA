class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0;
        map<int,int> M;
        int maxlen = 0;

        for(int right  = 0; right < fruits .size(); right++){
            M[fruits[right]]++;

            while(M.size() > 2){
                M[fruits[left]]--;
                if(M[fruits[left]] == 0){
                    M.erase(fruits[left]);
                }
                left++;
            }
            maxlen = max(maxlen,right - left + 1);
        }
        return maxlen;
    }
};