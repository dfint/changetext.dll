#include "Python.h"
#include "changetext.h"

#if defined(WIN32) || defined(WINDOWS)
#define ERROR_MESSAGE(message) MessageBox(0,message,"ChangeText",MB_ICONERROR)
#else
#define ERROR_MESSAGE(message) fputs(message, stderr)
#endif

PyObject * pModule = NULL,
         * pfuncChangeText = NULL,
         * pfuncInit = NULL,
         * pArgs = NULL;

int initialized = 0;

EXPORT int Init() {
    Py_Initialize();
    #if defined(WIN32) || defined(WINDOWS)
    PyRun_SimpleString("import sys\nsys.stderr = open('changetext.err', 'a', 1, encoding='utf-8')\nsys.stdout = open('changetext.log', 'a', 1, encoding='utf-8')");
    #endif
    pModule = PyImport_ImportModule("changetext");
    if(pModule) {
        pfuncChangeText = PyObject_GetAttrString(pModule, "ChangeText");
        if(!(pfuncChangeText && PyCallable_Check(pfuncChangeText))) {
            Py_XDECREF(pfuncChangeText);
            pfuncChangeText = NULL;
            ERROR_MESSAGE("Error: Probably changetext.py module doesn't contain ChangeText function.\n");
        }
        pArgs = PyTuple_New(1);
    }
    else {
        PyErr_PrintEx(1);
        #if defined(WIN32) || defined(WINDOWS)
        ERROR_MESSAGE("Error: Failed to import changetext.py module.\nSee changetext.err for details.\n");
        #endif
    }
    
    initialized = 1; // At least tried to initialize
    return pfuncChangeText!=NULL;
}

#define BUFFER_SIZE 0x100
uint16_t buffer[BUFFER_SIZE];

EXPORT uint16_t * ChangeText(uint16_t * src) {
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
    else return 0;
}
