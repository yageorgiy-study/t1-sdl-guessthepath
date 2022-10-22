#include "TitleText.h"
#include "../Defaults.h"

TitleText::TitleText(Game *game, const std::string &text) :
Text(game, text, TTF_OpenFont(Defaults::DEFAULT_FONT().c_str(), Defaults::TITLE_FONT_SIZE), Defaults::DEFAULT_COLOR()) {}
