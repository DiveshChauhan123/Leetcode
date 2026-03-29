const int mod=1e9+7;
using ll = long long;

vector<ll> fact, invFact;

ll powm(ll base, ll exp) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result = result * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return result;
}

void help(int n) {
    fact.resize(n + 1);
    invFact.resize(n + 1);
    fact[0] = invFact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i % mod;
    }
    invFact[n] = powm(fact[n], mod - 2);
    for (int i = n ; i >= 1; i--) {
        invFact[i-1] = invFact[i] * i % mod;
    }
}

ll nCr(int n, int r) {
    if (r > n || r < 0) return 0;
    return fact[n] * invFact[n-r] % mod * invFact[r] % mod;
}




class Solution {
public:
    int countVisiblePeople(int n, int pos, int k) {
        help(n);

        ll ans=0;

        for(int i=0;i<=k;i++){
            ans =  (ans + nCr(pos,i)*nCr(n-pos-1,k-i)%mod)%mod; // this is equal to ans = nCr(n-1,k)
        }
        ans = 2LL*ans%mod; // for pos index can fill with any it does'nt matter
        return ans;

        
    }
};