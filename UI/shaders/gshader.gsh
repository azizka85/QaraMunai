#version 330 core
layout (triangles) in;
layout (triangle_strip, max_vertices = 3) out;

uniform vec2 uViewPort;

in vec3 vertNormal[3];
in vec4 vertPosition[3];
in float vertExclude[3];
in float vertBlockI[3];
in float vertBlockJ[3];
in float vertBlockK[3];
in float vertValue[3];

out vec3 vNormal;
out vec4 vPosition;
out float vBlockI;
out float vBlockJ;
out float vBlockK;
out float vValue;
out vec3 d;

void main(void)
{
    float m = 1000.0f; // max edge width

    vec2 p0 = uViewPort * gl_in[0].gl_Position.xy / gl_in[0].gl_Position.w;
    vec2 p1 = uViewPort * gl_in[1].gl_Position.xy / gl_in[1].gl_Position.w;
    vec2 p2 = uViewPort * gl_in[2].gl_Position.xy / gl_in[2].gl_Position.w;

    vec2 v0 = p2-p1;
    vec2 v1 = p2-p0;
    vec2 v2 = p1-p0;

    float area = abs(v1.x*v2.y - v1.y * v2.x);

    d = vec3(area/length(v0), m * vertExclude[1], m * vertExclude[2]);
    vPosition = vertPosition[0];
    vNormal = vertNormal[0];
    vBlockI = vertBlockI[0];
    vBlockJ = vertBlockJ[0];
    vBlockK = vertBlockK[0];
    vValue = vertValue[0];
    gl_Position = gl_in[0].gl_Position;
    EmitVertex();

    d = vec3(m * vertExclude[0], area/length(v1), m * vertExclude[2]);
    vPosition = vertPosition[1];
    vNormal = vertNormal[1];
    vBlockI = vertBlockI[1];
    vBlockJ = vertBlockJ[1];
    vBlockK = vertBlockK[1];
    vValue = vertValue[1];
    gl_Position = gl_in[1].gl_Position;
    EmitVertex();

    d = vec3(m * vertExclude[0], m * vertExclude[1], area/length(v2));
    vPosition = vertPosition[2];
    vNormal = vertNormal[2];
    vBlockI = vertBlockI[2];
    vBlockJ = vertBlockJ[2];
    vBlockK = vertBlockK[2];
    vValue = vertValue[2];
    gl_Position = gl_in[2].gl_Position;
    EmitVertex();

    EndPrimitive();
}
