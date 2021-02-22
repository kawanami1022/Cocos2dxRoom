#include <string>
#include "Player.h"

Player::Player():CHARACTOR()
{
	sprite_ = cocos2d::Sprite::createWithSpriteFrameName("Run/sprites.png");
	sprite_->setPosition(this->getPosition());

}

Player::Player(cocos2d::Point pos)
{
	sprite_ = cocos2d::Sprite::createWithSpriteFrameName("Run/sprites.png");
	sprite_->setPosition(pos);
}

Player::~Player()
{
}

void Player::InitAnimation()
{
	auto cache= cocos2d::SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("Run/sprites.plist");
	auto animation_ = cocos2d::Animation::create();
	for (int idx = 0; idx < 9; idx++)
	{
		auto str_ = "PrototypeHero_0" + std::to_string(idx) + ".png";
		cocos2d::SpriteFrame* sprite = cache->getSpriteFrameByName(str_);
		animation_->addSpriteFrame(sprite);
	}

	animation_->setDelayPerUnit(0.5f);
	animation_->setRestoreOriginalFrame(true);

	auto action = cocos2d::Animate::create(animation_);
	auto anime = cocos2d::RepeatForever::create(action);
	sprite_->runAction(anime);
}

cocos2d::Sprite* Player::GetSprite()
{
	return sprite_;
}
