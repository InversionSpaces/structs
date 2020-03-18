#include <iostream>
#include "LinkedList.hpp"

using namespace std;

int main() 
{
	LinkedList<int> l;
	l.push_back(5);
	l.push_front(6);
	l.push_back(7);
	l.push_front(8);
	cout << l.front() << " " << l.back() << endl;
	cout << l.pop_front() << " " << l.pop_back() << endl;
	cout << l.size() << endl;
}
