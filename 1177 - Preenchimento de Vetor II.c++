#include <iostream>

using namespace std;

int main()
{
    int vet[1010], n, x=0;
    cin >> n;
        for(int i=0; i<1000; i++){
            cout << "N[" << i << "] = " << x << endl;
            x++;
            if(x == n)x = 0;
        }
    return 0;
}
