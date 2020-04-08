#include "Encoder.h"
#include <vector>


Encoder::Encoder() {
  // Initialize the encoder and decoder.
}

Encoder::~Encoder() {
  // De-Initialize the encoder and decoder safely.
}

void Encoder::getMediaSources(const MediaType mediaType, std::vector<MediaSource> &mediaSourceList) {
  // Assign a unique identifier to each media source and add it to the vector.
  // mediaType can be AUDIO, VIDEO or IMAGE.
  // For example:
  //if (mediaType == MediaType::AUDIO) {
  //	MediaSource audioParams;
  // 	audioSources.inputSource = "aud_1";
  //	audioSources.audioCodec = AudioCodec::G711;
  //	audioSources.audioSampleRate = SampleRate::Hz_16K;
  //	audioSources.bitRate = 128000;
  //	mediaSourceList.push_back(audioParams);
  //}
  //else if(mediaType == MediaType::VIDEO) {
  //	MediaSource videoParams1;
  //	videoSource1.inputSource = "vid_1";
  //	videoSource1.videoCodec = VideoCodec::H264;
  //	videoSource1.videoResolution = VideoResolution::WH_640x480;
  //	videoSource1.fps = 30;
  //	videoSource1.bitRate = 600000;
  //
  //	MediaSource videoParams2;
  //	videoSource2.inputSource = "vid_2";
  //	videoSource2.videoCodec = VideoCodec::H264;
  //	videoSource2.videoResolution = VideoResolution::WH_1280x720;
  //	videoSource2.fps = 30;
  //	videoSource2.bitRate = 1200000;
  //	mediaSourceList.push_back(videoParams1);
  //	mediaSourceList.push_back(videoParams2);
  //}
}

void Encoder::initMediaSource(const MediaType mediaType, const MediaSource mediaSource) {
  // Initializes an audio or video source.

  //if (mediaType == MediaType::AUDIO) {
  //	set initial audio parameters for an audio encoder.
  //}
  //else if(mediaType == MediaType::VIDEO) {
  //	set initial parameters for a video encoder/decoder. 
  //}

}

void Encoder::setInputSourceStatusCallback(onReceiveInputSourceStatus handler) {
  // Returns the status of the media sources.
  // This function must be non-blocking.
  this->statusHandler = handler;
}

void Encoder::changeMediaParameters(const std::string &inputSource, const MediaType mediaType, const MediaSource& mediaSource) {
  // Change parameters for an audio or video source,
  // (e.g. "bitrate", "fps", "resolution", "samplerate"), and
  // re-initialize the encoder with the changed parameters.
}

void Encoder::pushEncodedFrame(const std::string &inputSource, const MediaType mediaType, void *framePtr, long size, time_t timestamp, void *outFramePtr, long &outSize) {
  // Receive the encoded video or audio for the specified input source and do the decoding.
  // After decoding, copy the data to the *outFramePtr and specify the size in outSize.
}

void Encoder::getFrame(const std::string &inputSource, const bool encoded, const MediaType mediaType, void *framePtr, long &size, time_t& timestamp) {
  // Returns encoded audio or video to the EncoderService class.
  // Generate an encoded or raw frame from the specified inputSource depending on the "encoded" and "mediaType" parameters.
  // After encoding, copy the data to the *framePtr and specify the size in the "size" variable.
}

bool Encoder::setDataReceiveCallback(onDataReceiveHandler handler)
{
  // Returns data received from the camera encoder.
  // This function must be non-blocking.
  this->handler = handler;
}

void Encoder::requestIntraFrame(const std::string &inputSource, const bool encoded) {
  // Generate I-Frame (with SPS and PPS) from the encoder.
}

void Encoder::closeMedia(const std::string &inputSource, const MediaType mediaType)
{
  // Stop encoding an audio or video source.	
}

// Create and destroy the camera's Encoder instance.
extern "C" {
Encoder* create() {
	return new Encoder();
}
void destroy(Encoder* auth) {
	delete auth;
}
}
