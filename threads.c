#include <stdio.h>
#include <windows.h>

int N;

int isPrime(int num)
{
    if (num < 2)
        return 0;

    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
            return 0;
    }

    return 1;
}

DWORD WINAPI sumPrimeThread(LPVOID arg)
{
    int count = 0;
    int num = 2;
    long long sum = 0;

    while (count < N)
    {
        if (isPrime(num))
        {
            sum += num;
            count++;
        }
        num++;
    }

    printf("\nSum of first %d prime numbers = %lld\n", N, sum);

    return 0;
}

DWORD WINAPI thread1(LPVOID arg)
{
    for (int i = 0; i < 50; i++)
    {
        printf("Thread 1 running\n");
        Sleep(2000);
    }

    return 0;
}

DWORD WINAPI thread2(LPVOID arg)
{
    for (int i = 0; i < 34; i++)
    {
        printf("Thread 2 running\n");
        Sleep(3000); 
    }

    return 0;
}

int main()
{
    HANDLE tA, tB, tC;

    printf("Enter N: ");
    scanf("%d", &N);

    tA = CreateThread(
        NULL,
        0,
        sumPrimeThread,
        NULL,
        0,
        NULL);

    tB = CreateThread(
        NULL,
        0,
        thread1,
        NULL,
        0,
        NULL);

    tC = CreateThread(
        NULL,
        0,
        thread2,
        NULL,
        0,
        NULL);

    if (tA == NULL || tB == NULL || tC == NULL)
    {
        printf("Thread creation failed!\n");
        return 1;
    }

    WaitForSingleObject(tA, INFINITE);
    WaitForSingleObject(tB, INFINITE);
    WaitForSingleObject(tC, INFINITE);

    CloseHandle(tA);
    CloseHandle(tB);
    CloseHandle(tC);

    printf("\nAll threads completed.\n");

    return 0;
}