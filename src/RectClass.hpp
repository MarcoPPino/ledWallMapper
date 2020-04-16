#ifndef RectClass_hpp
#define RectClass_hpp

#include <stdio.h>
#include "ofMain.h"
#include "ofxGui.h"
#include "ofxDatGui.h"
#include "ofxOpenCv.h"

extern ofxPanel gui;


class Mirror{
public:
    void setup(int mirrorGrabberArr[]);
    void update();
    void draw();
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    
    ofxPanel gui;
    ofParameterGroup mainGroup;
    ofParameterGroup params;
    ofParameter<int> posX, posY, width, height;
    int displayX, displayY, displayWidth, displayHeight;
    int mirrorBoundsX, mirrorBoundsY, mirrorBoundsW, mirrorBoundsH;
    
    ofxCvColorImage mirrorContainer;
    
    
    int divider = 4;
    int ofsetx, ofsety;
    bool insideMirrorGrabber = false;
    bool clickedMirrorDisplay = false;
};
#endif /* RectClass_hpp */
