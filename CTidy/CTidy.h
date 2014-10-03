//
//  CTidy.h
//  TouchCode
//
//  Created by Jonathan Wight on 03/07/08.
//  Copyright 2011 toxicsoftware.com. All rights reserved.
//
//  Redistribution and use in source and binary forms, with or without modification, are
//  permitted provided that the following conditions are met:
//
//     1. Redistributions of source code must retain the above copyright notice, this list of
//        conditions and the following disclaimer.
//
//     2. Redistributions in binary form must reproduce the above copyright notice, this list
//        of conditions and the following disclaimer in the documentation and/or other materials
//        provided with the distribution.
//
//  THIS SOFTWARE IS PROVIDED BY TOXICSOFTWARE.COM ``AS IS'' AND ANY EXPRESS OR IMPLIED
//  WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
//  FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL TOXICSOFTWARE.COM OR
//  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
//  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
//  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
//  ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
//  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
//  ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//  The views and conclusions contained in the software and documentation are those of the
//  authors and should not be interpreted as representing official policies, either expressed
//  or implied, of toxicsoftware.com.

#import <Foundation/Foundation.h>

#include "tidy.h"
#include "buffio.h"

typedef enum {
	CTidyFormatHTML,
	CTidyFormatXML,
	CTidyFormatXHTML,
} CTidyFormat;

// TODO: create constant values for acceptable encoding values.

/** ObjC class wrapper for libtidy.
  * 
  * The character encoding should be from the set of:
  * ascii, latin1, raw, utf8, iso2022, mac, win1252, utf16le, utf16be, utf16, big5 and shiftjis.  Case in-sensitive. */
@interface CTidy : NSObject { }

+ (CTidy *)tidy;

- (NSData *)tidyData:(NSData *)inData
         inputFormat:(CTidyFormat)inInputFormat
        outputFormat:(CTidyFormat)inOutputFormat
            encoding:(NSString*)inEncoding
configurationHandler:(void (^)(TidyDoc doc))configHandler
         diagnostics:(NSString **)outDiagnostics
               error:(NSError **)outError;

- (NSString *)tidyString:(NSString *)inString
             inputFormat:(CTidyFormat)inInputFormat
            outputFormat:(CTidyFormat)inOutputFormat
                encoding:(NSString*)inEncoding
    configurationHandler:(void (^)(TidyDoc doc))configHandler
             diagnostics:(NSString **)outDiagnostics
                   error:(NSError **)outError;

- (NSString *)tidyHTMLString:(NSString *)inString
                    encoding:(NSString *)inEncoding
        configurationHandler:(void (^)(TidyDoc doc))configHandler
                       error:(NSError **)outError;
@end

