#ifdef GL_ES
precision mediump float;
#endif

uniform vec2 u_resolution;
uniform vec2 u_mouse;
uniform float u_time;
uniform sampler2D u_texture_0;

float rand(float value){
    return fract(sin(value*127.1452)*43758.5453123);
}

void main(){
    float speed=100.+250.*rand(floor(gl_FragCoord.x/11.));
    float fade=5.+5.*rand(floor(gl_FragCoord.x/11.)+.1);
    float cycle=10.+15.*rand(floor(gl_FragCoord.x/11.)+.2);
    float offset=rand(floor(gl_FragCoord.x/11.)+.3)*250.;
    vec2 uv=(gl_FragCoord.xy+vec2(0.,speed*u_time+offset))/vec2(11.,14.);
    float coordY=floor(uv.y);
    float index=floor(rand(coordY+floor(u_time*2.))*2.);
    uv=fract(uv);
    vec4 color=texture2D(u_texture_0,vec2((uv.x+index)/2.,uv.y));
    color.a*=(1.-color.r)*(1.-1./fade*mod(coordY+.01,cycle));
    color.g+=1.;
    gl_FragColor=color;
}