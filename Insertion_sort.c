#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <time.h>

#define REP 30000


void insertion(int a[], int n)
{
    int i, j, key;

    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }
}


void main()
{
    int gd = DETECT, gm;
    int a[1000];
    int n, i, r, p = 0;

    int x[10], y[10];

    clock_t s, e;
    double t;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

   
    line(50, 400, 50, 50);      // Y-axis
    line(50, 400, 600, 400);    // X-axis

    outtextxy(60, 40, "Time");
    outtextxy(480, 420, "Input Size");

    printf("Insertion Sort\n");
    printf("n\tTime\n");

    for (n = 10; n <= 100; n += 10)
    {
       
        for (i = 0; i < n; i++)
        {
            a[i] = n - i;
        }

        s = clock();

        for (r = 0; r < REP; r++)
        {
            insertion(a, n);
        }

        e = clock();

        t = (double)(e - s) / CLOCKS_PER_SEC;

        printf("%d\t%f\n", n, t);

      
        x[p] = 50 + n * 5;
        y[p] = 350 - n * 2;

        p++;
    }

 
    setcolor(RED);
    for (i = 0; i < p - 1; i++)
    {
        line(x[i], y[i], x[i + 1], y[i + 1]);
    }

    outtextxy(420, 80, "Insertion Sort");

    getch();
    closegraph();
}
