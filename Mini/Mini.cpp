#include "Mini.h"

#include <algorithm>
#include <format>
#include <iostream>
#include <sstream>

// NOTE: In this file I sue a lot of std::find_if to check if m_data has a section of a given name and then get it
// I wonder if I can use the already existing method Mini::GetSection(). But it throws an exception upon failure to find.
// I need something that can return two types. Either a ready-to-use section or false/null. Maybe a pointer?

// NOTE: I'd be cool if you could also provide this function with just a string and not require reading a whole file
//       For example have both: ReadFile() and ReadString()

/**
 *
 * @throws std::runtime_error When can't find file
 * @param path path to the .ini file
 */
void Mini::ReadFile(const std::string& path) {
    std::ifstream infile(path);
    
    if (infile.is_open()) {
        std::string line;
        
        while (std::getline(infile, line)) {
            ParseLine(line);
        }
    } else {
        throw std::runtime_error(std::format("Can't open file with path '{}'", path));
    }
}

std::optional<MiniSection> Mini::GetSection(const std::string& sectionName) const {
    auto it = std::ranges::find_if(m_data, [&](const MiniSection& s) {
        return s.GetName() == sectionName;
    });

    if (it != m_data.end()) {
        return *it;
    } else {
        return std::nullopt;
    }
}

MiniSection Mini::GetGlobalSection() const {
    auto res = GetSection(MINI_GLOBAL_SECTION_NAME);
    
    if (res.has_value()) {
        return res.value();
    } else {
        throw std::runtime_error("Global Section does not exist. This is a bug in Mini");
    }
}

bool Mini::ContainsSection(const std::string& query) const {
    return std::ranges::any_of(m_data, [&](const MiniSection& s) {
        return s.GetName() == query; 
    });
}

// NOTE: I feel like having an std:pair here is overkill?
// Also, this method is very large and I feel like it has too much to do
// Like, it parses, checks for sections, creates them and also inserts them to m_data all at once
void Mini::ParseLine(const std::string& line) {
    static MiniSection globalSection(MINI_GLOBAL_SECTION_NAME, {});
    static MiniSection* currentSection = nullptr;

    if (line.starts_with("[") && line.ends_with("]")) {
        std::string sectionName = line.substr(1, line.length() - 2);
        Util::Trim(sectionName);

        auto it = std::find_if(m_data.begin(), m_data.end(), [&](const MiniSection& s) {
            return s.GetName() == sectionName;
        });

        if (it == m_data.end()) {
            m_data.push_back(MiniSection(sectionName, {}));
            currentSection = &m_data.back();
        } else {
            currentSection = &(*it);
        }

        return;
    }
    
    if (line.empty() || line[0] == ';' || line[0] == '#') {
        return;
    }
    
    auto pos = line.find('=');
    if (pos == std::string::npos) {
        return;  // no key=value, ignore or handle error
    }

    std::string key = line.substr(0, pos);
    std::string value = line.substr(pos + 1);

    Util::Trim(key);
    Util::Trim(value);
    
    if (currentSection == nullptr) {
        if (std::find_if(m_data.begin(), m_data.end(), [&](const MiniSection& s) {
            return s.GetName() == MINI_GLOBAL_SECTION_NAME;
        }) == m_data.end()) {
            m_data.push_back(globalSection);
        }
        
        currentSection = &m_data.back();
    }

    currentSection->GetData()[key] = value;
}
