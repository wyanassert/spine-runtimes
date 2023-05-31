//
//  NFTExample.h
//  SpineExample
//
//  Created by wyan on 2023/5/31.
//  Copyright © 2023 Craig Hinrichs. All rights reserved.
//

#import "cocos2d.h"
#import <spine/spine-cocos2d-objc.h>

NS_ASSUME_NONNULL_BEGIN

@interface NFTExample : CCNode {
    SkeletonAnimation* skeletonNode;
}

+ (CCScene*) scene;

@end

NS_ASSUME_NONNULL_END
