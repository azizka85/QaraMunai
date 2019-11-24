#version 430
uniform int uPrimitiveCount;
uniform int uDiv;

layout (local_size_x = 1, local_size_y = 1, local_size_z = 1) in;
layout (std430, binding = 2) buffer OutputBuffer { float outBuffer[]; };

bool compare(in uint id1, in uint id2);
void check(in uint id1, in uint id2);

void main(void)
{
    uint id = gl_GlobalInvocationID.z * gl_NumWorkGroups.y * gl_NumWorkGroups.x +
                gl_GlobalInvocationID.y * gl_NumWorkGroups.x +
                gl_GlobalInvocationID.x;

    uint n = uDiv;

    uint id1 = n*(2*id);
    uint id2 = n*(2*id+1);

    if(id2 < uPrimitiveCount) check(id1, id2);
}

bool compare(in uint id1, in uint id2)
{
    if(outBuffer[5*id1 + 1] > 0)
    {
        if(outBuffer[5*id2 + 1] > 0)
        {
            if(outBuffer[5*id1] > outBuffer[5*id2]) return false;
        }

        return true;
    }

    return false;
}

void check(in uint id1, in uint id2)
{
    bool isMin = compare(id1, id2);

    if(!isMin)
    {
        float temp = outBuffer[5*id1];
        outBuffer[5*id1] = outBuffer[5*id2];
        outBuffer[5*id2] = temp;

        temp = outBuffer[5*id1 + 1];
        outBuffer[5*id1 + 1] = outBuffer[5*id2 + 1];
        outBuffer[5*id2 + 1] = temp;

        temp = outBuffer[5*id1 + 2];
        outBuffer[5*id1 + 2] = outBuffer[5*id2 + 2];
        outBuffer[5*id2 + 2] = temp;

        temp = outBuffer[5*id1 + 3];
        outBuffer[5*id1 + 3] = outBuffer[5*id2 + 3];
        outBuffer[5*id2 + 3] = temp;

        temp = outBuffer[5*id1 + 4];
        outBuffer[5*id1 + 4] = outBuffer[5*id2 + 4];
        outBuffer[5*id2 + 4] = temp;
    }
}


