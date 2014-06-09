/*
 *  SPSourceType.h
 *  Spritz Source Type
 *  Copyright 2014 Spritz Inc. All rights reserved.
 */

/**
 SPSourceType defines how the spritz control parses the source string associated with it.
 */

typedef NS_OPTIONS(NSUInteger, SPSourceFlags) {
    /**
     *  Empty flag. Used for internal purposes.
     */
    
    SPSourceFlagNone			= 0,
    
    /**
     *  Plain text flag. Treats the source as a plain text string.
     */
    
    SPSourceFlagPlainText       = 1,
    
    /**
     *  URL text flag. Downloads the website at the specified URL and starts spritzing the content.
     */
    
    SPSourceFlagURL             = 2
};
