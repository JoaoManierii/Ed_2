#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int M;

bool SortFunc(int i, int j)
{
    if (i % M != j % M)
        return i % M < j % M;
    if (i & 1) 
    {
        if (j & 1)
            return i > j;
        return true;
    }
    if (j & 1)
    {
        return false;
    }
    return i < j;
}

int main()
{
    int N;

    vector<int> numeros(10005);

    while (cin >> N >> M, cout << N << ' ' << M << '\n', N)
    {
        for (int i = 0; i < N; ++i)
        {
            cin >> numeros[i];
        }

        sort(numeros.begin(), numeros.begin() + N, SortFunc);
        ;
        for (int i = 0; i < N; ++i)
            cout << numeros[i] << '\n';
    }
}
