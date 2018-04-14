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

int main(){
	int n;
	ll a,b;
	cin>>n>>a>>b;
  ll h[n];
	REP(i,n)cin >> h[i];
	ll mi=0,ma=INFll;
	while(ma-mi>1){
		ll mid=(mi+ma)/2;
		long long int cnt=0;
		for(int i=0;i<n;i++){
			if(h[i]>b*mid){
				cnt+=(h[i] - b * mid + a - b - 1) / (a-b);
			}
		}
		if(cnt>mid){
			mi=mid;
		}
		else{
			ma=mid;
		}
	}
	cout<<ma<<endl;
	return 0;
}
