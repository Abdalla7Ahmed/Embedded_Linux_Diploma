// 7-change from decimal to binary and vice versa

#include <iostream>
#include <bitset>
/*

A bitset is an array of bools but each boolean value is not stored in a separate byte instead,
bitset optimizes the space such that each boolean value takes 1-bit space only,
so space taken by bitset is less than that of an array of bool or vector of bool.
A limitation of the bitset is that size must be known at compile time i.e. size of the bitset is fixed.
*/

/*
Syntax :
bitset<size> variable_name(initialization);
*/

/*
We can initialize bitset in three ways :

1. Uninitialized: All the bits will be set to zero.

bitset<size> variable_name;
2. Initialization with decimal integer: Bitset will represent the given decimal number in binary form.

bitset<size> variable_name(DECIMAL_NUMBER);
3. Initialization with binary string: Bitset will represent the given binary string.

bitset<size> variable_name(string("BINARY_STRING");
bitset<size> variable_name("BINARY_STRING");

*/

int main(int argc, const char **argv)
{
    while (1)
    {
        bool Choose = false;
        std::cout << "Chose ------- " << std::endl;
        std::cout << "0.convert from decimal to binary" << std::endl;
        std::cout << "1.convert from binary to decimal" << std::endl;
        std::cin >> Choose;

        if (Choose == false)
        {
            int decimal;
            std::cout << "Enter the decimal number " << std::endl;
            std::cin >> decimal;
            std::bitset<8> decimalBitset(decimal);

            std::cout << "Type: " << typeid(decimal).name() << std::endl; // Type: i  --> indicate to integer

            std::cout << "The number in binary is " << decimalBitset << std::endl;
        }
        else
        {
            std::string binary;
            std::cout << "Enter the binary number " << std::endl;
            std::cout << "0b";
            std::cin >> binary;
            std::bitset<8> binaryBitset(binary);

            std::cout << "Type: " << typeid(binary).name() << std::endl; // Type: NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE  --> indicate to string

            int number = binaryBitset.to_ullong();

            std::cout << "Type: " << typeid(number).name() << std::endl; // Type: i  --> indicate to integer

            std::cout << "The number in decimal is " << number << std::endl;
        }
    }

    return 0;
}