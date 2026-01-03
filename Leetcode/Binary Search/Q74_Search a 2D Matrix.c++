class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m * n - 1;
        while(left < right){
            int middle = (left + right) >> 1;
            int x = middle / n, y = middle % n;
            if(target <= matrix[x][y]) right = middle;
            else left = middle + 1;
        }
        return matrix[left / n][left % n] == target;
    }
};
