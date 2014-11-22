/*
 
 common.h ... Miscellaneous functions for iKeyEx.
 
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

#ifndef H_iKeyEx_common
#define H_iKeyEx_common

#import <objc/runtime.h>
#import <CoreGraphics/CGGeometry.h>


@class UIFont, NSString, UIView, NSDictionary;


#define UIColorWith(x) [UIColor colorWithRed:(x)[0] green:(x)[1] blue:(x)[2] alpha:(x)[3]]

#define iKeyEx_Prefix @"iKeyEx:"
#define iKeyEx_Prefix_length 7
#define iKeyEx_KeyboardsPath @"/Library/iKeyEx/Keyboards/"

// Store all your data in this directory to allow R/W from sandboxes applications.
#define iKeyEx_DataDirectory @"/var/mobile/Library/Keyboard/"
#define iKeyEx_DataPrefix iKeyEx_Prefix
#define iKeyEx_DataPath iKeyEx_DataDirectory iKeyEx_DataPrefix
#define iKeyEx_CachePrefix iKeyEx_Prefix@":cache:"
#define iKeyEx_CachePath iKeyEx_DataDirectory iKeyEx_CachePrefix
#define iKeyEx_InternalCachePrefix iKeyEx_CachePrefix@":iKeyEx:"
#define iKeyEx_InternalCachePath iKeyEx_DataDirectory iKeyEx_InternalCachePrefix

#define iKeyEx_KeyboardChooser iKeyEx_Prefix@"__KeyboardChooser"

// draw text in the center of the rectangle.
// The text size will be rescale to fit inside the rectangle totally.
void drawInCenter(NSString* str, CGRect rect, UIFont* defaultFont);
void drawInCenterWithTraits(NSDictionary* strtraits, CGRect rect, UIFont* defaultFont);

// create a new objective-C subclass that has a new automatically assigned
// thread-wise unique name.
Class createSubclassCopy (Class superclass);


// Play the keyboard "click" sound, if enabled.
void playKeyboardSound();


// Get version of this iKeyEx library.
NSString* iKeyExVersion();


// Run an iKeyEx-KBMan command
void iKeyEx_KBMan(const char* command, const char* arg);

#endif