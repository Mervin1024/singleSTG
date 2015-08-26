//
//  airframe.h
//  singleSTG
//
//  Created by sh219 on 15/8/25.
//  Copyright (c) 2015年 sh219. All rights reserved.
//

#import "SportsSpirit.h"

//typedef NS_ENUM(NSInteger, AirframeType) {
//    // 自机
//    AirframeTypePlayer,
//    // Boss
//    AirframeTypeBoss,
//    // 大妖精
//    AirframeTypeYousei,
//    // 大蝴蝶
//    AirframeTypeButterfly,
//    // 鬼火
//    AirframeTypeWildfire
//};

// 判定点大小
//typedef NS_ENUM(NSInteger, AirframeDetectionType) {
//    // 自机-默认大小
//    AirframeDetectionTypeNormalP,
//    // 自机-缩小型
//    AirframeDetectionTypeMiniP,
//    // 自机-放大型
//    AirframeDetectionTypeLargeP,
//    // 自机-擦单半径
//    AirframeDetectionTypePassBulletP,
//    // BOSS-中弹判定
//    AirframeDetectionTypeShotE,
//};

@class Bullet,Airframe;
@protocol AirframeDelegate <NSObject>

- (Airframe *)objectWillCollidedWithAirframe:(Airframe *)airframe;
// 碰撞时方法回调
- (void)airframe:(Airframe *)airframe didCollidedWithAirframe:(id)object;
// 跃出屏幕时方法回调
- (void)airframe:(Airframe *)airframe didOverScreenWithCenter:(CGPoint)center;

@end

@interface Airframe : SportsSpirit

@property (assign, nonatomic, readonly) CGFloat detectionRadius; // 中弹检测半径
@property (assign, nonatomic, readonly) CGFloat operationRadius; // 体术检测半径

- (instancetype)initWithCenter:(CGPoint)center
               detectionRadius:(CGFloat)detectionRadius
               operationRadius:(CGFloat)operationRadius
                         image:(UIImage *)image;

@property (weak, nonatomic) id<AirframeDelegate> delegate;
@end
