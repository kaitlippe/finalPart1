#pragma once

#include "ofMain.h"
#include "ofxKsmrFragmentFx.h"
#include "ofxOpenCV.h"

#define _USE_LIVE_VIDEO


class drawImage {
public:
    void setup();
    void update();
    void draw();
    
    ofFbo::Settings		setting;
    ofFbo				original;
    
    ofxKsmrFragmentFx	fx;
    
    float w;
    float h;
};

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    //KsmrFragmentFx
    ofFbo::Settings		setting;
    ofFbo				original;
    
    ofxKsmrFragmentFx	fx;
    
    //openCV
#ifdef _USE_LIVE_VIDEO
    ofVideoGrabber vidGrabber;
#else
    ofVideoPlayer vidPlayer;
#endif
    
    ofxCvColorImage	colorImg;
    
    ofxCvGrayscaleImage grayImage;
    ofxCvGrayscaleImage grayBg;
    ofxCvGrayscaleImage grayDiff;
    
    ofxCvContourFinder contourFinder;
    
    int threshold;
    bool bLearnBakground;
    
    float w;
    float h;
    
    ofImage one;
    ofImage two;
    ofImage three;
    ofImage four;
    ofImage five;
    ofImage six;
    ofImage seven;
    ofImage eight;
    ofImage nine;
    ofImage ten;
    ofImage eleven;
    ofImage twelve;
    ofImage thirteen;
    ofImage fourteen;

		
};
