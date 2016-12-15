uniform vec3 position;
uniform mat4 rotation;

varying vec3 N;
varying vec3 v;

varying vec4 vColor;

void main(void)
{
    v = vec3(gl_ModelViewMatrix * gl_Vertex);
    N = normalize(gl_NormalMatrix * gl_Normal);

    vec4 pos=vec4(position,0.0);
    vColor=vec4(abs(gl_Vertex).xyz,1.0);
   gl_Position = rotation*gl_Vertex+pos;
}
