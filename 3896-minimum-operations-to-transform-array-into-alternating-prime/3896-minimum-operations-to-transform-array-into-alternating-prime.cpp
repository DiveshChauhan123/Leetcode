class Solution {
public:
    int minOperations(vector<int>& nums) {
        int N = 200000;

    vector<bool> isPrime(N + 1, true);
    vector<int> primes;

    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= N; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= N; j += i) {
                isPrime[j] = false;
            }
        }
    }

    // Store all primes in array
    for (int i = 2; i <= N; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
    primes.push_back(100003);
    int ops=0;
    for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];

            if (i % 2 == 0) {
                // Need prime
                while (!isPrime[x]) {
                    x++;
                    ops++;
                }
            } else {
                // Need non-prime
                while (isPrime[x]) {
                    x++;
                    ops++;
                }
            }
        }
        return ops;
    }
};