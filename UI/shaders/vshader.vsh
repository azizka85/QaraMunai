#version 330 core

attribute vec4 aPosition;
attribute vec3 aNormal;
attribute float aExclude;
attribute float aBlockI;
attribute float aBlockJ;
attribute float aBlockK;
attribute float aValue;

uniform mat4 uProjectionMatrix;
uniform mat4 uMVMatrix;

out vec3 vertNormal;
out vec4 vertPosition;
out float vertExclude;
out float vertBlockI;
out float vertBlockJ;
out float vertBlockK;
out float vertValue;

void main(void)
{
    gl_Position = uProjectionMatrix * uMVMatrix * aPosition;

    vertNormal = normalize(vec3(uMVMatrix * vec4(aNormal, 0.0f)));
    vertPosition = uMVMatrix * aPosition;
    vertExclude = aExclude;
    vertBlockI = aBlockI;
    vertBlockJ = aBlockJ;
    vertBlockK = aBlockK;
    vertValue = aValue;
}
