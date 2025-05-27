#include <iostream>
#include <string.h>

using namespace std;

int main() {
  int n, t, d, p, c = 1, i = 0, j, m[601] = {0};
	while(1) {
		memset(m, 0, sizeof(m));
		cin >> n >> t;
		if(n == 0) break;
		for(j = 1; j <= n; j++) {
			cin >> d >> p;
			for(c = 1; c <= t; c++) {
				if(d <= c) {
					if(m[c] < m[c - d] + p)
						m[c] = m[c - d] + p;
				}
			}
		}
		i++;
		cout << "Instancia " << i << endl;
		cout << m[t] << endl;
		cout << endl;
	}
	return 0;
}