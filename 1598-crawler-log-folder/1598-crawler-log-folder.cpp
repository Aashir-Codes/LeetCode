class Solution {
public:
    int minOperations(vector<string>& logs) {
        int counter=0;

        for (string x : logs)
        {
            if(x=="../")
            {
                if(counter!=0)
                {
                    counter--;
                }
            }
            else if(x=="./")
            {
                continue;
            }
            else 
            {
                counter++;
            }
        }
        return counter;
    }
};