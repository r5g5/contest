class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> sortedNums(nums);
        sort(sortedNums.begin(), sortedNums.end());
        int groupID = 0;
        unordered_map<int, int> numToGroupMap;
        numToGroupMap[sortedNums[0]] = groupID;
        unordered_map<int, list<int>> groupToNumsMap;
        groupToNumsMap[groupID] = list<int>(1, sortedNums[0]);

        for (int i = 1; i < sortedNums.size(); i++) {
            if (abs(sortedNums[i] - sortedNums[i-1]) > limit) {
                groupID++;
            }
            numToGroupMap[sortedNums[i]] = groupID;
            if (groupToNumsMap.find(groupID) == groupToNumsMap.end()) {
                groupToNumsMap[groupID] = list<int>();
            }

                groupToNumsMap[groupID].push_back(sortedNums[i]);
        }

        for (int i = 0; i < nums.size(); i++) {
            groupID = numToGroupMap[nums[i]];
            nums[i] = *groupToNumsMap[groupID].begin();
            groupToNumsMap[groupID].pop_front();
        }

        return nums;

    }
};