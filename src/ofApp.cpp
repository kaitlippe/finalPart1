#include "ofApp.h"
#include "Poco/Base64Decoder.h"


int vidX = 450;
int vidY = 375;


int imageDisplay;
int effect;


//--------------------------------------------------------------
void ofApp::setup(){
    w = ofGetWidth();
    h = ofGetHeight();
    
    setting.width  = w;
    setting.height = h;
    
    original.allocate(setting);
    
    //ksmrFX setup
    fx.setup(&original, setting);
    
    colorImg.allocate(vidX,vidY);
    vidGrabber.setVerbose(true);
    vidGrabber.setup(vidX,vidY);
    grayDiff.allocate(vidX,vidY);
    
    bLearnBakground = true;
    threshold = 13;
    
    one.load("1.jpg");
    two.load("2.jpg");
    three.load("3.jpg");
    four.load("4.jpg");
    five.load("5.jpg");
    six.load("6.jpg");
    seven.load("7.jpg");
    eight.load("8.jpg");
    nine.load("9.jpg");
    ten.load("10.jpg");
    eleven.load("11.jpg");
    twelve.load("12.jpg");
    thirteen.load("13.jpg");
    fourteen.load("14.jpg");

    imageDisplay = 1;


}

//--------------------------------------------------------------
void ofApp::update(){
    ofBackground(100,100,100);
    bool bNewFrame = false;
    
    vidGrabber.update();
    bNewFrame = vidGrabber.isFrameNew();
    if (bNewFrame){
        colorImg.setFromPixels(vidGrabber.getPixels());
        grayImage = colorImg;
        if (bLearnBakground == true){
            grayBg = grayImage;
            bLearnBakground = false;
        }
        
        // take the abs value of the difference between background and incoming and then threshold:
        grayDiff.absDiff(grayBg, grayImage);
        grayDiff.threshold(threshold);
        
        contourFinder.findContours(grayDiff, 20, (vidX*vidY)/3, 5, false);
    }
    
    fx.getfxUnit(KSMR_FRAGFX_NOISE)->bEnable        = ofRandom(0,1);
    fx.getfxUnit(KSMR_FRAGFX_EDGEONTOP)->bEnable    = ofRandom(0,1);
    fx.getfxUnit(KSMR_FRAGFX_FRINGE)->bEnable       = ofRandom(0,1);
//    fx.getfxUnit(KSMR_FRAGFX_INVERT)->bEnable		= ofRandom(0,1);
    fx.getfxUnit(KSMR_FRAGFX_SLANTSHIFT)->bEnable	= ofRandom(0,1);
    fx.getfxUnit(KSMR_FRAGFX_TEXCHIP)->bEnable		= ofRandom(0,1);
    fx.getfxUnit(KSMR_FRAGFX_VERTNOISE)->bEnable	= ofRandom(0,1);
//    fx.getfxUnit(KSMR_FRAGFX_VERTSLIDE)->bEnable	= ofRandom(0,1);
    
}

//--------------------------------------------------------------
void ofApp::draw(){
//    grayDiff.draw(w/2-500, 385);
//    ofFill();
//    ofSetHexColor(0xffffff);
//
//    ofDrawRectangle(w/2+50, 200,vidX,vidY);
//    ofSetHexColor(0xffffff);
//    contourFinder.draw(w/2+50, 200);
    
    if (imageDisplay == 1) {
        original.begin();{
            ofSetColor(255);
            one.draw(0, 0, w, h);
        }original.end();
        
        ofSetColor(255);
        fx.applyFx();
        original.draw(0, 0, w,h);
    } else if (imageDisplay == 2) {
        original.begin();{
            ofSetColor(255);
            two.draw(0, 0, w, h);
        }original.end();
        
        ofSetColor(255);
        fx.applyFx();
        original.draw(0, 0, w,h);
    } else if (imageDisplay == 3) {
        original.begin();{
            ofSetColor(255);
            three.draw(0, 0, w, h);
        }original.end();
        
        ofSetColor(255);
        fx.applyFx();
        original.draw(0, 0, w,h);
    } else if (imageDisplay == 4) {
        original.begin();{
            ofSetColor(255);
            four.draw(0, 0, w, h);
        }original.end();
        
        ofSetColor(255);
        fx.applyFx();
        original.draw(0, 0, w,h);
    } else if (imageDisplay == 5) {
        original.begin();{
            ofSetColor(255);
            five.draw(0, 0, w, h);
        }original.end();
        
        ofSetColor(255);
        fx.applyFx();
        original.draw(0, 0, w,h);
    } else if (imageDisplay == 6) {
        original.begin();{
            ofSetColor(255);
            six.draw(0, 0, w, h);
        }original.end();
        
        ofSetColor(255);
        fx.applyFx();
        original.draw(0, 0, w,h);
    } else if (imageDisplay == 7) {
        original.begin();{
            ofSetColor(255);
            seven.draw(0, 0, w, h);
        }original.end();
        ofSetColor(255);
        fx.applyFx();
        original.draw(0, 0, w,h);
    } else if (imageDisplay == 8) {
        original.begin();{
            ofSetColor(255);
            eight.draw(0, 0, w, h);
        }original.end();
        ofSetColor(255);
        fx.applyFx();
        original.draw(0, 0, w,h);
    } else if (imageDisplay == 9) {
        original.begin();{
            ofSetColor(255);
            nine.draw(0, 0, w, h);
        }original.end();
        ofSetColor(255);
        fx.applyFx();
        original.draw(0, 0, w,h);
    } else if (imageDisplay == 10) {
        original.begin();{
            ofSetColor(255);
            ten.draw(0, 0, w, h);
        }original.end();
        
        ofSetColor(255);
        fx.applyFx();
        original.draw(0, 0, w,h);
    } else if (imageDisplay == 11) {
        original.begin();{
            ofSetColor(255);
            eleven.draw(0, 0, w, h);
        }original.end();
        ofSetColor(255);
        fx.applyFx();
        original.draw(0, 0, w,h);
    } else if (imageDisplay == 12) {
        original.begin();{
            ofSetColor(255);
            twelve.draw(0, 0, w, h);
        }original.end();
        ofSetColor(255);
        fx.applyFx();
        original.draw(0, 0, w,h);
    } else if (imageDisplay == 13) {
        original.begin();{
            ofSetColor(255);
            thirteen.draw(0, 0, w, h);
        }original.end();
        ofSetColor(255);
        fx.applyFx();
        original.draw(0, 0, w,h);
    } else if (imageDisplay == 14) {
        original.begin();{
            ofSetColor(255);
            fourteen.draw(0, 0, w, h);
        }original.end();
        ofSetColor(255);
        fx.applyFx();
        original.draw(0, 0, w,h);
    }
    
//    imageDisplay = ofRandom(1, 14);
//    ofSleepMillis(5000);
}



//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key ==' '){
        imageDisplay++;
    }
 
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
