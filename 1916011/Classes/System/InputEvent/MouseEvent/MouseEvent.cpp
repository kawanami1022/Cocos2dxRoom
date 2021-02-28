#include "MouseEvent.h"

MouseEvent::MouseEvent():InputEvent()
{
	listener_ = cocos2d::EventListenerMouse::create();
}

MouseEvent::~MouseEvent()
{
}
