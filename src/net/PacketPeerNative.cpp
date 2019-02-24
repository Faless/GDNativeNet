#include "PacketPeerNative.hpp"

void PacketPeerNative::_register_methods() { }

void PacketPeerNative::_init() {
	godot_net_bind_packet_peer(_owner, &interface);
}

PacketPeerNative::~PacketPeerNative() {
	if (_owner) {
		godot_net_bind_packet_peer(_owner, NULL);
	}
}

/*
 * The C interface that implements PacketPeer.
 * In this case it forwards calls to our C++ class, but could be plain C,
 * and you could use void *user for any kind of state struct pointer you have.
 */
godot_error get_packet_bind_pp(void *user, const uint8_t **r_buffer, int *r_len) {
	return ((PacketPeerNative *) user)->get_packet(r_buffer, r_len);
}

godot_error put_packet_bind_pp(void *user, const uint8_t *p_buffer, int p_len) {
	return ((PacketPeerNative *) user)->put_packet(p_buffer, p_len);
}

godot_int get_available_packet_count_bind_pp(const void *user) {
	return ((PacketPeerNative *) user)->get_available_packet_count();
}

godot_int get_max_packet_size_bind_pp(const void *user) {
	return ((PacketPeerNative *) user)->get_max_packet_size();
}
