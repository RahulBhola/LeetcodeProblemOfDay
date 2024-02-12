class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        int candidate = nums[0];
        int count = 1;
        
        // Find the candidate for the majority element
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == candidate) {
                ++count;
            } else {
                --count;
                if (count == 0) {
                    candidate = nums[i];
                    count = 1;
                }
            }
        }
        
        // Verify if the candidate is the majority element
        count = 0;
        for (int num : nums) {
            if (num == candidate) {
                ++count;
            }
        }
        
        if (count > nums.size() / 2) {
            return candidate;
        }
        return -1;
    }
};
