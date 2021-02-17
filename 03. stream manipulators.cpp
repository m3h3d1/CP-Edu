#include<iostream>
#include<iomanip> //setw, setfill
using namespace std;

int main() {
	cout<< "[" << setw(10) << "Hi" << "]" <<endl;
	cout<< "[" << left << setw(10) << "Hi" << "]" <<endl;
	cout<< "[" << left << setfill('-') << setw(10) << "Hi" << "]" << endl;
	cout << hex << 10<<endl; // prints a
	cout << oct << 10<<endl; // prints 12
	cout << dec << 10<<endl; // prints 10
	return 0;
}