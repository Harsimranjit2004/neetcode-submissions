class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<int> rows[9], cols[9], boxes[9];  

        for(int i = 0;i<9;i++){
            for(int j = 0;j<9;j++){

                   // check the row 
                   if(board[i][j] == '.'){
                    continue;
                   }
                    int val = board[i][j] -'0';
                    int box = (i/3) * 3 +j/3;
                   if(rows[i].contains(val)){
                    return false;
                   }
                   if(cols[j].contains(val)){
                    return false;
                   }
                   if(boxes[box].contains(val)){
                    return false;
                   }
                    rows[i].insert(val);
                    cols[j].insert(val);
                    boxes[box].insert(val);

            }
        }
        return true;
    }
};
