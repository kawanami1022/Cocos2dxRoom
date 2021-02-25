#pragma once
#include "Actor/Character/Character.h"
#ifndef __RING_H__
#define __RING_H__

class Ring:public Actor
{
public:
	Ring();
	Ring(cocos2d::Point);
	~Ring();
	void InitAnimation();
	cocos2d::Sprite* GetSprite();
private:
	cocos2d::Sprite* sprite_;
};
#endif
