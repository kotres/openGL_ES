uniform vec4 position;

void main(void)
{
   gl_Position = gl_Vertex+position;
}
