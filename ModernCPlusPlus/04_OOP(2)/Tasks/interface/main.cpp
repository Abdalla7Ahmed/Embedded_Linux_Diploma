#include "interface.hpp"

int main(void)
{

    Circle c;
    Triangle t;
    Rectangle r;
    c.shape_area();
    t.shape_area();
    r.shape_area();

    get_area(&c);
    get_area(&t);
    get_area(&r);

    return 0;
}
