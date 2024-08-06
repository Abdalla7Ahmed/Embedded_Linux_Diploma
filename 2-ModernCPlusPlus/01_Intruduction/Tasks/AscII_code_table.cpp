// 1-Create a table for AscII code
#include <iostream>

int main(int argc, const char **argv)
{
  char a;
  std::cout << "  ASCII Code Table :" << std::endl;
  std::cout << "+---------+---------+" << std::endl;
  std::cout << "|   Char  |   ASCII |" << std::endl;
  std::cout << "+---------+---------+" << std::endl;
  for (int i = 0; i < 127; i++)
  {
    a = i;
    if (i < 10)
    {
      std::cout << "|         |   " << i << "     |" << std::endl;
    }
    else if (i >= 10 && i < 33)
    {
      std::cout << "|         |   " << i << "    |" << std::endl;
    }
    else if (i >= 33 && i < 64)
    {
      std::cout << "|    " << static_cast<char>(i) << "    |   " << i << "    |" << std::endl;
    }
    else if (i >= 64 && i < 100)
    {
      std::cout << "|    " << static_cast<char>(i) << "    |   " << i << "    |" << std::endl;
    }
    else if (i >= 100 && i < 127)
    {
      std::cout << "|    " << static_cast<char>(i) << "    |  " << i << "    |" << std::endl;
    }
  }

  return 0;
}