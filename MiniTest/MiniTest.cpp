#include <cstdio>
#include <iostream>

#include "../Mini/Mini.h"

int main(int argc, char* argv[]) {
    Mini mini;

    mini.ReadFile("test.ini");
    auto x = mini.Query("songName").AsString();
    return 0;
}
