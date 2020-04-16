#ifndef rect_hpp
#define rect_hpp

#include "ofMain.h"
#include "ofxGui.h"

class RectMirror{
public:
    void setup(int, int, int, int, int, int, int, int);
    void update();
    void draw();
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void keyReleased(int key);
    
ofxPanel gui;
ofParameterGroup mainGroup;
ofParameterGroup params;
ofParameter<int> posX, posY, width, height;
int displayX, displayY, displayWidth, displayHeight;

ofTexture panel;

int divider = 4;
int ofsetx, ofsety;
bool inside = false;


    
};


#endif /* rect_hpp */
