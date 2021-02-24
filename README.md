





下のような地図を標準入力から渡されたとして

f:id:oajjmjgwm264d:20200304201015p:plain

oが陸地で . が海である。
oが上下左右0個以上連なっているものを島とする。陸地1つだけでも島とする。
で、島の数を数えるのが今回のテーマ。
上の例では島は3つ。

上下左右のため、

.o.
ooo
.o. 
は1つの島であり、

o.o
.o.
o.o
このように斜めに接している場合は島5つとみなす。

...
ooo
ooo
ooo
...
ややこしいかもしれないがこれは島1つ。



コードは以下。


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

実際の動き

g++ dfs.cpp
./a.out
(以下標準入力。数字は行数)
5
oo.....
o...ooo
.....oo
.o.....
.......
(標準入力終了　以下出力結果)
3


注意点

vector<string> mp(N);
.
.
.
mp.push_back(tmp);
と当初はやってしまい、mp[0]、mp[1]、mp[2]をcoutで出力しようとしても地図内容が出力されない(改行だけされて何も表示されない)という事態に陥った。
N個の空きを確保したつもりだったが、mp(N)と書くと、N個分の要素ができてしまい、push_backを使うとその空きの後ろにtmpを詰め込んでしまう。
push_backだけしてランダムアクセスしないときはvectorの定義だけしてサイズは決めないこと。
