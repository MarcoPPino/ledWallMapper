#include "VideoClass.hpp"
#include "ofApp.h"

ofVideoPlayer clip;
int videoDisplayX, videoDisplayY, videoDisplayW, videoDisplayH, videoDisplayMargin, videoDivisorH;

void VideoExtern::setup(){
    ofSetLogLevel(OF_LOG_VERBOSE);
    videoDisplayMargin = 100;
    if(clip.getWidth() < clip.getHeight()){
        videoDisplayH = fboVid.getHeight() - videoDisplayMargin;
        videoDisplayW = videoDisplayH * clip.getWidth() / clip.getHeight();
        videoDisplayX = fboVid.getWidth() / 2 - videoDisplayW / 2;
        videoDisplayY = fboVid.getHeight() / 2 - videoDisplayH / 2;
    }else{
        videoDisplayW = fboVid.getWidth() - videoDisplayMargin;
        videoDisplayH = videoDisplayW * clip.getHeight() / clip.getWidth();
        videoDisplayX = fboVid.getWidth() / 2 - videoDisplayW / 2;
        videoDisplayY = fboVid.getHeight() / 2 - videoDisplayH / 2;
    }
    
    videoDivisorH = clip.getHeight() / videoDisplayH;
    
}

void VideoExtern::update(){
    clip.update();
}

void VideoExtern::draw(){
    fboVid.begin();
    ofClear(50);
    clip.draw(videoDisplayX, videoDisplayY, videoDisplayW, videoDisplayH);
    fboVid.end();
}

void VideoExtern::keyReleased(int key){
    if (key == ' '){
        ofFileDialogResult openFileResult= ofSystemLoadDialog("Select a Video file");
        
        if (openFileResult.bSuccess){
            
            ofLogVerbose("User selected a file");
            processOpenFileSelection(openFileResult);
            
        }else {
            ofLogVerbose("User hit cancel");
        }
    }
}

void VideoExtern::processOpenFileSelection(ofFileDialogResult openFileResult){
    ofLogVerbose("getName(): "  + openFileResult.getName());
    ofLogVerbose("getPath(): "  + openFileResult.getPath());
    
    ofFile file (openFileResult.getPath());
    
    if (file.exists()){
    
    ofLogVerbose("The file exists - now checking the type via file extension");
    string fileExtension = ofToUpper(file.getExtension());
    
    //We only want images
        if (fileExtension == "MP4" || fileExtension == "MPEG4" || fileExtension == "MOV" || fileExtension == "JPG") {
            ofLogVerbose("File could be loaded, it's a video!");
            
            clip.close();
            clip.load(openFileResult.getPath());
            clip.play();
            setup();
        }
    }
}
