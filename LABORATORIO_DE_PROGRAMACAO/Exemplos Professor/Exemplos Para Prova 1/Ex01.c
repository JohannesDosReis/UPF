#include <stdio.h>
#include <math.h>

float ReadRes(void)
{
    float Num;
    char Unit, Error;
    int n;

    do
    {
        Error = 0;
        printf("Type resistor value as xx.xR/k/M/m or DDZ format: ");

        n = scanf("%f%c", &Num, &Unit);
        //printf("N=%d %f %c (%02X)\n", n, Num, Unit, Unit);

        if(n == 1 || Unit == '\n')
        {
            int val;

            val = (int)Num;

            if(val < 100 || val > 999) Error = 1;

            Num = (val/10) * pow(10, val%10);
        }
        else if(n == 2)
        {
            if(Unit == 'k') Num *= 1000;
            else if(Unit == 'M') Num *= 1000000;
            else if(Unit == 'm') Num *= 0.001;
            else if(Unit != 'R') Error = 1;
        }
        else
        {
            // dafuk?
            Error = 1;
        }
    }while(Error);

    return(Num);
}

void DrawRes(float Value)
{
    int i, j;

    const char ModelParts[][3] =
    {
        ' ', 196, ' ', // 0 fio
        218, 180, 192, // 1 inicio do resistor
        196, ' ', 196, // 2 parte sem listra
        194, 179, 193, // 3 parte com listra
        191, 195, 217  // 4 fim do resistor
    };

    const char Model[32] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                             1, 2, 3, 2, 3, 2, 3, 2, 2, 3, 2, 4,
                             0, 0, 0, 0, 0, 0, 0, 0, 0, 0        };

    for(i = 0; i < 3; i++)
    {
        putchar('\t');
        for(j = 0; j < 32; j++)
        {
            putchar(ModelParts[Model[j]][i]);
        }
        putchar('\n');
    }


//    // top
//    putchar('\t');
//    for(i = 0; i < 10; i++) putchar(' ');
//    putchar(218);
//    putchar(196); putchar(194); putchar(196); putchar(194); putchar(196); putchar(194); putchar(196); putchar(196);
//    putchar(194); putchar(196);
//    putchar(191);
//
//    putchar('\n');
//
//    // middle
//    putchar('\t');
//    for(i = 0; i < 10; i++) putchar(196);
//    putchar(180);
//    putchar(' '); putchar(179); putchar(' '); putchar(179); putchar(' '); putchar(179); putchar(' '); putchar(' ');
//    putchar(179); putchar(' ');
//    putchar(195);
//    for(i = 0; i < 10; i++) putchar(196);
//
//    putchar('\n');
//
//    // bottom
//    putchar('\t');
//    for(i = 0; i < 10; i++) putchar(' ');
//    putchar(192);
//    putchar(196); putchar(193); putchar(196); putchar(193); putchar(196); putchar(193); putchar(196); putchar(196);
//    putchar(193); putchar(196);
//    putchar(217);
//
//    putchar('\n');
}


int main(void)
{
    float Res;

    Res = ReadRes();

    if(Res > 1) printf("Resistor value is %.1f\n", Res);
    else  printf("Resistor value is %.3f\n", Res);

    putchar('\n');
    DrawRes(Res);

    return(0);
}

