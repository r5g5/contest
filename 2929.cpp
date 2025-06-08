struct VectorHasher {
    int operator()(const vector<int> &V) const {
        int hash = V.size();
        for(auto &i : V) {
            hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
    }
};


class Solution {
private:
    long long limit_ = 0;
    long long n_ = 0;
    std::vector<int> comb_;
    std::unordered_map<vector<int>, bool, VectorHasher> mp_;
    std::unordered_map<vector<int>, bool, VectorHasher>::iterator itr_;
public:
    long long distributeCandies(int n, int limit)  {
        n_ = n;
        limit_ = limit;
        return solve(0, n_);
    }
    long long solve(int pos, int leftCandies) {
        if (pos == 3) {
            if (leftCandies)
                return 0;
            // Check if this combination exists ?
            long long returnValue = 0;
            if (mp_.find(comb_) == mp_.end()) {
                mp_[comb_] = true;
                returnValue = 1;
            }
            cout << returnValue << endl;
            for (int& i : comb_) {
                cout << i << ' ';
            }
            cout << endl;
            comb_.clear();
            return returnValue;
        } else {
            // Give all possible left over candies to the pos child
            long long ways = 0;
            for (int i = 0; i <= leftCandies; i++) {
                if (i > limit_)
                    break;
                comb_.emplace_back(i);
                ways += solve(pos+1, leftCandies-i);
            }
            return ways;
        }
    }
};