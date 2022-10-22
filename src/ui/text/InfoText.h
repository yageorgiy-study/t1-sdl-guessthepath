#ifndef GUESSTHEPATH_INFOTEXT_H
#define GUESSTHEPATH_INFOTEXT_H

#include "../Text.h"

class InfoText : public Text {
public:
    InfoText(Game *renderer, const std::string &text);
};


#endif //GUESSTHEPATH_INFOTEXT_H
