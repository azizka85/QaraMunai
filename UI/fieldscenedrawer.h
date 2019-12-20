#ifndef FIELDSCENEDRAWER_H
#define FIELDSCENEDRAWER_H

#include <qvariant.h>
#include <qstring.h>
#include <qvector.h>

#include <qquickitem.h>
#include <qquickframebufferobject.h>

#include <qopenglframebufferobject.h>
#include <qopenglextrafunctions.h>
#include <qopenglshaderprogram.h>
#include <qopenglbuffer.h>
#include <qmatrix4x4.h>
#include <qvector2d.h>
#include <qquaternion.h>

#include <projectdata.h>

#include <datahelper.h>
#include <mathhelper.h>

#include <point3d.h>

#include <fieldinfo.h>

using namespace QaraMunai::Model::Domain::Project;
using namespace QaraMunai::Model::Domain::Grid;
using namespace QaraMunai::Model::Helpers;

class FieldSceneDrawer : public QQuickFramebufferObject
{
    Q_OBJECT

    Q_ENUMS(FieldNames)
    Q_ENUMS(RotationAxis)
    Q_ENUMS(MouseAction)

    Q_PROPERTY(ProjectData* pdata READ Data WRITE SetData NOTIFY DataChanged)    
    Q_PROPERTY(bool showMesh READ ShowMesh WRITE SetShowMesh NOTIFY ShowMeshChanged)
    Q_PROPERTY(bool showContour READ ShowContour WRITE SetShowContour NOTIFY ShowContourChanged)
    Q_PROPERTY(bool transparent READ Transparent WRITE SetTransparent NOTIFY TransparentChanged)
    Q_PROPERTY(bool lighting READ Lighting WRITE SetLighting NOTIFY LightingChanged)
    Q_PROPERTY(bool selectBlock READ SelectBlock WRITE SetSelectBlock NOTIFY SelectBlockChanged)
    Q_PROPERTY(RotationAxis axisOfRotation READ AxisOfRotation WRITE SetAxisOfRotation NOTIFY AxisOfRotationChanged)
    Q_PROPERTY(MouseAction actionByMouse READ ActionByMouse WRITE SetActionByMouse NOTIFY ActionByMouseChanged)
    Q_PROPERTY(int selectedBlockIndex READ SelectedBlockIndex WRITE SetSelectedBlockIndex NOTIFY SelectedBlockIndexChanged)
    Q_PROPERTY(QVector2D mousePosition READ MousePosition WRITE SetMousePosition NOTIFY MousePositionChanged)
    Q_PROPERTY(float zLocation READ ZLocation WRITE SetZLocation NOTIFY ZLocationChanged)
    Q_PROPERTY(float multX READ MultX WRITE SetMultX NOTIFY MultXChanged)
    Q_PROPERTY(float multY READ MultY WRITE SetMultY NOTIFY MultYChanged)
    Q_PROPERTY(float multZ READ MultZ WRITE SetMultZ NOTIFY MultZChanged)

public:
    explicit FieldSceneDrawer(QQuickItem *parent = nullptr);

    enum FieldNames { PERMX, PERMY, PERMZ, PORO, NTG, TRANX, TRANY, TRANZ, SWAT, SOIL, SGAS, RS, PRESSURE, PW, PBUB, DEPTH, PVTNUM, SATNUM, EQLNUM, PORV, OILV };
    enum RotationAxis {XY, X, Y, Z};    
    enum MouseAction { ActionRotate, ActionMove };

    QQuickFramebufferObject::Renderer *createRenderer() const;

    ProjectData* Data();
    bool ShowMesh();
    bool ShowContour();
    bool Transparent();
    bool Lighting();
    bool SelectBlock();
    RotationAxis AxisOfRotation();
    MouseAction ActionByMouse();
    int SelectedBlockIndex();
    QVector2D MousePosition();
    float ZLocation();
    float MultX();
    float MultY();
    float MultZ();

    void SetData(ProjectData* data);
    void SetShowMesh(const bool &showMesh);
    void SetShowContour(const bool &showContour);
    void SetTransparent(const bool &transparent);
    void SetLighting(const bool &lighting);
    void SetSelectBlock(const bool &selectBlock);
    void SetAxisOfRotation(const RotationAxis &axisOfRotation);
    void SetActionByMouse(const MouseAction &actionByMouse);
    void SetSelectedBlockIndex(const int &selectedBlockIndex);
    void SetMousePosition(const QVector2D &mousePosition);
    void SetZLocation(const float &zLocation);
    void SetMultX(const float &multX);
    void SetMultY(const float &multY);
    void SetMultZ(const float &multZ);

    Q_INVOKABLE QVariantMap getSelectedBlockIndexes();

    Q_INVOKABLE void setXYViewAxis();
    Q_INVOKABLE void setXZViewAxis();
    Q_INVOKABLE void setYZViewAxis();

    Q_INVOKABLE void rotateView(const QVector2D &displacement, RotationAxis rotationAxis);
    Q_INVOKABLE void translateView(const QVector2D &displacement);

    Q_INVOKABLE QVariantList getFields();
    Q_INVOKABLE QVariantList getCalcFields();

    Q_INVOKABLE void setDefaultPosition();

    Q_INVOKABLE void updateData(int state);

signals:
    void DataChanged();
    void ShowMeshChanged();
    void ShowContourChanged();
    void TransparentChanged();
    void LightingChanged();
    void SelectBlockChanged();
    void AxisOfRotationChanged();
    void ActionByMouseChanged();
    void SelectedBlockIndexChanged();
    void MousePositionChanged();
    void ZLocationChanged();
    void MultXChanged();
    void MultYChanged();
    void MultZChanged();

protected:
    class Renderer : public QQuickFramebufferObject::Renderer, protected QOpenGLExtraFunctions
    {
    public:
        Renderer();

    protected:
        QOpenGLFramebufferObject *createFramebufferObject(const QSize &size);
        void initialize();
        void synchronize(QQuickFramebufferObject *fbo);
        void render();
        void initShaders();
        void initBuffer();
        void initGeometry();
        void clearGeometry();        
        void findSelectedBlock();

    private:
        bool initialized;

        QVector2D mousePosition;

        GLuint primitiveCount;

        QMatrix4x4 projectionMatrix;
        QMatrix4x4 viewMatrix;
        QMatrix4x4 modelMatrix;
        QMatrix4x4 scaleMatrix;

        QOpenGLShaderProgram drawShaderProgram;
        QOpenGLShaderProgram selectShaderProgram;
        QOpenGLShaderProgram nearestShaderProgram;

        QOpenGLBuffer vertexBuffer;
        QOpenGLBuffer indexBuffer;

        QOpenGLBuffer blockIndexBuffer;
        QOpenGLBuffer valueBuffer;

        QOpenGLBuffer outBlockIndexBuffer;
        QOpenGLBuffer outBlockDistanceBuffer;
        QOpenGLBuffer outIsSelectedBlockBuffer;

        FieldSceneDrawer *drawer;
    };

private:
    ProjectData::ProjectState state;
    bool showMesh;
    bool showContour;
    bool transparent;
    bool lighting;
    bool selectBlock;
    RotationAxis axisOfRotation;
    MouseAction actionByMouse;
    int selectedBlockIndex;
    QVector2D mousePosition;
    QQuaternion rot;
    float zLocation;
    float yLocation;
    float xLocation;
    float multX, multY, multZ;

    bool dataUpdated;

    ProjectData *data;

    QVector<FieldInfo> fields;    

    void initVariables();
};

#endif // FIELDSCENEDRAWER_H
