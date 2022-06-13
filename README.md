# Scheduling_Simulator
到着順，処理時間順，ラウンドロビンの3つのスケジューリングアルゴリズムでプロセスを処理していくデモです．
実行したいアルゴリズムを選択し，プロセスの個数，それぞれの名前，到着時刻，処理時間，ラウンドロビンの場合はタイムスライスも入力して実行できます．

## How to
1. `scheduling.c`と`scheduling_main.c`をリンク，コンパイルして実行してください．
2. 実行したいアルゴリズムを選択してください．(1:到着順, 2:処理時間順, 3:ラウンドロビン)
3. 処理をするプロセスの数を入力して下さい．
4. それぞれのプロセスにおいて，プロセス名，到着時刻，処理時間をスペース区切りで入力してください．
5. ラウンドロビンを選択した場合はタイムスライスを入力して下さい．
6. 実行結果が出力されます．

## Example
次のプロセス集合に対してラウンドロビンを適応した場合のターンアラウンドタイムの平均値を求めます．
| プロセス | 到着時刻 | 処理時間 |
| ------ | ------ | ------|
| A | 0 | 2|
| B | 1 | 10 |
| C | 3 | 7 |
| D | 5 | 3 |

実行した結果，各時刻と処理中のプロセス名が表示され，最後に実行結果をまとめた表とターンアラウンドタイムの平均値が表示される．
今回の例では，ターンアラウンドタイムの平均値が12.5であることがわかる．
```
Please select scheduling algorithms
1:First Come First Served (input 1)
2:Shortest Processing Time First (input 2)
3:Round Robin (input 3)
3
Please input the number of processes
4
Please input each of the following
Process_name Arrival_time Processing_time
A 0 2
B 1 10
C 3 7
D 5 3
Time slice? : 2
Algorithms:Round Robin
START!
  1 Task:A
  2 Task:A is completed
  3 Task:B
  4 Task:B
  5 Task:C
  6 Task:C
  7 Task:B
  8 Task:B
  9 Task:D
 10 Task:D
 11 Task:C
 12 Task:C
 13 Task:B
 14 Task:B
 15 Task:D is completed
 16 Task:C
 17 Task:C
 18 Task:B
 19 Task:B
 20 Task:C is completed
 21 Task:B
 22 Task:B is completed
END!

RESULT
Process_Name|Arrival_Time|Processing_Time|Complete_Time|Turn_Around_Time
------------------------------------------------------------------------
           A|           0|              2|            2|               2
           B|           1|             10|           22|              21
           C|           3|              7|           20|              17
           D|           5|              3|           15|              10

Average_Turn_Around_Time : 12.5
```
