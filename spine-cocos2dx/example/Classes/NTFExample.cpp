//
//  NTFExample.cpp
//  spine-cocos2d-x
//
//  Created by wyan on 2023/5/25.
//

#include "NTFExample.h"
#include "TankExample.h"
#include <spine/Extension.h>

USING_NS_CC;
using namespace spine;

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

    skeletonNode = SkeletonAnimation::createWithJsonFile("NFT_1.json", "NFT_1.atlas", 1.f);
    skeletonNode->setAnimation(0, "room_guitar_right", true);
//    skeletonNode->addAnimation(1, "gun-grab", false, 2);
    skeletonNode->setTwoColorTint(true);
    
    ntfEffect.setCenterY(200);
    swirlTime = 0;
    
    skeletonNode->setVertexEffect(&ntfEffect);

    skeletonNode->setPosition(Vec2(_contentSize.width / 2, 20));
    addChild(skeletonNode);

    scheduleUpdate();
    
    EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = [this] (Touch* touch, cocos2d::Event* event) -> bool {
        if (!skeletonNode->getDebugBonesEnabled()) {
            skeletonNode->setDebugBonesEnabled(true);
            skeletonNode->setDebugMeshesEnabled(true);
        } else if (skeletonNode->getTimeScale() == 1)
            skeletonNode->setTimeScale(0.3f);
        else
            Director::getInstance()->replaceScene(TankExample::scene());
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


