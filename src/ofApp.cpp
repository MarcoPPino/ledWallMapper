#include "ofApp.h"

ofFbo fboVid;
ofFbo fboView;
ofFbo fboViewLong;
VideoExtern videoExtern;
int sizeArr[5][8];
int longY = 0;
//--------------------------------------------------------------
void ofApp::setup(){

    int mirrorGrabberArr[5][4] = {{0, 0, 384, 960}, {384, 0, 384, 960}, {768, 0, 384, 960}, {1152, 0, 384, 767}, {1536, 30, 384, 930}};

    fboVid.allocate(ofGetWidth()/3*2, ofGetHeight(), GL_RGB);
    fboView.allocate(mirrorGrabberArr[0][2] * 5 / divider, mirrorGrabberArr[0][3] / divider, GL_RGB);
    fboViewLong.allocate(mirrorGrabberArr[0][2] / divider, mirrorGrabberArr[0][3] * 5 / divider, GL_RGB); // height isnt quite right
    
    videoExtern.setup();
    guiClass = new GuiClass();
    guiClass->setup();
    
    for(int i=0; i<ELEMCOUNT; i++){
        mirror[i].setup(mirrorGrabberArr[i]);
        longY = longY + mirror[i].displayHeight;
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i=0; i<ELEMCOUNT; i++){
            mirror[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    videoExtern.draw();
    
    fboView.begin();
    ofClear(150);
    fboView.end();
    
    fboViewLong.begin();
    ofClear(150);
    fboViewLong.end();

    for(int i=0; i<ELEMCOUNT; i++){
            mirror[i].draw();
    }

    fboVid.draw(ofGetWidth()/3, 0);
    fboView.draw(0,0);
    fboViewLong.draw(500,0);
    
    guiClass->draw();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    for(int i=0; i<ELEMCOUNT; i++){
            mirror[i].keyPressed(key);
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    videoExtern.keyReleased(key);
    for(int i=0; i<ELEMCOUNT; i++){
        mirror[i].keyReleased(key);
       }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    for(int i=0; i<ELEMCOUNT; i++){
            mirror[i].mouseDragged( x,  y,  button);
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    for(int i=0; i<ELEMCOUNT; i++){
            mirror[i].mousePressed(x, y, button);
    }
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    for(int i=0; i<ELEMCOUNT; i++){
            mirror[i].mouseReleased(x,  y, button);
    }
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
