#include "TouchEvent.h"

TouchEvent::TouchEvent()
{
	listener_ = cocos2d::EventListenerTouchOneByOne::create();
}

TouchEvent::~TouchEvent()
{
}
