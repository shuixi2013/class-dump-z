/*

GPPreferences.h ... Obtain preferences for GriP.
 
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

#ifndef GRIP_GPPreferences_H
#define GRIP_GPPreferences_H

#ifdef __cplusplus
extern "C" {
#endif
	
#include <CoreFoundation/CoreFoundation.h>
	
#if __OBJC__
#include <Foundation/Foundation.h>
	@class UIColor;
	NSDictionary* GPCopyPreferences();
	void GPFlushPreferences();
		
	void GPUpdateRegistrationDictionaryForAppName(NSString* appName, NSDictionary* registrationDictionary);
	void GPModifyMessageForUserPreference(NSMutableDictionary* message);
		
	BOOL GPCheckEnabled(NSString* appName, NSString* msgName, BOOL respectStealth);
	
//#define GPPreferences() [GPCopyPreferences() autorelease]
#else
	typedef struct UIColor UIColor;
	
	CFDictionaryRef GPCopyPreferences();
	void GPFlushPreferences();
	
	void GPUpdateRegistrationDictionaryForAppName(CFStringRef appName, CFDictionaryRef registrationDictionary);
	void GPModifyMessageForUserPreference(CFMutableDictionaryRef message);
	
	Boolean GPCheckEnabled(CFStringRef appName, CFStringRef msgName, Boolean respectStealth);	
#endif
	
	void GPCopyColorsForPriority(int priority, UIColor** restrict outBGColor, UIColor** restrict outFGColor);
	
#ifdef __cplusplus
}
#endif

#endif