class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;
        for (int i = low; i <= high; i++) {
            string s = to_string(i);
            if (s.size() & 1)
                continue;
            int n = s.size();
            string firstHalf = s.substr(0, n / 2);
            string secondHalf = s.substr(n / 2, n);
            if (equalSum(firstHalf, secondHalf)) {
                    cnt++;
            }
        }
        return cnt;
    }
    inline bool equalSum(std::string& one, std::string& two) {
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < one.size(); i++) {
            sum1 += one[i];
            sum2 += two[i];
        }
        return sum1 == sum2;
    }
};