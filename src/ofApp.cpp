
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableDepthTest();
    ofBackground(0);
    
    shader.load("shaders/update.vert","shaders/update.frag");
    surface_shader.load("shaders/surface.vert", "shaders/surface.frag");
    
    // パーティクルの初期設定
    particle.setMode(OF_PRIMITIVE_POINTS);
    for (int i = 0; i < particleNum; i++){
        particle.addVertex(ofVec3f((float)i ,0.5,0));
    }
    
    cam.setDistance(2000);
    
    speedBuffer.allocate(particleNum, 1, GL_RGBA32F);
    positionBuffer_dist.allocate(particleNum, 1, GL_RGBA32F);
    positionBuffer_source.allocate(particleNum, 1, GL_RGBA32F);
    
    float * posAndAge = new float[particleNum * 4];
    for (int x = 0; x < particleNum; x++){
       
            int i = x;
            posAndAge[i*4 + 0] = ofRandom(-1.0,1.0);
            posAndAge[i*4 + 1] = ofRandom(-1.0,1.0);
            posAndAge[i*4 + 2] = ofRandom(-1.0,1.0);
            posAndAge[i*4 + 3] = 0;
       
    }
    positionBuffer_dist.getTextureReference(0).loadData(posAndAge, particleNum, 1, GL_RGBA32F);
    delete[] posAndAge;
}

//--------------------------------------------------------------
void ofApp::update(){
    
   

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    shader.setUniformTexture("posTex", positionBuffer_source.getTexture(), 0);
    //shader.setUniformTexture("speedTex", speedBuffer, 0);
    
    positionBuffer_dist.begin();
    positionBuffer_dist.activateAllDrawBuffers();
    ofClear(0);
    
    shader.begin();
    ofSetColor(100, 100, 100);
    ofDrawRectangle(0, 0, particleNum, 1);
    shader.end();
    positionBuffer_dist.end();
    ofPixels pixels;
    positionBuffer_dist.readToPixels(pixels);
    cout << pixels.size() << endl;
    for(int i = 0; i < positionBuffer_dist.getWidth(); i++){
        cout << (int)pixels[i * 4] << ',';
    }
    cout << endl;
    
    
    
    glPointSize(1.0);
    ofSetColor(255, 255, 255);
    positionBuffer_source = positionBuffer_dist;
    surface_shader.setUniformTexture("posTex", positionBuffer_source.getTexture(), 0);
    surface_shader.begin();
    particle.draw();
    surface_shader.end();
    //positionBuffer_dist.draw(100, 200);
    
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
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
