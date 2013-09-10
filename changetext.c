#include <windows.h>
#include "Python.h"
#include "changetext.h"

#define ERROR_MESSAGE(message) MessageBox(0,message,"ChangeText",MB_ICONERROR)

PyObject * pModule = NULL,
         * pfuncChangeText = NULL,
         * pArgs = NULL;

int initialized = 0;

EXPORT int init() {
    Py_Initialize();
    pModule = PyImport_ImportModule("changetext");
    if(pModule) {
        pfuncChangeText = PyObject_GetAttrString(pModule, "ChangeText");
        if(!pfuncChangeText)
            ERROR_MESSAGE("Error: Probably changetext.py module doesn't contain ChangeText function.");
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
    
    if(!initialized) init();
    
    if(pArgs && pfuncChangeText) {
        PyTuple_SetItem(pArgs, 0, PyUnicode_FromWideChar(src,-1));
        pValue = PyObject_CallObject(pfuncChangeText, pArgs);
        if(pValue == Py_None) {
            Py_DECREF(pValue);
            return 0;
        }
        else {
            PyUnicode_AsWideChar(pValue,buffer,BUFFER_SIZE);
            Py_DECREF(pValue);
            return buffer;
        }
    }
    else return src;
}
