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

EXPORT int Init();
EXPORT uint16_t * ChangeText(uint16_t * src);

#ifdef __cplusplus
}
#endif
