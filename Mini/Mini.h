#ifndef MINI_H
#define MINI_H

#include <string>
#include <fstream>
#include <map>
#include <optional>
#include <vector>

#include "MiniTypes.h"
#include "MiniQueryResult.h"
#include "MiniSection.h"
#include "Util.h"

#define MINI_GLOBAL_SECTION_NAME "_MINI_GLOBAL"

class Mini {
public:
    void ReadFile(const std::string& path);
    [[nodiscard]] std::optional<MiniSection> GetSection(const std::string& sectionName) const;
    [[nodiscard]] MiniSection GetGlobalSection(void) const;
    [[nodiscard]] bool ContainsSection(const std::string& query) const;
private:
    void ParseLine(const std::string& line);
    std::vector<MiniSection> m_data;
};
#endif // MINI_H
