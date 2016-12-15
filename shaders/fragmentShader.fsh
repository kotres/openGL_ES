varying vec4 vColor;
varying vec3 N;
varying vec3 v;

void main (void)
{

    vec3 L = normalize(gl_LightSource[0].position.xyz - v);
    vec4 Idiff = gl_FrontLightProduct[0].diffuse * max(dot(N,L), 0.0);
    Idiff = clamp(Idiff, 0.0, 1.0);
   //gl_FragColor = vColor; //vec4(vec3(gl_FragCoord.z),1.0);//vec4((0.5+0.5*sin(gl_FragCoord.xy)),0.5, 1.0);
    gl_FragColor=Idiff;
}
