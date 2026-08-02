class Solution {
public:
    int trap(vector<int>& height) {


    int maxHeight = INT_MIN; 
    int max  = 0;       

   for (int i = 0; i < height.size(); i++) {
        if (height[i] > maxHeight) {
           maxHeight = height[i];
           max  = i;            
    }
}
    int  secmax=INT_MIN;
    int  water=0;

     for (int i=0;i<max;i++)
     {
        if(height[i] > secmax)
        {
            secmax=height[i];
        }

        if(height[i]<secmax)
        {
            water+=secmax-height[i];
        }

     }

     secmax=INT_MIN;

     for(int i=height.size()-1;i>max;i--)
     {
        if(height[i] > secmax)
        {
            secmax=height[i];
        }

        if(height[i]<secmax)
        {
            water+=secmax-height[i];
        }
     }

       return water;






    }
};