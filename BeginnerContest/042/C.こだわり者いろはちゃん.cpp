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
    // commit できているかの確認用
    string N;
    int K;
    cin >> N >> K;
    vst kirai;
    rep(i, 0, K){
        string d;
        cin >> d;
        kirai.pb(d);
    }
    bool stop = true;
    while(stop){
        bool can = true;
        rep(i, 0, K){
            if(N.find(kirai[i]) != -1){
                can = false;
            }
        }
        if(can){
            stop = false;
        }
        else{
            int n;
            n = stoi(N);
            n++;
            N = to_string(n);
        }
    }
    cout << N << endl;
}