#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    long long currentSum = 0, maxSum = 0;
    int startIndex = 0;

    for (int i = 0; i < K; i++)
    {
        currentSum += A[i];
    }
    maxSum = currentSum;
    for (int i = K; i < N; i++)
    {
        currentSum += A[i] - A[i - K];
        if (currentSum > maxSum)
        {
            maxSum = currentSum;
            startIndex = i - K + 1;
        }
    }

    cout << maxSum << endl;
    for (int i = startIndex; i < startIndex + K; i++)
    {
        cout << A[i] << " ";
    }

    return 0;
}
