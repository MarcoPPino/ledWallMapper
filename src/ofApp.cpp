#include "ofApp.h"
//--------------------------------------------------------------
void ofApp::setup(){
    video.load("out_NoPad.mp4");
    video.play();

    rect.setup(500, 500, 384, 960, 0, 0, 384, 960);
    rect2.setup(550, 500, 384, 960, 384, 0, 384, 960);
    rect3.setup(600, 500, 384, 960, 768, 0, 384, 960);
    rect4.setup(650, 500, 384, 767, 1152, 0, 384, 767);
    rect5.setup(700, 500, 384, 930, 1536, 30, 384, 930);
    
    w1 = std::to_string(rect.width);
    w2 = std::to_string(rect2.width);
    w3 = std::to_string(rect3.width);
    w4 = std::to_string(rect4.width);
    w5 = std::to_string(rect5.width);
    
    h1 = std::to_string(rect.height);
    h2 = std::to_string(rect2.height);
    h3 = std::to_string(rect3.height);
    h4 = std::to_string(rect4.height);
    h5 = std::to_string(rect5.height);

}

//--------------------------------------------------------------
void ofApp::update(){
    video.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    video.draw(ofGetWidth() / 2 - video.getWidth() / 2, ofGetHeight() / 2 - video.getHeight() / 2, video.getWidth(), video.getHeight());
    rect.draw();
    rect2.draw();
    rect3.draw();
    rect4.draw();
    rect5.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if(key == ' '){
//            system(("/usr/local/bin/ffmpeg -i ../../../data/rocket.mp4 -filter_complex '[0]crop=100:100:0:0[l];[0]crop=100:100:0:100[r];[l][r]hstack' ../../../data/"+ ofGetTimestampString() +".mp4").c_str());
        system(("/usr/local/bin/ffmpeg -i ../../../data/out_NoPad.mp4 -filter_complex '[0]crop="+w1+":"+h1+":0:0[a];[0]crop="+w2+":"+h2+":384:0[b];[0]crop="+w3+":"+h3+":768:0[c];[0]crop="+w4+":"+h4+":1152:0,pad=384:960:0:0[d];[0]crop="+w5+":"+h5+":1536:30,pad=384:960:0:30[e];[a][b][c][d][e]hstack=inputs=5' ../../../data/"+ ofGetTimestampString() +".mp4").c_str());
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    rect.mouseDragged( x,  y,  button);
    rect2.mouseDragged( x,  y,  button);
    rect3.mouseDragged( x,  y,  button);
    rect4.mouseDragged( x,  y,  button);
    rect5.mouseDragged( x,  y,  button);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    rect.mousePressed(x, y, button);
    rect2.mousePressed(x, y, button);
    rect3.mousePressed(x, y, button);
    rect4.mousePressed(x, y, button);
    rect5.mousePressed(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    rect.mouseReleased(x,  y, button);
    rect2.mouseReleased(x,  y, button);
    rect3.mouseReleased(x,  y, button);
    rect4.mouseReleased(x,  y, button);
    rect5.mouseReleased(x,  y, button);
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
