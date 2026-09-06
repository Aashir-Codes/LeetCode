class Solution {
public:


    vector<vector<int>> permute(vector<int>& nums) {

        if(nums.size()<=1)
        {
            return {nums};
        }

        vector<vector<int>> result; //default constructor for a 2d array

        for (int i=0;i<nums.size();i++)
        {
            vector<int> temp{nums.begin(),nums.end()};
            temp.erase(temp.begin()+i);
            auto res=permute(temp);

            for (int j=0;j<res.size();j++)
            {
                vector<int> v = res[j];
                v.insert(v.begin(),nums[i]);
                result.push_back(v);
            }

        }

        return result;
        
    }
};