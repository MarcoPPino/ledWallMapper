#pragma once

#include "ofMain.h"
#include "ofxDatGui.h"
#include "ofxOpenCv.h"
#include "RectClass.hpp"
#include "VideoClass.hpp"
#include "RectTransform.hpp"
#include "gui.hpp"

extern ofFbo fboVid;
extern ofFbo fboView;
extern ofFbo fboViewLong;
extern VideoExtern videoExtern;
extern int mirrorGrabberArr[5][4];
extern int longY;

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
    
    
    GuiClass* guiClass;
    
    #define ELEMCOUNT 5    
    Mirror mirror[ELEMCOUNT];
};
