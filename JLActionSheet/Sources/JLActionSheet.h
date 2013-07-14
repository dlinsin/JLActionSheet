//
//  JLActionSheet.h
//  JLActionSheet
//
//  Created by Jason Loewy on 1/31/13.
//  Copyright (c) 2013 Jason Loewy. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "JLActionSheetStyle.h"

@class JLActionSheet;
@protocol JLActionSheetDelegate <NSObject>

- (void) actionSheet:(JLActionSheet*)actionSheet clickedButtonAtIndex:(NSInteger)buttonIndex;
- (void) actionSheet:(JLActionSheet*)actionSheet didDismissButtonAtIndex:(NSInteger)buttonIndex;

@end

typedef void(^JLActionBlock)(JLActionSheet* actionSheet, NSInteger buttonIndex);
@interface JLActionSheet : UIView
{
    JLActionBlock clickedButtonBlock;
    JLActionBlock didDismissBlock;
}

// Data Objects
@property (readonly) NSInteger cancelButtonIndex;
@property NSInteger destructiveIdx;

// UI Objects
@property JLStyle style;

/// Initialization Methods
+ (id) sheetWithTitle:(NSString*) title delegate:(id<JLActionSheetDelegate>) delegate cancelButtonTitle:(NSString*) cancelTitle otherButtonTitles:(NSArray*) buttonTitles destructiveIdx:(NSInteger)idx;
- (id) initWithTitle:(NSString*) title delegate:(id<JLActionSheetDelegate>) delegate cancelButtonTitle:(NSString*) cancelTitle otherButtonTitles:(NSArray*) buttonTitles destructiveIdx:(NSInteger)idx;

/// Action Block Methods
- (void) setClickedButtonBlock:(JLActionBlock) actionBlock;
- (void) setDidDismissBlock:(JLActionBlock) actionBlocks;

/// Presentation Methods
- (void) showInView:(UIView*) parentView;
- (void) showOnViewController:(UIViewController*) parentViewController;
- (void) showFromBarItem:(UIBarButtonItem*) barButton onView:(UIView*) parentView;
- (void) showFromBarItem:(UIBarButtonItem*) barButton onViewController:(UIViewController*) parentViewController;

/// Accessor Methods
- (NSString*) titleAtIndex:(NSInteger)buttonIndex;
- (BOOL) isVisible;

/// UI Mutator Methods
- (void) allowTapToDismiss:(BOOL) allowTap;

@end
