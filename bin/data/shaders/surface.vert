varying vec2 vTexCoord;
uniform sampler2DRect posTex;

void main() {
    vTexCoord =  gl_Vertex.xy;
    vec4 position = vec4(texture2DRect(posTex, vTexCoord).xyz, 1.0); // texcoord 0-2047
    gl_Position = gl_ModelViewProjectionMatrix * position;
}
