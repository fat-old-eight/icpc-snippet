#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;
int main()
{
    int T=0;
    while (1) 
    {
        system("./rand >data.in");
        auto begin=chrono::high_resolution_clock::now();
        system("./ac <data.in>data.ans");
        auto end=chrono::high_resolution_clock::now();
        auto t1=chrono::duration_cast<chrono::milliseconds>(end-begin);
        begin=chrono::high_resolution_clock::now();
        system("./B <data.in>data.out");
        end=chrono::high_resolution_clock::now();
        auto t2=chrono::duration_cast<chrono::milliseconds>(end-begin);
        if (system("diff data.ans data.out -B")) 
        {
            puts("WA");
            break;
        }
        printf("#%d : AC %ldms %ldms \n",++T,t1.count(),t2.count());
    }
    return 0;
}