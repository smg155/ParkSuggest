#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // Generalized setup of the window for the application.
    ofSetWindowShape(1920, 1080);
    ofSetBackgroundColor(ofColor::fromHex(0x006C00));
    ofSetWindowPosition(ofGetScreenWidth()/2 - ofGetWidth()/2, 0);
    ofEnableSmoothing();
    ofEnableAlphaBlending();
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    
    // Set up the text input box for username.
    text_input_user = new ofxDatGuiTextInput("Username", "username");
    text_input_user->setTheme(new ofxDatGuiThemeSmoke());
    text_input_user->setWidth(ofGetScreenWidth() / 3, .2);
    text_input_user->setPosition(ofGetScreenWidth() / 3, ofGetScreenHeight() / 2 - ofGetScreenHeight() / 10);
    text_input_user->onTextInputEvent(this, &ofApp::onTextInputEvent);
    
    // Set up the text input box for password.
    text_input_password = new ofxDatGuiTextInput("Password", "password");
    text_input_password->setTheme(new ofxDatGuiThemeSmoke());
    text_input_password->setWidth(ofGetScreenWidth() / 3, .2);
    text_input_password->setPosition(ofGetScreenWidth() / 3, ofGetScreenHeight() / 2);
    text_input_password->onTextInputEvent(this, &ofApp::onTextInputEvent);
    
    // Set up the button for the sign in.
    sign_in_button = new ofxDatGuiButton("Sign In");
    sign_in_button->setWidth(ofGetScreenWidth() / 3, .2);
    sign_in_button->setPosition(ofGetScreenWidth() / 3, ofGetScreenHeight() / 2 + ofGetScreenHeight() / 10);
    sign_in_button->onButtonEvent(this, &ofApp::onButtonEvent);
    sign_in_button->setTheme(new ofxDatGuiThemeSmoke());
    
    // General class variable setup.
    font.load("ofxbraitsch/fonts/Verdana.ttf", 24);
    sign_in_should_be_onscreen = true;
}

//--------------------------------------------------------------
void ofApp::update(){
    text_input_user->update();
    text_input_password->update();
    sign_in_button->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    if (sign_in_should_be_onscreen) {
        text_input_user->draw();
        text_input_password->draw();
        sign_in_button->draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}

//--------------------------------------------------------------
void ofApp::onTextInputEvent(ofxDatGuiTextInputEvent event){
    username_attempt = text_input_user->getText();
    password_attempt = text_input_password->getText();
}

//--------------------------------------------------------------
void ofApp::onButtonEvent(ofxDatGuiButtonEvent event){
    if (signInCorrect(username_attempt, password_attempt)) {
        sign_in_should_be_onscreen = false;
    }
}

//--------------------------------------------------------------
bool ofApp::signInCorrect(std::string username, std::string password){
    return true;
}

// This function adapted from Huu Nguyen in his talk
// at CppCon 2015 about his library, Curl For People.
//--------------------------------------------------------------
// Helper function that writes API response data into API response string.
size_t writeFunction(void *ptr, size_t size, size_t nmemb, std::string* data) {
    data->append((char*) ptr, size * nmemb);
    return size * nmemb;
}
