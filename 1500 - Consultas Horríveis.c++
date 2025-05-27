#include <bits/stdc++.h>
using namespace std;


unsigned long long getSum(unsigned long long BITree[], int index)
{
    unsigned long long sum = 0;


    index = index + 1;


    while (index > 0)
    {

        sum += BITree[index];


        index -= index & (-index);
    }
    return sum;
}


void updateBIT(unsigned long long BITree[], int n, int index, unsigned long long val)
{

    index = index + 1;


    while (index <= n)
    {

        BITree[index] += val;


        index += index & (-index);
    }
}


unsigned long long sum(int x, unsigned long long BITTree1[], unsigned long long BITTree2[])
{
    return (getSum(BITTree1, x) * x) - getSum(BITTree2, x);
}

void updateRange(unsigned long long BITTree1[], unsigned long long BITTree2[], int n,
                 unsigned long long val, int l, int r)
{



    updateBIT(BITTree1, n, l, val);
    updateBIT(BITTree1, n, r + 1, -val);


    updateBIT(BITTree2, n, l, val * (l - 1));
    updateBIT(BITTree2, n, r + 1, -val * r);
}

unsigned long long rangeSum(int l, int r, unsigned long long BITTree1[], unsigned long long BITTree2[])
{

    return sum(r, BITTree1, BITTree2)
           - sum(l - 1, BITTree1, BITTree2);
}

unsigned long long* constructBITree(int n)
{

    unsigned long long* BITree = new unsigned long long[n + 1];
    for (int i = 1; i <= n; i++)
        BITree[i] = 0;

    return BITree;
}

// Driver code
int main()
{
    std::ios_base::sync_with_stdio(false);
    int bi, p, t, q, c, n;
    unsigned long long v;
    unsigned long long *BITTree1, *BITTree2;

    cin >> t;
    while(t--)
    {
        cin >> n >> c;
        BITTree1 = constructBITree(n);
        BITTree2 = constructBITree(n);
        for(int i=0; i<c; i++)
        {
            cin >> bi;
            if(bi==0)
            {
                cin >> p >> q >> v;
                p--;
                q--;
                updateRange(BITTree1, BITTree2, n, v, p, q);
            }
            else if(bi==1)
            {
                cin >> p >> q;
                p--;
                q--;
                cout << rangeSum(p, q, BITTree1, BITTree2) << endl;
            }
        }

        delete BITTree1;
        delete BITTree2;


    }


    return 0;
}