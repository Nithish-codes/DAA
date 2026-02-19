#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <time.h>

#define REP 30000


void heapify(int a[], int n, int i)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int m = i;
    int t;

    if (l < n && a[l] > a[m])
        m = l;

    if (r < n && a[r] > a[m])
        m = r;

    if (m != i)
    {
        t = a[i];
        a[i] = a[m];
        a[m] = t;

        heapify(a, n, m);
    }
}


void heapsort(int a[], int n)
{
    int i, t;

    /* Build Max Heap */
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    /* Extract elements from heap */
    for (i = n - 1; i > 0; i--)
    {
        t = a[0];
        a[0] = a[i];
        a[i] = t;

        heapify(a, i, 0);
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

    
    line(50, 400, 50, 50);      
    line(50, 400, 600, 400);   

    outtextxy(60, 40, "Time");
    outtextxy(480, 420, "Input Size");

    printf("Heap Sort\n");
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
            heapsort(a, n);
        }

        e = clock();

        t = (double)(e - s) / CLOCKS_PER_SEC;

        printf("%d\t%f\n", n, t);

    
        x[p] = 50 + n * 5;
        y[p] = 350 - n;

        p++;
    }

   
    setcolor(BLUE);
    for (i = 0; i < p - 1; i++)
    {
        line(x[i], y[i], x[i + 1], y[i + 1]);
    }

    outtextxy(420, 80, "Heap Sort");

    getch();
    closegraph();
}
