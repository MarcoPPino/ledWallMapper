//
//  vid.cpp
//  video_mapper
//
//  Created by marco.pisano on 30.03.20.
//

#include "vid.hpp"

void VideoClass::setup(){
    video.load("rocket.mp4");
    video.play();

}

void VideoClass::update(){
    video.update();
}

void VideoClass::draw(){
    video.draw(ofGetWidth() / 2 - video.getWidth() / 2, ofGetHeight() / 2 - video.getHeight() / 2, video.getWidth(), video.getHeight());
}
