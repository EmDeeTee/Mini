#ifndef MINI_H
#define MINI_H

#include <string>
#include <fstream>
#include <map>

#include "MiniTypes.h"
#include "MiniQueryResult.h"

class Mini {
public:
    void ReadFile(const std::string& path);
    MiniQueryResult Query(const std::string& query);
    [[nodiscard]] bool Contains(const std::string& query) const;
private:
    static MiniPair_t ParseLine(const std::string& line);
    static void Trim(std::string& s);
    MiniMap_t m_data;
};
#endif // MINI_H
