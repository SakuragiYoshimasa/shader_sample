uniform float u_time;
uniform sampler2DRect posTex;
uniform sampler2DRect speedTex;
uniform vec2 resolution;

varying vec2 vTexCoord;

void main(void)
{

    //vec4 position = texture2DRect(posTex, gl_FragCoord.xy) + vec4(0.01, 0.0, 0.0, 0.0);
    
    gl_FragColor = vec4((-0.5 + float(vTexCoord.x)  / 2048.0) * 2.0, 0.3, 0.0, 1.0);
}
