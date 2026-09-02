class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int counter=0;
        if(nums.empty())
        {
            return counter;
        }
        vector<int> temp{nums};
        nums.clear();
        

        for (int num:temp){
            if(nums.empty())
            {
                nums.push_back(num);
            }
            if(nums.back() != num)
            {
                 nums.push_back(num);
            }
        }
        return nums.size();
    }
};