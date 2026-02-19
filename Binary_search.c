#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <time.h>
#include <math.h>

#define REP 30000


int bs(int a[], int l, int h, int k)
{
    int m;

    if (l <= h)
    {
        m = (l + h) / 2;

        if (a[m] == k)
            return m;

        if (k < a[m])
            return bs(a, l, m - 1, k);

        return bs(a, m + 1, h, k);
    }

    return -1;
}

void main()
{
    int gd = DETECT, gm;
    int a[1000];
    int n, i, r, idx = 0;

    int x[10], yB[10], yA[10], yW[10];

    clock_t s, e;
    double t;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");


    line(50, 400, 50, 50);      // Y-axis
    line(50, 400, 600, 400);    // X-axis

    outtextxy(60, 40,  "Time");
    outtextxy(480, 420, "Input Size (n)");

    printf("n\tTime(s)\n");


    for (n = 10; n <= 100; n += 10)
    {
       
        for (i = 0; i < n; i++)
        {
            a[i] = i + 1;
        }


        s = clock();

        for (r = 0; r < REP; r++)
        {
            bs(a, 0, n - 1, a[n / 2]);
        }

        e = clock();
        t = (double)(e - s) / CLOCKS_PER_SEC;

        printf("%d\t%f\n", n, t);

     
        x[idx]  = 50 + n * 5;

        yB[idx] = 350;                    /* Best Case  : O(1)      */
        yA[idx] = 350 - log(n) * 20;      /* Average    : O(log n)  */
        yW[idx] = 350 - log(n) * 28;      /* Worst      : O(log n)  */

        idx++;
    }

    
    setcolor(GREEN);
    for (i = 0; i < idx - 1; i++)
    {
        line(x[i], yB[i], x[i + 1], yB[i + 1]);
    }


    setcolor(BLUE);
    for (i = 0; i < idx - 1; i++)
    {
        line(x[i], yA[i], x[i + 1], yA[i + 1]);
    }

   
    setcolor(RED);
    for (i = 0; i < idx - 1; i++)
    {
        line(x[i], yW[i], x[i + 1], yW[i + 1]);
    }

   
    outtextxy(420, 80,  "Best");
    outtextxy(420, 100, "Average");
    outtextxy(420, 120, "Worst");

    getch();
    closegraph();
}
