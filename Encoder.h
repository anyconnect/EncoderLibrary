#ifndef _ENCODER_H_
#define _ENCODER_H_

// Encoder library header file.  
// This derived class overrides EncoderService base class member functions.
// The AnyConnect Smarter Camera Platform libraries calls these APIs
// to request/push data from/to a camera encoder/decoder.


#include "MediaService.h"

using namespace com::anyconnect::media;

class Encoder: public MediaService {
public:
  Encoder();
  virtual ~Encoder();
  
  void getMediaSources(const MediaType mediaType, std::vector<MediaSource> &mediaSourceList);

  void initMediaSource(const MediaType mediaType, const MediaSource mediaSource);

  void changeMediaParameters(const std::string &inputSource, const MediaType mediaType, const MediaSource& mediaSource); 

  void pushEncodedFrame(const std::string &inputSource, const MediaType mediaType, void *framePtr, long size, time_t timestamp, void *outFramePtr, long &outSize);

  void getFrame(const std::string &inputSource, const bool encoded, const MediaType mediaType, void *framePtr, long &size, time_t& timestamp);

  void requestIntraFrame(const std::string &inputSource, const bool encoded);

  void closeMedia(const std::string &inputSource, const MediaType mediaType);
	
};
#endif

