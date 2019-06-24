#ifndef _MEDIA_SERVICE_H_
#define _MEDIA_SERVICE_H_

#include <string>
#include <vector>

namespace com {
namespace anyconnect {
namespace media {

///
/// \brief Stream media types.
///
/// Supported media types: audio, video and image.
///
enum class MediaType { 
  AUDIO,
  VIDEO,
  IMAGE
};

///
/// \brief Video codecs.
///
/// Supported video codecs.
///
enum class VideoCodec {
  H263,
  H264,
  H264_SVC,
  H265,
  RAW
};

///
/// \brief Video resolutions.
///
/// Supported video resolutions.
///
enum class VideoResolution {
  WH_176x144,
  WH_192x144,
  WH_320x240,
  WH_352x288,
  WH_640x400,
  WH_640x480,
  WH_840x480,
  WH_848x480,
  WH_1280x720,
  WH_1920x1080,
  WH_3840x2160,
  WH_7680x4320,
  WH_15360x8640
};

///
/// \brief Audio Codecs.
///
/// Supported audio codecs.
///
enum class AudioCodec {
  AAC,
  G711,
  G722,
  OPUS,
  SIREN,
  SPEEX
};

///
/// \brief Audio sample rates.
///
/// Supported audio sample rates.
///
enum class SampleRate {
  Hz_8K,
  Hz_12K,
  Hz_16K,
  Hz_20K,
  Hz_32K,
  Hz_48K
};


///
/// \brief Media parameters for streaming session.
///
/// Media parameters.
///
struct MediaSource {

  ///
  /// Media source identifier. 
  /// Note, This needs to be unique for every different  
  /// stream or source. ex: "cam_1", "cam_2", "aud_1", "aud_2".
  ///
  std::string inputSource;

  ///
  /// Audio codec.
  ///
  AudioCodec audioCodec;

  ///
  /// Maximum audio sample rate.
  ///
  SampleRate audioSampleRate;

  ///
  /// Video codec.
  ///
  VideoCodec videoCodec;

  ///
  /// Video resolution.
  ///
  VideoResolution videoResolution;
 
  ///
  /// Maximum video frame per second.
  ///
  int fps;

  ///
  /// Maximum bitrate.
  ///
  long bitRate;
};

class MediaService {
public:
  MediaService()
  {
    ;
  }

  /// 
  /// Gets the camera's audio and video sources, their capabilities, and configuration parameters.
  /// 
  /// \param[in] mediaType - selected media type
  /// \param[in] mediaParamList - list of input sources capability for the mediaType 
  ///
  virtual void getMediaSources(const MediaType mediaType, std::vector<MediaSource> &mediaParamList) = 0;

  ///
  /// Initializes an audio or video source.
  ///
  /// \param[in] mediaType - selected media type
  /// \param[in] mediaParams - default parameter and capabilities for the mediaType
  ///
  virtual void initMediaSource(const MediaType mediaType, const MediaSource mediaSource) = 0;

  ///
  /// Changes parameters for an audio or video source.
  ///
  /// AnyConnect bandwidth management technology request for changes on the media
  /// configuration for smooth and seamless experience of streaming.
  ///
  /// \param[in] inputSource - source for which media params has changed
  /// \param[in] mediaType - for which media the params has changed
  /// \param[in] mediaParams - media parametes which has changed for the streaming session
  ///
  virtual void changeMediaParameters(const std::string &inputSource, const MediaType mediaType, const MediaSource& mediaSource) = 0;

  ///
  /// Decodes audio or video and returns a pointer to a decoded frame.
  ///
  /// \param[in] inputSource - the media stream source identifier 
  /// (if the camera has support for multiple stream).
  /// \param[in] mediaType - selected media type
  /// \param[in] inFramePtr - encoded frame data
  /// \param[in] inSize - encoded frame size
  /// \param[in] timestamp - time stamp of the frame
  /// \param[in] outFramePtr - decoded frame size
  /// \param[in] outSize - size of the decoded frame
  ///
  virtual void pushEncodedFrame(const std::string &inputSource, const MediaType mediaType, void *inFramePtr, long inSize, time_t timestamp, void *outFramePtr, long &outSize) = 0;

  ///
  /// Returns encoded audio or video to the EncoderService class.
  ///
  /// \param[in] inputSource - the media stream source identifier
  /// (if the camera has support for multiple stream).
  /// \param[in] encoded - is false, if raw frame requested. (raw frame required for vision ai)
  /// \param[in] mediaType - selected media type
  /// \param[in] framePtr - frame data
  /// \param[in] size - size of the frame
  /// \param[in] frameProperties - properties of the frame
  /// \param[in] timestamp - time stamp of the frame
  ///
  virtual void getFrame(const std::string &inputSource, const bool encoded, const MediaType mediaType, void *framePtr, long &size, time_t& timestamp) = 0;

  ///
  /// Requests an I-Frame (with PPS and SPS).
  ///
  /// \param[in] inputSource - source for which I-Frame requested
  /// \param[in] encoded - is false, if raw I-Frame requested. (raw frame required for vision ai)
  /// 
  virtual void requestIntraFrame(const std::string &inputSource, const bool encoded) = 0;  

  ///
  /// Stops encoding an audio or video source.
  ///
  /// \param[in] inputSource - source for which media params has changed
  /// \param[in] mediaType - for which close media is requested
  ///
  virtual void closeMedia(const std::string &inputSource, const MediaType mediaType) = 0;


  virtual ~MediaService()
  {
    ;
  }

};

} //< media
} //< anyconnect
} //< com

#endif