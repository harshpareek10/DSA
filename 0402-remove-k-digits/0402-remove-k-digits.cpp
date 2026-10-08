class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> S;

        for(int i = 0; i < num.size(); i++){

            while(!S.empty() && k > 0 && (S.top() - '0' > num[i] - '0')){
                S.pop();
                k--;
            }
            S.push(num[i]);
        }

        while(k > 0){
            S.pop();
            k--;
        }

        if(S.empty()) return "0";

        string res = "";
        while(!S.empty()){
            res += S.top();
            S.pop();
        }

        while(res.size() != 0 && res.back() == '0'){
            res.pop_back();
        }
        if(res.empty()) return "0";
        reverse(res.begin(),res.end());
        return res;
    }
};