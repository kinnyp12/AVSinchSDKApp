/*
 * Copyright (c) 2015 Sinch AB. All rights reserved.
 *
 * See LICENSE file for license terms and information.
 */

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import <Sinch/SINExport.h>

@class CXProvider;
@protocol SINCall;
@protocol SINCallClientDelegate;

/**
 * SINCallClient provides the entry point to the calling functionality of the Sinch SDK.
 * A SINCallClient can be acquired via SINClient.
 *
 * ### Example
 *
 * 	id<SINClient> sinchClient;
 * 	[sinchClient setSupportCalling:YES];
 * 	[sinchClient start];
 * 	...
 *
 * 	// Place outgoing call.
 * 	id<SINCallClient> callClient = [sinchClient callClient];
 * 	id<SINCall> call = [callClient callUserWithId:@"<REMOTE USERID>"];
 *
 * 	// Set the call delegate that handles all the call state changes
 * 	call.delegate= ... ;
 *
 * 	// ...
 *
 * 	// Hang up the call
 * 	[call hangup];
 *
 */

SIN_EXPORT SIN_EXTERN NSString *const SINIncomingCallNotification;      // userInfo contains SINCall
SIN_EXPORT SIN_EXTERN NSString *const SINCallDidProgressNotification;   // userInfo contains SINCall
SIN_EXPORT SIN_EXTERN NSString *const SINCallDidEstablishNotification;  // userInfo contains SINCall
SIN_EXPORT SIN_EXTERN NSString *const SINCallDidEndNotification;        // userInfo contains SINCall
SIN_EXPORT SIN_EXTERN NSString *const SINCallKey;                       // SINCallKey is used for SINCall in userInfo;
SIN_EXPORT SIN_EXTERN NSString *const SINCallIdKey;  // SINCallIdKey is used for a call id in userInfo;

@protocol SINCallClient <NSObject>

/**
 * The object that acts as the delegate of the call client.
 *
 * The delegate object handles call state change events and must
 * adopt the SINCallClientDelegate protocol.
 *
 * @see SINCallClientDelegate
 */
@property (nonatomic, weak) id<SINCallClientDelegate> delegate;

/**
 * Make a call to the user with the given id.
 *
 * @param userId The application specific id of the user to call.
 *
 * @exception NSInternalInconsistencyException Throws an exception if attempting
 *                                             to initiate a call before the
 *                                             SINClient is started.
 *                                             @see -[SINClientDelegate clientDidStart:].
 * @return SINCall Outgoing call
 */
- (id<SINCall>)callUserWithId:(NSString *)userId;

/**
* Calls the user with the given id and the given headers.
*
* @param userId The application specific id of the user to call.
*
* @param headers NSString key-value pairs to pass with the call.
*                The total size of header keys + values (when encoded with NSUTF8StringEncoding)
*                must not exceed 1024 bytes.
*
* @exception NSInternalInconsistencyException Throws an exception if attempting
*                                             to initiate a call before the
*                                             SINClient is started.
*                                             @see -[SINClientDelegate clientDidStart:].
*
* @exception NSInvalidArgumentException Throws an exception if headers are not strictly
*                                       containing only keys and values that are of type NSString,
*                                       or if the size of all header strings exceeds 1024 bytes when
*                                       encoded as UTF-8.
*
* @return SINCall Outgoing call
*/
- (id<SINCall>)callUserWithId:(NSString *)userId headers:(NSDictionary *)headers;

/**
 * Make a video call to the user with the given id
 *
 * @param userId The application specific id of the user to call.
 * @exception NSInternalInconsistencyException Throws an exception if attempting
 *                                             to initiate a call before the
 *                                             SINClient is started.
 *                                             @see -[SINClientDelegate clientDidStart:].
 * @return SINCall Outgoing call
 */
- (id<SINCall>)callUserVideoWithId:(NSString *)userId;

/**
 * Make a video call to the user with the given id and the give headers
 *
 * @param userId The application specific id of the user to call.
 *
 * @param headers NSString key-value pairs to pass with the call.
 *                The total size of header keys + values (when encoded with NSUTF8StringEncoding)
 *                must not exceed 1024 bytes.
 *
 * @exception NSInternalInconsistencyException Throws an exception if attempting
 *                                             to initiate a call before the
 *                                             SINClient is started.
 *                                             @see -[SINClientDelegate clientDidStart:].
 *
 * @exception NSInvalidArgumentException Throws an exception if headers are not strictly
 *                                       containing only keys and values that are of type NSString,
 *                                       or if the size of all header strings exceeds 1024 bytes when
 *                                       encoded as UTF-8.
 *
 * @return SINCall Outgoing call
 */
- (id<SINCall>)callUserVideoWithId:(NSString *)userId headers:(NSDictionary *)headers;

/**
 * Calls a phone number and terminates the call to the PSTN-network (Publicly Switched
 * Telephone Network).
 *
 * @param phoneNumber The phone number to call.
 *                    The phone number should be given according to E.164 number formatting
 *                    (http://en.wikipedia.org/wiki/E.164) and should be prefixed with a '+'.
 *                    E.g. to call the US phone number 415 555 0101, it should be specified as
 *                    "+14155550101", where the '+' is the required prefix and the US country
 *                    code '1' added before the local subscriber number.
 *
 * @exception NSInternalInconsistencyException Throws an exception if attempting
 *                                             to initiate a call before the
 *                                             SINClient is started.
 *                                             @see -[SINClientDelegate clientDidStart:].
 * @return SINCall Outgoing call
 */
- (id<SINCall>)callPhoneNumber:(NSString *)phoneNumber;

/**
* Calls a phone number and terminate the call to the PSTN-network (Publicly Switched
* Telephone Network).
*
* @param phoneNumber The phone number to call.
*                    The phone number should be given according to E.164 number formatting
*                    (http://en.wikipedia.org/wiki/E.164) and should be prefixed with a '+'.
*                    E.g. to call the US phone number 415 555 0101, it should be specified as
*                    "+14155550101", where the '+' is the required prefix and the US country
*                    code '1' added before the local subscriber number.
*
* @param headers NSString key-value pairs to pass with the call.
*                The total size of header keys + values (when encoded with NSUTF8StringEncoding)
*                must not exceed 1024 bytes.
*
* @exception NSInternalInconsistencyException Throws an exception if attempting
*                                             to initiate a call before the
*                                             SINClient is started.
*                                             @see -[SINClientDelegate clientDidStart:].
*
* @exception NSInvalidArgumentException Throws an exception if headers are not strictly
*                                       containing only keys and values that are of type NSString,
*                                       or if the size of all header strings exceeds 1024 bytes when
*                                       encoded as UTF-8.
*
* @return SINCall Outgoing call
*/
- (id<SINCall>)callPhoneNumber:(NSString *)phoneNumber headers:(NSDictionary *)headers;

/**
 * Make a SIP call to user with the given SIP Identity.
 *
 * @param sipIdentity The SIP identity string of the user to call, should be in the form of “user@domain”.
 *
 * @exception NSInternalInconsistencyException Throws an exception if attempting
 *                                             to initiate a call before the
 *                                             SINClient is started.
 *                                             @see -[SINClientDelegate clientDidStart:].
 * @return SINCall Outgoing call
 */
- (id<SINCall>)callSIP:(NSString *)sipIdentity;

/**
 * Make a SIP call to user with the given SIP Identity and adding the given headers.
 *
 * @param sipIdentity The SIP identity string of the user to call, should be in the form of “user@domain”.
 *
 * @param headers NSString key-value pairs to pass with the call.
 *                The total size of header keys + values (when encoded with NSUTF8StringEncoding)
 *                must not exceed 1024 bytes.
 *
 * @exception NSInternalInconsistencyException Throws an exception if attempting
 *                                             to initiate a call before the
 *                                             SINClient is started.
 *                                             @see -[SINClientDelegate clientDidStart:].
 * @return SINCall Outgoing call
 */
- (id<SINCall>)callSIP:(NSString *)sipIdentity headers:(NSDictionary*)headers;

/**
* Calls the conference with the given id.
*
* @param conferenceId The application specific id of the conference to call.
*
* @exception NSInternalInconsistencyException Throws an exception if attempting
*                                             to initiate a call before the
*                                             SINClient is started.
*                                             @see -[SINClientDelegate clientDidStart:].
*
* @exception NSInvalidArgumentException Throws an exception if conferenceId is longer than the maximum allowed 64
*                                       characters.
* @return SINCall Outgoing call
*/

- (id<SINCall>)callConferenceWithId:(NSString *)conferenceId;

/**
* Calls the conference with the given id and the given headers.
*
* @param conferenceId The application specific id of the conference to call.
*
* @param headers NSString key-value pairs to pass with the call.
*                The total size of header keys + values (when encoded with NSUTF8StringEncoding)
*                must not exceed 1024 bytes.
*
* @exception NSInternalInconsistencyException Throws an exception if attempting
*                                             to initiate a call before the
*                                             SINClient is started.
*                                             @see -[SINClientDelegate clientDidStart:].
*
* @exception NSInvalidArgumentException Throws an exception if conferenceId is longer than the maximum allowed 64
*                                       characters.
*
* @exception NSInvalidArgumentException Throws an exception if headers are not strictly
*                                       containing only keys and values that are of type NSString,
*                                       or if the size of all header strings exceeds 1024 bytes when
*                                       encoded as UTF-8.
*
* @return SINCall Outgoing call
*/
- (id<SINCall>)callConferenceWithId:(NSString *)conferenceId headers:(NSDictionary *)headers;

/**
 * This API is introduced to support CallKit integration. Invoke this method to notify the Sinch SDK that the App has
 * received the didActivateAudioSession callback from CXProviderDelegate. When CallKit is integrated in the App and an
 * incoming call is received in the background, this method has to be invoked for the Sinch SDK to start the media for
 * the call.
 *
 * @param audioSession The audioSession from the didActivateAudioSession callback of CXProviderDelegate.
 */
- (void)provider:(CXProvider *)provider didActivateAudioSession:(AVAudioSession *)audioSession;

/**
 * This API is introduced to support CallKit integration. Invoke this method to notify the Sinch SDK that the App has
 * received the didDeactivateAudioSession callback from CXProviderDelegate. When CallKit is integrated in the App, this
 * method has to be invoked to pass the didDeactivateAudioSession event from CallKit to the Sinch SDK for correct
 * audio session management.
 *
 * @param audioSession The audioSession from the didActivateAudioSession callback of CXProviderDelegate.
 */
- (void)provider:(CXProvider *)provider didDeactivateAudioSession:(AVAudioSession *)audioSession;
@end

@protocol SINCallClientDelegate <NSObject>

@optional

/**
 * Tells the delegate that an incoming call will be received. This is specially
 * useful for reporting the incoming call to CallKit when the app is in background.
 *
 * To receive further events related to this call, a SINCallDelegate
 * should be assigned to the call.
 *
 * The call has entered the `SINCallStateInitiating` state.
 *
 * @param client The client informing the delegate that an incoming call
 *               will be received. The delegate of the incoming call object
 *               should be set by the implementation of this method.
 *
 * @param call The incoming call.
 *
 * @see SINCallClient, SINCall, SINCallDelegate
 */
- (void)client:(id<SINCallClient>)client willReceiveIncomingCall:(id<SINCall>)call;

/**
 * Tells the delegate that an incoming call has been received.
 *
 * To receive further events related to this call, a SINCallDelegate
 * should be assigned to the call.
 *
 * The call has entered the `SINCallStateInitiating` state.
 *
 * @param client The client informing the delegate that an incoming call
 *               was received. The delegate of the incoming call object
 *               should be set by the implementation of this method.
 *
 * @param call The incoming call.
 *
 * @see SINCallClient, SINCall, SINCallDelegate
 */
- (void)client:(id<SINCallClient>)client didReceiveIncomingCall:(id<SINCall>)call;

@end
