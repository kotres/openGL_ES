
void main (void)
{
   gl_FragColor = vec4((0.5+0.5*sin(gl_FragCoord.xy)),0.5, 1.0);
}
