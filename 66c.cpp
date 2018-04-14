#include <iostream>
#include <cmath>
#include <algorithm>
#include <deque>
#include <vector>
#include <map>
#include <set>

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

int memo[301];

ll gcd(ll a, ll b){
  if(b==0){
    return a;
  }else{
    return gcd(b, a%b);
  }

}


int main(){
  ll n, m;
  cin >> n;
  ll a, sum=0;
  deque<ll> qa;

  REP(i,n){
    cin >> a;
    if((n-i)%2 ==1){
      qa.push_front(a);
    }else{
      qa.push_back(a);
    }
  }
  for(auto itr = qa.begin(); itr != qa.end()-1; itr++){
    cout << *itr << " ";
  }
  cout << qa[qa.size()-1] << endl;


  return 0;
}
