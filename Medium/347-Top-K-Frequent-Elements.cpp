class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> elemFreq;

        for(int i = 0; i < nums.size(); ++i) {
            elemFreq[nums[i]]++;
        }

        vector<pair<int, int>> elemVec(elemFreq.begin(), elemFreq.end());

        sort(elemVec.begin(), elemVec.end(), [](const pair<int, int> a, const pair<int, int> b) {
            return a.second > b.second; 
        });

        vector<int> kMostFreq;

        for (int i = 0; i < k; ++i) {
            kMostFreq.push_back(elemVec[i].first);
        }

        return kMostFreq;
    }
};
