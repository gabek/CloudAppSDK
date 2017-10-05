//
//  CASocket.h
//  CloudAppSDK
//
//  Created by Gabe Kangas on 10/4/17.
//

#import <Foundation/Foundation.h>

@interface CASocket : NSObject

- (id)initWithDictionary:(NSDictionary *)dictionary;

@property (nonatomic, readonly) NSString *url;
@property (nonatomic, readonly) NSString *key;
@property (nonatomic, readonly) NSString *appId;
@property (nonatomic, readonly) NSDictionary *channels;
@end
