class Solution {
public:
    string reverseParentheses(string s) {
        stack<char>S;

        for(auto C : s){
            if(C == '('){
                S.push(C);
            }else if(C == ')'){
                string temp = "";
                while(S.top() != '('){
                    temp += S.top();
                    S.pop();
                }
                S.pop();
                for(auto X : temp){
                    S.push(X);
                }
            }else{
                S.push(C);
            }
        }
        string ans = "";
        while(!S.empty()){
            ans += S.top();
            S.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};