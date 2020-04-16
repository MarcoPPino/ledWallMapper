#include "RectClass.hpp"
#include "ofApp.h"

ofxPanel gui;

void Mirror::setup(int mirrorGrabberArr[5]){
    posX = 0; //Get Position & size of MirrorGrabber -  might change soon
    posY = 0;
    if(clip.getWidth() < clip.getHeight()){
        width = clip.getWidth();
        height = clip.getHeight() / 5;
    }else{
        width = clip.getWidth() / 5;
        height = clip.getHeight() ;
    }
    
    
    displayX = mirrorGrabberArr[0] / divider; //Get Position & size of MirrorDisplay -  might change soon
    displayY = mirrorGrabberArr[1] / divider;
    displayWidth = mirrorGrabberArr[2] / divider;
    displayHeight = mirrorGrabberArr[3] / divider;
    
    mirrorContainer.allocate(ofGetWidth(), ofGetWidth()); //Allocate the Class Member context
    
    params.setName("rect params"); // init and Setup of GUI + Param bounding
    params.add(posX.set("posX", posX, 0, ofGetWidth() ));
    params.add(posY.set("posY", posY, 0, ofGetHeight() ));
    params.add(width.set("width", width, 0, width));
    params.add(height.set("height", height, 0, height));
    mainGroup.add(params);
    gui.setup();
    gui.setPosition(0,fboView.getHeight());
    gui.add(mainGroup);
}

void Mirror::update(){
        clip.update(); //Update Video from videoClass
        mirrorContainer.setFromPixels(clip.getPixels().getData(), clip.getWidth(), clip.getHeight()); // Grab the Whole video. MirrorContainer is CVColorImage
        mirrorContainer.resetROI(); //release ROI to be safe and clean for the next one
        mirrorContainer.setROI(posX * videoDivisorH, posY * videoDivisorW, width, height); //REAL MAGIC! WORK(ING) progress
    
        mirrorBoundsX = videoX + posX;
        mirrorBoundsY = videoY + posY;
        mirrorBoundsW = width / videoDivisorW;
        mirrorBoundsH = height / videoDivisorH;
}

void Mirror::draw(){
    fboVid.begin();
        ofNoFill();
    if(clickedMirrorDisplay == true){
            ofSetColor(255, 34, 255);
            ofSetLineWidth(2);
        ofDrawRectangle(mirrorBoundsX, mirrorBoundsY, mirrorBoundsW, mirrorBoundsH); // if active draw Mirror Bounds
        }
    fboVid.end();

    fboView.begin();
        ofNoFill();
        mirrorContainer.drawROI(displayX, displayY, displayWidth, displayHeight); //Draws the magic mirror to display
        ofDrawRectangle(displayX, displayY, displayWidth, displayHeight); //draw Mirror Bounds
    fboView.end();

}

//--------------------------------------------------------------
void Mirror::mouseDragged(int x, int y, int button){
    if (insideMirrorGrabber == true && clickedMirrorDisplay == true) {
        posX = x - ofsetx;
        posY = y - ofsety;
    }
}

//--------------------------------------------------------------
void Mirror::mousePressed(int x, int y, int button){
    if( x > posX + ofGetWidth()/3 && x < ((posX + ofGetWidth()/3) + width) &&  y > posY && y < (posY + height) && clickedMirrorDisplay == true ){ // ACHTUNG WORKAROUND "ofGetWidth()/3"
        ofsetx = x - posX;
        ofsety = y - posY;
        insideMirrorGrabber = true;
    }
    
    if( x > displayX && x < (displayX + displayWidth) &&  y > displayY && y < (displayY + displayHeight)){
        if ( clickedMirrorDisplay == true){
                clickedMirrorDisplay = false;
        }else{
            clickedMirrorDisplay = true;
        }
        
    }
}

//--------------------------------------------------------------
void Mirror::mouseReleased(int x, int y, int button){
    insideMirrorGrabber = false;
}

