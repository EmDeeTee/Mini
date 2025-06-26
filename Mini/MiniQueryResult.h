#ifndef MiniQueryResult_h
#define MiniQueryResult_h

#include <string>

#include "MiniTypes.h"

class MiniQueryResult {
public:
    // NOTE: The voices told me to use std::move. I still don't understand it
    MiniQueryResult(MiniPair_t rawData) : m_RawData(std::move(rawData)) {}
    // NOTE: I contemplated using something more like Mini.Query<double>()
    //       But i was worried it's going to be too complex and also,
    //       What if someone passed some wierd type instead of std::string or double or int? 
    [[nodiscard]] double AsDouble(void) const;
    [[nodiscard]] std::string AsString(void) const;
private:
    MiniPair_t m_RawData;
};
#endif
