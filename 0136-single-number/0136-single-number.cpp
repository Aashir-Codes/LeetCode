class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int number=0;
        for (auto num : nums)
        {
            number^=num;

        }
        return number;
    }
};