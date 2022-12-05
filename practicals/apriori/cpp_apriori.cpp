#include <bits/stdc++.h>
using namespace std;

void makeCombiUtil(vector<vector<int>> &ans,
                   vector<int> &tmp, int n, int left, int k)
{
    // Pushing this vector to a vector of vector
    if (k == 0)
    {
        ans.push_back(tmp);
        return;
    }

    // i iterates from left to n. First time
    // left will be 1
    for (int i = left; i <= n; ++i)
    {
        tmp.push_back(i);
        makeCombiUtil(ans, tmp, n, i + 1, k - 1);

        // Popping out last inserted element
        // from the vector
        tmp.pop_back();
    }
}

// Prints all combinations of size k of numbers
// from 1 to n.
vector<vector<int>> makeCombi(int n, int k)
{
    vector<vector<int>> ans;
    vector<int> tmp;
    if(k>n) return ans;
    makeCombiUtil(ans, tmp, n, 1, k);
    return ans;
}

signed main()
{

    // Numebr of Transactions
    int n;
    cin >> n;

    // Number of Items
    int m;
    cin >> m;

    // Name of the Items
    vector<string> item(m+1);
    for(int i=1;i<=m;i++) cin>>item[i];

    // Transaction Data Structure
    vector<vector<int>> tran(n, vector<int>(m+1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> tran[i][j];
        }
    }

    // Mininum Support and Confidence
    float sup, conf;
    cin >> sup >> conf;

    map<set<int>, int> mp;
    
    int round = 1, total_sets = n;
    do
    {
        cout<<endl<<"L"<<round<<endl;
        mp.clear();
        for(auto comb : makeCombi(m,round)){
            set<int> st(comb.begin(),comb.end());
            int found = 0;
            for(int i=0;i<n;i++){
                int curr = 0;
                for(auto j:comb){
                    if(tran[i][j]){
                        curr++;
                    }
                }
                if(curr == round){
                    found++;
                }
            }
            if(found>=sup){
                mp[st] = found;
                for(auto j:comb){
                    cout<<item[j]<<' ';
                }
                cout<<'\t';
                cout<<mp[st]<<endl;
            }
        }
        round++;
    } while (mp.size());
    

    return 0;
}