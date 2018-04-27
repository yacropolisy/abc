#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
#include <deque>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define ALL(v) v.begin(),v.end()
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

const int MAX_N = 200000;

int par1[MAX_N];
int rk1[MAX_N];

void init1(int n){
  REP(i,n){
    par1[i] = i;
    rk1[i] = 0;
  }
}

int find1(int x){
  if(par1[x] == x){
    return x;
  }else{
    return par1[x] = find1(par1[x]);
  }
}

void unite1(int x, int y){
  x = find1(x);
  y = find1(y);
  if(x==y) return;
  if(rk1[x] < rk1[y]){
    par1[x] = y;
  }else{
    par1[y] = x;
    if(rk1[x] == rk1[y]) rk1[x]++;
  }
}

bool same1(int x, int y){
  return find1(x) == find1(y);
}

int par2[MAX_N];
int rk2[MAX_N];

void init2(int n){
  REP(i,n){
    par2[i] = i;
    rk2[i] = 0;
  }
}

int find2(int x){
  if(par2[x] == x){
    return x;
  }else{
    return par2[x] = find2(par2[x]);
  }
}

void unite2(int x, int y){
  x = find2(x);
  y = find2(y);
  if(x==y) return;
  if(rk2[x] < rk2[y]){
    par2[x] = y;
  }else{
    par2[y] = x;
    if(rk2[x] == rk2[y]) rk2[x]++;
  }
}

bool same2(int x, int y){
  return find2(x) == find2(y);
}

int main(){
  int n, k, l;
  cin >> n >> k >> l;
  int p[k], q[k], r[l], s[l];
  init1(n); init2(n);
  REP(i,k){
    cin >> p[i] >> q[i];
    unite1(p[i]-1, q[i]-1);

  }
  REP(i,l){
    cin >> r[i] >> s[i];

    unite2(r[i]-1, s[i]-1);
  }

  map<pair<int, int>, int>  mp;

  REP(i,n){
    mp[make_pair(find1(i), find2(i))]++;
  }

  REP(i,n){
    cout << mp[make_pair(find1(i), find2(i))] << endl;
  }


  return 0;
}
