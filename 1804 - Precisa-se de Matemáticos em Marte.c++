#include <iostream>

using namespace std;

int getSum(int BITree[], int index) {
  int sum = 0;
  index = index + 1;
  while (index>0) {
    sum += BITree[index];
    index -= index & (-index);
  }
  return sum;
}

void updateBIT(int BITree[], int n, int index, int val) {
  index = index + 1;
  while (index <= n) {
  	BITree[index] += val;
  	index += index & (-index);
  }
}

int *constructBITree(int arr[], int n) {
  int *BITree = new int[n+1];
  for (int i=1; i<=n; i++)
    BITree[i] = 0;
  for (int i=0; i<n; i++)
    updateBIT(BITree, n, i, arr[i]);
  return BITree;
}

int freq[100001];

int main(){
    string op;
    int n, index;
    std::ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> freq[i];
    }
    int *BITree = constructBITree(freq, n);
        while(cin >> op >> index){
            if(op == "a"){
                updateBIT(BITree, n, index-1, -freq[index-1]);
                freq[index-1] = 0;
            }
            else cout << getSum(BITree, index-2) << endl;
        }

  return 0;

}
