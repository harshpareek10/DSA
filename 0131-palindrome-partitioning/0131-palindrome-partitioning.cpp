class Solution {
public:
    bool ispalindrome(string &s, int start, int end){
        while(start < end){
            if(s[start] != s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }


    void palindrome(string &s, vector<vector<string>>& ans, vector<string>& temp, int idx){
        if(idx == s.size()){
            ans.push_back(temp);
            return;
        }

        for(int i = idx; i < s.size(); i++){
            if(ispalindrome(s,idx,i)){
                temp.push_back(s.substr(idx,i - idx +1));
                palindrome(s,ans,temp,i+1);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;

        palindrome(s,ans,temp,0);
        return ans;
    }
};