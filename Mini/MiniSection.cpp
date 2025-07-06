#include "MiniSection.h"

#include <format>
#include <stdexcept>

MiniMap_t& MiniSection::GetData() {
    return m_data;
}

std::string MiniSection::GetName() const {
    return m_name;
}

// The original query was supposed to work like this:
// [SectionName].ValueName would return the value from the section
// [SectionName] Would return all values of the section
// ValueName would return the value from the global section

// But in the end I decided against it in favor of Mini::GetSection()
// It just has a much better flow and is easier to implement,
// if you want to get a value from a section, you just Mini::GetSection("Game").GetValue("WindowSizeX").AsDouble()

/**
 * 
 * @param query [Profile]Value or Value. For example: [Game]WindowSizeX or Name
 *
 * @throws std::out_of_range If query didn't find anything
 */
MiniQueryResult MiniSection::Query(const std::string& query) {
    auto kvPair = m_data.find(query);

    if (kvPair != m_data.end()) {
        return MiniQueryResult(*kvPair);
    } else {
        throw std::out_of_range(std::format("Can't find pair of name '{}' in section", query));
    }
}

bool MiniSection::Contains(const std::string& query) const {
    return m_data.contains(query);
}