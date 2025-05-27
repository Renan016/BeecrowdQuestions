#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int N, p, k=0;
    vector<int> V;
    while(1)
    {

        cin>>N;
        if(N==0)break;
        k = 0;
        do
        {
            k++;
            V.clear();
            for(int i = 0; i < N; i++)
            {
                V.push_back(i + 1);
            }
            p = 0;
            while(V.size() > 1)
            {
                V.erase(V.begin() + p);
                p += k - 1;
                p %= V.size();

            }



        }
        while(V[0]!=13);
        cout << k << endl;
    }
    return 0;
}