//
//  OSFileBrowserAppearanceConfigs.h
//  FileBrowser
//
//  Created by xiaoyuan on 20/11/2017.
//  Copyright © 2017 xiaoyuan. All rights reserved.
//

#ifndef OSFileBrowserAppearanceConfigs_h
#define OSFileBrowserAppearanceConfigs_h

#define OSSwizzleInstanceMethod(class, originalSEL, swizzleSEL) {\
    Method originalMethod = class_getInstanceMethod(class, originalSEL);\
    Method swizzleMethod = class_getInstanceMethod(class, swizzleSEL);\
    BOOL didAddMethod = class_addMethod(class, originalSEL, method_getImplementation(swizzleMethod), method_getTypeEncoding(swizzleMethod));\
    if (didAddMethod) {\
        class_replaceMethod(class, swizzleSEL, method_getImplementation(originalMethod), method_getTypeEncoding(originalMethod));\
    }\
    else {\
        method_exchangeImplementations(originalMethod, swizzleMethod);\
    }\
}

#define dispatch_main_safe_async(block)\
    if ([NSThread isMainThread]) {\
        block();\
    } else {\
        dispatch_async(dispatch_get_main_queue(), block);\
    }

#define kFileViewerGlobleColor [UIColor colorWithRed:36/255.0 green:41/255.0 blue:46/255.0 alpha:1.0]

#endif /* OSFileBrowserAppearanceConfigs_h */

@import Foundation;

FOUNDATION_EXPORT NSNotificationName const OSFileBrowserAppearanceConfigsSortTypeDidChangeNotification;

FOUNDATION_EXPORT NSNotificationName const OSFileCollectionViewControllerOptionFileCompletionNotification;
FOUNDATION_EXPORT NSNotificationName const OSFileCollectionViewControllerOptionSelectedFileForCopyNotification;
FOUNDATION_EXPORT NSNotificationName const OSFileCollectionViewControllerOptionSelectedFileForMoveNotification;
FOUNDATION_EXPORT NSNotificationName const OSFileCollectionViewControllerNeedOpenDownloadPageNotification;
FOUNDATION_EXPORT NSNotificationName const OSFileCollectionViewControllerDidMarkupFileNotification;

typedef NS_ENUM(NSInteger, OSFileBrowserSortType) {
    OSFileBrowserSortTypeOrderA_To_Z, // 按照字母a-z的排序方式
    OSFileBrowserSortTypeOrderLatestTime, // 按最新时间排序
};

typedef NS_ENUM(NSInteger, OSFileCollectionViewControllerMode) {
    OSFileCollectionViewControllerModeDefault, // 默认模式
    OSFileCollectionViewControllerModeEdit,    // 编辑模式
    OSFileCollectionViewControllerModeCopy,    // 复制模式，此控制器的rootDirectory为最终复制的目录
    OSFileCollectionViewControllerModeMove,    // 移动模式，此控制器的rootDirectory为最终移动的目录
    
};

@interface OSFileBrowserAppearanceConfigs : NSObject

@property (nonatomic, class) OSFileBrowserSortType fileSortType;

@end
