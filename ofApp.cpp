#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(239);
	ofSetWindowTitle("Insta");

	ofSetLineWidth(3);
	ofNoFill();
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
	
	ofTranslate(ofGetWidth() * 0.5, ofGetHeight() * 0.5);

	ofColor color;

	for (int len = 45; len < 720; len += 15) {

		color.setHsb(ofMap(len, 45, 720, 0, 255), 200, 200);
		ofSetColor(color);

		int deg_start = ofGetFrameNum() + len;

		ofBeginShape();
		for (int deg = deg_start; deg < deg_start + 45; deg += 1) {

			ofVertex(this->make_rect_point(len, deg));
		}
		ofEndShape();

		deg_start += 180;
		ofBeginShape();
		for (int deg = deg_start; deg < deg_start + 45; deg += 1) {

			ofVertex(this->make_rect_point(len, deg));
		}
		ofEndShape();
	}
}

//--------------------------------------------------------------
ofPoint ofApp::make_rect_point(float len, int deg, int z) {

	int half_len = len * 0.5;
	int param = (deg + 45) / 90;

	ofPoint point;

	switch (param % 4) {

	case 0:

		return ofPoint(half_len, ofMap((deg + 45) % 90, 0, 89, -half_len, half_len), z);
	case 1:

		return  ofPoint(ofMap((deg + 45) % 90, 0, 89, half_len, -half_len), half_len, z);
	case 2:

		return ofPoint(-half_len, ofMap((deg + 45) % 90, 0, 89, half_len, -half_len), z);
	case 3:

		return ofPoint(ofMap((deg + 45) % 90, 0, 89, -half_len, half_len), -half_len, z);
	default:

		return ofPoint(0, 0, 0);
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}