#include "myincludes.h"


using namespace std;

int main() {
    cout << "Hello World!\n";
    vector<int> arr = {1,3,7,9,10};
    
    bool index = binary_search(arr.begin(), arr.end(), 5);
    cout << index << endl;
    
    auto lb = lower_bound(arr.begin(), arr.end(), 8);
    auto ub = upper_bound(arr.begin(), arr.end(), 8);
    cout << *lb << " : " << *ub << endl;
    
    int lb1 = lower_bound(arr.begin(), arr.end(), 8) - arr.begin();
    int ub1 = upper_bound(arr.begin(), arr.end(), 8) - arr.begin();
    cout << lb1 << " : " << ub1 << endl;
}