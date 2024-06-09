#include<iostream>
#include <algorithm>


int main(int argc, const char** argv) {
    float side1,side2,side3;
    std::cout<<"Enter side1"<<std::endl;
    std::cin>>side1;
    std::cout<<"Enter side2"<<std::endl;
    std::cin>>side2;
    std::cout<<"Enter side3"<<std::endl;
    std::cin>>side3;
 
    if(side1 > side2)
    {
        if(side1>side3)
        {
               // side 1 is the biggest one
               if((side1*side1) == ( (side2*side2)+ (side3*side3) ) ) 
               {
                std::cout<<"RIGHT angle triangle"<<std::endl;
               }
               else
               {
                std::cout<<"NOT RIGHT angle triangle"<<std::endl;
               }
        }
        else
        {
            // side 3 is the biggest one
               if((side3*side3) == ( (side2*side2)+ (side1*side1) ) ) 
               {
                std::cout<<"RIGHT angle triangle"<<std::endl;
               }
               else
               {
                std::cout<<"NOT RIGHT angle triangle"<<std::endl;
               }


        }

    }
    else
    {
        if(side2>side3)
        {

            // side 2 is the biggest one
               if((side2*side2) == ( (side1*side1)+ (side3*side3) ) ) 
               {
                std::cout<<"RIGHT angle triangle"<<std::endl;
               }
               else
               {
                std::cout<<"NOT RIGHT angle triangle"<<std::endl;
               }
        }
        else
        {

            // side 3 is the biggest one 
               if((side3*side3) == ( (side1*side1)+ (side2*side2) ) ) 
               {
                std::cout<<"RIGHT angle triangle"<<std::endl;
               }
               else
               {
                std::cout<<"NOT RIGHT angle triangle"<<std::endl;
               }
        }
    }

    // OR =================================================
    float side[3];
    std::cout<<"Enter side1"<<std::endl;
    std::cin>>side[0];
    std::cout<<"Enter side2"<<std::endl;
    std::cin>>side[1];
    std::cout<<"Enter side3"<<std::endl;
    std::cin>>side[2];
    int size=sizeof(side)/sizeof(side[0]);
    //std::sort(side,side+size);
    std::sort(std::begin(side),std::end(side));
    
    if((side[2]*side[2]) == ( (side[1]*side[1])+ (side[0]*side[0]) ) ) 
    {
        std::cout<<"RIGHT angle triangle"<<std::endl;
    }
    else
    {
        std::cout<<"NOT RIGHT angle triangle"<<std::endl;
    }
 

    return 0;
}