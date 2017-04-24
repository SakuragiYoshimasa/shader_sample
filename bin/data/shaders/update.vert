#extension GL_ARB_texture_rectangle : enable 
#extension GL_EXT_gpu_shader4 : enable

uniform sampler2DRect posTex;
uniform float u_time;
varying vec2 vTexCoord;
varying vec4 pos;

void main() {
    vTexCoord = gl_Vertex.xy;
    pos = vec4(texture2DRect(posTex, vTexCoord).rgb, 1.0); // texcoord 0-2047
    gl_Position = ftransform();
}
