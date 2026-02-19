#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <time.h>

#define REPEAT 30000  

void main()
{
    int gd = DETECT, gm;
    int arr[1000];
    int i, n, idx = 0, r;
    int x[10], yBest[10], yAvg[10], yWorst[10];
    int key;

    clock_t start, end;
    double best, avg, worst;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    
    setcolor(WHITE);
    setlinestyle(SOLID_LINE, 0, 3);

    line(50, 400, 50, 50);      // Y-axis
    line(50, 400, 600, 400);    // X-axis

    outtextxy(60, 40,  "Time (seconds)");
    outtextxy(480, 420, "Input Size (n)");

    printf("n\tBest(s)\tAverage(s)\tWorst(s)\n\n");

    
    for (n = 10; n <= 100; n += 10)
    {
        
        for (i = 0; i < n; i++)
        {
            arr[i] = i + 1;
        }

        
        key = arr[0];
        start = clock();

        for (r = 0; r < REPEAT; r++)
        {
            for (i = 0; i < n; i++)
            {
                if (arr[i] == key)
                    break;
            }
        }

        end = clock();
        best = (double)(end - start) / CLOCKS_PER_SEC;

        
        key = arr[n / 2];
        start = clock();

        for (r = 0; r < REPEAT; r++)
        {
            for (i = 0; i < n; i++)
            {
                if (arr[i] == key)
                    break;
            }
        }

        end = clock();
        avg = (double)(end - start) / CLOCKS_PER_SEC;

        
        key = arr[n - 1];
        start = clock();

        for (r = 0; r < REPEAT; r++)
        {
            for (i = 0; i < n; i++)
            {
                if (arr[i] == key)
                    break;
            }
        }

        end = clock();
        worst = (double)(end - start) / CLOCKS_PER_SEC;

        printf("%d\t%f\t%f\t%f\n", n, best, avg, worst);

        
        x[idx]      = 50 + n * 5;
        yBest[idx]  = 380;              
        yAvg[idx]   = 400 - (n * 2);    
        yWorst[idx] = 400 - (n * 3);    

        idx++;
    }


    setcolor(GREEN);
    for (i = 0; i < idx - 1; i++)
    {
        line(x[i], yBest[i], x[i + 1], yBest[i + 1]);
    }


    setcolor(BLUE);
    for (i = 0; i < idx - 1; i++)
    {
        line(x[i], yAvg[i], x[i + 1], yAvg[i + 1]);
    }


    setcolor(RED);
    for (i = 0; i < idx - 1; i++)
    {
        line(x[i], yWorst[i], x[i + 1], yWorst[i + 1]);
    }


    setcolor(GREEN);
    outtextxy(420, 80, "Best Case");

    setcolor(BLUE);
    outtextxy(420, 100, "Average Case");

    setcolor(RED);
    outtextxy(420, 120, "Worst Case");

    getch();
    closegraph();
}
