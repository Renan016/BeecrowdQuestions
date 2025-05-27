#include <iostream>

using namespace std;

int main()
{
    int l, v[510], n, maior;
        while(cin >> l){
            for(int i=0; i<l; i++){
                cin >> v[i];
            }
            n = v[0];
            for(int i=1; i<l; i++){
                if(n<v[i])n = v[i];
            }

            if(n<10){
                cout << 1 << endl;
            }
            if(n>=10 && n<20){
                cout << 2 << endl;
            }
            if(n>=20){
                cout << 3 << endl;
            }

        }
    return 0;
}