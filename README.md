The AnyConnect Encoder Plugin Library creates a junction between AnyConnect's Smarter Camera Platform Libraries and your smarter camera’s media encoder.  The steps to build and deploy your Encoder Library are:

# Procedure

1. Complete the stub functions in libencoder.cpp.
2. Compile your libencoder.so.
3. Dynamically link your libencoder.so with your AnyConnect Camera Onboarding library (libonboard.so), AnyConnect platform libraries (libaccess.so. libconnect.so, libstream.so, and libvision.so), and your smart camera application.


# What’s Included:

- README		Instructions to complete the libencoder.cpp stub functions and compile and use libencoder.so.
- Encoder.h		Encoder library header file.  This derived class overrides EncoderService base class member functions.
- Encoder.cpp		Encoder library source file.  You must complete the stub functions.
- EncoderService.h	These base class member functions are overridden by Encoder derived class.
- Makefile		Compiles libencoder.so.
- test/Test.h		Test application for libencoder.so.
- test/Test.cpp		Test application for libencoder.so.
- test/Makefile		Compiles the test application.


# What’s Required:

### Software packages:
- Linux
- dl library
- pthreads library 
- gcc/g++ version 7.x or higher

### Encoder features:
- H.264 Baseline and Main Profiles
- Parallel H.264 and YUV streams
- 480p, 720p, 1080p, and higher resolutions

### Encoder interfaces to programmatically:
- Get a motion vector
- Generate an in-stream I-Frame with PPS and SPS
- Change in-stream bitrate and framerate 

### Optional:
- Opus or PCMU (G.711u) audio encoding


# How to complete the libencoder.cpp stub functions:

- getMediaSources() // Gets the camera's audio and video sources, their capabilities, and configuration parameters.
- initMediaSource() // Initializes an audio or video source.
- changeMediaParameters() // Changes parameters for an audio or video source.
- pushEncodedFrame() // Decodes audio or video and returns a pointer to a decoded frame.
- getFrame() // Returns encoded audio or video to the EncoderService class.
- requestIntraFrame() // Requests an I-Frame (with PPS and SPS).
- closeMedia() // Stops encoding an audio or video source.


# How to compile your Encoder Library.

Compile your libencoder.so by typing “make all”.


# How to test your Encoder Library.

Compile the test application by typing “test/make all”.  This will generate a test application called “encodertest”. Run the test application by typing “test/encodertest”.  

If successful, the test application will print “Your AnyConnect Encoder Library loads!”.  If not successful, the test application will print “Your AnyConnect Encoder Library does not load.”.
