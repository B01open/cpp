#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;
int main(){
    char s[3300];
    while(scanf("%s",s) != EOF){
        int n = strlen(s);
        sort(s,s + n);
        priority_queue<int> heap;
        int cnt = 0;
        for(int i = 0,j;i < n;){
            j = i;
            while(j < n && s[j] == s[i]) ++ j;
            heap.push(i - j);
            i = j;
            ++ cnt;
        }
        int ret = 0;
        for(int i = 0;i < cnt - 1;++ i){
            int A = heap.top(); heap.pop();
            int B = heap.top(); heap.pop();
            ret -= A + B;
            heap.push(A + B);
        }  
        printf("%d\n",ret);
    }
    return 0;
}
