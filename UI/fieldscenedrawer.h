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

#include <fieldinfo.h>

class FieldSceneDrawer : public QQuickFramebufferObject
{
    Q_OBJECT

    Q_ENUMS(FieldNames)
    Q_ENUMS(RotationAxis)

    Q_PROPERTY(bool showMesh READ ShowMesh WRITE SetShowMesh NOTIFY ShowMeshChanged)
    Q_PROPERTY(bool showContour READ ShowContour WRITE SetShowContour NOTIFY ShowContourChanged)
    Q_PROPERTY(bool transparent READ Transparent WRITE SetTransparent NOTIFY TransparentChanged)
    Q_PROPERTY(bool lighting READ Lighting WRITE SetLighting NOTIFY LightingChanged)
    Q_PROPERTY(RotationAxis axisOfRotation READ AxisOfRotation WRITE SetAxisOfRotation NOTIFY AxisOfRotationChanged)
    Q_PROPERTY(QVariant selectedValue READ SelectedValue WRITE SetSelectedValue NOTIFY SelectedValueChanged)
    Q_PROPERTY(QVector2D mousePosition READ MousePosition WRITE SetMousePosition NOTIFY MousePositionChanged)
    Q_PROPERTY(QVector2D mouseDisplacement READ MouseDisplacement WRITE SetMouseDisplacement NOTIFY MouseDisplacementChanged)
    Q_PROPERTY(float zLocation READ ZLocation WRITE SetZLocation NOTIFY ZLocationChanged)

public:
    explicit FieldSceneDrawer(QQuickItem *parent = nullptr);

    enum FieldNames { PERMX, PERMY, PERMZ, PORO, NTG, TRANX, TRANY, TRANZ, SWAT, SOIL, SGAS, RS, PRESSURE, PW, PBUB, DEPTH, PVTNUM, SATNUM, EQLNUM, PORV, OILV };
    enum RotationAxis {XY, X, Y, Z};

    QQuickFramebufferObject::Renderer *createRenderer() const;

    bool ShowMesh();
    bool ShowContour();
    bool Transparent();
    bool Lighting();
    RotationAxis AxisOfRotation();
    QVariant SelectedValue();
    QVector2D MousePosition();
    QVector2D MouseDisplacement();
    float ZLocation();

    void SetShowMesh(const bool &showMesh);
    void SetShowContour(const bool &showContour);
    void SetTransparent(const bool &transparent);
    void SetLighting(const bool &lighting);
    void SetAxisOfRotation(const RotationAxis &axisOfRotation);
    void SetSelectedValue(const QVariant &selectedValue);
    void SetMousePosition(const QVector2D &mousePosition);
    void SetMouseDisplacement(const QVector2D &mouseDisplacement);
    void SetZLocation(const float &zLocation);

    Q_INVOKABLE void setXYViewAxis();
    Q_INVOKABLE void setXZViewAxis();
    Q_INVOKABLE void setYZViewAxis();

    Q_INVOKABLE QVariantList getFields();
    Q_INVOKABLE QVector<int> getCalcFields();

signals:
    void ShowMeshChanged();
    void ShowContourChanged();
    void TransparentChanged();
    void LightingChanged();
    void AxisOfRotationChanged();
    void SelectedValueChanged();
    void MousePositionChanged();
    void MouseDisplacementChanged();
    void ZLocationChanged();

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
        void initCube(float width);
        QVariant compute();

    private:
        QVector2D mousePosition;

        GLuint primitiveCount;

        QMatrix4x4 projectionMatrix;
        QMatrix4x4 viewMatrix;
        QMatrix4x4 modelMatrix;

        QOpenGLShaderProgram shaderProgram;
        QOpenGLShaderProgram computeProgram;

        QOpenGLBuffer arrayBuffer;
        QOpenGLBuffer indBuffer;
        QOpenGLBuffer outputBuffer;

        FieldSceneDrawer *drawer;
    };

    struct VertexData
    {
        VertexData() {  }

        VertexData(QVector3D p, QVector3D n, float e, float v) : position(p), normal(n), exclude(e), value(v) {  }

        QVector3D position;
        QVector3D normal;
        float exclude;
        float value;
    };

private:
    bool showMesh;
    bool showContour;
    bool transparent;
    bool lighting;
    RotationAxis axisOfRotation;
    QVariant selectedValue;
    QVector2D mousePosition;
    QVector2D mouseDisplacement;
    QQuaternion rot;
    float zLocation;

    QVector<FieldInfo> fields;
    QVector<int> calcFields;

    void initVariables();
};

#endif // FIELDSCENEDRAWER_H
