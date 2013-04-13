#include "../include/Portal.h"

Portal::Portal(int r, int g, int b)
{
    sphere();
    scale(1);
    activeBody();
    visible(false);
    color(r,g,b);
}

Portal::~Portal()
{
    //dtor
}
