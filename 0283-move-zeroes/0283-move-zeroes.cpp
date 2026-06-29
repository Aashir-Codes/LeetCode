class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        // To solve this  problem i have two sols one naive in which i take another array take zero and then add non zero numbers 
        //other use insertion sort which is known for stable sorting 
         int size = nums.size();
         int pos=0;


         for (int i=0;i<size;i++)
             if(nums[i]!=0)
             nums[pos++]=nums[i];

         for (int i=pos;i<size;i++)
              nums[i]=0;    

    
    }
    
};