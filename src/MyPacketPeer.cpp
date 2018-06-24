#include "MyPacketPeer.hpp"

godot_error MyPacketPeer::get_packet(const uint8_t **r_buffer, int &r_len) {
	printf("Get packet");
	r_len = 0;
	return GODOT_OK;
}

godot_error MyPacketPeer::put_packet(const uint8_t *p_buffer, int p_len) {
	printf("Put packet");
	return GODOT_OK;
}

godot_int MyPacketPeer::get_available_packet_count() const {
	printf("Get packet count");
	return 2;
}

godot_int MyPacketPeer::get_max_packet_size() const {
	printf("Get max packet size");
	return 1024;
}

void MyPacketPeer::_register_methods() { }

void MyPacketPeer::_init() {
	this->PacketPeerNative::_init();
}

MyPacketPeer::~MyPacketPeer() {
}
