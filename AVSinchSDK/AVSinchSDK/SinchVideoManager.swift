//
//  SinchVideoManager.swift
//  AVSinchSDK
//
//  Created by Kinny Padia on 21/11/24.
//

import Foundation
import Sinch
import UIKit

public class SinchVideoManager {
    private let videoController: SINVideoController?

    public init(videoController: SINVideoController?) {
        self.videoController = videoController
    }

    public func addLocalVideo(to view: UIView) {
        guard let localView = videoController?.localView() else { return }
        localView.frame = view.bounds
        view.addSubview(localView)
    }

    public func addRemoteVideo(to view: UIView) {
        guard let remoteView = videoController?.remoteView() else { return }
        remoteView.frame = view.bounds
        view.addSubview(remoteView)
    }
}
