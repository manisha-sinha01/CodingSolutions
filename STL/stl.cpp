#include <iostream>
#include  <vector>
#include <algorithm>
using namespace std;

int main()
{
    //vector are array 
    vector<int> A = { 1,100,893,4 };
    cout << A[1] << endl;
    sort(A.begin(),A.end());
    //binary search
    bool present = binary_search(A.begin(),A.end(),4);
    present = binary_search(A.begin(),A.end(),3);
    A.push_back(1000);
    present = binary_search(A.begin(),A.end(),1000);

    A.push_back(1000);
    A.push_back(1000);
    A.push_back(1000);
    A.push_back(1000);
    A.push_back(1230);

    
    vector<int> :: iterator itl = lower_bound(A.begin(),A.end(),1000); // >=
    vector<int> :: iterator itu = upper_bound(A.begin(),A.end(),1000); // <

    cout << *itl << " " << *itu << endl;
    cout << itu-itl << endl;
    return 0;
}