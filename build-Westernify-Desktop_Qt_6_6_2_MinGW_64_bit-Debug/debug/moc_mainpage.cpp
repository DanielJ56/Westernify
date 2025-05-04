/****************************************************************************
** Meta object code from reading C++ file 'mainpage.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Westernify/LoginMainPage/mainpage.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainpage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.2. It"
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

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainPageENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSMainPageENDCLASS = QtMocHelpers::stringData(
    "MainPage",
    "on_goBackButton_clicked",
    "",
    "openSearchPage",
    "openUploadView",
    "openPlaylistPage",
    "showThisPage",
    "UploadImage"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainPageENDCLASS_t {
    uint offsetsAndSizes[16];
    char stringdata0[9];
    char stringdata1[24];
    char stringdata2[1];
    char stringdata3[15];
    char stringdata4[15];
    char stringdata5[17];
    char stringdata6[13];
    char stringdata7[12];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainPageENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainPageENDCLASS_t qt_meta_stringdata_CLASSMainPageENDCLASS = {
    {
        QT_MOC_LITERAL(0, 8),  // "MainPage"
        QT_MOC_LITERAL(9, 23),  // "on_goBackButton_clicked"
        QT_MOC_LITERAL(33, 0),  // ""
        QT_MOC_LITERAL(34, 14),  // "openSearchPage"
        QT_MOC_LITERAL(49, 14),  // "openUploadView"
        QT_MOC_LITERAL(64, 16),  // "openPlaylistPage"
        QT_MOC_LITERAL(81, 12),  // "showThisPage"
        QT_MOC_LITERAL(94, 11)   // "UploadImage"
    },
    "MainPage",
    "on_goBackButton_clicked",
    "",
    "openSearchPage",
    "openUploadView",
    "openPlaylistPage",
    "showThisPage",
    "UploadImage"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainPageENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x08,    1 /* Private */,
       3,    0,   51,    2, 0x08,    2 /* Private */,
       4,    0,   52,    2, 0x08,    3 /* Private */,
       5,    0,   53,    2, 0x08,    4 /* Private */,
       6,    0,   54,    2, 0x08,    5 /* Private */,
       7,    0,   55,    2, 0x08,    6 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainPage::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainPageENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainPageENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainPageENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainPage, std::true_type>,
        // method 'on_goBackButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'openSearchPage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'openUploadView'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'openPlaylistPage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showThisPage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'UploadImage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainPage *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_goBackButton_clicked(); break;
        case 1: _t->openSearchPage(); break;
        case 2: _t->openUploadView(); break;
        case 3: _t->openPlaylistPage(); break;
        case 4: _t->showThisPage(); break;
        case 5: _t->UploadImage(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *MainPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainPage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainPageENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int MainPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
