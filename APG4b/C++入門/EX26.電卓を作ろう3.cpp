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

// ベクトルA,Bのサイズは同じ(サイズをNとする)
vector<int> Addition(vector<int> A, vector<int> B, int N){
    vector<int> temp(N);
    for(int i = 0 ; i < N ; i++){
        temp[i] = A[i] + B[i];
    }
    return temp;
}

// ベクトルA,Bのサイズは同じ(サイズをNとする)
vector<int> ddition(vector<int> A, vector<int> B, int N){
    vector<int> temp(N);
    for(int i = 0 ; i < N ; i++){
        temp[i] = A[i] - B[i];
    }
    return temp;
}

int main() {
    int n;
    cin >> n;
    vst orders;
    rep(i,0,n+1){
        string order;
        getline(cin, order);
        orders.pb(order);
    }
    
    map<char, int> mp;
    map<char, vi> vmp;

    rep(i, 0, n+1) {
        int j = 0;
        int order_num = -1;
        char key_name;
        int num = 0;
        vector<int> vec, tempvec; 
        bool plus = true;
        bool mp_flug = false;
        bool vmp_flug = false;
        bool temp_flug = false;
        bool printint_flug = false;
        bool printvec_flug = false;
        bool once = true;
        while(orders[i][j]!=';'){
            if(j==0){
                if(orders[i][j]=='i'){
                    order_num = 0;
                    j += 1;
                    continue;
                }
                else if(orders[i][j]=='v'){
                    order_num = 1;
                    j += 1;
                    continue;
                }
                else if(orders[i][j]=='p'){
                    if(orders[i][j+6]=='i'){
                        order_num = 2;
                        j += 1;
                        continue;
                    }
                    else if(orders[i][j+6]=='v'){
                        order_num = 3;
                        j += 1;
                        continue;
                    }
                }
            }
            if(order_num==-1){
                break;
            }

            if(order_num == 0){
                if(j <= 3 || j == 5 || j == 6 || j == 7 || orders[i][j] == '+' || orders[i][j] == '-'){
                    j++;
                    continue;
                }
                else if(j == 4){
                    key_name = orders[i][j];
                    mp_flug = true;
                }
                else if(isdigit(orders[i][j])==0){
                    if(orders[i][j-2]=='+'){
                        num += mp[int(orders[i][j])];
                    }
                    else if (orders[i][j-2]=='='){
                        num += mp[int(orders[i][j])];
                    }
                    else{
                        num -= mp[int(orders[i][j])];
                    }
                }
                else{
                    if(orders[i][j-2]=='+'){
                        num += orders[i][j] - '0';
                    }
                    else if (orders[i][j-2]=='='){
                        num += orders[i][j] - '0';
                    }
                    else{
                        num -= orders[i][j] - '0';
                    }
                }
            }

            if(order_num == 1){
                if(j <= 3 || j == 5 || j == 6 || j == 7 || orders[i][j]==' ' || orders[i][j]==','){
                    j++;
                    continue;
                }
                else if(j == 4){
                    key_name = orders[i][j];
                    vmp_flug = true;
                }
                else if(orders[i][j]=='['){
                    temp_flug =true;
                }
                else if(orders[i][j]==']'){
                    temp_flug = false;
                    if(once){
                        vec = tempvec;
                        once = false;
                    }
                    else if(plus){
                        vec = Addition(vec, tempvec, vec.size());
                    }
                    else{
                        vec = ddition(vec, tempvec, vec.size());
                    }
                    tempvec.clear();
                }
                else if(orders[i][j]=='+'){
                    plus = true;
                }
                else if(orders[i][j]=='-'){
                    plus = false;
                }
                else if(isdigit(orders[i][j])==0){
                    if(temp_flug){
                        tempvec.pb(mp.at(orders[i][j]));
                    }
                    else {
                        if(once){
                            vec = vmp[orders[i][j]];
                            once = false;
                        }
                        else if(plus){
                            vec = Addition(vec, vmp[orders[i][j]], vec.size());
                        }
                        else{
                            vec = ddition(vec, vmp[orders[i][j]], vec.size());
                        }
                    }
                }
                else{
                    tempvec.pb(orders[i][j] - '0');
                }
            }

            if(order_num == 2){
                printint_flug = true;
                if(j <= 9){
                    j++;
                    continue;
                }
                else if(orders[i][j]=='+'){
                    plus = true;
                }
                else if(orders[i][j]=='-'){
                    plus = false;
                }
                else if(isdigit(orders[i][j])==0){
                    if(plus){
                        num += mp[orders[i][j]];
                    }
                    else{
                        num -= mp[orders[i][j]];
                    }
                }
                else{
                    if(plus){
                        num += orders[i][j] - '0';
                    }
                    else{
                        num -= orders[i][j] - '0';
                    }
                }
            }
            if(order_num == 3){
                printvec_flug = true;
                if(j <= 9 || orders[i][j]==' ' || orders[i][j]==','){
                    j++;
                    continue;
                }
                else if(orders[i][j]=='+'){
                    plus = true;
                }
                else if(orders[i][j]=='-'){
                    plus = false;
                }
                else if(orders[i][j]=='['){
                    temp_flug =true;
                }
                else if(orders[i][j]==']'){
                    temp_flug = false;
                    if(once){
                        vec = tempvec;
                        once = false;
                    }
                    else if(plus){
                        vec = Addition(vec, tempvec, vec.size());
                    }
                    else{
                        vec = ddition(vec, tempvec, vec.size());
                    }
                    tempvec.clear();
                }
                else if(orders[i][j]=='+'){
                    plus = true;
                }
                else if(orders[i][j]=='-'){
                    plus = false;
                }
                else if(isdigit(orders[i][j])==0){
                    if(temp_flug){
                        tempvec.pb(mp.at(orders[i][j]));
                    }
                    else {
                        if(once){
                            vec = vmp[orders[i][j]];
                            once = false;
                        }
                        else if(plus){
                            vec = Addition(vec, vmp[orders[i][j]], vec.size());
                        }
                        else{
                            vec = ddition(vec, vmp[orders[i][j]], vec.size());
                        }
                    }
                }
                else{
                    tempvec.pb(orders[i][j] - '0');
                }
            }
            j++;
        }
        if(mp_flug){
            mp[key_name] = num;
        }
        else if(vmp_flug){
            vmp[key_name] = vec;
        }
        else if(printint_flug){
            cout << num << endl;
        }
        else if(printvec_flug){
            cout << "[ ";
            rep(i,0,vec.size()){
                cout << vec.at(i) << " ";
            }
            cout << "]" << endl;
        }
    }
}