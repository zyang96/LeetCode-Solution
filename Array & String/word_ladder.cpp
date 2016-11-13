/*
Solution 1.
Use two vector to record the change from begin to end based on the word dictionary elements as intermediate steps.
Time complexity: O(nm) n is the size of wordDict, and m is the size of each string
Space complexity: O(n)	
*/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        unordered_set<string> head, tail;
        head.insert(beginWord);
        tail.insert(endWord);
        int dist = 2;
        while (!head.empty() && !tail.empty()) {
            if (head.size() > tail.size()) {
                swap(head, tail);
            }
            unordered_set<string> temp; 
            for (auto itr = head.begin(); itr != head.end(); itr++) {
                string word = *itr;
                wordDict.erase(word);
                for (int p = 0; p < (int)word.length(); p++) {
                    char letter = word[p];
                    for (int k = 0; k < 26; k++) {
                        word[p] = 'a' + k;
                        if (tail.find(word) != tail.end())
                            return dist;
                        if (wordDict.find(word) != wordDict.end()) {
                            temp.insert(word);
                            wordDict.erase(word); //therefore it doesnt add duplicates
                        }
                    }
                    word[p] = letter;
                }
            }
            dist++;
            head = temp;
        }
        return 0; 
    }
};