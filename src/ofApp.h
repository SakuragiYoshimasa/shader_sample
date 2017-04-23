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
		
    ofShader shader;
    ofShader surface_shader;
    const int particleNum = 2048;
   
    ofVboMesh particle;
    ofEasyCam cam;
    
    ofFbo positionBuffer_source;
    ofFbo positionBuffer_dist;
    ofTexture speedBuffer;
    
    ofMesh mesh;
    
     
    
};
