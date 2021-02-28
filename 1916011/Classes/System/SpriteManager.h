#pragma once
#include <unordered_map>
#include <string>

namespace cocos2d
{
	class Sprite;
}

class SpriteManager
{
public:
	static SpriteManager& Create()
	{
		if (hInstance_ == nullptr)
		{
			hInstance_ = new SpriteManager();
		}
	}

	static void Destroy()
	{
		if (hInstance_ == nullptr)
		{
			delete hInstance_;
			hInstance_ = nullptr;
		}
	}

	static SpriteManager& Instance()
	{
		Create();
		return (*hInstance_);
	}




private:

	
	std::unordered_map<std::string,cocos2d::Sprite*> spriteList_;
	SpriteManager();
	~SpriteManager();
	static SpriteManager* hInstance_;
};