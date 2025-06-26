#include <cstdio>
#include <iostream>

#include "../Mini/Mini.h"

int main(int argc, char* argv[]) {
    Mini mini;

    mini.ReadFile("test.ini");
    
    if (mini.Contains("PersonName")) {
        auto x = mini.Query("PersonName").AsDouble();
    } else {
        printf("Key not found\n");
    }

    if (mini.Contains("WindowSizeX")) {
        auto x = mini.Query("WindowSizeX").AsDouble();
    } else {
        printf("Key not found\n");
    }
    return 0;
}
