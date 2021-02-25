#include "Actor/Actor.h"
#ifndef __CHARATOR_H__
#define __CHARATOR_H__

class CHARACTOR :public Actor
{
public:
	CHARACTOR();
	~CHARACTOR();
	cocos2d::Sprite* GetSprite();
protected:
	cocos2d::Sprite* sprite_;
private:
};
#endif