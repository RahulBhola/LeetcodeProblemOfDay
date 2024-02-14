class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> res(nums.size(),0);

        int positive = 0, negative = 1;

        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                res[positive] =nums[i];
                positive+=2;
            }
            else{
                res[negative] = nums[i];
                negative += 2;
            }
        }
        return res;
    }
};