class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
    vector<bool> answer;
    int current = 0;

    for (int i = 0; i < (int)nums.size(); i++) {
        current = (current * 2 + nums[i]) % 5; 
        answer.push_back(current == 0);
    }

    return answer;
    }
};