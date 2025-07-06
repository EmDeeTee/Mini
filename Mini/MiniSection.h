#pragma once
#include <string_view>

#include "MiniTypes.h"
#include "MiniQueryResult.h"
#include "Util.h"

class MiniSection {
public:
    MiniSection(const std::string& name, const MiniMap_t& data) : m_name(name), m_data(data) {}
    [[nodiscard]] bool Contains(const std::string& query) const;
    MiniQueryResult Query(const std::string& query);
    MiniMap_t& GetData();
    [[nodiscard]] std::string GetName() const;
private:
    std::string m_name;
    MiniMap_t m_data;
};
