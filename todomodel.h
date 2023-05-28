#ifndef TODOMODEL_H
#define TODOMODEL_H

#include <QObject>
#include <QAbstractListModel>

class TodoItem{
public:
    explicit TodoItem(const QString &content, const bool isDone){
        pcontent = content;
        pisDone - isDone;
    };
    QString content() const{
        return pcontent;
    }
    bool isDone() const{
        return pisDone;
    }

    bool setContent(const QString &content){
        if(pcontent == content){
            return false;
        }
        pcontent = content;
        return true;
    }
    bool setIsDOne(const bool &isDone){
        if(pisDone == isDone){
            return false;
        }
        pisDone = isDone;
        return true;
    }

private:
    QString pcontent;
    bool pisDone;
};

class TodoModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit TodoModel(QObject *parent = nullptr)
        : QAbstractListModel(parent){
        pTodoList.append(TodoItem("a",false));
        pTodoList.append(TodoItem("b",false));
        pTodoList.append(TodoItem("c",false));
    }

    enum TodoItemRoles {
        ContentRole = Qt::UserRole + 1,
        IsDoneRole
    };

    int rowCount(const QModelIndex &parent = QModelIndex()) const override{
        return pTodoList.length();
    }

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override{
        if(!index.isValid()){
            return QVariant();
        }
        auto &item = pTodoList[index.row()];

        switch (role) {
        case ContentRole:
            return item.content();
        case IsDoneRole:
            return item.isDone();
        default:
            return QVariant();
        }
    }

    bool setData(const QModelIndex &index, const QVariant &value, int role) override{
        if(!index.isValid()){
            return false;
        }
        TodoItem &item = pTodoList[index.row()];
        switch (role) {
        case ContentRole:
            return item.setContent(value.toString());
        case IsDoneRole:
            return item.setIsDOne(value.toBool());
        default:
            return false;
        }


    }

    Q_INVOKABLE void addItem(){
        beginInsertRows(QModelIndex(),rowCount(), rowCount());
        pTodoList.append(TodoItem("",false));
        endInsertRows();
    }
    Q_INVOKABLE void removeItem(const int &index){
        beginRemoveRows(QModelIndex(),index,index);
        pTodoList.remove(index,1);
        endRemoveRows();
    }

protected:
    QHash<int,QByteArray> roleNames() const override{
        QHash<int,QByteArray> role;
        role[ContentRole] = "noidung";
        role[IsDoneRole] = "trangthai";
        return role;
    }

private:
    QList<TodoItem> pTodoList;
signals:


};

#endif // TODOMODEL_H
