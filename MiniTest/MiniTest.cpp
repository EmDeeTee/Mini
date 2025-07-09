#include <cstdio>
#include <format>
#include <iostream>

#include "../Mini/Mini.h"

// TODO: Yeah, I should probably use a real unit test
int main(int argc, char* argv[]) {
    Mini mini;

    mini.DoString(R"(PersonName = John C++
                    [Game]
                    WindowSizeX = 600)");
    
    auto& d = mini.GetSection("Game")->GetName();
    std::cout << d << '\n';
    
    return 0;
}
