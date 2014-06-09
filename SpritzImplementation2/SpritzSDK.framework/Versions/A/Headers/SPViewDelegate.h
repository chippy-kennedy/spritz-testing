/*
 *  SPViewDelegate.h
 *  Spritz View Delegate
 *  Copyright 2014 Spritz Inc. All rights reserved.
 */

@class SPBaseView;

/*
 Delegates of SPBaseView and SPControlView can implement the SPViewDelegate. Optional methods allow the delegate to respond to various events associated with the spritz control.
 */

@protocol SPViewDelegate <NSObject>

@optional

/**
 Informs the delegate that the spritz control started spritzing text.
 
 @param spritzView Spritz control informing the delegate.
 @param charPos Character index of the first character of the currently displayed word in the overall string of text.
 @param wordPos Word index of the currently displayed word in the overall string of text.
 @param timePos Time position of the currently displayed word at the currently set speed, measured in milliseconds.
 @param speed Current speed measured in words per minute (wpm).
 */

- (void)spritzView:(SPBaseView*)spritzView didStart:(NSInteger)charPos wordPos:(NSInteger)wordPos timePos:(CGFloat)timePos speed:(NSInteger)speed;

/**
 Informs the delegate that the spritz control reset its content.
 
 @param spritzView Spritz control informing the delegate.
 @param charPos Character index of the first character of the currently displayed word in the overall string of text.
 @param wordPos Word index of the currently displayed word in the overall string of text.
 @param timePos Time position of the currently displayed word at the currently set speed, measured in milliseconds.
 @param speed Current speed measured in words per minute (wpm).
 */

- (void)spritzView:(SPBaseView*)spritzView didReset:(NSInteger)charPos wordPos:(NSInteger)wordPos timePos:(CGFloat)timePos speed:(NSInteger)speed;

/**
 Informs the delegate that the spritz control is paused.
 
 @param spritzView Spritz control informing the delegate.
 @param charPos Character index of the first character of the currently displayed word in the overall string of text.
 @param wordPos Word index of the currently displayed word in the overall string of text.
 @param timePos Time position of the currently displayed word at the currently set speed, measured in milliseconds.
 @param speed Current speed measured in words per minute (wpm).
 */

- (void)spritzView:(SPBaseView*)spritzView didPause:(NSInteger)charPos wordPos:(NSInteger)wordPos timePos:(CGFloat)timePos speed:(NSInteger)speed;

/**
 Informs the delegate that the spritz control resumed spritzing text.
 
 @param spritzView Spritz control informing the delegate.
 @param charPos Character index of the first character of the currently displayed word in the overall string of text.
 @param wordPos Word index of the currently displayed word in the overall string of text.
 @param timePos Time position of the currently displayed word at the currently set speed, measured in milliseconds.
 @param speed Current speed measured in words per minute (wpm).
 */

- (void)spritzView:(SPBaseView*)spritzView didResume:(NSInteger)charPos wordPos:(NSInteger)wordPos timePos:(CGFloat)timePos speed:(NSInteger)speed;

/**
 Informs the delegate that the spritz control did seek to a different position.
 
 @param spritzView Spritz control informing the delegate. 
 @param charPos Character index of the first character of the currently displayed word in the overall string of text.
 @param wordPos Word index of the currently displayed word in the overall string of text.
 @param timePos Time position of the currently displayed word at the currently set speed, measured in milliseconds.
 @param speed Current speed measured in words per minute (wpm).
 */

- (void)spritzView:(SPBaseView*)spritzView didSeek:(NSInteger)charPos wordPos:(NSInteger)wordPos timePos:(CGFloat)timePos speed:(NSInteger)speed;

/**
 Informs the delegate that the spritz control moved backward a number of sentences.
 
 @param spritzView Spritz control informing the delegate.
 @param numSentences Number of sentences the Spritz control moved forward.
 @param charPos Character index of the first character of the currently displayed word in the overall string of text.
 @param wordPos Word index of the currently displayed word in the overall string of text.
 @param timePos Time position of the currently displayed word at the currently set speed, measured in milliseconds.
 @param speed Current speed measured in words per minute (wpm).
 */

- (void)spritzView:(SPBaseView*)spritzView didGoBackSentence:(NSInteger)numSentences charPos:(NSInteger)charPos wordPos:(NSInteger)wordPos timePos:(CGFloat)timePos speed:(NSInteger)speed;

/**
 Informs the delegate that the spritz moved forward a number of sentences.
 
 @param spritzView Spritz control informing the delegate.
 @param numSentences Number of sentences the Spritz control moved forward.
 @param charPos Character index of the first character of the currently displayed word in the overall string of text.
 @param wordPos Word index of the currently displayed word in the overall string of text.
 @param timePos Time position of the currently displayed word at the currently set speed, measured in milliseconds.
 @param speed Current speed measured in words per minute (wpm).
*/

- (void)spritzView:(SPBaseView*)spritzView didGoForwaredSentence:(NSInteger)numSentences charPos:(NSInteger)charPos wordPos:(NSInteger)wordPos timePos:(CGFloat)timePos speed:(NSInteger)speed;

/**
 Informs the delegate that the Spritz control has finished Spritzing the content.
 
 @param spritzView Spritz control informing the delegate.
 @param charPos Character index of the first character of the currently displayed word in the overall string of text.
 @param wordPos Word index of the currently displayed word in the overall string of text.
 @param timePos Time position of the currently displayed word at the currently set speed, measured in milliseconds.
 @param speed Current speed measured in words per minute (wpm).
 */

- (void)spritzView:(SPBaseView*)spritzView didComplete:(NSInteger)charPos wordPos:(NSInteger)wordPos timePos:(CGFloat)timePos speed:(NSInteger)speed;

/**
 Informs the delegate that the spritz control received an error and was unable to spritz the requested content.
 
 @warning If this method is not implemented or no delegate is set, a UIAlertView containing the details of the error is presented to the user. If this delegate is set, the SDK makes no indication to the user that there was an error.
 
 @param spritzView The Spritz control informing the delegate.
 @param error Error that prevented the Spritz control from displaying the requested content.
 */

- (void)spritzView:(SPBaseView*)spritzView didRecieveError:(NSError*)error;

@end
