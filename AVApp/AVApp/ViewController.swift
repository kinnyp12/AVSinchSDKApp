//
//  ViewController.swift
//  AVApp
//
//  Created by Kinny Padia on 22/11/24.
//

import UIKit
import AVSinchSDK
import AVFoundation

class ViewController: UIViewController {

    var userName = ""
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        
        SinchManager.shared.initialize(userId: "abc0001") // Add your userID here
    }
    
    
    @IBAction func btnVC(_ sender: UIButton) {
        if let call = SinchManager.shared.startVideoCall(to: "abc0002") {
            // Use the non-optional 'call' safely
            print("Video call started: \(call)")
        } else {
            print("Failed to start video call")
        }
    }
    
    @IBAction func btnAC(_ sender: UIButton) {
        if let call = SinchManager.shared.startAudioCall(to: "abc0002") {
            // Use the non-optional 'call' safely
            print("Audio call started: \(call)")
        } else {
            print("Failed to start video call")
        }
    }

    @IBAction func txtUserID(_ sender: UITextField){
        userName = sender.text ?? ""
    }
    
}

