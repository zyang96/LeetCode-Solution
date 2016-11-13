/*
Solution 1.
It is the same as word ladder problem. Technique is to have both start vector and end vector. At each iteration, use the smaller vector as the begin vector and the other are end vector. For each iteration, if element in begin vector can be found in end vector, then it can return the counter of mutation step number.
Time complexity: O(nm) n is the size of bank, and m is the maximum length of the gene expression string
Space complexity: O(n)	
*/
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        vector<string> vecStart;
        vector<string> vecEnd;
        vecStart.push_back(start);
        vecEnd.push_back(end);
        unordered_set<string> st;
        int counter(0);
        for (auto itr : bank) st.insert(itr);
        while (vecStart.size() != 0 && vecEnd.size() != 0) {
            if (vecStart.size() > vecEnd.size()) {
                swap(vecStart, vecEnd);
            }
            vector<string> temp;
            for (auto tempStr : vecStart) {
                st.erase(tempStr);
                if (find(vecEnd.begin(), vecEnd.end(), tempStr) != vecEnd.end()) return counter;
                for (int i = 0; i < tempStr.size(); i++) {
                    char mid = tempStr[i];
                    tempStr[i] = 'A';
                    if (st.find(tempStr) != st.end()) temp.push_back(tempStr);
                    tempStr[i] = 'C';
                    if (st.find(tempStr) != st.end()) temp.push_back(tempStr);
                    tempStr[i] = 'G';
                    if (st.find(tempStr) != st.end()) temp.push_back(tempStr);
                    tempStr[i] = 'T';
                    if (st.find(tempStr) != st.end()) temp.push_back(tempStr);
                    tempStr[i] = mid;
                }
            }
            counter++;
            vecStart = temp;
        }
        return -1;
    }
};