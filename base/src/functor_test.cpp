/*
 * =====================================================================================
 *
 *       Filename:  functor_test.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年12月18日 05时43分03秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  piboye
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include "functor.h"

using namespace conet;

int main(int argc, char const* argv[])
{
    int c=1, b=2, d=3;
    DEFER((c, b, d), {
        printf("c:%d, b:%d, d:%d\n", c, b, d);
    });

    conet::Closure<int> *a = NewFunc(int, (), (c, b),
    {
            printf("hello \n");
            return 0;
    });
    a->Run();

    /*
    conet::Closure<int> *a2 = NewFunc(int,(), (),
    {
            printf("hello \n");
            return 0;
    });
    a2->Run();
   */
    return 0;
}

