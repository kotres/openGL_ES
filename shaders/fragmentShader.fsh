varying vec4 vColor;

void main (void)
{
   gl_FragColor = vColor; //vec4(vec3(gl_FragCoord.z),1.0);//vec4((0.5+0.5*sin(gl_FragCoord.xy)),0.5, 1.0);
}