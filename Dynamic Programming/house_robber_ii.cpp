/*
Explanation: this is based on house robber i. The difference is that either the the first house or the second house can be considered. Therefore, do twice the greedy loop, and each includes only the first or the second house, and choose the maximum between two. We must understand that both the first or the second houses could be excluded, but at least only the first or the second house can be included. So loop it twice with either first or last house excluded is a safe way to do this problem.
Solution 1.
Time complexity: O(n)
Space complexity: O(n)	
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        int sum1(0), sum2(0);
        vector<int> ret(nums.size());
        ret[0] = 0;
        ret[1] = nums[0];
        for (int i = 2; i < nums.size(); i++) {
            ret[i] = max(ret[i - 1], nums[i - 1] + ret[i - 2]);
        }
        sum1 = ret[nums.size() - 1];
        ret[0] = 0;
        ret[1] = nums[1];
        for (int i = 2; i < nums.size(); i++) {
            ret[i] = max(ret[i - 1], nums[i] + ret[i - 2]);
        }
        sum2 = ret[nums.size() - 1];
        return max(sum1, sum2);
    }
};