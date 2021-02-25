/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/
#include <string>
#include "GameScene.h"
#include "Actor/Character/Ring/Ring.h"
USING_NS_CC;

Scene* GameScene::createScene()
{
    return GameScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto winSize = Director::getInstance()->getWinSize();
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.





    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

    auto label = Label::createWithTTF("Game Scene", "fonts/Marker Felt.ttf", 24);
    if (label == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label->setPosition(Vec2(origin.x + visibleSize.width / 2,
            origin.y + visibleSize.height - label->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label, 1);
    }

    gameLayer_ = cocos2d::Layer::create();
    gameCamera_ = Camera::createOrthographic(winSize.width, winSize.height, -200, 1000);

    map_ = cocos2d::TMXTiledMap::create("map.tmx");
    map_->setPosition(0, 0);
    gameCamera_->addChild(map_, -2, -100);
    // create mouse
    LeftButtton_ = 
        cocos2d::ui::Button::create("ArrowButton/ArrowButton_00.png", "ArrowButton/ArrowButton_01.png");
    LeftButtton_->setScaleX(-1);
    auto ButtonSize=LeftButtton_->getNormalTextureSize();
    LeftButtton_->setPosition(Vec2(visibleSize.width- ButtonSize.width/2-ButtonSize.width, ButtonSize.height/2));
    LeftButtton_->setPosition(Vec2(visibleSize.width- ButtonSize.width/2-ButtonSize.width, ButtonSize.height/2));
    LeftButtton_->addTouchEventListener([&](Ref* sender, cocos2d::ui::Widget::TouchEventType type) {
        switch (type)
        {
        case ui::Widget::TouchEventType::BEGAN:
            leftFlag_ = true;
            break;
        case ui::Widget::TouchEventType::ENDED:
            leftFlag_ = false;
            break;
        default:
            break;
        }
        });;
    gameLayer_->addChild(LeftButtton_);

    RightButtton_ =
        cocos2d::ui::Button::create("ArrowButton/ArrowButton_00.png", "ArrowButton/ArrowButton_01.png");
    RightButtton_->addTouchEventListener([&](Ref* sender, cocos2d::ui::Widget::TouchEventType type) {
        switch (type)
        {
        case ui::Widget::TouchEventType::BEGAN:
            rightFlag_ = true;
            break;
        case ui::Widget::TouchEventType::ENDED:
            rightFlag_ = false;
            break;
        default:
            break;
        }
       });;
    ButtonSize = RightButtton_->getNormalTextureSize();
    RightButtton_->setPosition(Vec2(visibleSize.width - ButtonSize.width / 2, ButtonSize.height / 2));

    gameLayer_->addChild(RightButtton_);
    gameLayer_->addChild(gameCamera_);
    gameCamera_->setCameraFlag(CameraFlag::USER1);



    this->addChild(gameLayer_);

    this->scheduleUpdate();
    return true;
}

void GameScene::update(float delta)
{
    auto gameCameraPos = gameCamera_->getPosition();
    if (rightFlag_)
    {
        gameCameraPos.x -= 200* delta;
    }

    if (leftFlag_)
    {
        gameCameraPos.x += 200 * delta;
    }
    gameCamera_->setPosition(gameCameraPos);
}


