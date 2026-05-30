#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <signal.h>
#include <time.h>

int N;

void signalHandler(int sig)
{
    if(sig == SIGINT)
    {
        printf("\nSIGINT (Ctrl+C) received.\n");
        printf("Termination prevented.\n");
    }
}

int isPrime(int num)
{
    if(num < 2)
        return 0;

    for(int i = 2; i * i <= num; i++)
    {
        if(num % i == 0)
            return 0;
    }

    return 1;
}

DWORD WINAPI sumPrimeThread(LPVOID arg)
{
    long long sum = 0;
    int count = 0;
    int num = 2;

    DWORD start = GetTickCount();

    while(count < N)
    {
        if(isPrime(num))
        {
            sum += num;
            count++;
        }
        num++;
    }

    DWORD end = GetTickCount();

    printf("\nThread A Completed\n");
    printf("Sum = %lld\n", sum);
    printf("Time Taken = %lu ms\n", end - start);

    return 0;
}

DWORD WINAPI thread1(LPVOID arg)
{
    DWORD start = GetTickCount();

    for(int i = 0; i < 50; i++)
    {
        printf("Thread 1 running\n");
        Sleep(2000);
    }

    DWORD end = GetTickCount();

    printf("\nThread B Time = %lu ms\n", end - start);

    return 0;
}

DWORD WINAPI thread2(LPVOID arg)
{
    DWORD start = GetTickCount();

    for(int i = 0; i < 34; i++)
    {
        printf("Thread 2 running\n");
        Sleep(3000);
    }

    DWORD end = GetTickCount();

    printf("\nThread C Time = %lu ms\n", end - start);

    return 0;
}

int main()
{
    HANDLE tA, tB, tC;

    signal(SIGINT, signalHandler);

    printf("Enter N: ");
    scanf("%d", &N);

    DWORD totalStart = GetTickCount();

    tA = CreateThread(NULL, 0, sumPrimeThread, NULL, 0, NULL);
    tB = CreateThread(NULL, 0, thread1, NULL, 0, NULL);
    tC = CreateThread(NULL, 0, thread2, NULL, 0, NULL);

    WaitForSingleObject(tA, INFINITE);
    WaitForSingleObject(tB, INFINITE);
    WaitForSingleObject(tC, INFINITE);

    DWORD totalEnd = GetTickCount();

    printf("\nTotal Execution Time = %lu ms\n",
           totalEnd - totalStart);

    CloseHandle(tA);
    CloseHandle(tB);
    CloseHandle(tC);

    return 0;
}