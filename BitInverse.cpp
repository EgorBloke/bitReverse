// BitInverse.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<bitset>
uint8_t bitInverse(uint8_t val);
void printByte(uint8_t& val);
int main()
{

	uint8_t byte = 0b10101111;	//пробный байт
	printByte(byte);	
	uint8_t byte_edited = bitInverse(byte);
	printByte(byte_edited);
	return 0;
}

uint8_t bitInverse(uint8_t val) 
{
	for (int i = 0; i < 4; ++i)		//цикл до полбайт
	{
		if (bool(val & (1 << i)) != bool(val & (1 << (7 - i)))) //
		{
			bool buf = static_cast<bool>(val & (1 << i));		//значение текущего бита
			if (buf) // если == 1
			{
				val &= ~(1 << i);	//устанавливаем значение в 0
				val |= (1 << (7 - i));	//устанавливаем значение в 1
			}
			else  //если ==0, то наоборот: текущий бит в 1, зекркальный - в 0
			{
				val |= 1 << (7 - i);		
				val &= 1 << i;
			}
		}
	}
	return val;
}
void printByte(uint8_t& val) {
	std::cout << static_cast<int>(val) << std::endl;
	std::cout << std::bitset<sizeof(val) * 8>(val) << std::endl;
}
