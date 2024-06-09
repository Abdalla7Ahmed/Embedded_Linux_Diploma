//4-decide the letter is vowel or not
#include<iostream>


int main(void)
{
    //A, E, I, O, U, 
    char vowel[5] = {'A','E','I','U','O'};
    char letter;
    std::cout<<"Enter letter to check if is vowel or not"<<std::endl;
    std::cin>>letter;
    int i {};
    for (; i < 5; i++)
    {
        if(letter == vowel[i] || letter == vowel[i] + 32 )
        {
            break;
        }
    }
    if(i == 5)
    {
        std::cout<<"letter "<<letter<<" is not a Vowel"<<std::endl;
    }
    else
    {
        std::cout<<"letter "<<letter<<" is a Vowel"<<std::endl;

    }

    
    
    return 0;
}