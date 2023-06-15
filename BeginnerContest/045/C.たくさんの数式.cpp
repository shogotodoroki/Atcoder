#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
 
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vld = vector<ld>;
using vvld = vector<vld>;
using vst = vector<string>;
using vvst = vector<vst>;
 
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define pq_big(T) priority_queue<T,vector<T>,less<T>>
#define pq_small(T) priority_queue<T,vector<T>,greater<T>>
#define all(a) a.begin(),a.end()
#define rep(i,start,end) for(ll i=start;i<(ll)(end);i++)
#define per(i,start,end) for(ll i=start;i>=(ll)(end);i--)
#define uniq(a) sort(all(a));a.erase(unique(all(a)),a.end())

int main() {
    string S;
    cin >> S;
    int N = S.size();
    ll res = 0;
    for(int bit = 0; bit < (1<<(N-1)); ++bit){
        ll tmp = 0;
        rep(i, 0, N-1){
            tmp *= 10;
            tmp += S[i] - '0';
            if(bit & (1<<i)) res += tmp, tmp = 0;
        }
        tmp *= 10;
        tmp += S.back() - '0';
        res += tmp;
    }

    cout << res << endl;
}