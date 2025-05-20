#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int NC, n, p, m, i, k;
    vector<int> V;
    cin>>NC;

    for (i = 1; i <= NC; i++){


        cin>>n>>k;
        for(int i=0; i<n; i++){
            V.push_back(i+1);
        }
        p = 0;
        while((int)V.size() > 1){
            p = p + (k-1);
            p = p % V.size();
            V.erase(V.begin() + p);

        }
        cout << "Case " << i << ": " << V[0] << endl;
        V.clear();
        }

    return 0;
}