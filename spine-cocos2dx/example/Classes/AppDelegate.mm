/******************************************************************************
 * Spine Runtimes License Agreement
 * Last updated January 1, 2020. Replaces all prior versions.
 *
 * Copyright (c) 2013-2020, Esoteric Software LLC
 *
 * Integration of the Spine Runtimes into software or otherwise creating
 * derivative works of the Spine Runtimes is permitted under the terms and
 * conditions of Section 2 of the Spine Editor License Agreement:
 * http://esotericsoftware.com/spine-editor-license
 *
 * Otherwise, it is permitted to integrate the Spine Runtimes into software
 * or otherwise create derivative works of the Spine Runtimes (collectively,
 * "Products"), provided that each user of the Products must obtain their own
 * Spine Editor license and redistribution of the Products in any form must
 * include this license and copyright notice.
 *
 * THE SPINE RUNTIMES ARE PROVIDED BY ESOTERIC SOFTWARE LLC "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL ESOTERIC SOFTWARE LLC BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES,
 * BUSINESS INTERRUPTION, OR LOSS OF USE, DATA, OR PROFITS) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THE SPINE RUNTIMES, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *****************************************************************************/

#include "AppDelegate.h"

#include <vector>
#include <string>

#include "IKExample.h"
#include "NTFExample.h"
#include "GoblinsExample.h"
#include <spine/spine-cocos2dx.h>
#include <spine/Debug.h>
#include "AppMacros.h"
#import <WebKit/WKWebView.h>
#import <WebKit/WKWebViewConfiguration.h>

USING_NS_CC;
using namespace std;

using namespace spine;

DebugExtension debugExtension(SpineExtension::getInstance());

AppDelegate::AppDelegate () {
}

AppDelegate::~AppDelegate () {
	SkeletonBatch::destroyInstance();
	SkeletonTwoColorBatch::destroyInstance();
	debugExtension.reportLeaks();
}

bool AppDelegate::applicationDidFinishLaunching () {
	// initialize director
	auto director = Director::getInstance();
	auto glview = director->getOpenGLView();
	if (!glview) {
		GLContextAttrs attrs = { 8, 8, 8, 8, 0, 0 };
		GLView::setGLContextAttrs(attrs);
		glview = GLViewImpl::create("Spine Example");
		director->setOpenGLView(glview);
	}

	// Set the design resolution
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	// a bug in DirectX 11 level9-x on the device prevents ResolutionPolicy::NO_BORDER from working correctly
	glview->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, ResolutionPolicy::SHOW_ALL);
#else
	glview->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, ResolutionPolicy::NO_BORDER);
#endif

	cocos2d::Size frameSize = glview->getFrameSize();
	
	vector<string> searchPath;

	// In this demo, we select resource according to the frame's height.
	// If the resource size is different from design resolution size, you need to set contentScaleFactor.
	// We use the ratio of resource's height to the height of design resolution,
	// this can make sure that the resource's height could fit for the height of design resolution.
	if (frameSize.height > mediumResource.size.height) {
		// if the frame's height is larger than the height of medium resource size, select large resource.
		searchPath.push_back(largeResource.directory);
		director->setContentScaleFactor(MIN(largeResource.size.height/designResolutionSize.height, largeResource.size.width/designResolutionSize.width));
	} else if (frameSize.height > smallResource.size.height) {
		// if the frame's height is larger than the height of small resource size, select medium resource.
		searchPath.push_back(mediumResource.directory);
		director->setContentScaleFactor(MIN(mediumResource.size.height/designResolutionSize.height, mediumResource.size.width/designResolutionSize.width));
	} else {
		// if the frame's height is smaller than the height of medium resource size, select small resource.
		searchPath.push_back(smallResource.directory);
		director->setContentScaleFactor(MIN(smallResource.size.height/designResolutionSize.height, smallResource.size.width/designResolutionSize.width));
	}
	
	searchPath.push_back("common");
	 
	// set search path
	FileUtils::getInstance()->setSearchPaths(searchPath);
	
	// turn on display FPS
	director->setDisplayStats(true);

	// set FPS. the default value is 1.0/60 if you don't call this
	director->setAnimationInterval(2.0f / 60);

	// Set the Debug wrapper extension so we know about memory leaks.
	SpineExtension::setInstance(&debugExtension);
	
	// create a scene. it's an autorelease object
	//auto scene = RaptorExample::scene();
	auto scene = IKExample::scene();
//    auto scene = GoblinsExample::scene();
//    auto scene = NTFExample::scene();

	// run
	director->runWithScene(scene);
    
//    WKWebViewConfiguration *webConfiguration = [WKWebViewConfiguration new];
//    WKWebView *webView = [[WKWebView alloc] initWithFrame:[UIScreen mainScreen].bounds configuration:webConfiguration];
//    NSString *urlStr1 = @"https://fastest.y.qq.com/m/skelton_frames/index.html?_tde_id=18021&isTest=1&count=3&debug=1&ID=80066&Skeleton=skeleton_mfer&Features=skeleton_mfer-body-body-human_a-mfer_summer_longhair_human_1,skeleton_mfer-head-hair-hair_a-mfer_summer_longhair_hair_1,skeleton_mfer-head-eye-eye_a-mfer_summer_longhair_eye_7,skeleton_mfer-head-mouth-mouth_a-mfer_summer_longhair_mouth_3,skeleton_mfer-clothing-top-top_a-mfer_summer_longhair_top_16,skeleton_mfer-clothing-bottom-pants_a-mfer_summer_longhair_pants_1,skeleton_mfer-clothing-shoe-shoe_a-mfer_summer_longhair_shoe_2,skeleton_mfer-prop-guitar-guitar_a-bass";
//    NSString *urlStr2 = @"https://y.qq.com/m/skelton_frames/index.html?stay_anim=1&ID=80066&Skeleton=skeleton_mfer&Features=skeleton_mfer-body-body-human_a-mfer_summer_longhair_human_1,skeleton_mfer-head-hair-hair_a-mfer_summer_longhair_hair_1,skeleton_mfer-head-eye-eye_a-mfer_summer_longhair_eye_7,skeleton_mfer-head-mouth-mouth_a-mfer_summer_longhair_mouth_3,skeleton_mfer-clothing-top-top_a-mfer_summer_longhair_top_16,skeleton_mfer-clothing-bottom-pants_a-mfer_summer_longhair_pants_1,skeleton_mfer-clothing-shoe-shoe_a-mfer_summer_longhair_shoe_2,skeleton_mfer-prop-guitar-guitar_a-bass";
//    NSURL *url = [NSURL URLWithString:urlStr1];
//    NSURLRequest *request = [[NSURLRequest alloc] initWithURL:url];
//    [webView loadRequest:request];
//    UIWindow* window = [UIApplication sharedApplication].keyWindow;
//    if (!window) {
//        window = [[UIApplication sharedApplication].windows objectAtIndex:0];
//    }
//    [window addSubview:webView];
//
//    NSSet *websiteDataTypes = [WKWebsiteDataStore allWebsiteDataTypes];
//
//    NSDate *dateFrom = [NSDate dateWithTimeIntervalSince1970:0];
//
//    [[WKWebsiteDataStore defaultDataStore] removeDataOfTypes:websiteDataTypes modifiedSince:dateFrom completionHandler:^{
//
//    }];
    
    

	return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground () {
	Director::getInstance()->stopAnimation();

	// if you use SimpleAudioEngine, it must be paused
	// SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground () {
	Director::getInstance()->startAnimation();

	// if you use SimpleAudioEngine, it must resume here
	// SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
