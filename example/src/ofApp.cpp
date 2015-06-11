#include "ofApp.h"
#include "MappingObjectFactory.h"

//--------------------------------------------------------------
void ofApp::setup(){

    show_controls = true;

    //setup some content that should get mapped
    scene1.setup(1600, 900);
    scene2.setup(1600, 900);

    //create template mapping objects that can be added afterwards via button

    //option to add shapes that show the content of a given fbo

    ofPtr<MappingFbo> content1 = mapping.getControl()->addTemplate<MappingFbo>("scene1");
    content1->setFbo(scene1.getFbo());

    ofPtr<MappingFbo> content2 = mapping.getControl()->addTemplate<MappingFbo>("scene2");
    content2->setFbo(scene2.getFbo());

    //option to add black shapes
    ofPtr<MappingColorShape> black_shape = mapping.getControl()->addTemplate<MappingColorShape>("black");
    black_shape->setColor(ofColor(0));

    //option to add black shapes
    ofPtr<MappingImage> logo = mapping.getControl()->addTemplate<MappingImage>("image");
    logo->loadImage("images/ente.jpg");
    logo->setColor(ofColor(0,200,255));

    //init mapping and load mapping settings from xml
    mapping.setup("mapping/mapping.xml");

    //set size of control panel
    mapping.getControlView()->setup(ofGetWindowWidth()/2, ofGetWindowHeight());

}

//--------------------------------------------------------------
void ofApp::exit() {
}

//--------------------------------------------------------------
void ofApp::update() {

    //update the addon
    mapping.update();

    //update your content
    scene1.update();
    scene2.update();
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofSetColor(255);

    //draw the mapped output image and the controls
    mapping.draw(
                ofGetWidth()/2, 0,
                ofGetWidth()/2, ofGetHeight());

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    switch(key) {
    case 'c': {
        show_controls = !show_controls;
        mapping.showControls(show_controls);
    }
    case 'f': {
        ofToggleFullscreen();
    }
    default: break;
    }
	
}

//--------------------------------------------------------------
void ofApp::mouseMoved(ofMouseEventArgs &args){
	
}

//--------------------------------------------------------------
void ofApp::mouseDragged(ofMouseEventArgs &args){
}

//--------------------------------------------------------------
void ofApp::mousePressed(ofMouseEventArgs &args){
}

//--------------------------------------------------------------
void ofApp::mouseReleased(ofMouseEventArgs &args){
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
