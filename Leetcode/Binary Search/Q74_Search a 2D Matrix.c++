class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), col = matrix[0].size();
        int left = 0, right = row * col - 1;
        while(left < right){
            int middle = (left + right) >> 1;
            int x = middle / col, y = middle % col;
            if(target <= matrix[x][y]) right = middle;
            else left = middle + 1;
        }
        return matrix[left / col][left % col] == target;
    }
};
