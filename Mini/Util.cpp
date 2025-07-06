#include "Util.h"

void Util::Trim(std::string& s) {
    auto not_space = [](const unsigned char c){ return !std::isspace(c); };
    
    s.erase(
        std::ranges::find_if(s | std::views::reverse, not_space).base(),
        s.end());
    s.erase(
        s.begin(),
        std::ranges::find_if(s, not_space));
}