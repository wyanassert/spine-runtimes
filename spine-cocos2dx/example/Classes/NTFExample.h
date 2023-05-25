//
//  NTFExample.hpp
//  spine-cocos2d-x
//
//  Created by wyan on 2023/5/25.
//

#ifndef NTFExample_hpp
#define NTFExample_hpp

#include "cocos2d.h"
#include <spine/spine-cocos2dx.h>

class NTFExample : public cocos2d::LayerColor {
public:
    static cocos2d::Scene* scene ();

    CREATE_FUNC(NTFExample);

    virtual bool init ();
    
    virtual void update(float fDelta);

private:
    spine::SkeletonAnimation* skeletonNode;
    float swirlTime;
};

#endif /* NTFExample_hpp */
