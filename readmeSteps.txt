Extra steps for Webcam and Spinnaker

---------
Webcam -> VideoInput

 1- Download last version of this addon. 
 2- Copy it in the addons folder. 
 3- Copy "example_simpleCapture" in myApps folder.
 4- Generate Project with project generator ( addons required -> ofxSingleTon, ofxPlugin, ofxLiquidEvent, ofxMachineVision
 5- Follow Readme Steps: 
   5.1- "Add the ofxMachineVisionLib/ofxMachineVisionLib.vcxproj project to your solution"
   5.2- "Go to your project properties, go to 'Common Properties' at the top of the tree on the left, select 'Add New Reference...' and add the ofxMachineVisionLib project."


------------

Spinnaker

 1- Download this addon and ofxSpinnaker. 
 2- Copy it in the addons folder. 
 3- Copy "example_simpleCapture" in myApps folder.
 4- Generate Project with project generator ( addons required -> ofxSingleTon, ofxPlugin, ofxLiquidEvent, ofxMachineVision
 5- Follow Readme Steps: 
   5.1- "Add the ofxMachineVisionLib/ofxMachineVisionLib.vcxproj project to your solution"
   5.2- "Add the ofxSpinnakerLib/ofxSpinnaker.vcxproj project to your solution"
   5.3- "Go to your project properties, go to 'Common Properties' at the top of the tree on the left, select 'Add New Reference...' and add the ofxMachineVision"
   5.4- "Go to your project properties, go to 'Common Properties' at the top of the tree on the left, select 'Add New Reference...' and add the ofxSpinnaker"
   5.5- "Download and Install last SpinnakerSDK
	- 5.5.1 Copy&Paste Include scr into you addon ofxSpinnaker\libs\Spinnaker\
        - 5.5.2 Copy&Paste Debug(Spinnakerd_v140.lib) and Realease(Spinnaker_v140.lib) Lib into you addon ofxSpinnaker\libs\Spinnaker\lib\vs\Win32\Debug. Same for x64.
        - 5.5.3 Copy&Paste Debug(Spinnakerd_v140.dll) and Realease(Spinnaker_v140.dll) Lib into you addon ofxSpinnaker\libs\Spinnaker\bin\vs\Win32\Debug. Same for x64.
   5.6 "Remove from your project properties -> Linker -> Input the Spinnakerd_v140.dll from debug and Release"

Enjoy