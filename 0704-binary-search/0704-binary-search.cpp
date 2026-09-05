class Solution {
public:

    int recursive_binarysearch(vector<int>& nums,int start, int end, int target)
    {
        if(start>end)
        {
            return -1;
        }
        auto middle= start + (end-start)/2;

        if(nums[middle]==target)
        {
            return middle;
        }
        if(nums[middle]<target)
        {
           return  recursive_binarysearch(nums,middle+1,end,target);
        }
        return recursive_binarysearch(nums,start,middle-1,target);

    }

    int search(vector<int>& nums, int target) {
        if(nums.empty())
        {
            return -1;
        }
      return   recursive_binarysearch(nums,0,nums.size()-1,target);


        
    }
};