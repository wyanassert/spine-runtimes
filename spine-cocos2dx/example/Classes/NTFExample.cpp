//
//  NTFExample.cpp
//  spine-cocos2d-x
//
//  Created by wyan on 2023/5/25.
//

#include "NTFExample.h"
#include <spine/Extension.h>
#include <iostream>

USING_NS_CC;
using namespace spine;
using namespace std;

PowInterpolation ntfPow2(2);
PowOutInterpolation ntfPowOut2(2);
SwirlVertexEffect ntfEffect(400, ntfPowOut2);

Scene* NTFExample::scene () {
    Scene *scene = Scene::create();
    scene->addChild(NTFExample::create());
    return scene;
}

bool NTFExample::init () {
    if (!LayerColor::initWithColor(Color4B(128, 128, 128, 255))) return false;

    skeletonNode = SkeletonAnimation::createWithJsonFile("NFT_1.json", "NFT_1.atlas", 0.7f);
    skeletonNode->setAnimation(0, "room_guitar_right", true);
    skeletonNode->setTwoColorTint(true);
    
    ntfEffect.setCenterY(200);
    swirlTime = 0;
    
    skeletonNode->setVertexEffect(&ntfEffect);

    skeletonNode->setPosition(Vec2(_contentSize.width / 2, 150));
    addChild(skeletonNode);
    
    for(int i = 0; i < 6; i++)
    {
        spine::SkeletonAnimation* skeletonNode = SkeletonAnimation::createWithJsonFile("NFT_1.json", "NFT_1.atlas", 0.7f);
        skeletonNode->setAnimation(0, "room_guitar_right", true);
    //    skeletonNode->addAnimation(1, "gun-grab", false, 2);
        skeletonNode->setTwoColorTint(true);

        ntfEffect.setCenterY(200);
        swirlTime = 0;

        skeletonNode->setVertexEffect(&ntfEffect);

        skeletonNode->setPosition(Vec2(_contentSize.width / 2 + i * 5, 145 - i * 5));
        addChild(skeletonNode);
    }

    scheduleUpdate();
    
    EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = [this] (Touch* touch, cocos2d::Event* event) -> bool {
        static int index = 0;
        std::string animations[] = {
            "avatar",
            "beach_sitted",
            "enlarge",
            "enter_pool",
            "gym_meditate",
            "hold_both",
            "hold_left",
            "hold_right",
            "mj_five",
            "mj_four",
            "mj_one",
            "mj_three",
            "mj_two",
            "normal",
            "normal_picked",
            "normal_sit",
            "normal_sitted",
            "normal_sitted_listen",
            "normal_stand",
            "normal_stand_listen",
            "normal_stand_scratch",
            "player_sit",
            "room_drum",
            "room_guitar_low",
            "room_guitar_right",
            "room_piano",
            "sitted_lazysofa",
            "sitted_motorcycle",
            "sitted_tent",
            "stand_pool",
            "test"
        };
        index %= 31;
        std::string currentAni = animations[index];
        cout << currentAni << endl;
        index ++;
        skeletonNode->setAnimation(0, currentAni, true);
        
        return true;
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    return true;
}

void NTFExample::update(float fDelta) {
//    swirlTime += fDelta;
//    float percent = spine::MathUtil::fmod(swirlTime, 2);
//    if (percent > 1) percent = 1 - (percent - 1);
//    ntfEffect.setAngle(ntfPow2.interpolate(-60.0f, 60.0f, percent));
}


