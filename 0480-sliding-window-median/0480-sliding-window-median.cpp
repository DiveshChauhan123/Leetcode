class Solution {
public:
    multiset<int> low, high;

    void balance() {
        if (low.size() > high.size() + 1) {
            high.insert(*low.rbegin());
            low.erase(prev(low.end()));
        }
        else if (low.size() < high.size()) {
            low.insert(*high.begin());
            high.erase(high.begin());
        }
    }

    void insert(int x) {
        if (low.empty() || x <= *low.rbegin())
            low.insert(x);
        else
            high.insert(x);
        balance();
    }

    void remove(int x) {
        if (low.find(x) != low.end())
            low.erase(low.find(x));
        else
            high.erase(high.find(x));
        balance();
    }

    double getMedian(int k) {
        if (k & 1)
            return (double)*low.rbegin();
        return ((double)*low.rbegin() + *high.begin()) / 2.0;
    }

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;

        for (int i = 0; i < nums.size(); i++) {
            insert(nums[i]);

            if (i >= k)
                remove(nums[i - k]);

            if (i >= k - 1)
                ans.push_back(getMedian(k));
        }
        return ans;
    }
};
