#include <bits/stdc++.h>
using namespace std;

vector<int> f(vector<int> a, vector<int> b) {
    int i = 0;
    int j = 0;
    int idx = -1;
    vector<int> arr;
    
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            i++;
        } 
        else if (a[i] == b[j]) {
            if (idx == -1) {
                arr.push_back(a[i]);
                i++;
                j++;
                idx++;
            }
            else if (a[i] != arr[idx]) {
                arr.push_back(a[i]);
                i++;
                j++;
                idx++;
            }
            else if (a[i] == arr[idx]) {
                i++;
                j++;
            }
        }
        else {
            j++;
        }
    }
    
    return arr;
}

int main()
{
    vector<int> a = {1, 2, 2, 3, 3, 4, 5, 6};
    vector<int> b = {2, 3, 3, 5, 6, 6, 7};
    
    vector<int> c = f(a, b);
    for (auto it: c) {
        cout << it << " ";
    }
    // cout << c.size() << endl;

    return 0;
}
