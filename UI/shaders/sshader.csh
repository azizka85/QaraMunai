#version 430
uniform int uPrimitiveCount;
uniform int uNumIteration;

layout (local_size_x = 1, local_size_y = 1, local_size_z = 1) in;
layout (std430, binding = 2) buffer OutputBuffer { float outBuffer[]; };

bool compare(in uint id1, in uint id2);
void check(in uint id1, in uint id2);

void main(void)
{
    uint i = uNumIteration;
    uint id = gl_GlobalInvocationID.x;;
    uint n = uPrimitiveCount;

    // odd iteration
    if(i % 2 == 1)
    {
        id = 2*id + 1;        

        if(id < n - 1) check(id, id+1);
    }

    // even iteration
    if(i % 2 == 0)
    {
        id = 2*id;

        if(id < n - 1) check(id, id+1);
    }
}

bool compare(in uint id1, in uint id2)
{
    if(outBuffer[3*id1 + 2] > 0)
    {
        if(outBuffer[3*id2 + 2] > 0)
        {
            if(outBuffer[3*id1] > outBuffer[3*id2]) return false;
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
        float temp = outBuffer[3*id1];
        outBuffer[3*id1] = outBuffer[3*id2];
        outBuffer[3*id2] = temp;

        temp = outBuffer[3*id1 + 1];
        outBuffer[3*id1 + 1] = outBuffer[3*id2 + 1];
        outBuffer[3*id2 + 1] = temp;

        temp = outBuffer[3*id1 + 2];
        outBuffer[3*id1 + 2] = outBuffer[3*id2 + 2];
        outBuffer[3*id2 + 2] = temp;
    }
}


