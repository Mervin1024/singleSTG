//
//  BulletShape.h
//  singleSTG
//
//  Created by sh219 on 15/8/25.
//  Copyright (c) 2015年 sh219. All rights reserved.
//

#import "SportsSpirit.h"

typedef NS_ENUM(NSUInteger, BulletShapeType) {
    // 鬼人正邪
    BulletShapeTypeKIJINSEIJA,
    // 小玉
    BulletShapeTypeSmallJade,
    
    // 椭弹
    BulletShapeTypeEllipse,
    
    // 大玉
    BulletShapeTypeLargeJade,
    
    // 中玉
    BulletShapeTypeMediumJade,
    
    // 米弹
    BulletShapeTypeRice,
    
    // 麟弹
    BulletShapeTypeFlake,
    
    // 刀弹
    BulletShapeTypeKnife,
    
    // 针弹
    BulletShapeTypeNeedle
    
};

typedef NS_ENUM(NSUInteger, BulletSource) {
    BulletSourceEnemy,
    BulletSourceFirendly
};

@class Bullet,Airframe;
@protocol BulletDelegate <NSObject>

- (Airframe *)objectWillCollidedWithBullet:(Bullet *)bullet;
- (BOOL)moveState;
// 碰撞时方法回调
- (void)bullet:(Bullet *)bullet didCollidedWithAirframe:(Airframe *)object;
// 跃出屏幕时方法回调
- (void)bullet:(Bullet *)bullet didOverScreenWithCenter:(CGPoint)center;

@end
//--------------------------

#pragma mark - Bullet
@interface Bullet : SportsSpirit

@property (assign, nonatomic) BulletSource bulletSource;
@property (assign, nonatomic) BulletShapeType bulletShapeType;
@property (assign, nonatomic) CGRect collisionZone;  // 碰撞检测区域

- (instancetype)initWithCenter:(CGPoint)center
                  bulletSource:(BulletSource)bulletSource
               bulletShapeType:(BulletShapeType)bulletShapeType;
+ (instancetype)bulletWithCenter:(CGPoint)center
                    bulletSource:(BulletSource)bulletSource
                 bulletShapeType:(BulletShapeType)bulletShapeType;

@property (weak, nonatomic) id <BulletDelegate> delegate;
@end
//---------------------------

#pragma mark - BulletSmallJade
@interface BulletSmallJade : NSObject

@property (assign, nonatomic, readonly) CGFloat diameter; // 圆的直径
@property (strong, nonatomic, readonly) UIImage *bulletImage;

@end
//---------------------------

#pragma mark - BulletEllipse
typedef NS_ENUM(NSInteger, BulletEllipseColor) {
    BulletEllipseColorBlue,
    BulletEllipseColorGreen,
};

@interface BulletEllipse : NSObject

@property (assign, nonatomic, readonly) CGFloat majorAxis; // 长轴 2a
@property (assign, nonatomic, readonly) CGFloat shortAxis; // 短轴 2b
@property (strong, nonatomic, readonly) UIImage *bulletImage;
@property (assign, nonatomic, readonly) BulletEllipseColor bulletEllipseColor;

- (instancetype)initWithBulletEllipseColor:(BulletEllipseColor)ellipseColor;

@end
#pragma mark - BulletKIJINSEIJA
typedef NS_ENUM(NSInteger, BulletKIJINSEIJAType) {
    BulletKIJINSEIJATypeMini,
    BulletKIJINSEIJATypeNormal,
    BulletKIJINSEIJATypeLarge
};

@interface BulletKIJINSEIJA : NSObject

@property (assign, nonatomic, readonly) CGFloat horizontalSide; // 水平边
@property (assign, nonatomic, readonly) CGFloat verticalSide; // 垂直边
@property (strong, nonatomic, readonly) UIImage *bulletImage;
@property (assign, nonatomic, readonly) BulletKIJINSEIJAType bulletKIJINSEIJAType;
@property (assign, nonatomic) NSUInteger times;

- (instancetype)initWithBulletKIJINSEIJAType:(BulletKIJINSEIJAType)KIJINSEIJAType;

@end
