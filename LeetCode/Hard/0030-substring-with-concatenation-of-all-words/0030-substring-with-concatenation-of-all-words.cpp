class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (words.empty()) return result;
        int wordLen = words[0].size();
        int numWords = words.size();
        int totalLen = wordLen * numWords;
        if (s.size() < totalLen) return result;
        // Build frequency map for words
        unordered_map<string, int> wordCount;
        for (auto &w : words) wordCount[w]++;
        // Try starting at each offset within wordLen
        for (int offset = 0; offset < wordLen; offset++) {
            int left = offset, count = 0;
            unordered_map<string, int> windowCount;
            for (int right = offset; right + wordLen <= s.size(); right += wordLen) {
                string word = s.substr(right, wordLen);
                if (wordCount.find(word) != wordCount.end()) {
                    windowCount[word]++;
                    count++;
                    // If a word occurs too many times, shrink from left
                    while (windowCount[word] > wordCount[word]) {
                        string leftWord=s.substr(left, wordLen);
                        windowCount[leftWord]--;
                        left+=wordLen;
                        count--;
                    }
                    // If window matches exactly
                    if (count==numWords) {
                        result.push_back(left);
                    }
                } else {
                    windowCount.clear();
                    count=0;
                    left=right+wordLen;
                }
            }
        }
        return result;
    }
};
