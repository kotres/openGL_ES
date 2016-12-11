uniform vec3 position;
uniform mat4 rotation;

void main(void)
{
    vec4 pos=vec4(position,0.0);
   gl_Position = rotation*gl_Vertex+pos;
}
