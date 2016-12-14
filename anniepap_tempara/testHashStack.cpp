#include "HashStack.h"
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	HashStack hs(5);
	
	hs.push(1995);
	hs.push(2013);
	hs.push(2015);
	hs.push(2016);
	cout << hs.pop() << endl;
	cout << hs.pop() << endl;
	hs.push(2019);
	cout << hs.pop() << endl;
	cout << hs.pop() << endl;
	cout << hs.pop() << endl;
	
	return 0;
}
