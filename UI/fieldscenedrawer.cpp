#include "fieldscenedrawer.h"

FieldSceneDrawer::FieldSceneDrawer(QQuickItem *parent) : QQuickFramebufferObject(parent)
{
    initVariables();
}

QQuickFramebufferObject::Renderer *FieldSceneDrawer::createRenderer() const
{
    return new FieldSceneDrawer::Renderer();
}

ProjectData *FieldSceneDrawer::Data()
{
    return data;
}

bool FieldSceneDrawer::ShowMesh()
{
    return showMesh;
}

bool FieldSceneDrawer::ShowContour()
{
    return showContour;
}

bool FieldSceneDrawer::Transparent()
{
    return transparent;
}

bool FieldSceneDrawer::Lighting()
{
    return lighting;
}

bool FieldSceneDrawer::SelectBlock()
{
    return selectBlock;
}

FieldSceneDrawer::RotationAxis FieldSceneDrawer::AxisOfRotation()
{
    return axisOfRotation;
}

FieldSceneDrawer::MouseAction FieldSceneDrawer::ActionByMouse()
{
    return actionByMouse;
}

int FieldSceneDrawer::SelectedBlockIndex()
{
    return selectedBlockIndex;
}

QVector2D FieldSceneDrawer::MousePosition()
{
    return mousePosition;
}

float FieldSceneDrawer::ZLocation()
{
    return zLocation;
}

float FieldSceneDrawer::MultX()
{
    return multX;
}

float FieldSceneDrawer::MultY()
{
    return multY;
}

float FieldSceneDrawer::MultZ()
{
    return multZ;
}

void FieldSceneDrawer::SetData(ProjectData *data)
{
    this->data = data;

    dataUpdated = true;

    update();

    DataChanged();
}

void FieldSceneDrawer::SetShowMesh(const bool &showMesh)
{
    if(this->showMesh != showMesh)
    {
        this->showMesh = showMesh;

        update();

        ShowMeshChanged();
    }
}

void FieldSceneDrawer::SetShowContour(const bool &showContour)
{
    if(this->showContour != showContour)
    {
        this->showContour = showContour;

        update();

        ShowContourChanged();
    }
}

void FieldSceneDrawer::SetTransparent(const bool &transparent)
{
    if(this->transparent != transparent)
    {
        this->transparent = transparent;

        update();

        TransparentChanged();
    }
}

void FieldSceneDrawer::SetLighting(const bool &lighting)
{
    if(this->lighting != lighting)
    {
        this->lighting = lighting;

        update();

        LightingChanged();
    }
}

void FieldSceneDrawer::SetSelectBlock(const bool &selectBlock)
{
    if(this->selectBlock != selectBlock)
    {
        this->selectBlock = selectBlock;

        SelectBlockChanged();
    }
}

void FieldSceneDrawer::SetAxisOfRotation(const RotationAxis &axisOfRotation)
{
    if(this->axisOfRotation != axisOfRotation)
    {
        this->axisOfRotation = axisOfRotation;

        AxisOfRotationChanged();
    }
}

void FieldSceneDrawer::SetActionByMouse(const FieldSceneDrawer::MouseAction &actionByMouse)
{
    if(this->actionByMouse != actionByMouse)
    {
        this->actionByMouse = actionByMouse;

        ActionByMouseChanged();
    }
}

void FieldSceneDrawer::SetSelectedBlockIndex(const int &selectedBlockIndex)
{
    if(this->selectedBlockIndex != selectedBlockIndex)
    {
        this->selectedBlockIndex = selectedBlockIndex;

        update();

        SelectedBlockIndexChanged();
    }
}

void FieldSceneDrawer::SetMousePosition(const QVector2D &mousePosition)
{
    this->mousePosition = mousePosition;

    update();

    MousePositionChanged();
}

void FieldSceneDrawer::SetZLocation(const float &zLocation)
{
    this->zLocation = zLocation;

    update();

    ZLocationChanged();
}

void FieldSceneDrawer::SetMultX(const float &multX)
{
    this->multX = multX;

    update();

    MultXChanged();
}

void FieldSceneDrawer::SetMultY(const float &multY)
{
    this->multY = multY;

    update();

    MultYChanged();
}

void FieldSceneDrawer::SetMultZ(const float &multZ)
{
    this->multZ = multZ;

    update();

    MultZChanged();
}

QVariantMap FieldSceneDrawer::getSelectedBlockIndexes()
{
    int index = selectedBlockIndex;

    int i = -1;
    int j = -1;
    int k = -1;

    if(index >= 0 && data != nullptr)
    {
        int nx = data->Nx();
        int ny = data->Ny();

        if(nx > 0 && ny > 0) DataHelper::DivideOnAxesNodes(index, nx, ny, i, j, k);
    }

    return {{"i", i}, {"j", j}, {"k", k}};
}

void FieldSceneDrawer::setXYViewAxis()
{
    setDefaultPosition();

    rot = QQuaternion::fromAxisAndAngle(0, 0, 0, 0);

    update();
}

void FieldSceneDrawer::setXZViewAxis()
{
    setDefaultPosition();

    rot = QQuaternion::fromAxisAndAngle(1, 0, 0, 90);

    update();
}

void FieldSceneDrawer::setYZViewAxis()
{
    setDefaultPosition();

    rot = QQuaternion::fromAxisAndAngle(0, 1, 0, 90);

    update();
}

void FieldSceneDrawer::rotateView(const QVector2D &displacement, FieldSceneDrawer::RotationAxis rotationAxis)
{
    float angle = displacement.length() / 2.0f;

    QVector3D axis;

    switch (rotationAxis) {
    case RotationAxis::XY:
        axis = QVector3D(displacement.y(), displacement.x(), 0.0);
        break;
    case RotationAxis::X:
        axis = QVector3D(displacement.y(), 0.0, 0.0);
        break;
    case RotationAxis::Y:
        axis = QVector3D(0.0, displacement.x(), 0.0);
        break;
    case RotationAxis::Z:
        axis = QVector3D(0.0, 0.0, displacement.x());
        break;
    }

    rot = QQuaternion::fromAxisAndAngle(axis, angle) * rot;

    update();
}

void FieldSceneDrawer::translateView(const QVector2D &displacement)
{
    xLocation -= displacement.y()/1000;
    yLocation += displacement.x()/1000;

    update();
}

QVariantList FieldSceneDrawer::getFields()
{
    QVariantList data;

    foreach (FieldInfo fi, fields) {
        data.append(fi.toMap());
    }

    return data;
}

QVariantList FieldSceneDrawer::getCalcFields()
{
    QVariantList calcFields;

    calcFields.append(fields[SWAT].toMap());
    calcFields.append(fields[SOIL].toMap());
    calcFields.append(fields[SGAS].toMap());
    calcFields.append(fields[PRESSURE].toMap());
    calcFields.append(fields[PBUB].toMap());

    return calcFields;
}

void FieldSceneDrawer::setDefaultPosition()
{
    xLocation = 0;
    yLocation = 0;
    zLocation = -1;
}

void FieldSceneDrawer::updateData(int state)
{
    this->state = static_cast<ProjectData::ProjectState>(state);

    dataUpdated = true;

    update();
}

void FieldSceneDrawer::initVariables()
{
    data = nullptr;

    dataUpdated = false;
    state = ProjectData::ProjectState::CLOSED;

    selectedBlockIndex = -1;

    setDefaultPosition();

    showMesh = true;
    showContour = true;
    transparent = false;
    lighting = true;
    selectBlock = true;

    axisOfRotation = RotationAxis::XY;
    actionByMouse = MouseAction::ActionRotate;

    multX = multY = multZ = 1;

    QMetaObject metaObject = staticMetaObject;

    QMetaEnum fieldNamesEnum = metaObject.enumerator(metaObject.indexOfEnumerator("FieldNames"));

    fields.resize(fieldNamesEnum.keyCount());

    fields[PERMX] = FieldInfo(QString("Прон. по X"), QString("Прон. по X"), QString("mD"));
    fields[PERMY] = FieldInfo(QString("Прон. по Y"), QString("Прон. по Y"), QString("mD"));
    fields[PERMZ] = FieldInfo(QString("Прон. по Z"), QString("Прон. по Z"), QString("mD"));
    fields[PORO] = FieldInfo(QString("Пористость"), QString("Пористость"), QString());
    fields[NTG] = FieldInfo(QString("Песчанистость"), QString("Песчанистость"), QString());
    fields[TRANX] = FieldInfo(QString("TranX"), QString("Проводимость по X"), QString("cP-rm3/day/bar"));
    fields[TRANY] = FieldInfo(QString("TranY"), QString("Проводимость по Y"), QString("cP-rm3/day/bar"));
    fields[TRANZ] = FieldInfo(QString("TranZ"), QString("Проводимость по Z"), QString("cP-rm3/day/bar"));
    fields[SWAT] = FieldInfo(QString("Sw"), QString("Насыщ. водой"), QString());
    fields[SOIL] = FieldInfo(QString("So"), QString("Насыщ. нефтью"), QString());
    fields[SGAS] = FieldInfo(QString("Sg"), QString("Насыщ. газом"), QString());
    fields[RS] = FieldInfo(QString("RS"), QString("RS"), QString());
    fields[PRESSURE] = FieldInfo(QString("Давление"), QString("Давление"), QString("barsa"));
    fields[PW] = FieldInfo(QString("PW"), QString("PW"), QString("barsa"));
    fields[PBUB] = FieldInfo(QString("Давл. насыщения"), QString("Давл. насыщ."), QString("barsa"));
    fields[DEPTH] = FieldInfo(QString("Глубина"), QString("Глубина"), QString("m"));
    fields[PVTNUM] = FieldInfo(QString("PVTNUM"), QString("PVTNUM"), QString());
    fields[SATNUM] = FieldInfo(QString("SATNUM"), QString("SATNUM"), QString());
    fields[EQLNUM] = FieldInfo(QString("EQLNUM"), QString("EQLNUM"), QString());
    fields[PORV] = FieldInfo(QString("PORV"), QString("PORV"), QString());
    fields[OILV] = FieldInfo(QString("OILV"), QString("OILV"), QString());
}

QOpenGLFramebufferObject *FieldSceneDrawer::Renderer::createFramebufferObject(const QSize &size)
{
    QOpenGLFramebufferObjectFormat format;

    format.setAttachment(QOpenGLFramebufferObject::CombinedDepthStencil);

    return new QOpenGLFramebufferObject(size, format);
}

FieldSceneDrawer::Renderer::Renderer() : QQuickFramebufferObject::Renderer(), indexBuffer(QOpenGLBuffer::IndexBuffer)
{
    initialize();
}

void FieldSceneDrawer::Renderer::initialize()
{
    initialized = true;

    initializeOpenGLFunctions();

    initShaders();
    initBuffer();
}

void FieldSceneDrawer::Renderer::synchronize(QQuickFramebufferObject *fbo)
{
    drawer = static_cast<FieldSceneDrawer*>(fbo);       

    float w = static_cast<float>(drawer->width());
    float h = static_cast<float>(drawer->height());

    float multX = drawer->multX;
    float multY = drawer->multY;
    float multZ = drawer->multZ;

    QQuaternion rotation = drawer->rot;
    float z = drawer->zLocation;
    float y = drawer->xLocation;
    float x = drawer->yLocation;

    float aspect = w/h;

    projectionMatrix.setToIdentity();
    projectionMatrix.perspective(45.0f, aspect, 0.01f, 100.0f);

    viewMatrix.setToIdentity();
    viewMatrix.translate(x, y, z);
    viewMatrix.rotate(rotation);

    modelMatrix.setToIdentity();    

    scaleMatrix.setToIdentity();
    scaleMatrix.scale(multX, multY, multZ);

    if(drawer->dataUpdated || initialized)
    {
        if(drawer->state != ProjectData::ProjectState::CLOSED) initGeometry();
        else clearGeometry();

        drawer->dataUpdated = false;
        initialized = false;
    }

    if(drawer->selectBlock && mousePosition != drawer->mousePosition)
    {
        findSelectedBlock();

        mousePosition = drawer->mousePosition;
    }
}

void FieldSceneDrawer::Renderer::render()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glEnable(GL_DEPTH_TEST);
    // glEnable(GL_CULL_FACE);

    // glEnable(GL_ALPHA_TEST);
    glEnable(GL_BLEND);    
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    float m = 1000.0f; // max edge width

    bool showMesh = drawer->showMesh;
    bool showContour = drawer->showContour;
    bool transparent = drawer->transparent;
    bool lighting = drawer->lighting;

    float w = static_cast<float>(drawer->width());
    float h = static_cast<float>(drawer->height());

    QVector2D viewPort(w, h);

    QVector3D maxColor(1, 0, 0);
    QVector3D midColor(0, 1, 0);
    QVector3D minColor(0, 0, 1);

    float maxValue = 150.0f;
    float minValue = 0.0f;

    float index = drawer->selectedBlockIndex;

    QMatrix4x4 mvMatrix = viewMatrix * modelMatrix * scaleMatrix;

    drawShaderProgram.bind();
    drawShaderProgram.setUniformValue("uM", m);
    drawShaderProgram.setUniformValue("uProjectionMatrix", projectionMatrix);
    drawShaderProgram.setUniformValue("uMVMatrix", mvMatrix);
    drawShaderProgram.setUniformValue("uViewPort", viewPort);
    drawShaderProgram.setUniformValue("uShowMesh", showMesh);
    drawShaderProgram.setUniformValue("uShowContour", showContour);
    drawShaderProgram.setUniformValue("uTransparent", transparent);
    drawShaderProgram.setUniformValue("uLighting", lighting);
    drawShaderProgram.setUniformValue("uMaxColor", maxColor);
    drawShaderProgram.setUniformValue("uMidColor", midColor);
    drawShaderProgram.setUniformValue("uMinColor", minColor);
    drawShaderProgram.setUniformValue("uMaxValue", maxValue);
    drawShaderProgram.setUniformValue("uMinValue", minValue);
    drawShaderProgram.setUniformValue("uSelectedBlockIndex", index);

    vertexBuffer.bind();

    int offset = 0;

    int vLocation = drawShaderProgram.attributeLocation("vV");

    drawShaderProgram.enableAttributeArray(vLocation);
    drawShaderProgram.setAttributeBuffer(vLocation, GL_FLOAT, offset, 3, sizeof (QVector3D));

    vertexBuffer.release();

    valueBuffer.bind();

    offset = 0;

    int valueLocation = drawShaderProgram.attributeLocation("vValue");

    drawShaderProgram.enableAttributeArray(valueLocation);
    drawShaderProgram.setAttributeBuffer(valueLocation, GL_FLOAT, offset, 1, sizeof (float));

    valueBuffer.release();

    blockIndexBuffer.bind();

    offset = 0;

    int blockIndexLocation = drawShaderProgram.attributeLocation("vBlockIndex");

    drawShaderProgram.enableAttributeArray(blockIndexLocation);
    drawShaderProgram.setAttributeBuffer(blockIndexLocation, GL_FLOAT, offset, 1, sizeof (float));

    blockIndexBuffer.release();

    indexBuffer.bind();

    glDrawElements(GL_TRIANGLES, indexBuffer.size(), GL_UNSIGNED_INT, nullptr);

    indexBuffer.release();

    drawShaderProgram.release();
}

void FieldSceneDrawer::Renderer::initShaders()
{
    drawShaderProgram.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/shaders/vshader.glsl");
    drawShaderProgram.addShaderFromSourceFile(QOpenGLShader::Geometry, ":/shaders/gshader.glsl");
    drawShaderProgram.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/shaders/fshader.glsl");
    drawShaderProgram.link();

    selectShaderProgram.addShaderFromSourceFile(QOpenGLShader::Compute, ":/shaders/compute_selected_blocks.glsl");
    selectShaderProgram.link();

    nearestShaderProgram.addShaderFromSourceFile(QOpenGLShader::Compute, ":/shaders/find_nearest_block.glsl");
    nearestShaderProgram.link();
}

void FieldSceneDrawer::Renderer::initBuffer()
{
    vertexBuffer.create();
    indexBuffer.create();

    blockIndexBuffer.create();
    valueBuffer.create();

    outBlockIndexBuffer.create();
    outBlockDistanceBuffer.create();
    outIsSelectedBlockBuffer.create();
}

void FieldSceneDrawer::Renderer::initGeometry()
{
    primitiveCount = 0;

    QVector<QVector3D> vertexes;
    QVector<GLuint> indexes;

    QVector<float> blockIndexes;
    QVector<float> values;

    if(drawer->data != nullptr)
    {
        double xMin = 0;
        double xMax = 0;

        double yMin = 0;
        double yMax = 0;

        double zMin = 0;
        double zMax = 0;

        QVector<bool> existBlock;
        QVector<bool> drawBlock;
        QVector<Block> blocks;

        int nx = drawer->data->Nx();
        int ny = drawer->data->Ny();
        int nz = drawer->data->Nz();

        qDebug() << nx << ", " << ny << ", " << nz;

        DataHelper::CalculateExistBlockArray(drawer->data, existBlock);
        DataHelper::CalculateDrawBlockArray(drawer->data, existBlock, drawBlock);
        DataHelper::GetDrawBlocks(drawer->data, drawBlock, blocks, xMin, xMax, yMin, yMax, zMin, zMax);
        DataHelper::NormalizeBlocks(xMin, xMax, yMin, yMax, zMin, zMax, blocks);

        for(int index = 0; index < blocks.size(); index++)
        {
            Block& block = blocks[index];

            float blockIndex = block.I() + block.J() * nx + block.K() * nx * ny;

            // bottom
            vertexes.append(QVector3D(block.P1().X(), block.P1().Y(), block.P1().Z()));
            values.append(0.0f);
            blockIndexes.append(blockIndex);

            vertexes.append(QVector3D(block.P3().X(), block.P3().Y(), block.P3().Z()));
            values.append(0.0f);
            blockIndexes.append(blockIndex);

            vertexes.append(QVector3D(block.P4().X(), block.P4().Y(), block.P4().Z()));
            values.append(0.0f);
            blockIndexes.append(blockIndex);

            vertexes.append(QVector3D(block.P2().X(), block.P2().Y(), block.P2().Z()));
            values.append(0.0f);
            blockIndexes.append(blockIndex);

            // top
            vertexes.append(QVector3D(block.P5().X(), block.P5().Y(), block.P5().Z()));
            values.append(0.0f);
            blockIndexes.append(blockIndex);

            vertexes.append(QVector3D(block.P6().X(), block.P6().Y(), block.P6().Z()));
            values.append(0.0f);
            blockIndexes.append(blockIndex);

            vertexes.append(QVector3D(block.P8().X(), block.P8().Y(), block.P8().Z()));
            values.append(0.0f);
            blockIndexes.append(blockIndex);

            vertexes.append(QVector3D(block.P7().X(), block.P7().Y(), block.P7().Z()));
            values.append(0.0f);
            blockIndexes.append(blockIndex);

            // left face
            indexes.append(8*index + 0);
            indexes.append(8*index + 4);
            indexes.append(8*index + 1);

            indexes.append(8*index + 7);
            indexes.append(8*index + 1);
            indexes.append(8*index + 4);

            // right face
            indexes.append(8*index + 3);
            indexes.append(8*index + 2);
            indexes.append(8*index + 5);

            indexes.append(8*index + 6);
            indexes.append(8*index + 5);
            indexes.append(8*index + 2);

            // back face
            indexes.append(8*index + 7);
            indexes.append(8*index + 6);
            indexes.append(8*index + 1);

            indexes.append(8*index + 2);
            indexes.append(8*index + 1);
            indexes.append(8*index + 6);

            // front face
            indexes.append(8*index + 4);
            indexes.append(8*index + 0);
            indexes.append(8*index + 5);

            indexes.append(8*index + 3);
            indexes.append(8*index + 5);
            indexes.append(8*index + 0);

            // down face
            indexes.append(8*index + 1);
            indexes.append(8*index + 2);
            indexes.append(8*index + 0);

            indexes.append(8*index + 3);
            indexes.append(8*index + 0);
            indexes.append(8*index + 2);

            // up face
            indexes.append(8*index + 7);
            indexes.append(8*index + 4);
            indexes.append(8*index + 6);

            indexes.append(8*index + 5);
            indexes.append(8*index + 6);
            indexes.append(8*index + 4);

            primitiveCount += 12;
        }

        vertexBuffer.bind();
        vertexBuffer.allocate(vertexes.constData(), vertexes.size() * sizeof (QVector3D));
        vertexBuffer.release();

        indexBuffer.bind();
        indexBuffer.allocate(indexes.constData(), indexes.size() * sizeof (GLuint));
        indexBuffer.release();

        blockIndexBuffer.bind();
        blockIndexBuffer.allocate(blockIndexes.constData(), blockIndexes.size() * sizeof (float));
        blockIndexBuffer.release();

        valueBuffer.bind();
        valueBuffer.allocate(values.constData(), values.size() * sizeof (float));
        valueBuffer.release();

        outBlockIndexBuffer.bind();
        outBlockIndexBuffer.allocate(primitiveCount * sizeof (float));
        outBlockIndexBuffer.release();

        outBlockDistanceBuffer.bind();
        outBlockDistanceBuffer.allocate(primitiveCount * sizeof (float));
        outBlockDistanceBuffer.release();

        outIsSelectedBlockBuffer.bind();
        outIsSelectedBlockBuffer.allocate(primitiveCount * sizeof (float));
        outIsSelectedBlockBuffer.release();
    }
}

void FieldSceneDrawer::Renderer::clearGeometry()
{
    primitiveCount = 0;

    vertexBuffer.bind();
    vertexBuffer.allocate(0);
    vertexBuffer.release();

    indexBuffer.bind();
    indexBuffer.allocate(0);
    indexBuffer.release();

    blockIndexBuffer.bind();
    blockIndexBuffer.allocate(0);
    blockIndexBuffer.release();

    valueBuffer.bind();
    valueBuffer.allocate(0);
    valueBuffer.release();

    outBlockIndexBuffer.bind();
    outBlockIndexBuffer.allocate(0);
    outBlockIndexBuffer.release();

    outBlockDistanceBuffer.bind();
    outBlockDistanceBuffer.allocate(0);
    outBlockDistanceBuffer.release();

    outIsSelectedBlockBuffer.bind();
    outIsSelectedBlockBuffer.allocate(0);
    outIsSelectedBlockBuffer.release();
}

void FieldSceneDrawer::Renderer::findSelectedBlock()
{
    float width = static_cast<float>(drawer->width());
    float height = static_cast<float>(drawer->height());

    QVector2D viewPort(width, height);

    QVector2D mousePosition = drawer->MousePosition();

    mousePosition.setX(2*mousePosition.x() - width);
    mousePosition.setY(2*mousePosition.y() - height);

    QVector4D rayClip(mousePosition.x()/width, mousePosition.y()/height, -1.0f, 1.0f);

    QVector4D rayEye = projectionMatrix.inverted() * rayClip;

    rayEye.setW(0);

    QVector4D rayWorld = rayEye;

    rayWorld.normalize();

    QMatrix4x4 mvMatrix = viewMatrix * modelMatrix * scaleMatrix;

    int gNx, gNy, gNz;

    glGetIntegeri_v(GL_MAX_COMPUTE_WORK_GROUP_COUNT, 0, &gNx);
    glGetIntegeri_v(GL_MAX_COMPUTE_WORK_GROUP_COUNT, 1, &gNy);
    glGetIntegeri_v(GL_MAX_COMPUTE_WORK_GROUP_COUNT, 2, &gNz);

    // qDebug() << "Max work groups: " << gNx << ", " << gNy << ", " << gNz;

    int lNx, lNy, lNz;

    glGetIntegeri_v(GL_MAX_COMPUTE_WORK_GROUP_SIZE, 0, &lNx);
    glGetIntegeri_v(GL_MAX_COMPUTE_WORK_GROUP_SIZE, 1, &lNy);
    glGetIntegeri_v(GL_MAX_COMPUTE_WORK_GROUP_SIZE, 2, &lNz);

    // qDebug() << "Max work group sizes: " << lNx << ", " << lNy << ", " << lNz;

    int iN;

    glGetIntegerv(GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS, &iN);

    // qDebug() << "Number of invocations in a single local work group: " << iN;

    int sN;

    glGetIntegerv(GL_MAX_COMPUTE_SHARED_MEMORY_SIZE, &sN);

    // qDebug() << "Shared memory size: " << sN;

    int cx, cy, cz;

    glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, vertexBuffer.bufferId());
    glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 1, indexBuffer.bufferId());
    glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 2, blockIndexBuffer.bufferId());
    glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 3, outBlockIndexBuffer.bufferId());
    glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 4, outBlockDistanceBuffer.bufferId());
    glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 5, outIsSelectedBlockBuffer.bufferId());

    selectShaderProgram.bind();
    selectShaderProgram.setUniformValue("uViewPort", viewPort);
    selectShaderProgram.setUniformValue("uRay", rayWorld);
    selectShaderProgram.setUniformValue("uMVMatrix", mvMatrix);
    selectShaderProgram.setUniformValue("uPrimitiveCount", primitiveCount);

    DataHelper::NumberOfGPUNodes(primitiveCount, gNx, gNy, cx, cy, cz);

    // qDebug() << "Compute: " << cx << ", " << cy << ", " << cz;

    glDispatchCompute(cx, cy, cz);

    glMemoryBarrier(GL_SHADER_IMAGE_ACCESS_BARRIER_BIT | GL_SHADER_STORAGE_BARRIER_BIT | GL_BUFFER_UPDATE_BARRIER_BIT);

    selectShaderProgram.release();

    nearestShaderProgram.bind();
    nearestShaderProgram.setUniformValue("uPrimitiveCount", primitiveCount);

    uint d = 1;
    uint n = primitiveCount;

    while(d < primitiveCount)
    {
        n = (n%2 == 0) ? n/2 : (n+1)/2;

        nearestShaderProgram.setUniformValue("uDiv", d);

        DataHelper::NumberOfGPUNodes(n, gNx, gNy, cx, cy, cz);

        // qDebug() << "Sort " << d << ": " << cx << ", " << cy << ", " << cz;

        glDispatchCompute(cx, cy, cz);

        glMemoryBarrier(GL_SHADER_IMAGE_ACCESS_BARRIER_BIT | GL_SHADER_STORAGE_BARRIER_BIT | GL_BUFFER_UPDATE_BARRIER_BIT);

        d = 2*d;
    }

    nearestShaderProgram.release();

    outBlockIndexBuffer.bind();

    float outBlockIndex;

    outBlockIndexBuffer.read(0, &outBlockIndex, sizeof (float));

    outBlockIndexBuffer.release();

    outIsSelectedBlockBuffer.bind();

    float outIsSelectedBlock;

    outIsSelectedBlockBuffer.read(0, &outIsSelectedBlock, sizeof (float));

    outIsSelectedBlockBuffer.release();

    if(outIsSelectedBlock > 0)
    {
        float index = outBlockIndex;

        drawer->SetSelectedBlockIndex(index);

        qDebug() << index;
    }
    else
    {
        drawer->SetSelectedBlockIndex(-1);
    }
}
