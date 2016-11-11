/*
Solution 1.
Using vector's function
Time complexity: O(1)
Space complexity: O(k%n)
*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (k == 0) return;
        int realK = k % nums.size();
        vector<int> temp;
        temp.assign(nums.end() - realK, nums.end()); //[a,b,'empty') 'empty' is not included
        nums.erase(nums.end() - realK, nums.end());  //[q,q,q,q,a,b,'empty') => [q,q,q,q,'empty')
        nums.insert(nums.begin(), temp.begin(), temp.end()); //assume the last element is a "empty", when insert, it won't be inserted
    }
};