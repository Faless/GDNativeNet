#include "StreamPeerNative.hpp"

void StreamPeerNative::_register_methods() { }

void StreamPeerNative::_init() {
	godot_net_bind_stream_peer(_owner, &interface);
}

StreamPeerNative::~StreamPeerNative() {
	if (_owner) {
		godot_net_bind_stream_peer(_owner, NULL);
	}
}

/*
 * The C interface that implements StreamPeer.
 * In this case it forwards calls to our C++ class, but could be plain C,
 * and you could use void *user for any kind of state struct pointer you have.
 */
godot_error get_data_bind_sp(void *user, uint8_t *p_buffer, int p_bytes) {
	return ((StreamPeerNative *) user)->get_data(p_buffer, p_bytes);
}

godot_error get_partial_data_bind_sp(void *user, uint8_t *p_buffer, int p_bytes, int &r_received) {
	return ((StreamPeerNative *) user)->get_partial_data(p_buffer, p_bytes, r_received);
}

godot_error put_data_bind_sp(void *user, const uint8_t *p_buffer, int p_bytes) {
	return ((StreamPeerNative *) user)->put_data(p_buffer, p_bytes);
}

godot_error put_partial_data_bind_sp(void *user, const uint8_t *p_buffer, int p_bytes, int &r_sent) {
	return ((StreamPeerNative *) user)->put_partial_data(p_buffer, p_bytes, r_sent);
}

godot_int get_available_bytes_bind_sp(const void *user) {
	return ((StreamPeerNative *) user)->get_available_bytes();
}
