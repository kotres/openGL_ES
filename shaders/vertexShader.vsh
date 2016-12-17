uniform mat4 worldMatrix;

varying vec3 N;
varying vec3 v;

varying vec4 vColor;

void main(void)
{
    v = vec3(gl_ModelViewMatrix * gl_Vertex);
    N = normalize(gl_NormalMatrix * gl_Normal);

    vColor=vec4(abs(gl_Vertex).xyz,1.0);
   gl_Position = worldMatrix*gl_Vertex;
}
