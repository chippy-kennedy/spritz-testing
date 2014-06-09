/*
 *  SpritzSDK.h
 *  Spritz SDK
 *  Copyright 2014 Spritz Inc. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import "SPBaseView.h"
#import "SPControlView.h"
#import "SPViewDelegate.h"
#import "SPSourceType.h"
#import "SPActionButton.h"
#import "SPCurrentUser.h"

/**
 SpritzSDK is the entry point for communication with the spritz servers. It lets you set your SDK Client IDs and contains utility methods for user management.
 */

@interface SpritzSDK : NSObject

/**
 Sets your application Client ID and Client Secret for the SpritzSDK. This must be done before any other actions can be performed. If you don’t have a Client ID or Client Secret, create one at http://www.spritzinc.com/developers/.
 
 @warning If you fail to set the ClientID or ClientSecret your app will crash with an assertion failure on SDK use. Setting an invalid ClientID or ClientSecret will result in an API error message.
 
 @param clientID Your application's unique Client ID
 @param clientSecret Your application's unique Client Secret.
 */

+ (void)setClientID:(NSString *)clientID clientSecret:(NSString *)clientSecret;

/**
 Displays the user login dialog box, with an optional callback handling any errors with login. If this is never called by the developer, it is called automatically the first time the user tries to interact with the SpritzSDK.
    @param completionBlock This block is called when the user completes or cancels the dialog box.
 */

+ (void)loginUser:(void(^)(BOOL success, NSError *error))completionBlock;

/**
 Logs out the current user and destroys the session.
 @param completionBlock This block is called when the session is destroyed.
 */

+ (void)logoutUser:(void(^)(NSError *error))completionBlock;

/**
 Retrieves the currently logged in user. If there no user is currently logged in, this method calls the login dialog box.
 @param completionBlock This block is called after the user is retrieved.
 */

+ (void)getLoggedInUser:(void(^)(SPCurrentUser *user, NSError *error))completionBlock;

@end
