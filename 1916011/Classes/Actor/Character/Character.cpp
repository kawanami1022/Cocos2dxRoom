#include "Character.h"

CHARACTOR::CHARACTOR():Actor()
{
}

CHARACTOR::~CHARACTOR()
{
}

cocos2d::Sprite* CHARACTOR::GetSprite()
{
    return sprite_;
}
