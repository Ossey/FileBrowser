//
//  OSFileCollectionHeaderView.m
//  FileDownloader
//
//  Created by Swae on 2017/11/19.
//  Copyright © 2017年 Ossey. All rights reserved.
//

#import "OSFileCollectionHeaderView.h"
#import "UIImage+XYImage.h"

NSString * const OSFileCollectionHeaderViewDefaultIdentifier = @"UICollectionReusableView";

@interface OSFileCollectionHeaderView ()

@property (nonatomic, strong) UIButton *searchButton;
@property (nonatomic, strong) UIButton *changeStyleButton;

@end

@implementation OSFileCollectionHeaderView

- (instancetype)initWithFrame:(CGRect)frame {
    if (self = [super initWithFrame:frame]) {
        self.backgroundColor = [UIColor colorWithRed:31/255.0 green:31/255.0 blue:31/255.0 alpha:1.0];
        [self setupViews];
    }
    return self;
}

- (void)setupViews {
    [self addSubview:self.searchButton];
    [self addSubview:self.changeStyleButton];
    CGFloat iconWidth = 26.0;
    NSLayoutConstraint *searchBtnCenterY = [NSLayoutConstraint constraintWithItem:self.searchButton attribute:NSLayoutAttributeCenterY relatedBy:NSLayoutRelationEqual toItem:self attribute:NSLayoutAttributeCenterY multiplier:1.0 constant:0.0];
     NSLayoutConstraint *searchBtnLeft = [NSLayoutConstraint constraintWithItem:self.searchButton attribute:NSLayoutAttributeLeading relatedBy:NSLayoutRelationEqual toItem:self attribute:NSLayoutAttributeLeading multiplier:1.0 constant:10.0];
    NSLayoutConstraint *searchBtnWidth = [NSLayoutConstraint constraintWithItem:self.searchButton attribute:NSLayoutAttributeWidth relatedBy:NSLayoutRelationEqual toItem:nil attribute:NSLayoutAttributeNotAnAttribute multiplier:1.0 constant:iconWidth];
    NSLayoutConstraint *searchBtnHeight = [NSLayoutConstraint constraintWithItem:self.searchButton attribute:NSLayoutAttributeHeight relatedBy:NSLayoutRelationEqual toItem:nil attribute:NSLayoutAttributeNotAnAttribute multiplier:1.0 constant:iconWidth];
    [NSLayoutConstraint activateConstraints:@[searchBtnLeft, searchBtnWidth, searchBtnHeight, searchBtnCenterY]];
    
    NSLayoutConstraint *changeStyleBtnCenterY = [NSLayoutConstraint constraintWithItem:self.changeStyleButton attribute:NSLayoutAttributeCenterY relatedBy:NSLayoutRelationEqual toItem:self attribute:NSLayoutAttributeCenterY multiplier:1.0 constant:0.0];
    NSLayoutConstraint *changeStyleBtnRight = [NSLayoutConstraint constraintWithItem:self.changeStyleButton attribute:NSLayoutAttributeTrailing relatedBy:NSLayoutRelationEqual toItem:self attribute:NSLayoutAttributeTrailing multiplier:1.0 constant:-10.0];
    NSLayoutConstraint *changeStyleBtnWidth = [NSLayoutConstraint constraintWithItem:self.changeStyleButton attribute:NSLayoutAttributeWidth relatedBy:NSLayoutRelationEqual toItem:nil attribute:NSLayoutAttributeNotAnAttribute multiplier:1.0 constant:iconWidth];
    NSLayoutConstraint *changeStyleHeight = [NSLayoutConstraint constraintWithItem:self.changeStyleButton attribute:NSLayoutAttributeHeight relatedBy:NSLayoutRelationEqual toItem:nil attribute:NSLayoutAttributeNotAnAttribute multiplier:1.0 constant:iconWidth];
    [NSLayoutConstraint activateConstraints:@[changeStyleBtnRight, changeStyleBtnWidth, changeStyleHeight, changeStyleBtnCenterY]];
}


- (UIButton *)searchButton {
    if (!_searchButton) {
        _searchButton = [UIButton buttonWithType:UIButtonTypeCustom];
        static UIImage *searchImage = nil;
        static dispatch_once_t onceToken;
        dispatch_once(&onceToken, ^{
            searchImage = [[UIImage OSFileBrowserImageNamed:@"sortbar_search"] xy_changeImageColorWithColor:[UIColor whiteColor]];
        });
        [_searchButton setImage:searchImage forState:UIControlStateNormal];
        _searchButton.translatesAutoresizingMaskIntoConstraints = NO;
        [_searchButton addTarget:self action:@selector(searchButtonClick:) forControlEvents:UIControlEventTouchUpInside];
    }
    return _searchButton;
}

- (UIButton *)changeStyleButton {
    if (!_changeStyleButton) {
        _changeStyleButton = [UIButton buttonWithType:UIButtonTypeCustom];
        [_changeStyleButton addTarget:self action:@selector(changeStyleButtonClick:) forControlEvents:UIControlEventTouchUpInside];
        _changeStyleButton.translatesAutoresizingMaskIntoConstraints = NO;
        static UIImage *normalImage = nil;
        static UIImage *selectedImage = nil;
        static dispatch_once_t onceToken;
        dispatch_once(&onceToken, ^{
           normalImage = [[UIImage OSFileBrowserImageNamed:@"sortbar_grid_s"] xy_changeImageColorWithColor:[UIColor whiteColor]];
            selectedImage = [[UIImage OSFileBrowserImageNamed:@"sortbar_listview_s"] xy_changeImageColorWithColor:[UIColor whiteColor]];
        });
        [_changeStyleButton setImage:normalImage forState:UIControlStateNormal];
        [_changeStyleButton setImage:selectedImage forState:UIControlStateSelected];
    }
    return _changeStyleButton;
}

- (void)updateChangeStyleButton {
    _changeStyleButton.selected = !_changeStyleButton.isSelected;
}

////////////////////////////////////////////////////////////////////////
#pragma mark - Actions
////////////////////////////////////////////////////////////////////////
- (void)changeStyleButtonClick:(UIButton *)sender {
    [sender setUserInteractionEnabled:NO];
    OSFileCollectionLayoutStyle style = ![OSFileCollectionViewFlowLayout collectionLayoutStyle];
    [OSFileCollectionViewFlowLayout setCollectionLayoutStyle:style];
    [self updateChangeStyleButton];
    if (self.delegate && [self.delegate respondsToSelector:@selector(fileCollectionHeaderView:reLayoutStyle:)]) {
        [self.delegate fileCollectionHeaderView:self reLayoutStyle:style];
    }
    [sender setUserInteractionEnabled:YES];
}

- (void)searchButtonClick:(UIButton *)btn {
    if (self.delegate && [self.delegate respondsToSelector:@selector(fileCollectionHeaderView:clickedSearchButton:)]) {
        [self.delegate fileCollectionHeaderView:self clickedSearchButton:btn];
    }
}

@end
