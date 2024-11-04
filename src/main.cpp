#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){

	// Use ofGLFWWindowSettings for more options like multi-monitor fullscreen
	ofGLWindowSettings settings;
	settings.setSize(1024, 768);
	settings.windowMode = OF_WINDOW; // Can also be OF_FULLSCREEN

	const auto window = ofCreateWindow(settings);

	ofRunApp(window, make_shared<of_app>());
	ofRunMainLoop();
}
