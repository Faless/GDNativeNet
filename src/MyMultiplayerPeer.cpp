#include "MyMultiplayerPeer.hpp"

void MyMultiplayerPeer::_register_methods() { }

void MyMultiplayerPeer::_init()
{
	this->MultiplayerPeerNative::_init(); // Always call parent init!
}

/* PacketPeer */
godot_error MyMultiplayerPeer::get_packet(const uint8_t **r_buffer, int &r_len) {
	return GODOT_FAILED;
}

godot_error MyMultiplayerPeer::put_packet(const uint8_t *p_buffer, int p_len) {
	return GODOT_FAILED;
}

godot_int MyMultiplayerPeer::get_available_packet_count() const {
	return 3;
}

godot_int MyMultiplayerPeer::get_max_packet_size() const {
	return 512;
}

/* MultiplayerPeer */
void MyMultiplayerPeer::set_transfer_mode(godot_int p_mode) {

}

godot_int MyMultiplayerPeer::get_transfer_mode() const {
	return 0;
}

void MyMultiplayerPeer::set_target_peer(godot_int p_peer_id) {

}

godot_int MyMultiplayerPeer::get_packet_peer() const {
	return 1;
}

godot_bool MyMultiplayerPeer::is_server() const {
	return false;
}

void MyMultiplayerPeer::poll() {

}

godot_int MyMultiplayerPeer::get_unique_id() const {
	return 2;
}

void MyMultiplayerPeer::set_refuse_new_connections(godot_bool p_enable) {

}

godot_bool MyMultiplayerPeer::is_refusing_new_connections() const {
	return true;
}

godot_int MyMultiplayerPeer::get_connection_status() const {
	return 0;
}
