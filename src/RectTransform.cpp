#include "RectTransform.hpp"
#include "ofApp.h"
#include <GLUT/GLUT.h>

//--------------------------------------------------------------
void RectTransform::setup(int initX, int initY, int initWidth, int initHeight ){
    rec.set(initX, initY, initWidth, initHeight);
    cornerSize = 10;
    sideSize = 8;
    
    startWidth=0;
    startHeight=0;
}

//--------------------------------------------------------------
void RectTransform::update(){
    corner1.set(rec.getMinX() - cornerSize / 2, rec.getMinY() - cornerSize / 2, cornerSize, cornerSize);
    corner2.set(rec.getMaxX() - cornerSize / 2, rec.getMinY() - cornerSize / 2, cornerSize, cornerSize);
    corner3.set(rec.getMaxX() - cornerSize / 2, rec.getMaxY() - cornerSize / 2, cornerSize, cornerSize);
    corner4.set(rec.getMinX() - cornerSize / 2, rec.getMaxY() - cornerSize / 2, cornerSize, cornerSize);
    side1.set(rec.getHorzAnchor(OF_ALIGN_HORZ_CENTER) - sideSize / 2, rec.getMinY() - sideSize / 2, sideSize, sideSize);
    side2.set(rec.getMaxX() - sideSize / 2, rec.getVertAnchor(OF_ALIGN_VERT_CENTER) - sideSize / 2, sideSize, sideSize);
    side3.set(rec.getHorzAnchor(OF_ALIGN_HORZ_CENTER) - sideSize / 2, rec.getMaxY() - sideSize / 2, sideSize, sideSize);
    side4.set(rec.getMinX() - sideSize / 2, rec.getVertAnchor(OF_ALIGN_VERT_CENTER) - sideSize / 2, sideSize, sideSize);
    
    x = rec.getX();
    y = rec.getY();
    width = rec.getWidth();
    height = rec.getHeight();
    
}

//--------------------------------------------------------------
void RectTransform::draw(){
    ofSetColor(255,255,255);
    ofNoFill();
    ofDrawRectangle(rec);
    ofDrawRectangle(corner1);
    ofDrawRectangle(corner2);
    ofDrawRectangle(corner3);
    ofDrawRectangle(corner4);
    
    ofDrawRectangle(side1);
    ofDrawRectangle(side2);
    ofDrawRectangle(side3);
    ofDrawRectangle(side4);
    
    if(insideGlobal == true || insideHandle == true){
        string x = ofToString(rec.getX());
        string y = ofToString(rec.getY());
        string w = ofToString(rec.getWidth());
        string h = ofToString(rec.getHeight());
        string str;
        if(insideGlobal == true){
            str ="X: " + x + "px" + "\n" + "Y: " + y + "px";
        }
        if(insideHandle == true){
            str = "Width:  " + w + "px" + "\n" + "Height: " + h + "px";
        }
        if(insideSide1 == true || insideSide3 == true){
            str = "Height: " + h  + "px";
        }
        if(insideSide2 == true || insideSide4 == true){
            str = "Width:  " + w + "px";
        }
        ofDrawBitmapStringHighlight(str, ofGetMouseX() - ofGetWidth()/3 + 10, ofGetMouseY() - 10);
    }

    
}

//--------------------------------------------------------------
void RectTransform::keyPressed(int key){
    if (OF_KEY_SHIFT) {
        shiftPressed = true;
    }
}

//--------------------------------------------------------------
void RectTransform::keyReleased(int key){
    if (OF_KEY_SHIFT) {
        shiftPressed = false;
    }
}

//--------------------------------------------------------------
void RectTransform::mouseDragged(int x, int y, int button){
    if(insideGlobal == true && insideHandle == false){
        rec.setPosition(x - ofsetX, y - ofsetY);
    }
    
    if(insideCorner1 == true){
        if(x < rec.getX() || x > rec.getX()){
            rec.set(x, rec.getY(), rec.getMaxX() - x, rec.getHeight());
        }
        if(y < rec.getY() || y > rec.getY()){
            rec.set(rec.getX(), y, rec.getWidth(), rec.getMaxY() - y);
        }
    }
    
    if(insideCorner2 == true){
        if(x < rec.getMaxX() || x > rec.getMaxX()){
            rec.set(rec.getX(), rec.getY(), x - rec.getX() , rec.getHeight());
        }
        if(y < rec.getMinY() || y > rec.getMinY()){
            rec.set(rec.getX(), y, rec.getWidth() , rec.getMaxY() - y);
        }
        
    }
    
    if(insideCorner3 == true){
        rec.setSize(x - rec.getX(), y - rec.getY());
        float factor;
        if(shiftPressed == true){
            if(abs(startWidth - rec.getWidth()) > abs(startHeight - rec.getHeight())){
                factor = abs(startWidth - rec.getWidth());
            }else{
                factor = abs(startHeight - rec.getHeight());
            }
            if(startWidth < rec.getWidth() || startHeight < rec.getHeight() ){
                rec.setWidth(startWidth + factor);
                rec.setHeight(startHeight + factor);
            }else{
                rec.setWidth(startWidth - factor);
                rec.setHeight(startHeight - factor);
            }
        }
    }
    
    if(insideCorner4 == true){
        if(x < rec.getMaxX() || x > rec.getMaxX()){
            rec.set(x, rec.getY(), rec.getMaxX() - x , rec.getHeight());
        }
        if(y < rec.getMaxY() || y > rec.getMaxY()){
            rec.set(rec.getX(), y, rec.getWidth(), rec.getMinY() - y);
        }
    }
    
    if(insideSide1 == true){
        rec.set(rec.getX(), y, rec.getWidth() , rec.getMaxY() - y);
    }
    
    if(insideSide2 == true){
        rec.set(rec.getX(), rec.getY(), x - rec.getX() , rec.getHeight());
    }
    
    if(insideSide3 == true){
        rec.set(rec.getX(), rec.getY(), rec.getWidth() , y - rec.getY());
    }
    
    if(insideSide4 == true){
        rec.set(x, rec.getY(), rec.getMaxX() - x , rec.getHeight());
    }
    
}

//--------------------------------------------------------------
void RectTransform::mousePressed(int x, int y, int button){
    if(rec.inside(x,y) && insideGlobal == false){
        ofsetX = x - rec.getX();
        ofsetY = y - rec.getY();
        insideGlobal = true;
    }
    
    if(corner1.inside(x,y) && insideCorner1 == false){
        insideCorner1 = true;
        insideHandle = true;
    }
    
    if(corner2.inside(x,y) && insideCorner2 == false){
        insideCorner2 = true;
        insideHandle = true;
    }
    
    if(corner3.inside(x,y) && insideCorner3 == false){
        insideCorner3 = true;
        insideHandle = true;
        startWidth = rec.getWidth();
        startHeight = rec.getHeight();
    }
    
    if(corner4.inside(x,y) && insideCorner4 == false){
        insideCorner4 = true;
        insideHandle = true;
    }
    
    if(side1.inside(x,y) && insideSide1 == false){
        insideSide1 = true;
        insideHandle = true;
    }
    
    if(side2.inside(x,y) && insideSide2 == false){
        insideSide2 = true;
        insideHandle = true;
    }
    
    if(side3.inside(x,y) && insideSide3 == false){
        insideSide3 = true;
        insideHandle = true;
    }
    
    if(side4.inside(x,y) && insideSide4 == false){
        insideSide4 = true;
        insideHandle = true;
    }
    
    
}

//--------------------------------------------------------------
void RectTransform::mouseReleased(int x, int y, int button){
    insideGlobal = false;
    insideHandle = false;
    
    insideCorner1 = false;
    insideCorner2 = false;
    insideCorner3 = false;
    insideCorner4 = false;
    
    insideSide1 = false;
    insideSide2 = false;
    insideSide3 = false;
    insideSide4 = false;
    
}

