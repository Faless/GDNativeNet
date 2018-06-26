#include "MyStreamPeer.hpp"

godot_error MyStreamPeer::get_data(uint8_t *p_buffer, int p_bytes) {
	printf("Get data");
	return GODOT_FAILED;
}

godot_error MyStreamPeer::get_partial_data(uint8_t *p_buffer, int p_bytes, int &r_received) {
	printf("Get partial data");
	r_received = 0;
	return GODOT_FAILED;
}

godot_error MyStreamPeer::put_data(const uint8_t *p_buffer, int p_bytes) {
	printf("Put data");
	return GODOT_OK;
}

godot_error MyStreamPeer::put_partial_data(const uint8_t *p_buffer, int p_bytes, int &r_sent) {
	printf("Put data");
	r_sent = 2;
	return GODOT_OK;
}

godot_int MyStreamPeer::get_available_bytes() const {
	printf("Get bytes count");
	return 2;
}

void MyStreamPeer::_register_methods() { }

void MyStreamPeer::_init() {
	this->StreamPeerNative::_init();
}

MyStreamPeer::~MyStreamPeer() {
}
