#include "MiniQueryResult.h"

double MiniQueryResult::AsDouble() const {
    return std::stod(m_RawData.second);
}

std::string MiniQueryResult::AsString() const {
    return m_RawData.second;
}
