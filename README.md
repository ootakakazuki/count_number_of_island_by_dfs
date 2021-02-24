
## 島の数を数えるプログラム




下のような地図を標準入力から渡されたとして  
`oo.oo`  
`o..oo`  
`.....`  
`oooo.`  
  
oが陸地で . が海である。  
oが上下左右0個以上連なっているものを島とする。陸地1つだけでも島とする。  
島の数を数えることがこのプログラムの目的。
上の例では島は3つ。  
  
上下左右のため、  

`.o.`  
`ooo`  
`.o.`   
は1つの島であり、  

`o.o`  
`.o.`  
`o.o`  
このように斜めに接している場合は島5つとみなす。  
  
`...`  
`ooo`  
`ooo`  
`ooo`  
`...`  
ややこしいかもしれないがこれは島1つ。




実際の操作方法

`g++ count_number_of_island_by_dfs.cpp`  
`./a.out`  
(以下標準入力。数字はマップの行数)  
5  
`oo.....`  
`o...ooo`  
`.....oo`  
`.o.....`  
`.......`  
(標準入力終了　以下出力結果)  
3  
  
  
7  
`...................................`  
`....oooooooooooooooooooooooooo.....`  
`.oooooooooooooooooooooooooo........`  
`...................................`  
`.......oo...................ooooooo`  
`.......oo....ooooooooooooooooooooo.`  
`.oooo..............................`  

4(出力結果)  
  
注意点  
  
`vector<string> mp(N);`  
.  
.  
.  
`mp.push_back(tmp);`  

と当初はやってしまい、mp[0]、mp[1]、mp[2]をcoutで出力しようとしても地図内容が出力されない(改行だけされて何も表示されない)という事態に陥った。
N個の空きを確保したつもりだったが、mp(N)と書くと、N個分の要素ができてしまい、push_backを使うとその空きの後ろにtmpを詰め込んでしまう。
push_backだけしてランダムアクセスしないときはvectorの定義だけしてサイズは決めないこと。
