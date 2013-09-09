#ifdef BUILD_DLL
   // the dll exports
   #define EXPORT __declspec(dllexport)
#else
   // the exe imports
   #define EXPORT __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C" {
#endif

EXPORT int init();
EXPORT wchar_t * ChangeText(wchar_t * src);

#ifdef __cplusplus
}
#endif
