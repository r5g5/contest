class Solution {
public:
    vector<int> minOperations(string boxes) {
        int shiftBoxes = 0, moves = 0;
        vector<int> ans(boxes.size(), 0);
        for (int i = 0; i < boxes.size(); i++) {
            ans[i] += moves;
            shiftBoxes += boxes[i] - '0';
            moves += shiftBoxes;
        }

        shiftBoxes = 0, moves = 0;

        for (int i = boxes.size() - 1; i >= 0; i--) {
            ans[i] += moves;
            shiftBoxes += boxes[i] - '0';
            moves += shiftBoxes;
        }

        return ans;
    }
};