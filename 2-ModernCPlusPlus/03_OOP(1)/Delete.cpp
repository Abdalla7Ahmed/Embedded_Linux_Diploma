


/*

default and delete 
 
default come with :-
1. default constructor     --> do nothing
2. copy constructor		   --> copy the members of the copied class to this class
3. assigment operator
4. destructor			   --> do nothing
===============
delete come with :-
1. default constructor    
2. copy constructor		  
3. assigment operator
4. destructor	
5. parametarize constructor 
6. any function in the class 

*/
#include<iostream>
class DELETE
{
private:
    /* data */
public:
    DELETE()= delete;    
    DELETE(int y);
    void set(float y,float x) = delete;
    void set(int y,int x) ;
    ~DELETE() = default;
};

DELETE::DELETE(int y)
{
    std::cout<<"y = "<<y<<std::endl;
}
void DELETE::set(int y,int x) 
{
    std::cout<<"y = "<<y<<" and x = "<<x<<std::endl;

}


int main(void)
{
    // DELETE d1;      // error  use of deleted function ‘DELETE::DELETE()’
    DELETE d2(5);
    d2.set(5,10);
   // d2.set(10.5f,11.5f);   // error use of deleted function
    return 0;
}
