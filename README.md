### Quick start

Example of reading strings and numbers from an .ini file

TODO:
- Update the example below
- Use the builder pattern
- Use CMake instead of MSBuild

```ini
; KV pairs outside of any section are in the Global Section
PersonName = John C++
[Game]
WindowSizeX = 600
```

```cpp
    #include "Mini.h"

    Mini mini;

    mini.ReadFile("test.ini");

    // Deal with non-existent files
    try {
        mini.ReadFile("test.ini1");
    }
    catch (std::exception& e) {
        std::cout << std::format("Exception occured: {}\n", e.what());
    }

    // Get a value that doesn't belong to any section
    // ... And I just realised there is no way to check if the value exists beforehand lol
    // Professional C++ library
    std::string personName = mini.GetGlobalSection().Query("PersonName").AsString();

    // Get a specific value from a section
    if (mini.ContainsSection("Game")) {
        double windowSizeX = mini.GetSection("Game").Query("WindowSizeX").AsDouble();
    }

    // Get the entire section and its KV pairs
    if (mini.ContainsSection("Game")) {
        MiniSection gameSection = mini.GetSection("Game");
    }

    // Check if a section exists/doesn't exist
    if (!mini.ContainsSection("Game1")) {
        printf("The section doesn't exist\n");
    }
```
