#include "ofMain.h"
#include "ofApp.h"

//#ifdef MOSAIC_ENABLE_PROFILING
#ifdef TRACY_ENABLE
#include <Tracy.hpp>
#include <memory>

// Overload global new and delete for memory inspection
void* operator new(std::size_t n)
{
    void* ptr = malloc(n);
    TracyAlloc(ptr, n);
    return ptr;
}
void operator delete(void* ptr) noexcept
{
    TracyFree(ptr);
    free(ptr);
}
#endif

//========================================================================
int main( ){
#ifdef TRACY_ENABLE
    ZoneScopedN("main()");
#endif
    ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context

    // this kicks off the running of my app
    // can be OF_WINDOW or OF_FULLSCREEN
    // pass in width and height too:
    ofRunApp(new ofApp());

}
