#include "Actor/Actor.h"

#ifndef __BUTTON_H__
#define __BUTTON_H__

class Button :public Actor
{
public:
	Button();
	Button(cocos2d::Sprite* sprite);
	~Button();
protected:
	cocos2d::Sprite* sprite_;
private:
};
#endif