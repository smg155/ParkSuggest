#pragma once

#include "ofMain.h"
#include "ofxDatGui.h"
#include "stdio.h"
#include "sqlite3.h"

// Write function for the libcurl API request declaration.
size_t writeFunction(void *ptr, size_t size, size_t nmemb, std::string* data);

class ofApp : public ofBaseApp{
public:
    // Class variables
    ofTrueTypeFont font;
    bool sign_in_should_be_onscreen;
    
    // API URL collection variables.
    
    // User sign-in collection variables.
    std::string username_attempt;
    std::string password_attempt;
    
    // General methods for Open Frameworks.
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    // Text input section.
    ofxDatGuiTextInput* text_input_user;
    ofxDatGuiTextInput* text_input_password;
    void onTextInputEvent(ofxDatGuiTextInputEvent event);
    
    // Sign-in button section.
    ofxDatGuiButton* sign_in_button;
    void onButtonEvent(ofxDatGuiButtonEvent event);
    
    //Check if the sign in is correct.
    bool signInCorrect(std::string username, std::string password);
};
