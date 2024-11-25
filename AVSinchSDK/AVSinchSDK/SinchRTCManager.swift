//
//  SinchRTCManager.swift
//  AVSinchSDK
//
//  Created by Kinny Padia on 21/11/24.
//

import Foundation
import Sinch

public protocol SinchCallDelegate: AnyObject {
    func onIncomingCall(call: SINCall)
    func onCallEstablished(call: SINCall)
    func onCallEnded(call: SINCall)
}

public class SinchManager: NSObject {
    public static let shared = SinchManager()
    private var sinchClient: SINClient?
    public weak var callDelegate: SinchCallDelegate?

    // Configure the Sinch client
    public func initialize(userId: String) {
        guard sinchClient == nil else { return } // Prevent re-initializing
        sinchClient = Sinch.client(withApplicationKey: "951d4620-67a9-489b-a38f-92df09167a0c",
                                   applicationSecret: "3R6/bPyJnkyzJRfnK0hKNw==",
                                   environmentHost: "clientapi.sinch.com",
                                   userId: userId)
        sinchClient?.delegate = self
        sinchClient?.call()?.delegate = self
        sinchClient?.setSupportCalling(true)
//        sinchClient?.setSupportVideo(true)
        sinchClient?.start()
        sinchClient?.startListeningOnActiveConnection()
    }

    // Start a video call
    public func startVideoCall(to userId: String) -> SINCall? {
        let call = sinchClient?.call().callUserVideo(withId: userId)
        call?.delegate = self
        return call
    }

    // Start an audio call
    public func startAudioCall(to userId: String) -> SINCall? {
        let call = sinchClient?.call().callUser(withId: userId)
        call?.delegate = self
        return call
    }
}

extension SinchManager: SINClientDelegate {
    public func clientDidStart(_ client: SINClient!) {
        print("Sinch client started successfully!")
    }

    public func clientDidFail(_ client: SINClient!, error: Error!) {
        print("Sinch client failed to start: \(error.localizedDescription)")
    }
}

extension SinchManager: SINCallDelegate {
    public func callDidProgress(_ call: SINCall!) {
        print("Call is ringing...")
    }

    public func callDidEstablish(_ call: SINCall!) {
        print("Call connected!")
        callDelegate?.onCallEstablished(call: call)
    }

    public func callDidEnd(_ call: SINCall!) {
        print("Call ended!")
        callDelegate?.onCallEnded(call: call)
    }
}

extension SinchManager: SINCallClientDelegate {
    public func client(_ client: SINCallClient!, didReceiveIncomingCall call: SINCall!) {
        print("Incoming call from: \(call.remoteUserId ?? "unknown")")
        call.delegate = self
        callDelegate?.onIncomingCall(call: call)
    }
}
