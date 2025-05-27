#include <iostream>
#include <cstdlib>

using namespace std;

int maior(int a, int b){
    return (a + b + abs(a - b))/2;
}

int main(){
    int a, b, c, solve;

    cin >> a >> b >> c;

    solve = maior(a, b);

    if(solve < c){
        cout << c << " eh o maior" << endl;
    }
    else{
    cout << solve << " eh o maior" << endl;
    }

    return 0;
}