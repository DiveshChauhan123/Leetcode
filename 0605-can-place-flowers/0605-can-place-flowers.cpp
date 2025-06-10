class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int p) {
        int n = flowerbed.size();
        int count = 0;
        int i = 0;
        while (i < n) {
            if (flowerbed[i] == 0) {
                bool leftEmpty = (i == 0 || flowerbed[i - 1] == 0);
                bool rightEmpty = (i == n - 1 || flowerbed[i + 1] == 0);
                if (leftEmpty && rightEmpty) {
                    flowerbed[i] = 1;
                    count++;
                    if (count >= p) return true;
                    i++; // Skip the next spot to avoid adjacent planting
                }
            }
            i++;
        }
        return count >= p;
    }
};
