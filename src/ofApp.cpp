#include "ofApp.h"

void ofApp::setup(){
    
    //Settings
    ofEnableDepthTest();
    ofSetVerticalSync(false);
    ofBackground(0);
    cam.setDistance(200);
    
    //Loading Shader
    shader.load("shaders/update.vert","shaders/update.frag");
    surface_shader.load("shaders/surface.vert", "shaders/surface.frag");
    
    //Init particle positon(=>surface.vert::gl_Vertex.xy)
    //Set postion only here
    //because I need texcoord like these...
    //xy = (0, 0.5), (1, 0.5), (2, 0.5), ... (particleNum - 2, 0.5), (particleNum - 1, 0.5)
    particle.setMode(OF_PRIMITIVE_POINTS);
    for (int i = 0; i < particleNum; i++){
        particle.addVertex(ofVec3f((float)i ,0.5,0));
    }
    
    //No comment
    init_fbo();
}


void ofApp::update(){

    //Draw To FBO 'dist'
    dist->begin();
    dist->activateAllDrawBuffers();
    
    ofClear(0);
    //Use update_shader
    //posTex = source
    //update.vert : pass a particle position(to draw) and texcoord extracted from source
    //update.frag : calc a previous frame position to new position
    shader.begin();
    shader.setUniform1f("u_time", ofGetElapsedTimef());
    shader.setUniformTexture("posTex", source->getTexture(), 0);
    source->draw(0, 0);
    shader.end();
    //'dist' has colors representing particle positions;
    dist->end();
    
    //Swap to 'dist' is used to only distination, 'source' only parameter
    swap();
}

void ofApp::draw(){
    //Rendering
    renderFbo.begin();
    
    //Settings
    ofClear(0);
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    ofEnablePointSprites();
    glPointSize(1.0);
    ofSetColor(255, 255, 255);
    
    
    //dipict particle using surface_shader
    //posTex = source(=drawed at update to (copy of dist))
    //surface.vert : pass a particle position and texcoord extracted from source
    //               and put that position * MVP mat into gl_position
    //surface.frag : set particle color
    surface_shader.setUniformTexture("posTex", source->getTexture(), 0);
    surface_shader.begin();
    particle.draw();
    surface_shader.end();
    

    renderFbo.end();
    renderFbo.draw(0,0);
}

void ofApp::init_fbo(){
    
    ofFbo::Settings fboSettings;
    fboSettings.width  = particleNum;
    fboSettings.height = 1;
    fboSettings.numColorbuffers = 1;
    fboSettings.useDepth = false;
    fboSettings.internalformat = GL_RGBA32F;
    fboSettings.wrapModeHorizontal = GL_CLAMP_TO_EDGE;
    fboSettings.wrapModeVertical = GL_CLAMP_TO_EDGE;
    fboSettings.minFilter = GL_NEAREST;
    fboSettings.maxFilter = GL_NEAREST;
    
    positionBuffer_dist.allocate(fboSettings);
    positionBuffer_source.allocate(fboSettings);
    
    float * src = new float[particleNum * 4];
    for (int x = 0; x < particleNum; x++){
        //src[x*4 + 0] = ofRandom(-1.0,1.0);
        //src[x*4 + 1] = ofRandom(-1.0,1.0);
        //src[x*4 + 2] = ofRandom(-1.0,1.0);
        src[x*4 + 0] = (float)x;
        src[x*4 + 1] = 0.5;
        src[x*4 + 2] = 0;
        src[x*4 + 3] = 1.0;
    }
    
    float * dst = new float[particleNum * 4];
    for (int x = 0; x < particleNum; x++){
        dst[x*4 + 0] = 0.0;
        dst[x*4 + 1] = 0.0;
        dst[x*4 + 2] = 0.0;
        dst[x*4 + 3] = 1.0;
    }
    renderFbo.allocate(ofGetWidth(), ofGetHeight());
    positionBuffer_source.getTexture().loadData(src, particleNum, 1, GL_RGBA);
    positionBuffer_dist.getTexture().loadData(dst, particleNum, 1, GL_RGBA);
    
    dist = &positionBuffer_dist;
    source = &positionBuffer_source;
    
    delete[] src;
    delete[] dst;
}

void ofApp::swap(){
    ofFbo * temp = source;
    source = dist;
    dist = temp;
}

void ofApp::keyPressed(int key){
    //output fbo as png to confirmation
    if(key =='s'){
        ofPixels pixels;
        renderFbo.readToPixels(pixels);
        ofImage img;
        img.setFromPixels(pixels);
        char fileNameStr[255];
        string date = ofGetTimestampString();
        sprintf(fileNameStr, "%s.png", date.c_str());
        img.save(fileNameStr,OF_IMAGE_QUALITY_BEST);
    }
}


void ofApp::keyReleased(int key){

}


void ofApp::mouseMoved(int x, int y ){

}


void ofApp::mouseDragged(int x, int y, int button){

}


void ofApp::mousePressed(int x, int y, int button){

}


void ofApp::mouseReleased(int x, int y, int button){

}


void ofApp::mouseEntered(int x, int y){

}


void ofApp::mouseExited(int x, int y){

}


void ofApp::windowResized(int w, int h){

}


void ofApp::gotMessage(ofMessage msg){

}


void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
