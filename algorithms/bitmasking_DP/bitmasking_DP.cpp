#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

/* this dynamic array contains the 
*/
vector<int> ncaps[101];

/* This array dp contains the maximum number of users 
    with the maximum no of caps to be considered.
*/
int dp[2^10][101];

int fullmask;

int countWaysUtil( int mask, int cap)
{
    if(mask == fullmask)
        return 1;
    
    if(cap > 100)
        return -1;

    if(dp[mask][cap] != -1) 
        return dp[mask][cap];
    
    long long int ways = countWaysUtil(mask,cap+1);
    int n = ncaps[cap].size();

    for(int i =0; i< n; i++)
    {
        if(mask & (1<< ncaps[cap][i]))
            continue;
        else
        {
            ways+=countWaysUtil((mask | (1<<ncaps[cap][i])) ,cap+1);
            ways %= MOD;
        }
        

    }
    return dp[mask][cap] = ways;
}

int countWays(int n)
{
    string temp,word;
    int val;
    getline(cin,word);
    for(int i =0;i<n;i++)
    {
        getline(cin,word);
        stringstream ss(word);
        while(ss >> temp)
        {
            stringstream s;
            s << temp;
            s >> val;

            ncaps[val].push_back(i);

        }
            
    }

    fullmask = (2^n)-1;

    memset(dp,-1,sizeof(dp));


    cout << "Total no of ways are : " << countWaysUtil(0,1) << endl;
}

int main(){

    int n;
    cout << "No of person in considersation:" << n;
     
    return 0;
}