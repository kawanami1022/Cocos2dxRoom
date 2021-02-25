#include <string>
#include "Player.h"

Player::Player():CHARACTOR()
{
	sprite_ = cocos2d::Sprite::createWithSpriteFrameName("Run/sprites.png");
	sprite_->setPosition(this->getPosition());

}

Player::Player(cocos2d::Point pos, cocos2d::Node* layer)
{
    setPosition(pos);
    sprite_ = cocos2d::Sprite::create("sprites.png");
    sprite_->setPosition(cocos2d::Point(pos));
    layer->addChild(sprite_);
    auto cache = cocos2d::SpriteFrameCache::getInstance();
    cache->addSpriteFramesWithFile("sprites.plist");
    auto _animation = cocos2d::Animation::create();
    for (int i = 0; i < 9; i++) {

        auto str = "PrototypeHero_0" + std::to_string(i) + ".png";
        cocos2d::SpriteFrame* player = cache->getSpriteFrameByName(str.c_str());
        _animation->addSpriteFrame(player);

    }

    _animation->setDelayPerUnit(0.5f);
    _animation->setRestoreOriginalFrame(true);

    auto action = cocos2d::Animate::create(_animation);
    auto anime = cocos2d::RepeatForever::create(action);
    sprite_->runAction(anime);
}


Player::~Player()
{
}

void Player::InitAnimation()
{

}

