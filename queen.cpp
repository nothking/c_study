#include <iostream>
#include <string>
#include <string.h>
#include <ctime>
using namespace std;

long sum = 0, upperlim = 1;
void test(long row, long ld, long rd)
/*
 * 分别表示在纵列和两个对角线方向的限制条件下这一行的哪些地方不能放
 * 注意：是不能放！！！
 */
{
    if (row != upperlim)
    {

        long pos = upperlim & ~(row | ld | rd);
        //位于该行上的冲突位置就用row、ld和rd中的1来表示。
        // 把它们三个并起来，得到该行所有的禁位，取反后就得到所有可以放的位置（用pos来表示）。
        while (pos) //从所有非禁位寻找
        {
            long p = pos & -pos;
            pos -= p;
            /*
             * 其结果是取出最右边的那个1。这样，p就表示该行的某个可以放子的位置，
             * 把它从pos中移除并递归调用test过程。
             */
            test(row + p, (ld + p) << 1, (rd + p) >> 1);
            // row + p，将当前列置1，表示记录这次皇后放置的列。
            // (ld + p) << 1，标记当前皇后左边相邻的列不允许下一个皇后放置。
            // (ld + p) >> 1，标记当前皇后右边相邻的列不允许下一个皇后放置。
            // 此处的移位操作实际上是记录对角线上的限制，只是因为问题都化到一行网格上来解决，所以表示为列的限制就可以了。显然，随着移位
            // 在每次选择列之前进行，原来N×N网格中某个已放置的皇后针对其对角线
            // 上产生的限制都被记录下来了
        }
    }
    else
    {
        sum++;
    }
}

int main()
{

    int n;
	clock_t start,end;
    while (cin >> n && n != 0)
    {	
		start = clock();
        upperlim = (upperlim << n) - 1;
        test(0, 0, 0);
		end = clock();
        printf("%ld\n", sum);
		double cost_time = (double)(end-start)/CLOCKS_PER_SEC;
		cout<<"cost time : " <<cost_time<<endl;
        upperlim = 1;
        sum = 0;
    }
    return 0;
}
