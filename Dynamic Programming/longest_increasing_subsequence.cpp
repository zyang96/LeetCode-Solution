/*
Solution 1.
Time complexity: O(n^2)
Space complexity: O(n)	
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        vector<int> dp(nums.size(), 1);
        for (int i = 0; i< nums.size(); i++) {
             for (int j = 0; j < i; j++) {
                 if (nums[i] > nums[j])
                 dp[i] = max (dp[i], dp[j] + 1);
             }
        }
        vector<int>::iterator itr = max_element(dp.begin(), dp.end());
        return *itr;
    }
};


/* 
Solution 2.
a good explanation of NlogN algorithm http://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/

Time complexity: O(nlogn)
Space complexity: O(n)
Note: it is important to realize when current element is in between smallest and largest value of the current increasing array, we just need to find the ceiling element and replace it.
*/
class Solution {
public:
    void helper(vector<int> & arr, int current, int & currentMax, int & counter) {
        if (currentMax < current) {
            currentMax = current;
            counter++;
            arr.push_back(current);
        } else {
            int left(0), right(counter - 1), mid;
            while (left + 1 < right) {
                mid = (left + right) / 2;
                if (arr[mid] == current) return;
                else if (arr[mid] < current) left = mid;
                else right = mid;
            }
            int insertIndex(-1);
            if (arr[left] >= current) insertIndex = left; // be careful about this condition, if originally left + 1 == right, than, arr[left] may equal to current
            else if (arr[right] > current) insertIndex = right;
            if (insertIndex != -1) arr[insertIndex] = current;
            if (insertIndex == counter - 1) currentMax = current;
        }
    }
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int counter(1);
        vector<int> arr;
        int currentMax(nums[0]);
        arr.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            helper(arr, nums[i], currentMax, counter);
        }
        return counter;
    }
};