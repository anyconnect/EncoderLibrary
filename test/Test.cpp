#include "Test.h"
#include "MediaService.h"
#include <assert.h>
#include <dlfcn.h>
#include <cstdio>
#include <iostream>
#include <unistd.h>
#include <vector>

Test::Test()
{

}

void Test::loadLib(std::string name) 
{
  instance = NULL;
  handle = dlopen(name.c_str(), RTLD_LAZY);
	 
  if (!handle) {
    printf("%s\n", dlerror());
    return;
  }

  create = (MediaService* (*)()) dlsym(handle, "create");
  destroy = (void(*)(MediaService*)) dlsym(handle, "destroy");

  char* error;
  if ((error = dlerror()) != NULL) {
    printf("%s\n", error);
    return;
  }

  instance = create();
}

bool Test::isLoaded() 
{
  return instance != NULL; 
}

bool Test::getMediaParams() 
{
  std::vector<MediaSource> config;
  
  // Get audio media info
  instance->getMediaSources(MediaType::AUDIO, config);

  // Show audio info
  for(int i = 0; i < int(config.size()); i++)
  {
      std::cout << config[i].inputSource << "\t" << static_cast<std::underlying_type<AudioCodec>::type>(config[i].audioCodec) << "\t" << static_cast<std::underlying_type<SampleRate>::type>(config[i].audioSampleRate) << std::endl;
  }

  config.clear();

  // Get video media info
  instance->getMediaSources(MediaType::VIDEO, config);

  // Show video info
  for(int i = 0; i < int(config.size()); i++)
  {
      std::cout << config[i].inputSource << "\t" << static_cast<std::underlying_type<VideoCodec>::type>(config[i].videoCodec) << "\t" << static_cast<std::underlying_type<VideoResolution>::type>(config[i].videoResolution) << "\t" << config[i].fps << "\t" << config[i].bitRate << std::endl;
  }
  return true;
}

Test::~Test() {
  destroy(instance);
  dlclose(handle);
  handle = NULL;
}

Test *pTest = new Test();

int main()
{
  pTest->loadLib("./libencoder.so");
  if(pTest->isLoaded()) {
    printf("Your AnyConnect Encoder Library loads!\n");
  }
  else {
    printf("Your AnyConnect Encoder Library does not load.\n");
  }
  pTest->getMediaParams(); 
  while(1) {
    sleep(3);
  }
  return 0;
}
