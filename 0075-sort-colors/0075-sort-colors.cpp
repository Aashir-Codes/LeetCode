class Solution {
public:
   
    void sortColors(vector<int>& nums) {
        int ones=0;
        int twos=0;
        int zeroes=0;

        for(auto num:nums)
        {
            if(num==0)zeroes++;
            else if(num==1)ones++;
            else twos++;
        }     
        
        nums.clear();
        for(int i=1;i<=zeroes;i++)
            nums.push_back(0);
        for(int i=1;i<=ones;i++)
            nums.push_back(1);
        for(int i=1;i<=twos;i++)
            nums.push_back(2);
    }
};