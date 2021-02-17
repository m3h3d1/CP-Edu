// constructing vectors
#include <iostream>
#include <vector>
using namespace std;
 
int main () {
    // constructors used in the same order as described above:
    vector<int> first;                                // empty vector of ints
    vector<int> second (4,100);                       // four ints with value 100
    vector<int> third (second.begin(),second.end());  // iterating through second
    vector<int> fourth (third);                       // a copy of third
     
    // the iterator constructor can also be used to construct from arrays:
    int myints[] = {16,2,77,29};
    vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
 
    cout << "The contents of fifth are:";
    for (unsigned i=0; i < fifth.size(); i++) cout << " " << fifth[i]; cout << endl;
     
     

    // use of [] and ()
    vector<int> v1[100]; // creates an array of vectors, i.e. 100 vectors
    vector<int> v2(100); // creates 1 vector of size 100

    // creating a 2D array 100x2 where each element is a vector,
    // so in total, it is a 3D structure, as vector itself is 1D
    vector<int> v3[100][2];
    return 0;
}