//
//  NZAssetsLibrary.h
//  NZAssetsLibrary
//
//  Created by Bruno Furtado on 12/12/13.
//  Copyright (c) 2013 No Zebra Network. All rights reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import <AssetsLibrary/AssetsLibrary.h>
#import "NZAssetImageFile.h"

typedef void(^SaveImageCompletion)(NSError* error);
typedef void(^LoadImagesCallback)(NSArray<NZAssetImageFile> *items, NSError *error);



@interface NZAssetsLibrary : ALAssetsLibrary

+ (NZAssetsLibrary *)defaultAssetsLibrary;

- (instancetype) init
__attribute__((unavailable("[-init] is not allowed, use [+defaultAssetsLibrary]")));

- (void)addAssetURL:(NSURL *)assetURL
            toAlbum:(NSString *)albumName
     withCompletion:(SaveImageCompletion)completion;

- (void)deleteImageAtPath:(NSString *)path;

- (void)loadAssetsFromAlbum:(NSString *)albumName
               withCallback:(LoadImagesCallback)callback;

- (NSArray<NZAssetImageFile> *)loadImagesFromDocumentDirectory;

- (void)saveImage:(UIImage *)image
          toAlbum:(NSString *)albumName
   withCompletion:(SaveImageCompletion)completion;

- (void)saveJPGImageAtDocumentDirectory:(UIImage *)image;

- (void)savePNGImageAtDocumentDirectory:(UIImage *)image;

@end