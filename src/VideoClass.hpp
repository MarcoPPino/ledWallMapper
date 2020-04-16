#ifndef VideoClass_hpp
#define VideoClass_hpp

#include <stdio.h>
#include "ofMain.h"
#include "ofxGui.h"
#include "ofxDatGui.h"
#include "ofxOpenCv.h"

extern ofVideoPlayer clip;
extern int videoDisplayX, videoDisplayY, videoDisplayW, videoDisplayH, videoDisplayMargin, videoDivisorH;

class VideoExtern{
public:
    void setup();
    void update();
    void draw();
    void keyReleased(int key);
    
    void processOpenFileSelection(ofFileDialogResult openFileResult);
    
};

#endif /* VideoClass_hpp */
