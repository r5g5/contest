class NumberContainers {
public:
    NumberContainers() {}

    void change(int index, int number) {
        indexToNumbers[index] = number;
        numberToIndices[number].push(index);
    }

    int find(int number) {
        if (numberToIndices.find(number) != numberToIndices.end()) {
            auto& minHeap = numberToIndices[number];
            while (!minHeap.empty()) {
                int smallestIdx = minHeap.top();

                if (indexToNumbers[smallestIdx] == number)
                    return smallestIdx;

                minHeap.pop();
            }
        }
        return -1;
    }
private:
    unordered_map<int, int> indexToNumbers;
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> numberToIndices;
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */