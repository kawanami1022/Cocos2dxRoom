#include "Actor/Character/Character.h"
#ifndef __PLAYER_H__
#define __PLAYER_H__

class Player :public CHARACTOR
{
public:
	Player();
	Player(cocos2d::Point,cocos2d::Node* layer);
	~Player();
	void InitAnimation();
protected:
	
};
#endif