#include "Mini.h"

#include <iostream>
#include <sstream>
#include <ranges>

// NOTE: I'd be cool if you could also provide this function with just a string and not require reading a whole file
//       For example have both: ReadFile() and ReadString()
void Mini::ReadFile(const std::string& path) {
    std::ifstream infile(path);
    
    if (infile.is_open()) {
        std::string line;
        
        while (std::getline(infile, line)) {
            auto [key, value] = ParseLine(line);
            
            m_data.insert(std::pair(key, value));
        }
    } else {
        // based printf
        printf("Failed to open file: %s\n", path.c_str());
    }
}

/**
 * 
 * @param query [Profile].Value or Value. For example: [Game].WindowSizeX or Name
 *
 * @throws std::out_of_range If query didn't find anything
 */
MiniQueryResult Mini::Query(const std::string& query) {
    auto it = m_data.find(query);
    
    if (it == m_data.end()) {
        throw std::out_of_range("Query does not exist");
    }
    return MiniQueryResult(MiniPair_t(it->first, it->second));
}

bool Mini::Contains(const std::string& query) const {
    return m_data.contains(query);
}

// NOTE: I feel like having an std:pair here is overkill?
std::pair<std::string, std::string> Mini::ParseLine(const std::string& line) {
    auto key = line.substr(0, line.find('='));
    auto value = line.substr(line.find('=')+1, line.length() - line.find('='));

    Trim(key);
    Trim(value);

    return std::make_pair(key, value);
}

void Mini::Trim(std::string& s) {
    auto not_space = [](const unsigned char c){ return !std::isspace(c); };
    
    s.erase(
        std::ranges::find_if(s | std::views::reverse, not_space).base(),
        s.end());
    s.erase(
        s.begin(),
        std::ranges::find_if(s, not_space));
}
