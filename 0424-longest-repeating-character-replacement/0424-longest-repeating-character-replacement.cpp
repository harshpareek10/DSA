class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int maxelem = 0;
        map<char,int> M;
        int freq = 0;

        for(int right = 0; right < s.size(); right++){
            M[s[right]]++;
            freq = max(freq,M[s[right]]);

            while((right - left + 1) - freq > k){
                M[s[left]]--;
                left++;
            }
            maxelem = max(maxelem,right-left+1);
        }
        return maxelem;
    }
};