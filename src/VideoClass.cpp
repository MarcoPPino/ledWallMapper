#include "VideoClass.hpp"
#include "ofApp.h"

ofVideoPlayer clip;
int videoX, videoY, videoW, videoH, videoMargin, videoDivisorH, videoDivisorW;

void VideoExtern::setup(){
    clip.load("test_long.mp4");
    clip.play();
    
    videoMargin = 0;
    
    if(clip.getWidth() < clip.getHeight()){
        videoH = fboVid.getHeight() - videoMargin;
        videoW = videoH * clip.getWidth() / clip.getHeight();
        videoX = fboVid.getWidth() / 2 - videoW / 2;
        videoY = fboVid.getHeight() / 2 - videoH / 2;
        
        videoDivisorH = clip.getHeight() / videoH;
        videoDivisorW = clip.getWidth() / videoW;
    }else{
        videoW = fboVid.getWidth() - videoMargin;
        videoH = videoW * clip.getHeight() / clip.getWidth();
        videoX = 0;
        videoY = fboVid.getHeight() / 2 - videoH / 2;
    }
}

void VideoExtern::update(){
    clip.update();
}

void VideoExtern::draw(){
    fboVid.begin();
    ofClear(50);
    clip.draw(videoX, videoY, videoW, videoH);
    fboVid.end();
}

