#include <iostream>
#include <vector>    
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            nums[i] = nums[i] * nums[i];
        }
        sort(nums.begin(), nums.end());
        return nums;
    }
};

int main() {
    // Example usage
    Solution sol;
    vector<int> input = {-4, -1, 0, 3, 10};
    vector<int> result = sol.sortedSquares(input);
    
    // Print the result
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
