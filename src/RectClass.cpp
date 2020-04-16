#include "rect.hpp"

void RectMirror::setup(int _posX, int _posY, int _width, int _height, int _displayX, int _displayY, int _displayWidth, int _displayHeight){
    posX = _posX;
    posY = _posY;
    width = _width;
    height = _height;
    displayX = _displayX / divider;
    displayY = _displayY / divider;
    displayWidth = _displayWidth / divider;
    displayHeight = _displayHeight / divider;
    
    params.setName("rect params");
    params.add(posX.set("posX", posX, 0, ofGetWidth() ));
    params.add(posY.set("posY", posY, 0, ofGetHeight() ));
    params.add(width.set("width", width, 0, width));
    params.add(height.set("height", height, 0, height));
    mainGroup.add(params);
    gui.setup(mainGroup);
    
    panel.allocate(width, height, GL_RGB);

    
}

void RectMirror::update(){
        
}

void RectMirror::draw(){
    ofNoFill();
    panel.loadScreenData(posX, posY, width, height); //Get Mirror
    ofDrawRectangle(posX, posY, width, height); //draw Mirror Bounds
    panel.draw(0, 0, displayWidth, displayHeight); //Draw mirror on display
    ofDrawRectangle(0, 0, displayWidth, displayHeight); //draw display bounds
    gui.draw();
    
}

//--------------------------------------------------------------
void RectMirror::mouseDragged(int x, int y, int button){
    if (inside == true) {
        posX = x - ofsetx;
        posY = y - ofsety;
    }
    
}

//--------------------------------------------------------------
void RectMirror::mousePressed(int x, int y, int button){
    if( x > posX && x < (posX + width) &&  y > posY && y < (posY + height) ){
        ofsetx = x - posX;
        ofsety = y - posY;
        inside = true;
    }
}

//--------------------------------------------------------------
void RectMirror::mouseReleased(int x, int y, int button){
    inside = false;
}

