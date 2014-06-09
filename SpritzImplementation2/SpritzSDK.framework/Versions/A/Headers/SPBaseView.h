/*
 *  SPBaseView.h
 *  Spritz Base View
 *  Copyright 2014 Spritz Inc. All rights reserved.
 */

#import <UIKit/UIKit.h>
#import "SPViewDelegate.h"
#import "SPSourceType.h"

/**
 SPBaseView is the base spritz control. It provides a basic spritz retical, with no spritzing controls associated with the view.
 */

@interface SPBaseView : UIView

/**
 The delegate receives events associated with the user's spritzing actions (such as start, stop, pause, and so on).
 */

@property (nonatomic, weak) id<SPViewDelegate> delegate;

/**
 Current speed measured in words per minute (wpm). Can be set at anytime and updates the view in real time.
 */

@property (nonatomic, assign) NSInteger speed;

/**
 Character index of the first character of the currently displayed word in the overall string of text. (read-only)
 */

@property (nonatomic, readonly) NSInteger characterPosition;

/**
 Word index of the currently displayed word in the overall string of text. (read-only)
 */

@property (nonatomic, readonly) NSInteger wordPosition;

/**
 Time position of the currently displayed word at the currently set speed, measured in milliseconds. (read-only)
 */

@property (nonatomic, readonly) NSInteger timePosition;

/**
 Returns YES if the Spritz control is currently loading text. Readonly.
 */

@property (nonatomic, readonly) BOOL loading;

/**
 Returns YES if the spritz control currently has content loaded, even if the spritz control is paused. (read-only)
 */

@property (nonatomic, readonly) BOOL started;

/**
 Returns YES if the Spritz control is currently paused. Return NO if there is no content loaded.
 */

@property (nonatomic, readonly) BOOL paused;

/**
 Starts spritzing the specified text to the spritz control.
 
 @param source Source of the text. Can be either a plain text string or a website URL. If a URL is passed in, the spritz control automatically parses the website and sends only display-releavent content text.
 @param sourceType Type of the source. Can be set to either a URL or a plain text string.
 
 */

- (void)start:(NSString *)source sourceType:(SPSourceFlags)sourceType;

/**
 Starts spritzing the specified text to the spritz control with the specified speed.
 
 @param source Source of the text. Can be either a plain text string or a website URL. If a URL is passed in, the spritz control automatically parses the website and sends only display-releavent content text.
 @param sourceType Type of the source. Can be set to either a URL or a plain text string.
 @param speed Speed at which to spritz the text, in words per minute. (wpm)
 */

- (void)start:(NSString *)source sourceType:(SPSourceFlags)sourceType speed:(NSInteger)speed;

/**
 Starts spritzing the specified text to the spritz control with the specified speed and position.
 
 @param source Source of the text. Can be either a plain text string or a website URL. If a URL is passed in, the spritz control automatically parses the website and sends only display-releavent content text.
 @param sourceType Type of the source. Can be set to either a URL or a plain text string.
 @param speed Speed at which to spritz the text, in words per minute. (wpm)
 @param position Position at which to start spritzing, specified by word index.
 */

- (void)start:(NSString *)source sourceType:(SPSourceFlags)sourceType speed:(NSInteger)speed position:(NSInteger)position;

/**
 Resets the spritz control, clears all content and resets to the default state.
 
 @warning Resetting the Spritz control does not reset the speed.
 */

- (void)reset;

/**
 Pauses the spritz control if the control is currently spritzing text.
 */

- (void)pause;

/**
 Resumes the spritz control if the control is currently in a paused state
 */

- (void)resume;

/**
 Toggles the spritz control between paused and playing states.
 */

- (void)togglePause;

/**
 Seeks to the specified word index. 
 
 @param position index of the word to seek to.
 @param absolute If set to YES, the control seeks to the specified index in the overall text. If set to NO, the control seeks to the word relative to the current word index.
 */

- (void)seek:(NSInteger)position absolute:(BOOL)absolute;

/**
 Returns to the beginning of the current sentence or one sentence past the current sentence if the current word is located at the beginning of a sentence.
 
 @warning Calling this method pauses the spritz control automatically.
 */

- (void)goBackSentence;

/**
 Returns to the specified number of sentences. If the current word is not at the beginning of a sentence, the current sentence is counted as one sentence.
 
 @warning Calling this method pauses the spritz control automatically.
 */

- (void)goBackSentences:(NSInteger)numOfSentences;

/**
 Moves forward to the next sentence.
 
 @warning Calling this method pauses the spritz control automatically.
 */

- (void)goForwardSentence;

/**
 Moves forward based on the number of sentences specified.
 
 @warning Calling this method pauses the spritz control automatically.
 */

- (void)goForwardSentences:(NSInteger)numOfSentences;

@end