/*
 
 layout.m ... Layout classes for MultiTap input method.
 
 Copyright (c) 2009, KennyTM~
 All rights reserved.
 
 Redistribution and use in source and binary forms, with or without modification,
 are permitted provided that the following conditions are met:
 
 * Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright notice, 
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.
 * Neither the name of the KennyTM~ nor the names of its contributors may be
   used to endorse or promote products derived from this software without
   specific prior written permission.
 
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 
 */

#import "layout.h"
#import <UIKit2/Constants.h>
#import <UIKit2/UIKeyboardSublayout.h>
#import <iKeyEx/common.h>
#import <UIKit/UIImageView.h>

BOOL layoutWillEnableManager = YES;

#define SublayoutTypeAlert   UIKeyboardLayoutPhonePadTransparent
#define SublayoutTypeDefault UIKeyboardLayoutPhonePad
#define buildSublayoutTypeAlert   buildUIKeyboardLayoutPhonePadTransparent
#define buildSublayoutTypeDefault buildUIKeyboardLayoutPhonePad

#define ImplementSublayoutBuilderX(name,keyboardType,isLandscape) \
-(UIKeyboardSublayout*)buildUIKeyboardLayout##name { return [self buildSublayoutType##keyboardType]; }

#define ImplementSublayoutBuilder(name,isLandscape) \
ImplementSublayoutBuilderX(name,Default,isLandscape); \
ImplementSublayoutBuilderX(name##Transparent,Alert,isLandscape)

#define keyboardHeightLandscapeYES 162
#define keyboardWidthLandscapeYES  480
#define keyboardHeightLandscapeNO  320
#define keyboardWidthLandscapeNO   216

// disable the input manager when the user is in Alt modes. 
#define ImplementShowKeyboardTypeForKey(isLandscape) \
-(void)showKeyboardTypeForKey:(NSString*)key { \
	[super showKeyboardTypeForKey:key]; \
	layoutWillEnableManager = ( \
		key == UIKeyboardLayoutMain || \
		key == UIKeyboardLayoutAlphabet || \
		key == UIKeyboardLayoutURL || \
		key == UIKeyboardLayoutSMSAddressing || \
		key == UIKeyboardLayoutEmailAddress || \
		key == UIKeyboardLayoutAlphabetTransparent || \
		key == UIKeyboardLayoutURLTransparent || \
		key == UIKeyboardLayoutSMSAddressingTransparent || \
		key == UIKeyboardLayoutEmailAddressTransparent \
	); \
	if (layoutWillEnableManager) { \
		[[self activeSublayout] addInternationalKeyIfNeeded:UIKeyboardLayoutPhonePadTransparent]; \
	} else if (key == UIKeyboardLayoutSMSAddressingAlt || key == UIKeyboardLayoutSMSAddressingAltTransparent) { \
		[[self activeSublayout] addInternationalKeyIfNeeded:UIKeyboardLayoutNumbersTransparent]; \
	} \
}

@implementation MultiTapLayout
ImplementSublayoutBuilder(Alphabet,NO);
ImplementSublayoutBuilder(URL,NO);
ImplementSublayoutBuilder(SMSAddressing,NO);
ImplementSublayoutBuilder(EmailAddress,NO);
ImplementShowKeyboardTypeForKey(NO);
@end

@implementation MultiTapLayoutLandscape
ImplementSublayoutBuilder(Alphabet,YES);
ImplementSublayoutBuilder(URL,YES);
ImplementSublayoutBuilder(SMSAddressing,YES);
ImplementSublayoutBuilder(EmailAddress,YES);
ImplementShowKeyboardTypeForKey(YES);
@end