//
//  drawImage.cpp
//  finalProjectTest
//
//  Created by Kaitlyn Lippe on 5/5/16.
//
//

#include "drawImage.hpp"
#include "ofApp.h"

void drawImage::setup() {
    w = ofGetWidth();
    h = ofGetHeight();
    
    setting.width  = w;
    setting.height = h;
    
    original.allocate(setting);
    
    //ksmrFX setup
    fx.setup(&original, setting);
    
}

void drawImage::update() {
    
    
}

void drawImage::draw() {
    original.begin();{
        ofSetColor(255);
//        image.draw(0, 0, w, h);
    }original.end();
    
    
    ofSetColor(255);
    fx.applyFx();
    original.draw(0, 0, w,h);
    
}
