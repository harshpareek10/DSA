class Solution {
public:
    int NCR(int row, int col){
        long long res = 1;

        for(int i = 0; i < col; i++){
            res = res * (row - i);
            res = res / (i + 1);
        }
        return res;
    }

    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        for(int i = 0; i <= rowIndex; i++){
            ans.push_back(NCR(rowIndex,i));
        }
        return ans;
    }
};