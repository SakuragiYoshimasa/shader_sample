varying vec2 vTexCoord;
uniform sampler2DRect posTex;

void main() {
    vTexCoord =  gl_Vertex.xy;
    //vTexCoord.x = vTexCoord.x * 2048.0;
    //vTexCoord.y = vTexCoord.y * 1.0;
    gl_Position = ftransform();
}
