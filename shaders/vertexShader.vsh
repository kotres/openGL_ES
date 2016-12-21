uniform mat4 mvpMatrix;
attribute vec3 inVertex;
attribute vec3 inNormal;
/*varying vec3 N;
varying vec3 v;*/

varying vec4 vColor;

void main(void)
{
   /* v = vec3(gl_ModelViewMatrix * gl_Vertex);
    N = normalize(gl_NormalMatrix * gl_Normal);*/
    vec4 vertex=vec4(inVertex,1.0);
    vColor=vec4(inNormal,1.0);//vertex;
   gl_Position = mvpMatrix*vertex;
}
