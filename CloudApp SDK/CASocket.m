//
//  CASocket.m
//  CloudAppSDK
//
//  Created by Gabe Kangas on 10/4/17.
//

#import "CASocket.h"
#import "CANetworkKeys.h"

@interface CASocket ()
@property (nonatomic) NSString *url;
@property (nonatomic) NSString *key;
@property (nonatomic) NSString *appId;
@property (nonatomic) NSDictionary *channels;
@end

@implementation CASocket

- (id)initWithDictionary:(NSDictionary *)dictionary {
    self.url                    =  dictionary[kAuthURL];
    self.key                    = dictionary[kAPIKey];
    self.appId                  = dictionary[kAppID];
    self.channels               = dictionary[kChannels];
    return self;
}
@end
