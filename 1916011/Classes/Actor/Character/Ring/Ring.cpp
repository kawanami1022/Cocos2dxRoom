#include "Ring.h"

Ring::Ring()
{
	sprite_ = cocos2d::Sprite::createWithSpriteFrameName("sprites.png");
	sprite_->setPosition(0,0);
}

Ring::Ring(cocos2d::Point pos)
{
	sprite_ = cocos2d::Sprite::createWithSpriteFrameName("sprites.png");
	sprite_->setPosition(pos);
}

Ring::~Ring()
{
}

void Ring::InitAnimation()
{
	auto cache = cocos2d::SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("sprites.plist");
	auto animation_ = cocos2d::Animation::create();
	for (int idx = 1; idx < 9; idx++)
	{
		auto str_ = "point_0" + std::to_string(idx) + ".png";
		cocos2d::SpriteFrame* sprite = cache->getSpriteFrameByName(str_);
		animation_->addSpriteFrame(sprite);
	}

	animation_->setDelayPerUnit(0.5f);
	animation_->setRestoreOriginalFrame(true);

	auto action = cocos2d::Animate::create(animation_);
	auto anime = cocos2d::RepeatForever::create(action);
	sprite_->runAction(anime);
}

cocos2d::Sprite* Ring::GetSprite()
{
	return sprite_;
}
