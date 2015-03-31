//
//  APNumberPad.h
//
//  Created by Andrew Podkovyrin on 16/05/14.
//  Copyright (c) 2014 Podkovyrin. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "APNumberPadStyle.h"

@protocol APNumberPadDelegate;

///

@interface APNumberPad : UIView <UIInputViewAudioFeedback>

+ (instancetype)numberPadWithDelegate:(id<APNumberPadDelegate>)delegate numberPadStyleClass:(Class)styleClass;

+ (instancetype)numberPadWithDelegate:(id<APNumberPadDelegate>)delegate;



/**
 *  Array of APNumberButton
 */
@property (copy, readwrite, nonatomic) NSArray *numberButtons;

@property BOOL timeInput;

//-(void)timeStringKeypadHandler:(NSString*)timeString;
-(void)configureKeypadFor:(NSString*)keypadType;
//-(void)timeStringKeypadHandler:(NSString*)timeString;

/**
 *  Left function button for custom configuration
 */
@property (strong, readonly, nonatomic) UIButton *leftFunctionButton;

/**
 *  The class to use for styling the number pad
 */
@property (strong, readonly, nonatomic) Class<APNumberPadStyle> styleClass;

@end

///

@protocol APNumberPadDelegate <NSObject>

@optional

- (void)numberPad:(APNumberPad *)numberPad functionButtonAction:(UIButton *)functionButton textInput:(UIResponder<UITextInput> *)textInput;
- (void)numberPad:(APNumberPad *)numberPad numberButtonAction:(UIButton *)numberButton textInput:(UIResponder<UITextInput> *)textInput;



@end
