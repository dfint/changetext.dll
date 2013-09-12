#include <windows.h>
#include "Python.h"
#include "changetext.h"

#define ERROR_MESSAGE(message) MessageBox(0,message,"ChangeText",MB_ICONERROR)

PyObject * pModule = NULL,
         * pfuncChangeText = NULL,
         * pfuncInit = NULL,
         * pArgs = NULL;

int initialized = 0;

EXPORT int Init() {
    Py_Initialize();
    pModule = PyImport_ImportModule("changetext");
    if(pModule) {
        pfuncChangeText = PyObject_GetAttrString(pModule, "ChangeText");
        if(!(pfuncChangeText && PyCallable_Check(pfuncChangeText))) {
            Py_XDECREF(pfuncChangeText);
            pfuncChangeText = NULL;
            ERROR_MESSAGE("Error: Probably changetext.py module doesn't contain ChangeText function.");
        }
        pArgs = PyTuple_New(1);
    }
    else ERROR_MESSAGE("Error: Failed to import changetext.py module.");
    initialized = 1; // At least tried to initialize
    return pfuncChangeText!=NULL;
}

#define BUFFER_SIZE 0x100
wchar_t buffer[BUFFER_SIZE];

EXPORT wchar_t * ChangeText(wchar_t * src) {
    PyObject * pValue = NULL;
    
    if(!initialized) Init();
    
    if(pfuncChangeText && pArgs) {
        PyTuple_SetItem(pArgs, 0, PyUnicode_FromWideChar(src,-1));
        pValue = PyObject_CallObject(pfuncChangeText, pArgs);
        if(!pValue)
            PyErr_PrintEx(1);
        if(pValue && PyUnicode_Check(pValue)) {
            PyUnicode_AsWideChar(pValue,buffer,BUFFER_SIZE);
            Py_DECREF(pValue);
            return buffer;
        }
        else {
            Py_XDECREF(pValue);
            return 0;
        }
    }
    else return src;
}
