#include "InfoText.h"
#include "../Defaults.h"

InfoText::InfoText(Game *game, const std::string &text) :
Text(game, text, TTF_OpenFont(Defaults::DEFAULT_FONT().c_str(), Defaults::MEDIUM_FONT_SIZE), Defaults::DEFAULT_COLOR()) {}
