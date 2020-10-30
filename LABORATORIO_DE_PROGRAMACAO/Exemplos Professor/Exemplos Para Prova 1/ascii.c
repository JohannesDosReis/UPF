
/*
 * MAIN
 */
int main(void)
{
    int i;

    for(i = 1; i < 255; i++)
    {
        if(i == 127) continue;
        printf("%3d %c | ", i, i);
        if(i < ' ') putchar('\n');
    }

    return(0);
}
