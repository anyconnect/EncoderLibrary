#include "MediaService.h"
#include <functional>

using namespace com::anyconnect::media;

class Test {
void* handle;
MediaService* instance;
MediaService* (*create)();
void (*destroy)(MediaService*);

public:
  Test();
  ~Test();
void loadLib(std::string name);
bool isLoaded();
bool getMediaParams();
 
};

