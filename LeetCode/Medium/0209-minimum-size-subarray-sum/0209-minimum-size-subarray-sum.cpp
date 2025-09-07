class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int sum = 0;
        int windowLen = INT_MAX;

        for (int right = 0; right < n; right++) {
            sum += nums[right];   // expand window
            // shrink window while condition is satisfied
            while (sum >= target) {
                windowLen = min(windowLen, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        return (windowLen == INT_MAX) ? 0 : windowLen;
    }
};
