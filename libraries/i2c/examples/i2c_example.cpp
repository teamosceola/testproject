#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <iostream>
#include "../i2c.h"

int main(int argc, char const *argv[])
{
	using namespace std;

	// Instantiate i2c class
	cout << "Instantiating i2c class" << endl;
	i2c i2c3("/dev/i2c-3");

	// Declare variables
	uint8_t addr = 0x1A;
	uint8_t len = 2;
	uint8_t data[len];

	data[0] = data[1] = 0;

	cout << "i2c3.begin()" << endl;
	i2c3.begin();
	cout << "i2c3.write()" << endl;
	i2c3.write(addr, len, data);
	cout << "i2c3.read()" << endl;
	i2c3.read(addr, len, data);
	cout << "i2c3.end()" << endl;
	i2c3.end();

	cout << "End Program" << endl;
	return 0;
}