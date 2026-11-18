class Solution {
public:
bool isSafe(vector<vector<char>>&board,int row,int col,char dig){
    for(int i=0;i<9;++i){//horizontally check krra hu
       if(board[row][i]==dig){
        return false;
       }
    }
    for(int i=0;i<9;++i){//vertically check krra hu
        if(board[i][col]==dig){
            return false;
        }
    }
    //grid check krra hu neeche
    int stRow=(row/3)*3;
    int stCol=(col/3)*3;
    for(int i=stRow;i<=stRow+2;++i){
        for(int j=stCol;j<=stCol+2;++j){
            if(board[i][j]==dig){
                 return false;
            }
        }
    }
    return true;
}
bool solveSudoku(vector<vector<char>> &board,int row,int col){
    if(row==9){
        return true;
    }
    int nextRow=row;
    int nextCol=col+1;
        if(nextCol==9){
        nextRow=row+1;
        nextCol=0;
        }
        if(board[row][col]!='.'){
            return (solveSudoku(board,nextRow,nextCol));
        }
    for(char dig='1';dig<='9';++dig){
        if(isSafe(board,row,col,dig)){
            board[row][col]=dig;
            if(solveSudoku(board,nextRow,nextCol)){
                return true;
            }
            board[row][col]='.';//backtracking krra hu
        }
        
    }
    return false;
}
    void solveSudoku(vector<vector<char>>& board) {
      solveSudoku(board,0,0);  
    }
};