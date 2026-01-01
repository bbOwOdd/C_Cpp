class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i = 0, size = numbers.size(); ; i++){
            int x = target - numbers[i];
            int j = lower_bound(numbers.begin() + i + 1, numbers.end(), x) - numbers.begin();
            if(j < size && numbers[j] == x) return {i + 1, j + 1};
        }
    }
};
