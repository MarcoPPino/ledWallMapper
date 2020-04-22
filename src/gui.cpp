#include "gui.hpp"


//--------------------------------------------------------------
void GuiClass::setup(){
    gui = new ofxDatGui(0, 500);
    buttonOpen = gui->addButton("Load Video");
    
    buttonOpen->onButtonEvent(this, &GuiClass::onButtonEvent);
}

//--------------------------------------------------------------
void GuiClass::update(){
    
}

//--------------------------------------------------------------
void GuiClass::draw(){
    gui->draw();
}

//--------------------------------------------------------------
void GuiClass::onButtonEvent(ofxDatGuiButtonEvent e){
    ofFileDialogResult openFileResult = ofSystemLoadDialog("Select a Video file");
    
    if (openFileResult.bSuccess){
        
        ofLogVerbose("User selected a file");
        VideoExtern::processOpenFileSelection(openFileResult);
        
        
    }else {
        ofLogVerbose("User hit cancel");
    }
}


