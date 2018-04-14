#include <iostream>
#include <cmath>
#include <algorithm>
#include <deque>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;

typedef long long ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef pair<string,string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

double EPS = 1e-9;
int INFi = 1000000005;
long long INFll = 1000000000000000005ll;
double PI = acos(-1);
int dirx[8] = {-1,0,0,1,-1,-1,1,1};
int diry[8] = {0,1,-1,0,-1,1,-1,1};
ll MOD = 1000000007;

#define FOR(a,b,c) for (int (a)=(b);(a)<(c);++(a))
#define FORN(a,b,c) for (int (a)=(b);(a)<=(c);++(a))
#define FORD(a,b,c) for (int (a)=(b);(a)>=(c);--(a))
#define FORSQ(a,b,c) for (int (a)=(b);(a)*(a)<=(c);++(a))
#define FORC(a,b,c) for (char (a)=(b);(a)<=(c);++(a))
#define FOREACH(a,b) for (auto &(a) : (b))
#define REP(i,n) FOR(i,0,n)
#define REPN(i,n) FORN(i,1,n)
#define MAX(a,b) a = max(a,b)
#define MIN(a,b) a = min(a,b)
#define SQR(x) ((ll)(x) * (x))
#define RESET(a,b) memset(a,b,sizeof(a))
#define fi first
#define se second
// #define mp make_pair
// #define pb push_back
#define ALL(v) v.begin(),v.end()
#define ALLA(arr,sz) arr,arr+sz
#define SIZE(v) (int)v.size()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr,sz) sort(ALLA(arr,sz))
#define REVERSEA(arr,sz) reverse(ALLA(arr,sz))
#define PERMUTE next_permutation
#define TC(t) while(t--)
#define show(x) cout << #x << " = " << x << endl;

ll modpow(ll x, ll y){
  ll tmp;
  if(y == 0)return 0;
  else if(y == 1)return x;
  else if(y % 2 == 0){
    tmp = pow(modpow(x,y/2),2);
    return tmp % MOD;
  }else{
    tmp = pow(modpow(x,y/2),2) * x;
    return tmp % MOD;
  }
}

ll gcd(ll a, ll b){
  if(b==0){
    return a;
  }else{
    return gcd(b, a%b);
  }
}



int main(){
  string a,b;
  cin >> a >> b;
  ll A = stoi(a);
  ll B = stoi(b);
  bool flag = true;
  ll suma=0, sumb=0;
  REP(i,a.size()-1){
    if(a[i]>= '0' && a[i] < '4'){
      if(flag == true){
        suma = suma * 2 + (a[i] - '0');
      }else{
        suma = suma * 2;
      }
    }else if(a[i] == '4'){
      if(flag == true){
        suma = suma * 2 + (a[i] - '0');
      }else{
        sumb = sumb * 2;
      }
      flag = false;
    }else if(a[i]>= '5' && a[i] < '9'){
      if(flag == true){
        suma = suma * 2 + (a[i] - '1');
      }else{
        sumb = sumb * 2;
      }
    }else if(a[i] == '9'){
      if(flag == true){
        suma = suma * 2 + (a[i] - '1');
      }else{
        sumb = sumb * 2;
      }
      flag = false;
    }
  }
  int i = a.size()-1;
  if(a[i]>= '0' && a[i] < '4'){
    if(flag == true){
      suma = suma * 2 + (a[i] - '0');
    }else{
      suma = suma * 2;
    }
  }else if(a[i] == '4'){
    if(flag == true){
      suma = suma * 2 + (a[i] - '0');
    }else{
      sumb = sumb * 2;
    }
    flag = false;
  }else if(a[i]>= '5' && a[i] < '9'){
    if(flag == true){
      suma = suma * 2 + (a[i] - '1');
    }else{
      sumb = sumb * 2;
    }
  }else if(a[i] == '9'){
    if(flag == true){
      suma = suma * 2 + (a[i] - '1');
    }else{
      sumb = sumb * 2;
    }
    flag = false;
  }


  REP(i,b.size()){
    if(b[i]>= '0' && b[i] < '4'){
      if(flag == true){
        sumb = sumb * 2 + (b[i] - '0');
      }else{
        sumb = sumb * 2;
      }
    }else if(b[i] == '4'){
      if(flag == true){
        sumb = sumb * 2 + (b[i] - '0');
      }else{
        sumb = sumb * 2;
      }
      flag = false;
    }else if(b[i]>= '5' && b[i] < '9'){
      if(flag == true){
        sumb = sumb * 2 + (b[i] - '1');
      }else{
        sumb = sumb * 2;
      }
    }else if(b[i] == '9'){
      if(flag == true){
        sumb = sumb * 2 + (b[i] - '1');
      }else{
        sumb = sumb * 2;
      }
      flag = false;
    }
  }

  cout << sumb - suma << endl;

  return 0;
}
