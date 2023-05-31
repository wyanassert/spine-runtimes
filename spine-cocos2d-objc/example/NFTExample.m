//
//  NFTExample.m
//  SpineExample
//
//  Created by wyan on 2023/5/31.
//  Copyright © 2023 Craig Hinrichs. All rights reserved.
//

#import "NFTExample.h"

@implementation NFTExample

+ (CCScene*) scene {
    CCScene *scene = [CCScene node];
    [scene addChild:[NFTExample node]];
    return scene;
}

-(id) init {
    self = [super init];
    if (!self) return nil;

    skeletonNode = [SkeletonAnimation skeletonWithFile:@"NFT_1.json" atlasFile:@"NFT_1.atlas" scale:0.5];

    __weak SkeletonAnimation* node = skeletonNode;
    skeletonNode.twoColorTint = false;

    CGSize windowSize = [[CCDirector sharedDirector] viewSize];
    [skeletonNode setPosition:ccp(windowSize.width / 2, windowSize.height / 2 - 100)];
    [self addChild:skeletonNode];

    self.userInteractionEnabled = YES;
    self.contentSize = windowSize;

    return self;
}

#if ( TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR )
- (void)touchBegan:(UITouch *)touch withEvent:(UIEvent *)event {
    if (!skeletonNode.debugBones)
        skeletonNode.debugBones = true;
    else if (skeletonNode.timeScale == 1)
        skeletonNode.timeScale = 0.3f;
    
}
#endif

@end
