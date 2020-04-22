#ifndef gui_hpp
#define gui_hpp

#include "ofxDatGui.h"
#include "VideoClass.hpp"
#include "RectTransform.hpp"

#include <stdio.h>
class GuiClass{
public:
    void setup();
    void update();
    void draw();

    
    ofxDatGui* gui;
    ofxDatGuiButton* buttonOpen;
    
    void onButtonEvent(ofxDatGuiButtonEvent e);
    


};
#endif /* gui_hpp */
