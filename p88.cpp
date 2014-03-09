#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	int sum;

	sum = 0;

	for (int i = 1; i <= 1000; i++)
		sum += i;
	
	cout << "The sum from 1 to 1000 is: " << sum << endl;
}
