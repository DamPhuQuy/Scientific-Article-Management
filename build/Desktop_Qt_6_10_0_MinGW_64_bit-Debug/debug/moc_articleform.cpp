/****************************************************************************
** Meta object code from reading C++ file 'articleform.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/components/widgets/article/articleform.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'articleform.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN11ArticleFormE_t {};
} // unnamed namespace

template <> constexpr inline auto ArticleForm::qt_create_metaobjectdata<qt_meta_tag_ZN11ArticleFormE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "ArticleForm",
        "requestBack",
        "",
        "openArticleInputDialog",
        "openArtilceStatisticsDialog",
        "openArticleUpdateArticDialog",
        "openArticleRemoveArticleDialog",
        "on_newArticleBtn_clicked",
        "on_statsBtn_clicked",
        "on_updateArtticleBtn_clicked",
        "on_RemoveArticleBtn_clicked",
        "on_searchBtn_clicked"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'requestBack'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'openArticleInputDialog'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'openArtilceStatisticsDialog'
        QtMocHelpers::SignalData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'openArticleUpdateArticDialog'
        QtMocHelpers::SignalData<void()>(5, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'openArticleRemoveArticleDialog'
        QtMocHelpers::SignalData<void()>(6, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'on_newArticleBtn_clicked'
        QtMocHelpers::SlotData<void()>(7, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_statsBtn_clicked'
        QtMocHelpers::SlotData<void()>(8, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_updateArtticleBtn_clicked'
        QtMocHelpers::SlotData<void()>(9, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_RemoveArticleBtn_clicked'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_searchBtn_clicked'
        QtMocHelpers::SlotData<void()>(11, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<ArticleForm, qt_meta_tag_ZN11ArticleFormE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject ArticleForm::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11ArticleFormE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11ArticleFormE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN11ArticleFormE_t>.metaTypes,
    nullptr
} };

void ArticleForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<ArticleForm *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->requestBack(); break;
        case 1: _t->openArticleInputDialog(); break;
        case 2: _t->openArtilceStatisticsDialog(); break;
        case 3: _t->openArticleUpdateArticDialog(); break;
        case 4: _t->openArticleRemoveArticleDialog(); break;
        case 5: _t->on_newArticleBtn_clicked(); break;
        case 6: _t->on_statsBtn_clicked(); break;
        case 7: _t->on_updateArtticleBtn_clicked(); break;
        case 8: _t->on_RemoveArticleBtn_clicked(); break;
        case 9: _t->on_searchBtn_clicked(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (ArticleForm::*)()>(_a, &ArticleForm::requestBack, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (ArticleForm::*)()>(_a, &ArticleForm::openArticleInputDialog, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (ArticleForm::*)()>(_a, &ArticleForm::openArtilceStatisticsDialog, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (ArticleForm::*)()>(_a, &ArticleForm::openArticleUpdateArticDialog, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (ArticleForm::*)()>(_a, &ArticleForm::openArticleRemoveArticleDialog, 4))
            return;
    }
}

const QMetaObject *ArticleForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ArticleForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11ArticleFormE_t>.strings))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ArticleForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void ArticleForm::requestBack()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ArticleForm::openArticleInputDialog()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ArticleForm::openArtilceStatisticsDialog()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void ArticleForm::openArticleUpdateArticDialog()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void ArticleForm::openArticleRemoveArticleDialog()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
