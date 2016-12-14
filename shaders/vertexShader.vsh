uniform vec3 position;
uniform mat4 rotation;

varying vec4 vColor;

void main(void)
{
    vec4 pos=vec4(position,0.0);
    vColor=vec4(abs(gl_Vertex).xyz,1.0);
   gl_Position = rotation*gl_Vertex+pos;
}
