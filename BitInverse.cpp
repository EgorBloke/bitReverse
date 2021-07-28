// BitInverse.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<bitset>
void bitInverse(uint8_t& val);
void printByte(uint8_t& val);
int main()
{

	uint8_t byte = 0b10101111;
	printByte(byte);
	bitInverse(byte);
	printByte(byte);
	return 0;
}

void bitInverse(uint8_t &val) {
	for (int i = 0; i < 4; ++i) {
		if (bool(val & (1 << i)) != bool(val & (1 << (7 - i)))) //
		{
			bool buf = static_cast<bool>(val & (1 << i));
			if (buf) // ==1
			{
				val &= ~(1 << i);
				val |= (1 << (7 - i));
			}
			else
			{
				val |= 1 << (7 - i);
				val &= 1 << i;
			}
		}
	}
	return;
}
void printByte(uint8_t& val) {
	std::cout << static_cast<int>(val) << std::endl;
	std::cout << std::bitset<sizeof(val) * 8>(val) << std::endl;
}
