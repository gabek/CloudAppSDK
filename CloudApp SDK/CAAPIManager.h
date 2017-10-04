//
//  CAAPIManager.h
//  CloudApp SDK
//
//  Created by Rocco Del Priore on 5/2/17.
//  Copyright © 2017 Rocco Del Priore. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "CAItem.h"

extern NSString *const bookmarkNameKey;
extern NSString *const bookmarkURLKey;

@interface CAAPIManager : NSObject

@property (nonatomic) NSInteger defaultItemsPerPage;

+ (instancetype)sharedInstance;

//Fetch
- (void)fetchItemWithUniqueId:(NSInteger)uniqueId success:(void (^)(CAItem *item))success failure:(void (^)(NSError *error))failure;

- (void)fetchItemsAtPage:(NSInteger)page success:(void (^)(NSArray<CAItem *> *items))success failure:(void (^)(NSError *error))failure;

- (void)fetchItemsAtPage:(NSInteger)page
    numberOfItemsPerPage:(NSInteger)numberOfItems
                    type:(CAItemType)type
                 success:(void (^)(NSArray<CAItem *> *items))success
                 failure:(void (^)(NSError *error))failure;

- (void)fetchItemsAtPage:(NSInteger)page
    numberOfItemsPerPage:(NSInteger)numberOfItems
                  source:(NSString *)source
                 success:(void (^)(NSArray<CAItem *> *items))success
                 failure:(void (^)(NSError *error))failure;

- (void)fetchArchivedItemsAtPage:(NSInteger)page success:(void (^)(NSArray<CAItem *> *items))success failure:(void (^)(NSError *error))failure;

- (void)fetchArchievedItemsAtPage:(NSInteger)page
     numberOfItemsPerPage:(NSInteger)numberOfItems
                     type:(CAItemType)type
                  success:(void (^)(NSArray<CAItem *> *items))success
                  failure:(void (^)(NSError *error))failure;

- (void)fetchItemFavoriteStatus:(CAItem *)item success:(void (^)(CAItem *item))success failure:(void (^)(NSError *error))failure;

- (void)fetchHomePageForDomain:(NSString *)domain success:(void (^)(NSString *homepage))success failure:(void (^)(NSError *error))failure;

//Create
- (void)createNewItem:(NSString *)name filePath:(NSString *)path isPrivate:(BOOL)private success:(void (^)(CAItem *item))success failure:(void (^)(NSError *error))failure;

- (void)createBookmarkWithName:(NSString *)name url:(NSURL *)url success:(void (^)(CAItem *item))success failure:(void (^)(NSError *error))failure;

- (void)createBookmarks:(NSArray<NSDictionary *> *)bookmarks success:(void (^)(NSArray<CAItem *> *items))success failure:(void (^)(NSError *error))failure;

//Modify
- (void)setItemFavorite:(CAItem *)item isFavorite:(BOOL)favorite success:(void (^)(CAItem *item))success failure:(void (^)(NSError *error))failure;

- (void)setItemPrivate:(CAItem *)item isPrivate:(BOOL)private success:(void (^)(CAItem *item))success failure:(void (^)(NSError *error))failure;

- (void)setItemExpiration:(CAItem *)item expirationDate:(NSDate *)date success:(void (^)(CAItem *item))success failure:(void (^)(NSError *error))failure;

- (void)setItemExpiration:(CAItem *)item afterViews:(NSInteger)numberOfViews success:(void (^)(CAItem *item))success failure:(void (^)(NSError *error))failure;

- (void)shareItem:(CAItem *)item with:(NSArray<NSString *> *)recipients message:(NSString *)message success:(void (^)())success failure:(void (^)(NSError *error))failure;

- (void)deleteItem:(CAItem *)item success:(void (^)(CAItem *item))success failure:(void (^)(NSError *error))failure;

- (void)recoverItem:(CAItem *)item success:(void (^)(CAItem *item))success failure:(void (^)(NSError *error))failure;

- (void)renameItem:(CAItem *)item name:(NSString *)name success:(void (^)(CAItem *item))success failure:(void (^)(NSError *error))failure;

@end
