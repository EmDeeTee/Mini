#include "MiniSection.h"

#include <format>
#include <stdexcept>

MiniMap_t& MiniSection::GetData() {
    return m_data;
}

const std::string& MiniSection::GetName() const {
    return m_name;
}

bool MiniSection::Contains(const std::string& query) const {
    return m_data.contains(query);
}

std::optional<MiniQueryResult> MiniSection::Query(const std::string& query) const {
    auto kvPair = m_data.find(query);

    if (kvPair != m_data.end()) {
        return MiniQueryResult(*kvPair);
    } else {
        return std::nullopt;
    }
}
