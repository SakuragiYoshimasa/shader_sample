#pragma once

#include "ofMain.h"

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
    
private:
    #pragma mark fbo_manipulation
    void swap();
    void init_fbo();
    
    #pragma mark particle
    const int particleNum = 2048;
	ofVboMesh particle;
    
    #pragma mark shaders
    ofShader shader;
    ofShader surface_shader;
    
    #pragma mark fbo_instances
    ofFbo positionBuffer_source;
    ofFbo positionBuffer_dist;

    #pragma mark fbo_pointers
    ofFbo * source;
    ofFbo * dist;
    
    #pragma mark Render
    ofEasyCam cam;
    ofFbo renderFbo;
};
