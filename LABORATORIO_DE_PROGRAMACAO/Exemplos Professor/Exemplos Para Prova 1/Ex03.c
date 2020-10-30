#include <stdio.h>
#include <math.h>

/* **********************************************************
 * Read weight values based on array and size
 */
void ReadWeights(char *Stations[], int Weight[])
{
    int i;

    putchar(201); for(i = 0; i < 50; i++) putchar(205); putchar('\n');
    printf("%c Type the weight of all items:\n%c\n", 186, 186);

    for(i = 0; i < 6; i++)
    {
        printf("%c %s: ", 186, Stations[i]);
        scanf("%d", &Weight[i]);
    }

    // now read FUEL and convert to KG!
    printf("%c %s: ", 186, Stations[7]);
    scanf("%d", &Weight[7]);
    Weight[7] = Weight[7] * 0.72;

    //putchar(211); for(i = 0; i < 50; i++) putchar(196);
    putchar('\n'); putchar('\n');
}

/* ***********************************************************
 * Ballance calculus
 */
void Ballance(int Weight[], int Arm[], int Moment[])
{
    int i;
    int Tow;
    int Mom;

    Tow = 0;
    Mom = 0;

    // for all stations from pilot (0) to Oil (8)
    for(i = 0; i < 9; i++)
    {
        // the math is simple =)
        Moment[i] = Weight[i] * Arm[i];

        // sum all moments and weights
        Mom = Mom + Moment[i];
        Tow = Tow + Weight[i];
    }

    // compute TakeOff Weight/Moment
    Weight[10] = Tow;
    Moment[10] = Mom;

    // compute Zero Fuel Weight/Moment (all - fuel)
    Weight[9] = Tow - Weight[7];
    Moment[9] = Mom - Moment[7];

    // compute all CG values
    Arm[9]  = Moment[9]  / Weight[9];	// ZFW
	Arm[10] = Moment[10] / Weight[10];	// TOW
}

/* ***********************************************************
 * Display Table
 */
void Display(char *Stations[], int Weight[], int Arm[], int Moment[])
{
    int i;

    // labels
    printf("\n\n%15s %c%15s%10s%10s\n", "STATIONS", 179, "WEIGHT (kg)", "ARM (mm)", "MOMENT");

    // horizontal bar
    for(i = 0; i < 16; i++) putchar(196); putchar(197); for(i = 0; i < 37; i++) putchar(196); putchar('\n');

    // for all stations from pilot (0) to Oil (8)
    for(i = 0; i < 9; i++)
    {
        printf("%15s %c%15d%10d%10d\n", Stations[i], 179, Weight[i], Arm[i], Moment[i]);
    }

    // horizontal bar
    for(i = 0; i < 16; i++) putchar(196); putchar(197); for(i = 0; i < 37; i++) putchar(196); putchar('\n');

    // remaining stations
    printf("%15s %c%15d%10d%10d\n", Stations[9], 179, Weight[9], Arm[9], Moment[9]);
    printf("%15s %c%15d%10d%10d\n", Stations[10], 179, Weight[10], Arm[10], Moment[10]);
    printf("%15s %c%15d\n", Stations[11], 179, Weight[11]);
}

/* ***********************************************************
 * main!
 */
int main(void)
{
    const char *Stations[] = { "Pilot", "Co-Pilot", "Pax 1", "Pax 2", "Baggage 1", "Baggage 2",
                               "Empty", "Fuel", "Oil", "ZFW", "TOW", "MTOW" };
    int Weight[] = { 0, 0, 0, 0, 0, 0, 765, 0, 5, 0, 0, 1150 };
    int Arm[] = { 940, 940, 1854, 1854, 2413, 3124, 1018, 1219, -231, 0, 0, 0 };
    int Moment[] = { 0, 0, 0, 0, 0, 0, 778794, 0, -1154, 0, 0, 0 };

    // read all weights from Pilot to Baggage 2
    ReadWeights(Stations, Weight);

    // perform all calculus numericus
    Ballance(Weight, Arm, Moment);

    // display Weight && Balance table
    Display(Stations, Weight, Arm, Moment);

    return(0);
}

