### Quick start

Example of reading strings and numbers from an .ini file
```ini
; KV pairs outside of any section are in the Global Section
PersonName = John C++
[Game]
WindowSizeX = 600
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
