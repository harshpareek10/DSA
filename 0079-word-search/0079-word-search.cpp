class Solution {
public:

    bool find(vector<vector<char>>& board , string word , int i, int j, int idx){

        if(idx == word.size()){
            return true;
        }

        if(i < 0 || j < 0 || i >= board.size() || j >=board[0].size() || board[i][j] != word[idx] || board[i][j] == '#'){
            return false;
        }

        char ch = board[i][j];
        board[i][j] = '#';

    bool found = 
        find(board,word,i+1,j,idx+1)  ||
        find(board,word,i-1,j,idx+1)  ||
        find(board,word,i,j+1,idx+1) ||
        find(board,word,i,j-1,idx+1) ;

        board[i][j] = ch;
        return found;

    }


    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if( find(board,word,i,j,0)){
                    return true;
                }
            }
        }
         return false;
    }
};