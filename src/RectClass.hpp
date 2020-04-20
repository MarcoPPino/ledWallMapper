#ifndef RectClass_hpp
#define RectClass_hpp

#include <stdio.h>
#include "ofMain.h"
#include "ofxGui.h"
#include "ofxDatGui.h"
#include "ofxOpenCv.h"
#include "RectTransform.hpp"

extern ofxPanel gui;


class Mirror{
public:
    void setup(int mirrorGrabberArr[]);
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    
    ofxPanel gui;
    ofParameterGroup mainGroup;
    ofParameterGroup params;
    ofParameter<int>  mirrorBoundsX, mirrorBoundsY, mirrorBoundsW, mirrorBoundsH;
    int displayX, displayY, displayWidth, displayHeight;
    int nativeX, nativeY, nativeW, nativeH;
    
    ofxCvColorImage mirrorContainer;
    
    RectTransform rectTransform;
    
    int divider;
    int ofsetx, ofsety;
    bool insideMirrorGrabber = false;
    bool clickedMirrorDisplay = false;
};
#endif /* RectClass_hpp */
