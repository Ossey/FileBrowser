//
//  OSFileAttributeItem.h
//  FileBrowser
//
//  Created by xiaoyuan on 05/08/2014.
//  Copyright © 2014 xiaoyuan. All rights reserved.
//

#import "OSFile.h"

typedef NS_ENUM(NSInteger, OSFileAttributeItemStatus) {
    /// 默认状态
    OSFileAttributeItemStatusDefault,
    /// 编辑状态
    OSFileAttributeItemStatusEdit,
    /// 被标记状态
    OSFileAttributeItemStatusChecked
};

@interface OSFileAttributeItem : OSFile

@property (nonatomic, copy) NSString *fullPath;
@property (nonatomic, assign) OSFileAttributeItemStatus status;

@end

