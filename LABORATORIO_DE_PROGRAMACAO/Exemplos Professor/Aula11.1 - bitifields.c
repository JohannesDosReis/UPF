#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define os bits
#define MOT_A_MASK      0x03    // bits 1:0
#define MOT_B_MASK      0x0C    // bits 3:2
    #define MOT_ON      0x01    // 1=liga 0=desliga
    #define MOT_DIR     0x02    // 0=forward 1=reverse
#define LIGHTS          0x10    // bit 4
#define HORN            0x20    // bit 5

void ExibeStatus(char Status)
{
    char MA, MB;

    // obtem o status de cada motor
    MA = Status & MOT_A_MASK;
    MB = (Status & MOT_B_MASK) >> 2; // bits 3:2 --> 1:0

    printf("Status do sistema____________\n");
    printf("Motor A: ");
    if((MA & MOT_ON) == 0) printf("Desligado\n");
    else
    {
        printf("Ligado, ");
        if(MA & MOT_DIR) printf("reverso!\n");
        else printf("normal!\n");
    }

    printf("Motor B: ");
    if((MB & MOT_ON) == 0) printf("Desligado\n");
    else
    {
        printf("Ligado, ");
        if(MB & MOT_DIR) printf("reverso!\n");
        else printf("normal!\n");
    }

    printf("Farois : ");
    if(Status & LIGHTS) printf("Ligados\n");
    else printf("Desligados\n");

    printf("Buzina : ");
    if(Status & HORN) printf("Tocando\n");
    else printf("Silencio\n");
    putchar('\n');
}

/*
 * main
 */
int main(void)
{
    unsigned char Status;   // variável que vai manter os campos de bits

    Status = 0x00;
    ExibeStatus(Status);

    Status = LIGHTS | HORN;
    ExibeStatus(Status);

    // desliga apenas a buzina
    // X &= Y --> X = X & Y;
    // HORN = 0010.0000 --> ~HORN = 1101.1111
    Status &= ~HORN;
    ExibeStatus(Status);

    // liga ambos os motores
    Status |= MOT_ON;       // Motor A: bits 1:0
    Status |= MOT_ON << 2;  // Motor B: bits 3:2
    ExibeStatus(Status);

    // reverte ambos os motores
    Status |= MOT_DIR;       // Motor A: bits 1:0
    Status |= MOT_DIR << 2;  // Motor B: bits 3:2
    ExibeStatus(Status);

    // normaliza ambos os motores
    // Motor A: bits 1:0, Motor B: bits 3:2
    //Status		00HL.1111

    //MOT_DIR		0000.0010
    //MOT_DIR << 2	0000.1000
    //OR		    0000.1010
    //~		        1111.0101
    //AND		    00HL.0101
    Status &= ~(MOT_DIR | MOT_DIR << 2);
    ExibeStatus(Status);

    return(0);
}
