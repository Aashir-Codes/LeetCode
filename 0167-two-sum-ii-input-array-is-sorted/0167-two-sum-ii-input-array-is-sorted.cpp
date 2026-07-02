

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {


        // We are give a sorted array ok can we do somrthing like binary search to optmise


        int start = 0;
        int end = numbers.size() - 1;
        vector<int> indexes;

        while (start < end)
        {
            if (numbers[start] + numbers[end] == target)
            {
                indexes.push_back(start + 1);
                indexes.push_back(end + 1);
                return indexes;
            }
            if (numbers[start] + numbers[end] < target)
            {
                start++;
            }

            if (numbers[start] + numbers[end] > target)
            {
                end--;
            }


            
        }
        return indexes;
    }


};