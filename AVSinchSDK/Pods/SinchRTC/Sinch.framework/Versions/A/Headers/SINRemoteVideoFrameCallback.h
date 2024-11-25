/*
 * Copyright (c) 2015 Sinch AB. All rights reserved.
 *
 * See LICENSE file for license terms and information.
 */

#import <Foundation/Foundation.h>
#import <CoreVideo/CVPixelBuffer.h>

@protocol SINVideoFrame;

/**
 * The callback object that will process frames from a remote stream.
 *
 * IMPORTANT: the developer needs to retain the CVPixelBuffer object
 * received from the callback by CVPixelBufferRetain,and to release the
 * object by CVPixelBufferRelease.
 *
 * @param cvPixelBuffer The video frame captured from the camera.
 * @param completionHandler The completionHandler needs to be invoked with
 * a cvPixelBuffer object which will be sent to the remote peer.
 *
 * IMPORTANT: The invocation of the completionHandler is mandatory when
 * SINLocalVideoFrameCallback is set, otherwise the Sinch SDK will not send
 * any frame to the remote peer in this case.
 */
@protocol SINRemoteVideoFrameCallback <NSObject>

- (void)onFrame:(CVPixelBufferRef)cvPixelBuffer
    completionHandler:(void (^)(CVPixelBufferRef retCVPixelBuffer))completionHandler;

@end
