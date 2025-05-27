#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    char letra;
    int N, num1, num2, solve, cont = 0;
    cin >> N;
        while(N--){
            cin >> num1 >> letra >> num2;
            if(num1 != num2){
                if(letra>='A' && letra<='Z'){
                    solve = (num2-num1);
                }
                else if(letra>='a' && letra<='z'){
                    solve = (num1+num2);
                }
            }

            else solve = (num1*num2);

            cout << solve << endl;
            cont++;
        }
    return 0;
}