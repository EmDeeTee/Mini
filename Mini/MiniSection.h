#pragma once
#include <optional>
#include <string_view>

#include "MiniTypes.h"
#include "MiniQueryResult.h"
#include "Util.h"

class MiniSection {
public:
    MiniSection(std::string&& name, MiniMap_t&& data) : m_name(std::move(name)), m_data(std::move(data)) {}
    [[nodiscard]] bool Contains(const std::string& query) const;
    [[nodiscard]] std::optional<MiniQueryResult> Query(const std::string& query) const;
    [[nodiscard]] const std::string& GetName() const;
    MiniMap_t& GetData();
private:
    std::string m_name;
    MiniMap_t m_data;
};
