#pragma once
#include <memory>
#include <unordered_map>
#include <string>
#include <cocos2d.h>
class InputEvent
{
public:
	
	InputEvent();
	~InputEvent();
protected:
	cocos2d::EventListener* listener_;
private:
};