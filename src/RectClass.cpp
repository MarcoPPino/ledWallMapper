#include "RectClass.hpp"
#include "ofApp.h"

ofxPanel gui;

void Mirror::setup(int mirrorGrabberArr[5]){
    if(clip.isLoaded()){
        mirrorBoundsX = 0;
        mirrorBoundsY = 0;
        if(clip.getWidth() < clip.getHeight()){
            mirrorBoundsW = videoDisplayW;
            mirrorBoundsH = videoDisplayH / 5;
        }else{
            mirrorBoundsW = videoDisplayW / 5;
            mirrorBoundsH = videoDisplayH;
        }
    }
    displayX = mirrorGrabberArr[0] / divider; //Get Position & size of MirrorDisplay -  might change soon
    displayY = mirrorGrabberArr[1] / divider;
    displayWidth = mirrorGrabberArr[2] / divider;
    displayHeight = mirrorGrabberArr[3] / divider;
    
    mirrorContainer.allocate(ofGetWidth(), ofGetWidth()); //Allocate the Class Member context
    
    rectTransform.setup(25,25);
}

void Mirror::update(){
    rectTransform.update();
    nativeX = ofMap(mirrorBoundsX, 0, videoDisplayW, 0, clip.getWidth());
    nativeY = ofMap(mirrorBoundsY, 0, videoDisplayH, 0, clip.getHeight());
    nativeW = ofMap(mirrorBoundsW, 0, videoDisplayW, 0, clip.getWidth());
    nativeH = ofMap(mirrorBoundsH, 0, videoDisplayH, 0, clip.getHeight());
    
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
        ofSetColor(255, 34, 255);
        ofSetLineWidth(2);
        ofDrawRectangle(mirrorBoundsX + videoDisplayX , mirrorBoundsY + videoDisplayY, mirrorBoundsW, mirrorBoundsH); // if active draw Mirror Bounds
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
    
    if (insideMirrorGrabber == true && clickedMirrorDisplay == true) {
        mirrorBoundsX = x - ofsetx;
        mirrorBoundsY = y - ofsety;
    }
    
//    if(x - ofsetx < videoDisplayX){
//        mirrorBoundsX = 0;
//        std::cout << "Yooooo get back " << "\n";
//    }
}


//--------------------------------------------------------------
void Mirror::mousePressed(int x, int y, int button){
    rectTransform.mousePressed(x - ofGetWidth()/3, y, button);
    
    if( x > mirrorBoundsX + ofGetWidth()/3 + videoDisplayX && x < ((mirrorBoundsX + mirrorBoundsW + ofGetWidth()/3) + videoDisplayX ) &&  y > mirrorBoundsY && y < (mirrorBoundsY + mirrorBoundsH) && clickedMirrorDisplay == true ){ // ACHTUNG WORKAROUND "ofGetWidth()/3"
        ofsetx = x - mirrorBoundsX;
        ofsety = y - mirrorBoundsY;
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
    rectTransform.mouseReleased(x - ofGetWidth()/3, y, button);
    insideMirrorGrabber = false;
}

