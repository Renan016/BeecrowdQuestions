#include <iostream>

using namespace std;

int MDC(int p, int q){
    if(p==q)return q;
    if(p<q)return MDC(q, p);
    else return MDC(p-q, q);
}
int main()
{
    int N, f1, f2;
    cin >> N;
        while(N--){
            cin >> f1 >> f2;
            cout << MDC(f1, f2) << endl;
        }

    return 0;
}
