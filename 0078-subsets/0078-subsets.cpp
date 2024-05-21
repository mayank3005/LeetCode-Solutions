class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> sol;
        for (int i = 0; i < (1 << n); i++)
        {
            vector<int> temp;
            for (int j = n; j >= 1; j--)
            {
                int val = (1 << (j - 1));
                if (i & val)
                    temp.push_back(nums[j - 1]);
            }
            sol.push_back(temp);
        }
        return sol;
    }
};