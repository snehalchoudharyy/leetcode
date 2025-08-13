class Solution {
public:
    void solve(vector<int> nums, vector<int> op, vector<vector<int>> &res) {
        if (nums.empty()) {
            res.push_back(op);
            return;
        }

        int element = nums[0];
        nums.erase(nums.begin());
        solve(nums, op, res);
        op.push_back(element);
        solve(nums, op, res);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // sort to handle duplicates
        vector<vector<int>> tempRes;
        vector<int> op;
        solve(nums, op, tempRes);
        sort(tempRes.begin(), tempRes.end());
        tempRes.erase(unique(tempRes.begin(), tempRes.end()), tempRes.end());

        return tempRes;
    }
};
