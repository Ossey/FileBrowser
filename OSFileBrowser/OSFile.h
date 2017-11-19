//
//  OSFile.h
//  FileBrowser
//
//  Created by xiaoyuan on 05/08/2014.
//  Copyright © 2014 xiaoyuan. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef enum {
    OSFileFlagsArchived         = 0x01,
    OSFileFlagsHidden           = 0x02,
    OSFileFlagsNoDump           = 0x04,
    OSFileFlagsOpaque           = 0x08,
    OSFileFlagsSystemAppendOnly = 0x10,
    OSFileFlagsSystemImmutable  = 0x20,
    OSFileFlagsUserAppendOnly   = 0x40,
    OSFileFlagsUserImmutable    = 0x80
}
OSFileFlags;

@interface OSFile : NSObject {
@protected
    
    BOOL            _isDirectory;
    BOOL            _isRegularFile;
    BOOL            _isSymbolicLink;
    BOOL            _isSocket;
    BOOL            _isCharacterSpecial;
    BOOL            _isBlockSpecial;
    BOOL            _isUnknown;
    BOOL            _isImmutable;
    BOOL            _isAppendOnly;
    BOOL            _isBusy;
    BOOL            _extensionIsHidden;
    BOOL            _isReadable;
    BOOL            _isWriteable;
    BOOL            _isExecutable;
    BOOL            _isImage;
    BOOL            _isAudio;
    BOOL            _isVideo;
    BOOL            _isArchive;
    BOOL            _isWindows;
    OSFileFlags     _flags;
    NSUInteger      _size;
    NSUInteger      _referenceCount;
    NSUInteger      _deviceIdentifier;
    NSUInteger      _ownerID;
    NSUInteger      _groupID;
    NSUInteger      _permissions;
    NSUInteger      _octalPermissions;
    NSUInteger      _systemNumber;
    NSUInteger      _systemFileNumber;
    NSUInteger      _HFSCreatorCode;
    NSUInteger      _HFSTypeCode;
    NSUInteger      _numberOfSubFiles;
    NSString      * _path;
    NSString      * _filename;
    NSString      * _displayName;
    NSString      * _fileExtension;
    NSString      * _parentDirectoryPath;
    NSString      * _type;
    NSString      * _humanReadableSize;
    NSString      * _owner;
    NSString      * _group;
    NSString      * _humanReadablePermissions;
    NSDate        * _creationDate;
    NSDate        * _modificationDate;
    UIImage       * _icon;
    NSDictionary  * _attributes;
    NSFileManager * _fileManager;
    OSFile        * _targetFile;
    BOOL            _hideDisplayFiles;
    NSString      * _mimeType;
@private
    
    id __OSFile_Reserved[ 5 ] __attribute__((unused));
}


@property (atomic, readonly) BOOL          isDirectory;
@property (atomic, readonly) BOOL          isRegularFile;
@property (atomic, readonly) BOOL          isSymbolicLink;
@property (atomic, readonly) BOOL          isSocket;
@property (atomic, readonly) BOOL          isCharacterSpecial;
@property (atomic, readonly) BOOL          isBlockSpecial;
@property (atomic, readonly) BOOL          isUnknown;
@property (atomic, readonly) BOOL          isImmutable;
@property (atomic, readonly) BOOL          isAppendOnly;
@property (atomic, readonly) BOOL          isBusy;
@property (atomic, readonly) BOOL          extensionIsHidden;
@property (atomic, readonly) BOOL          isReadable;
@property (atomic, readonly) BOOL          isWriteable;
@property (atomic, readonly) BOOL          isExecutable;
@property (atomic, readonly) BOOL          isImage;
@property (atomic, readonly) BOOL          isAudio;
@property (atomic, readonly) BOOL          isVideo;
@property (atomic, readonly) BOOL          isArchive;
@property (atomic, readonly) BOOL          isWindows;
@property (atomic, readonly) OSFileFlags   flags;
@property (atomic, readonly) NSUInteger    size;
@property (atomic, readonly) NSUInteger    referenceCount;
@property (atomic, readonly) NSUInteger    deviceIdentifier;
@property (atomic, readonly) NSUInteger    ownerID;
@property (atomic, readonly) NSUInteger    groupID;
@property (atomic, readonly) NSUInteger    permissions;
@property (atomic, readonly) NSUInteger    octalPermissions;
@property (atomic, readonly) NSUInteger    systemNumber;
@property (atomic, readonly) NSUInteger    systemFileNumber;
@property (atomic, readonly) NSUInteger    HFSCreatorCode;
@property (atomic, readonly) NSUInteger    HFSTypeCode;
@property (atomic, readonly) NSUInteger    numberOfSubFiles;
@property (atomic, readonly) NSString    * path;
@property (atomic, readonly) NSString    * filename;
@property (atomic, readonly) NSString    * displayName;
@property (atomic, readonly) NSString    * fileExtension;
@property (atomic, readonly) NSString    * parentDirectoryPath;
@property (atomic, readonly) NSString    * type;
@property (atomic, readonly) NSString    * owner;
@property (atomic, readonly) NSString    * group;
@property (atomic, readonly) NSString    * humanReadableSize;
@property (atomic, readonly) NSString    * humanReadablePermissions;
@property (atomic, readonly) NSDate      * creationDate;
@property (atomic, readonly) NSDate      * modificationDate;
@property (atomic, readonly) UIImage     * icon;
@property (atomic, readonly) OSFile      * targetFile;
@property (atomic, readwrite) NSArray     * subFiles;
@property (atomic, readonly) BOOL          hideDisplayFiles;
@property (atomic, readonly) NSString    * mimeType;

/// 初始化方法，根据文件路径创建一个OSFile对象
/// @param filePath 文件完整路径
/// @param hideDisplayFiles 是否显示隐藏文件，默认显示的,
/// @param error 返回错误信息
/// @return OSFile对象，当文件不存在获取读取文件失败时，return nil
+ (instancetype)fileWithPath:(NSString *)filePath hideDisplayFiles:(BOOL)hideDisplayFiles error:(NSError *__autoreleasing *)error;
- (instancetype)initWithPath:(NSString *)filePath hideDisplayFiles:(BOOL)hideDisplayFiles error:(NSError *__autoreleasing *)error;
- (instancetype)initWithPath:(NSString *)filePath error:(NSError *__autoreleasing *)error;
+ (instancetype)fileWithPath:(NSString *)filePath;
+ (instancetype)fileWithPath:(NSString *)filePath error:(NSError *__autoreleasing *)error;

/// 重新加载当前文件文件，对象不会改变，但会重新获取文件的结果，
/// @param error 返回错误信息
/// @return 如果当前文件不存在了，会返回NO
- (BOOL)reloadFileWithError:(NSError *__autoreleasing *)error;
- (BOOL)reloadFile;
/// 加载一个新的文件路径，对象不会改变，如果当前文件不存在了，会返回NO
/// @param filePath 需要加载的路径
/// @param error 返回错误信息
/// @return 如果当前文件不存在了，会返回NO
- (BOOL)reloadFileWithPath:(NSString *)filePath error:(NSError *__autoreleasing *)error;

@end

