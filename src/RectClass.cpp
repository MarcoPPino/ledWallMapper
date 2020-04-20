#include "RectClass.hpp"
#include "ofApp.h"

ofxPanel gui;

void Mirror::setup(int mirrorGrabberArr[5]){
    rectTransform.setup(mirrorGrabberArr[0], mirrorGrabberArr[1], mirrorGrabberArr[2], mirrorGrabberArr[3]);
    
    divider = 4;
    displayX = mirrorGrabberArr[0] / divider; //Get Position & size of MirrorDisplay -  might change soon
    displayY = mirrorGrabberArr[1] / divider;
    displayWidth = mirrorGrabberArr[2] / divider;
    displayHeight = mirrorGrabberArr[3] / divider;
    
    mirrorContainer.allocate(ofGetWidth(), ofGetWidth()); //Allocate the Class Member context
}

void Mirror::update(){
    rectTransform.update();
    nativeX = ofMap(rectTransform.x, 0, videoDisplayW, 0, clip.getWidth());
    nativeY = ofMap(rectTransform.y, 0, videoDisplayH - 100, 0, clip.getHeight());
    nativeW = ofMap(rectTransform.width, 0, videoDisplayW, 0, clip.getWidth());
    nativeH = ofMap(rectTransform.height, 0, videoDisplayH, 0, clip.getHeight());
    
    
    
    clip.update(); //Update Video from videoClass
    mirrorContainer.setFromPixels(clip.getPixels().getData(), clip.getWidth(), clip.getHeight()); // Grab the Whole video. MirrorContainer is CVColorImage
    mirrorContainer.resetROI(); //release ROI to be safe and clean for the next one
    mirrorContainer.setROI(nativeX, nativeY, nativeW, nativeH);
}

void Mirror::draw(){
    fboVid.begin();
        ofNoFill();
    if(clickedMirrorDisplay == true){
        rectTransform.draw();
        }
    fboVid.end();

    fboView.begin();
        ofNoFill();
        mirrorContainer.drawROI(displayX, displayY, displayWidth, displayHeight); //Draws the magic mirror to display
        ofDrawRectangle(displayX, displayY, displayWidth, displayHeight); //draw Mirror Bounds
    fboView.end();
    
    

}
//--------------------------------------------------------------
void Mirror::keyPressed(int key){
    rectTransform.keyPressed(key);
}

//--------------------------------------------------------------
void Mirror::keyReleased(int key){
    rectTransform.keyReleased(key);
}

//--------------------------------------------------------------
void Mirror::mouseDragged(int x, int y, int button){
    rectTransform.mouseDragged(x - ofGetWidth()/3 , y, button);
}


//--------------------------------------------------------------
void Mirror::mousePressed(int x, int y, int button){
    rectTransform.mousePressed(x - ofGetWidth()/3, y, button);
    
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
    rectTransform.mouseReleased(x, y, button);
    insideMirrorGrabber = false;
}

