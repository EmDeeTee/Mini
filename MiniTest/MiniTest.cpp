#include <cstdio>
#include <format>
#include <iostream>

#include "../Mini/Mini.h"

// TODO: Yeah, I should probably use a real unit test
int main(int argc, char* argv[]) {
    Mini mini;

    mini.DoString("PersonName = John C++ \n \
                            [Game] \n \
                            WindowSizeX = 600");
    
    auto b = mini.GetSection("Game")->Query("WindowSizeX")->AsDouble();
    
    return 0;
}
