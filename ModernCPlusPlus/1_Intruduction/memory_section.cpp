#include<iostream>

// global variable stored in .bss section because it global uninitialized variable
int Global_var_bss{};
// global variable stored in .data section because it global initialized variable
int Global_var_data{20};


int main(void)
{
    // local variable stored in stack  because it local variable
    int Local_var_stack{500};


    std::cout << "Global_var_bss = " <<Global_var_bss<< std::endl;
    std::cout << "Global_var_data = " <<Global_var_data<< std::endl;
    std::cout << "Local_var_stack = " <<Local_var_stack<< std::endl;
    return 0;
}