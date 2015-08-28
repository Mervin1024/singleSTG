//
//  OperationView.h
//  singleSTG
//
//  Created by sh219 on 15/8/27.
//  Copyright (c) 2015年 sh219. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SteeringWheel.h"
@class KeyButton,OperationView;
@protocol OperationViewDelegate <NSObject>

- (void)operationView:(OperationView *)operationView steeringWheelDirection:(double)angle;

@end

@interface OperationView : UIView

@property (strong, nonatomic) SteeringWheel *wheel;
@property (strong, nonatomic) KeyButton *pauseButton;
@property (strong, nonatomic) KeyButton *shotButton;
@property (strong, nonatomic) KeyButton *actionButton;
@property (strong, nonatomic) KeyButton *slowButton;

- (instancetype)initWithSuperView:(UIView *)view andViewController:(UIViewController *)viewController;
@property (weak, nonatomic) id <OperationViewDelegate> delegate;
@end

@interface KeyButton : UIButton

- (instancetype)initWithFrame:(CGRect)frame title:(NSString *)title titleColor:(UIColor *)titleColor backgroundColor:(UIColor *)backColor image:(UIImage *)image;
+ (instancetype)buttonWithFrame:(CGRect)frame title:(NSString *)title titleColor:(UIColor *)titleColor backgroundColor:(UIColor *)backColor image:(UIImage *)image;
// titleColor = blackColor  backgroundColor = orangeColor
- (instancetype)initWithFrame:(CGRect)frame title:(NSString *)title image:(UIImage *)image;


- (void)restore;

@property (copy, nonatomic) NSDictionary *restoreDic;
@end