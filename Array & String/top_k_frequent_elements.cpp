/*
First uses a map to store the counts of all the element. Then uses another vector<vector<int>> to store the elements that are indexed by their count. Notice, we need to realize the vector<vector>> has a size <= n + 1 (if 0 is also included)
Solution 1.
Time complexity: O(n)
Space complexity: O(n)	
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<int> ret;
        for (auto itr : nums) mp[itr]++;
        vector<vector<int>> helper(nums.size() + 1);
        for (auto itr : mp) helper[itr.second].push_back(itr.first);
        for (int i = helper.size() - 1; i >= 0; i--) {
            while (helper[i].size() > 0 && k > 0) {
                k--;
                ret.push_back(helper[i].back());
                helper[i].pop_back();
            }
        }
        return ret;
    }
};