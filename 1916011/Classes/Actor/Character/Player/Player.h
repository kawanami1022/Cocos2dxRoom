#include "Actor/Character/Character.h"
#ifndef __PLAYER_H__
#define __PLAYER_H__

class Player :public CHARACTOR
{
public:
	Player();
	Player(cocos2d::Point);
	~Player();
	void InitAnimation();
	cocos2d::Sprite* GetSprite();
protected:
	cocos2d::Sprite* sprite_;
};
#endif