#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxOpenCv.h"
#include "rect.hpp"

class ofApp : public ofBaseApp{

    public:
        void setup();
        void update();
        void draw();

        void keyPressed(int key);
        void keyReleased(int key);
        void mouseMoved(int x, int y );
        void mouseDragged(int x, int y, int button);
        void mousePressed(int x, int y, int button);
        void mouseReleased(int x, int y, int button);
        void mouseEntered(int x, int y);
        void mouseExited(int x, int y);
        void windowResized(int w, int h);
        void dragEvent(ofDragInfo dragInfo);
        void gotMessage(ofMessage msg);
    
    RectMirror rect;
    RectMirror rect2;
    RectMirror rect3;
    RectMirror rect4;
    RectMirror rect5;
    
    std::string w1;
    std::string w2;
    std::string w3;
    std::string w4;
    std::string w5;
    
    std::string h1;
    std::string h2;
    std::string h3;
    std::string h4;
    std::string h5;
    
    ofVideoPlayer video; 
    
    
//    int LedWall[5][8] = { {1000, 1000, 384, 960, 0, 0, 384, 960}, {1000, 1000, 384, 960, 384, 0, 384, 960}, {1000, 1000, 384, 960, 768, 0, 384, 960}, {1000, 1000, 384, 767, 1152, 0, 384, 767}, {1920, 0, 384, 930, 1536, 30, 384, 930} };
    
//    int ofsetx, ofsety;
//    bool inside = false;
    
//    ofTexture   panel1;
//    ofTexture   panel2;
//    ofTexture   panel3;
//    ofTexture   panel4;
//    ofTexture   panel5;
    
};

