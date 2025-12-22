class SmallestInfiniteSet {
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    unordered_set<int> seen;
    int current;

public:
    SmallestInfiniteSet() {
        current = 1;
    }

    int popSmallest() {
        if (!pq.empty()) {
            int x = pq.top();
            pq.pop();
            seen.erase(x);
            return x;
        }
        return current++;
    }

    void addBack(int num) {
        if (num < current && seen.find(num) == seen.end()) {
            pq.push(num);
            seen.insert(num);
        }
    }
};
