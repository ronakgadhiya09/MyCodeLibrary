#include<bits/stdc++.h>

using namespace std;

class fenwickTree
{
private:
    vector<int>fen;
    int size;
public:
    fenwickTree(int N);
    ~fenwickTree();

    void update(int index,int addVal){
        while(index < size){
            fen[index] += addVal;
            index += (index&(-index));
        }
    }

    int prefixSum(int right){
        int sum = 0;
        while(right > 0){
            sum += fen[right];
            right -= (right&(-right));
        }
        return sum;
    }
};

fenwickTree::fenwickTree(int N)
{   
    this->size = N+1;
    fen.resize(N+1);
}

fenwickTree::~fenwickTree()
{
    fen.clear();
}

int main(){

    int n;
    cout << "Enter the size of the array : ";
    cin >> n;

    fenwickTree f(n);

    cout << "Enter array Elements : ";
    for(int i = 0 ; i < n ; i++){
        int x;
        cin >> x;
        f.update(i+1, x);  // Fixing to 1-based indexing
    }

    int q;
    cout << "enter number of queries : ";
    cin >> q;
    while(q--){
        int l,r;
        cout << "Enter l and r: ";
        cin >> l >> r;
        // cout << endl;
        cout << "sum from l to r is : " << f.prefixSum(r) - f.prefixSum(l-1) << endl;
    }

    return 0;
}
