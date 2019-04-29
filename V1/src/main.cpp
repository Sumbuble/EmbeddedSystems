#include "7Segment.h"
#include<iostream>

int main()
{
    constexpr MultiDigit test{0,1,2,3,4,5,11,6,7,12,8,9,};

    constexpr MultiDigit test2{'a',4,5,12,50};

    printf("%s", static_cast<const char*>(test2));

    printf("%s", static_cast<const char*>(test));
}