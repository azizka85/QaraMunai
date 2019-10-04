#version 330 core

attribute vec4 aPosition;
attribute vec3 aNormal;
attribute float aExclude;
attribute float aValue;

uniform mat4 uProjectionMatrix;
uniform mat4 uViewMatrix;
uniform mat4 uModelMatrix;

out vec3 vertNormal;
out vec4 vertPosition;
out float vertExclude;
out float vertValue;

void main(void)
{
    mat4 mvMatrix = uViewMatrix * uModelMatrix;

    gl_Position = uProjectionMatrix * mvMatrix * aPosition;

    vertNormal = normalize(vec3(mvMatrix * vec4(aNormal, 0.0f)));
    vertPosition = mvMatrix * aPosition;
    vertExclude = aExclude;
    vertValue = aValue;
}
