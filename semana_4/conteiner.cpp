#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    int ca = 1;
    for (string s; cin >> s && s != "fim"; ++ca)
    {
        vector<char> top(26, 'Z'+ 1);
        int nstacks = 0;
        for (int i = 0; i < int(s.size()); ++i)
        {
            int st = -1;
            for (int j = 0; j < nstacks; ++j)
            {
                if (s[i] <= top[j])
                {
                    if (st == -1 || top[j] < top[st])
                    {
                        st = j;
                    }
                }
            }
            if (st == -1)
            {
                st = nstacks;
                ++nstacks;
            }
            top[st] = s[i];
        }
        cout << "Caso " << ca << ": " << nstacks << endl;
    }
}
