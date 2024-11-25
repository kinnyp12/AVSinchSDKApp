/*
 * Copyright (c) 2019 Sinch AB. All rights reserved.
 *
 * See LICENSE file for license terms and information.
 */

#ifndef SIN_LOG_CALLBACK_H
#define SIN_LOG_CALLBACK_H

#import <Foundation/Foundation.h>
#import "SINLogSeverity.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^SINLogCallback)(SINLogSeverity severity, NSString* area, NSString* message, NSDate* timestamp);

NS_ASSUME_NONNULL_END

#endif  // SIN_LOG_CALLBACK_H
