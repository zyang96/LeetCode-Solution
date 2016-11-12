/*
The best way to understand this algorithm is to go through an example e.g n = 10
Solution 1.
Time complexity: O(n)
Space complexity: O(n)	
*/
class Solution {
public:
    int nthUglyNumber(int n) {
        if (n == 0) return 0;
        int l2(0), l3(0), l5(0);
        vector<int> ret(n);
        ret[0] = 1;
        for (int i = 1; i < n; i++) {
            ret[i] = min(ret[l2] * 2, min (ret[l3] * 3, ret[l5] * 5));
            if (ret[i] == ret[l2] * 2) l2++; //think about the case when ret[l2] * 2 == ret[l3] * 3, therefore, need to increment both l2, l3 pointer to the next number
            if (ret[i] == ret[l3] * 3) l3++; 
            if (ret[i] == ret[l5] * 5) l5++;
        }
        return ret[n - 1];
    }
};