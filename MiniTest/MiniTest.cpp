#include <cstdio>
#include <format>
#include <iostream>

#include "../Mini/Mini.h"

// TODO: Yeah, I should probably use a real unit test
int main(int argc, char* argv[]) {
    Mini mini;

    mini.ReadFile("test.ini");
    
    auto b = mini.GetSection("Game")->Query("WindowSizeX1")->AsDouble();
    
    return 0;
}
