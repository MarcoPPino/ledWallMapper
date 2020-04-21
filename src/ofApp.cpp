#include "ofApp.h"

ofFbo fboVid;
ofFbo fboView;
VideoExtern videoExtern;
int sizeArr[5][8];
//--------------------------------------------------------------
void ofApp::setup(){
    
    int mirrorGrabberArr[5][4] = {{0, 0, 384, 960}, {384, 0, 384, 960}, {768, 0, 384, 960}, {1152, 0, 384, 767}, {1536, 30, 384, 930}};

    fboVid.allocate(ofGetWidth()/3*2, ofGetHeight(), GL_RGB);
    fboView.allocate(ofGetWidth()/3, 350, GL_RGB);
    
    videoExtern.setup();
    
    for(int i=0; i<ELEMCOUNT; i++){
        mirror[i].setup(mirrorGrabberArr[i]);
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

    for(int i=0; i<ELEMCOUNT; i++){
            mirror[i].draw();
    }

    fboVid.draw(ofGetWidth()/3, 0);
    fboView.draw(0,0);
    
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
