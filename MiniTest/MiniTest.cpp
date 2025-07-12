#include <cstdio>
#include <format>
#include <iostream>

#include "../Mini/Mini.h"

// TODO: Yeah, I should probably use a real unit test

// https://stackoverflow.com/questions/6388698/c-return-stdstring-reference-from-stack-memory
int main(int argc, char* argv[]) {
    Mini mini;

    mini.DoString(R"(PersonName = John C++
                    [Game]
                    WindowSizeX = 600)");

    auto s = mini.GetSection("Game1");
    
    if (s.has_value()) {
        auto& name = s.value()->GetName();
        std::cout << name << "\n";
    } else {
        throw std::runtime_error("Yes, this is an exception. Deal with it");
    }
    
    
    return 0;
}
