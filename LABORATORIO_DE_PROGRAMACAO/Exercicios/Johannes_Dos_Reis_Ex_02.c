#include <stdio.h>

int main(void)
{
    int n, h = 0 , m = 0, s = 0;
    n = scanf("%dh%dm%ds", &h,&m,&s);
    if(n == 2) printf("%dh%dm = %d min", h, m, (h*60)+m);
    if (n == 3)printf("%dh%dm%ds = %d seg", h, m, s, (h*3600)+(m*60)+s);
    return 0;
}
