#include <bits/stdc++.h>
using namespace std;


void    dfs(vector<string>& mp, int y, int x, int Y, int X)
{
    if (x < 0 || X <= x || y < 0 || Y <= y || mp[y][x] == '.' ) return ;
    mp[y][x] = '.';

    dfs(mp, y + 1, x, Y, X); 
    dfs(mp, y - 1, x, Y, X); 
    dfs(mp, y, x + 1, Y, X); 
    dfs(mp, y, x - 1, Y, X); 
}


int     main()
{
    int y;
    cin>>y;
    vector<string> mp; 
    string tmp;
    for (int i = 0; i < y; i++)
    {   
        cin>>tmp;
        mp.push_back(tmp);
    }   
    int x = mp[0].size();
    int count = 0;
    for (int i = 0; i < y; i++){
        for (int j = 0; j < x; j++){
            if (mp[i][j] == 'o')
            {   
                count++;
                dfs(mp, i, j, y, x); 
            }   
        }   
    }   
    cout<<count<<endl;
}
