class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> wordFreq;

        for(int i = 0; i < words.size(); ++i) {
            wordFreq[words[i]]++;
        }

        vector<pair<string, int>> wordVec(wordFreq.begin(), wordFreq.end());

        sort(wordVec.begin(), wordVec.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
            if (a.second == b.second) {
                return a.first < b.first;
            }
            return a.second > b.second; 
        });

        vector<string> kMostFreq;
        for (int i = 0; i < k; ++i) {
            kMostFreq.push_back(wordVec[i].first);
        }

        return kMostFreq;

    }
};
