#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
#define F first
#define S second
typedef vector<pli> vpli;
#define hell 1000000007
#define mp make_pair
#define pb push_back
#define all(v) v.begin(),v.end() 
#define tests int t; cin>>t; while(t--)
#define take(a,b,c) for(b=0;b<c;b++) scanf("%d",&a[b]);

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    int i=0;
    int ans=0;
    while(i<n)
    if(s[i]!=t[i])
    {
        if(i+1<n&&s[i+1]!=t[i+1]&&s[i]!=s[i+1])
        {
            ans++;
            i+=2;
        }
        else
        {
            ans++;
            i++;
        }
    }
    else
    i++;
    cout<<ans<<endl;
    return 0;
    
}