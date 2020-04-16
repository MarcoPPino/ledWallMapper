# ledWallMapper
ledWallMapper is an openFrameworks project that mirrors user specified parts of a video to fbo's which can then be displayed on our new LedWall @ work.  

So we've got a new led wall @ work with pretty uncommon dimensions (384 x 4577). <br/>
The wall consists of 5 panel groups which are mapped next to each other so the whole wall can run on one videofile (1920 x 1080). See the figure below for better understanding
![ledWall_mappingExplanation](https://user-images.githubusercontent.com/25278349/79458789-9feacd80-7ff2-11ea-8879-d4a06d3059b7.png)

As not everybody in our office works with video software or the terminal, to use the commands we've been writing for the inputVideo->mapping conversion, we needed something with a gui: <br/>
LedWallMapper loads a video and provides functionality to define which part of the video should be mapped to each panel.
Should be fairly easy to port for use with other dimensions and panels.

screenshots will follow as soon as i get it to work again.

issues:
- RectClass instantiates rectTransform just once instead of 5 times
- export of video needs to be rewritten
- Mirrors bigger than the video scales the displayed part on the mirrordisplay

todo: 
- LESS MESS
- more options to show things other then videos. eg. shaders
- check if sending fbo via syphon to another app works properly -> maybe theres no need for video export -> live 
