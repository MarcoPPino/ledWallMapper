//
//  vid.hpp
//  video_mapper
//
//  Created by marco.pisano on 30.03.20.
//

#ifndef vid_hpp
#define vid_hpp
#include <stdio.h>
#include "ofMain.h"


class VideoClass{
public:
    void setup();
    void update();
    void draw();
    ofVideoPlayer video;
private:

};




#endif /* vid_hpp */
