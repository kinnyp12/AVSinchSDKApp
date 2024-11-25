/*
 * Copyright (c) 2015 Sinch AB. All rights reserved.
 *
 * See LICENSE file for license terms and information.
 */

#import <Foundation/Foundation.h>

/**
 * SINNotificationResult is used to indicate the result of -[SINClient relayRemotePushNotification:] .
 *
 * When a user acts on a push notification, the Sinch-specific payload which is embedded in the
 * notification may represent either an incoming call, or an incoming instant-
 * message. SINNotificationResult is used to give information about what the
 * notification payload represented, and can thus be used by the application to
 * take appropriate actions.
 *
 * See SINCallNotificationResult for additional details.
 *
 * Example use:
 *
 * id<SINNotificationResult> result = [self.client relayRemotePushNotification:payload];
 *
 * if ([result isCall] && [[result callResult] isTimedOut]) {
 *     NSString* remoteUserId = [[result callResult] remoteUserId];
 *     // present UIAlert indicating user has a missed call.
 * }
 *
 * It can be especially useful for scenarios which will not result in
 * the SINClientDelegate receiving any callback for an incoming call as a result
 * of calling the methods mentioned above. One such scenario is when a user
 * have been attempted to be reached, but not acted on the notification directly.
 * In that case, the notification result object can indicate that the
 * notification is too old (`isTimedOut`), and also contains the `remoteUserId` which can be
 * used for display purposes.
 *
 */

@protocol SINCallNotificationResult;

@protocol SINNotificationResult <NSObject>

/** Indicates whether the notification is valid or not. */
@property (nonatomic, readonly, assign) BOOL isValid;

/** Indicates whether the notification is call related */
- (BOOL)isCall;

/** If the notification is call related (isCall is true), callResult contains the notification result */
- (id<SINCallNotificationResult>)callResult;

@end
