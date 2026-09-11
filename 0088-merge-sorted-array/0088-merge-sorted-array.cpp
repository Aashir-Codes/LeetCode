class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {


        vector<int> temp = nums1;
        nums1.clear();

        int i=0;
        int j=0;
        while (i<m && j<n)
        {
            if(temp[i]<=nums2[j] )
            {
                nums1.push_back(temp[i++]);
            }
            else
            {
                nums1.push_back(nums2[j++]);
            }
        }

        for (;j<n;)
        {
              nums1.push_back(nums2[j++]);
        }

        for (;i<m;)
        {
              nums1.push_back(temp[i++]);
        }





        
    }
};