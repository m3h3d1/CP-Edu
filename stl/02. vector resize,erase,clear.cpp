#include <iostream>
#include <vector>
using namespace std;
 
int main () {
    unsigned int i;
    vector<unsigned int> myvector;
    // set some values (from 1 to 10)
    for (i=1; i<=10; i++) myvector.push_back(i);
    // erase the 6th element
    myvector.erase (myvector.begin()+5);
    // erase the first 3 elements:
    myvector.erase (myvector.begin(),myvector.begin()+3);
    cout << "myvector contains:";
    for (i=0; i<myvector.size(); i++)
        cout << " " << myvector[i];
    cout << endl;
 
    // clear all
    myvector.clear();
    cout << "size: " << myvector.size() << endl;
 
    // resize and then check size
    myvector.resize(10);
    cout << "size: " << myvector.size() << endl;


    //x.clear() করা আর x.erase(x.begin(), x.end()) একই কথা। তাই কোডে খুব বেশি clear না মারাই ভাল।
    return 0;
}