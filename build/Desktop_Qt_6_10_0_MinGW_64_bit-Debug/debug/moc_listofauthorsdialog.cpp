/****************************************************************************
** Meta object code from reading C++ file 'listofauthorsdialog.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/components/dialogs/author/listofauthorsdialog.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'listofauthorsdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN19ListOfAuthorsDialogE_t {};
} // unnamed namespace

template <> constexpr inline auto ListOfAuthorsDialog::qt_create_metaobjectdata<qt_meta_tag_ZN19ListOfAuthorsDialogE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "ListOfAuthorsDialog",
        "requestBack",
        "",
        "on_listViewAuthors_doubleClicked",
        "QModelIndex",
        "index",
        "on_btnClose_clicked",
        "on_okBtn_clicked",
        "on_lineEditSearch_textChanged",
        "text",
        "on_comboCountry_currentTextChanged",
        "on_comboField_currentTextChanged",
        "on_btnApplyFilter_clicked"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'requestBack'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'on_listViewAuthors_doubleClicked'
        QtMocHelpers::SlotData<void(const QModelIndex &)>(3, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 4, 5 },
        }}),
        // Slot 'on_btnClose_clicked'
        QtMocHelpers::SlotData<void()>(6, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_okBtn_clicked'
        QtMocHelpers::SlotData<void()>(7, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_lineEditSearch_textChanged'
        QtMocHelpers::SlotData<void(const QString &)>(8, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 9 },
        }}),
        // Slot 'on_comboCountry_currentTextChanged'
        QtMocHelpers::SlotData<void(const QString &)>(10, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 9 },
        }}),
        // Slot 'on_comboField_currentTextChanged'
        QtMocHelpers::SlotData<void(const QString &)>(11, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 9 },
        }}),
        // Slot 'on_btnApplyFilter_clicked'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<ListOfAuthorsDialog, qt_meta_tag_ZN19ListOfAuthorsDialogE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject ListOfAuthorsDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19ListOfAuthorsDialogE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19ListOfAuthorsDialogE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN19ListOfAuthorsDialogE_t>.metaTypes,
    nullptr
} };

void ListOfAuthorsDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<ListOfAuthorsDialog *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->requestBack(); break;
        case 1: _t->on_listViewAuthors_doubleClicked((*reinterpret_cast<std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 2: _t->on_btnClose_clicked(); break;
        case 3: _t->on_okBtn_clicked(); break;
        case 4: _t->on_lineEditSearch_textChanged((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->on_comboCountry_currentTextChanged((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 6: _t->on_comboField_currentTextChanged((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 7: _t->on_btnApplyFilter_clicked(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (ListOfAuthorsDialog::*)()>(_a, &ListOfAuthorsDialog::requestBack, 0))
            return;
    }
}

const QMetaObject *ListOfAuthorsDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ListOfAuthorsDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19ListOfAuthorsDialogE_t>.strings))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ListOfAuthorsDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void ListOfAuthorsDialog::requestBack()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
