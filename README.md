### Quick start

Example of reading strings and numbers from an .ini file
```ini
WindowSizeX = 600
PersonName = John C++
```

```cpp
    #include "Mini.h"

   // Reading an std::string
    if (mini.Contains("PersonName")) {
        auto x = mini.Query("PersonName").AsString();
    } else {
        printf("Key not found\n");
    }

    // Reading a double
    if (mini.Contains("WindowSizeX")) {
        auto x = mini.Query("WindowSizeX").AsDouble();
    } else {
        printf("Key not found\n");
    }
```
