class Solution {
private:
    int limit_ = 0;
    int dp_[46];
public:
    int climbStairs(int n) {
        memset(dp_, -1, sizeof(dp_));
        limit_ = std::move(n);
        return findNoOfWays(0);
    }
    int findNoOfWays(const int level)  {
        // cache
        if (dp_[level] != -1) {
            return dp_[level];
        }
        if (level == limit_) {
            return 1;
        } else {
            int ways = 0;
            if (level + 1 <= limit_) {
                ways += findNoOfWays(level + 1);
            }
            if (level + 2 <= limit_) {
                ways += findNoOfWays(level + 2);
            }
            return dp_[level] = ways;
        }
    }
};