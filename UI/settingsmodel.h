#ifndef SETTINGSMODEL_H
#define SETTINGSMODEL_H
#include <QAbstractTableModel>
class SettingsModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    enum Roles {
        NameRole = Qt::UserRole + 1,
        VisibleRole,
        LineColorRole,
        LineWidthRole,
        LineTypeRole,
        MarkerColorRole,
        MarkerWidthRole,
        MarkerTypeRole
    };

    int rowCount(const QModelIndex & = QModelIndex()) const override;

    int columnCount(const QModelIndex & = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role) const override;

    QHash<int, QByteArray> roleNames() const override;

    virtual bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    virtual Qt::ItemFlags flags(const QModelIndex &index) const override;

private:
    QVariantList seriesList;
};


#endif // SETTINGSMODEL_H
