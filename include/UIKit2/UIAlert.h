/*
 *     Generated by class-dump 3.1.2.
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2007 by Steve Nygard.
 */

#import <UIKit/UIAlert.h>

@class UIPushButton;

@interface UIActionSheet (Private)
+ (CGSize)minimumSize;
+ (id)_popupAlertBackground;
- (id)initWithTitle:(id)fp8 buttons:(id)fp12 defaultButtonIndex:(int)fp16 delegate:(id)fp20 context:(id)fp24;
- (BOOL)requiresPortraitOrientation;
- (int)_currentOrientation;
- (void)_setAlertSheetStyleFromButtonBar:(id)fp8;
- (id)buttons;
- (void)_createTitleLabelIfNeeded;
- (void)_createSubtitleLabelIfNeeded;
- (void)_createBodyTextLabelIfNeeded;
- (void)_createTaglineTextLabelIfNeeded;
- (void)_setupTitleStyle;
@property(retain) NSString* bodyText;
@property(retain) NSString* subtitle;
- (void)setTaglineText:(id)fp8;
@property(assign) int titleMaxLineCount;
@property(assign,getter=bodyMaxLineCount) int bodyTextMaxLineCount;
- (id)addTextFieldWithValue:(id)fp8 label:(id)fp12;
- (id)textFieldAtIndex:(int)fp8;
- (int)textFieldCount;
- (id)textField;
- (void)_alertSheetTextFieldReturn:(id)fp8;
- (id)keyboard;
@property(assign) UIPushButton* defaultButton;
@property(assign) UIPushButton* destructiveButton;
- (UIPushButton*)_addButtonWithTitle:(NSString*)fp8 label:(id)fp12 buttonClass:(Class)fp16;
- (UIPushButton*)addButtonWithTitle:(NSString*)fp8 label:(id)fp12;
- (UIPushButton*)_addButtonWithTitle:(NSString*)fp8;
- (UIPushButton*)addButtonWithTitle:(NSString*)fp8 buttonClass:(Class)fp12;
- (int)buttonCount;
@property(retain) id context;
- (void)_buttonClicked:(id)fp8;
- (void)_cleanupAfterPopupAnimation;
@property(assign) BOOL tableShouldShowMinimumContent;
- (id)table;
- (BOOL)_needsKeyboard;
@property(assign) BOOL showsOverSpringBoardAlerts;
- (void)_performPopup:(BOOL)fp8;
- (void)_growAnimationDidStop:(id)fp8 finished:(id)fp12;
- (void)_bubbleAnimationShrinkDidStop:(id)fp8 finished:(id)fp12;
- (void)_bubbleAnimationNormalDidStop:(id)fp8 finished:(id)fp12;
- (BOOL)_isAnimating;
- (void)_popoutAnimationDidStop:(id)fp8 finished:(id)fp12;
- (void)_performPopoutAnimationAnimated:(BOOL)fp8;
- (void)_repopup;
- (BOOL)_dimsBackground;
- (BOOL)_canShowAlerts;
- (void)_removeAlertWindowOrShowAnOldAlert;
- (void)_temporarilyHideAnimated:(BOOL)fp8;
- (void)_setupInitialFrame;
- (void)_rotatingAnimationDidStop:(id)fp8;
- (void)layoutAnimated:(BOOL)fp8;
- (BOOL)isBodyTextTruncated;
- (void)_layoutPopupAlertWithOrientation:(int)fp8 animated:(BOOL)fp12;
- (void)_layoutIfNeeded;
- (void)_adjustLabelFontSizes;
- (void)popupAlertAnimated:(BOOL)fp8 atOffset:(float)fp12;
- (void)popupAlertAnimated:(BOOL)fp8;
- (void)_presentSheetFromView:(id)fp8 above:(BOOL)fp12;
- (void)presentSheetFromBehindView:(id)fp8;
- (void)presentSheetFromAboveView:(id)fp8;
- (void)presentSheetInView:(id)fp8;
- (void)presentSheetToAboveView:(id)fp8;
- (void)setDimView:(id)fp8;
- (id)_dimView;
- (void)_presentSheetStartingFromYCoordinate:(double)fp8;
- (void)_slideSheetOut:(BOOL)fp8;
- (void)dismiss;
- (void)dismissAnimated:(BOOL)fp8;
- (struct CGSize)backgroundSize;
- (float)_titleVerticalTopInset;
- (float)_titleVerticalBottomInset;
- (float)_titleHorizontalInset;
- (float)_bottomVerticalInset;
- (void)drawRect:(struct CGRect)fp8;
- (void)_appSuspended:(id)fp8;
- (void)_alertSheetAnimationDidStop:(id)fp8 finished:(id)fp12;
@property(assign) int numberOfRows;
@property(assign) int alertSheetStyle;
@property(assign) BOOL dimsBackground;
@property(assign) int suspendTag;
@property(assign) BOOL blocksInteraction;
@property(assign) BOOL runsModal;
@property(assign,readonly) CGRect titleRect;
- (float)_maxHeight;
- (float)_buttonHeight;
- (void)layout;
- (void)presentSheetFromButtonBar:(id)fp8;
@end


@interface UIAlertView (Private)
@property(assign) BOOL runsModal;
@property(assign) int numberOfRows;
@end
