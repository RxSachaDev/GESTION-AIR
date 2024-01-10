#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "color.h"

void color(int t,int f)
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(H,f*16+t);
}

