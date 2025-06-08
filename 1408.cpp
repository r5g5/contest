class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words.size(); j++) {
                if (i != j && (words[i].find(words[j]) != std::string::npos)) {
                    if (find(ans.begin(), ans.end(), words[j]) == ans.end())
                        ans.push_back(words[j]);
                }
            }
        }
        return ans;
    } // TODO: Please try KMP and other types of algorithms. Please learn them.
};