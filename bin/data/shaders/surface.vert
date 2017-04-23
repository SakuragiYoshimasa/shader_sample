
varying vec2 vTexCoord;
uniform sampler2DRect posTex;


void main() {
    vTexCoord =  gl_Vertex.xy;
    vTexCoord.x = vTexCoord.x;
    
    vec4 position = texture2DRect(posTex, vTexCoord); // texcoord 0-2047
    gl_Position = position;
}
