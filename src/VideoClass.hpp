#ifndef VideoClass_hpp
#define VideoClass_hpp

#include <stdio.h>
#include "ofMain.h"
#include "ofxGui.h"
#include "ofxDatGui.h"
#include "ofxOpenCv.h"

extern ofVideoPlayer clip;
extern int videoX, videoY, videoW, videoH, videoMargin, videoDivisorH, videoDivisorW;

class VideoExtern{
public:
    void setup();
    void update();
    void draw();
};

#endif /* VideoClass_hpp */
