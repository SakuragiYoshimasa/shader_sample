#version 120
#extension GL_ARB_texture_rectangle : enable
#extension GL_EXT_gpu_shader4 : enable
#pragma include "noise4D.frag"

uniform sampler2DRect posTex;
uniform float u_time;
varying vec2 vTexCoord;
varying vec4 pos;


void main(void)
{
    vec4 position = pos;
        
    if(position.x <= 2000.0){
        gl_FragColor = vec4(position.x + 3.0, position.y + 2.0, 0.0, 1.0);
        return;
    }else{
        gl_FragColor = vec4(100.0, 0.0, 0.0, 1.0);
        return;
        
    }
}
