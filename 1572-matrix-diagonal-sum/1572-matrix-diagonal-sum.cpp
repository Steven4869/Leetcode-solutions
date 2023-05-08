class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum =0;
        int i=0;
        int j=mat.size()-1;
        while(i<mat.size()&&j>=0){
            sum = sum + mat[i][i]+mat[i][j];
            i++;
            j--;
        }
        if(mat.size()%2==1){
            return sum-mat[mat.size()/2][mat.size()/2];
        }
        else{
            return sum;
        }
    }
};