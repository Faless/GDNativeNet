#include "MultiplayerPeerNative.hpp"

namespace godot {
namespace net {

void MultiplayerPeerNative::_register_methods() { }

void MultiplayerPeerNative::_init()
{
	godot_net_bind_multiplayer_peer(_owner, &interface);
}

MultiplayerPeerNative::~MultiplayerPeerNative() {
	if (_owner) {
		godot_net_bind_multiplayer_peer(_owner, NULL);
	}
}

/*
 * The C interface that implements PacketPeer.
 * In this case it forwards calls to our C++ class, but could be plain C,
 * and you could use void *user for any kind of state struct pointer you have.
 */
godot_error get_packet_bind_mp(void *user, const uint8_t **r_buffer, int *r_len) {
	return ((MultiplayerPeerNative *) user)->get_packet(r_buffer, r_len);
}

godot_error put_packet_bind_mp(void *user, const uint8_t *p_buffer, int p_len) {
	return ((MultiplayerPeerNative *) user)->put_packet(p_buffer, p_len);
}

godot_int get_available_packet_count_bind_mp(const void *user) {
	return ((MultiplayerPeerNative *) user)->get_available_packet_count();
}

godot_int get_max_packet_size_bind_mp(const void *user) {
	return ((MultiplayerPeerNative *) user)->get_max_packet_size();
}

/*
 * The C interface that implements NetworkedMultiplayerPeer.
 * In this case it forwards calls to our C++ class, but could be plain C,
 * and you could use void *user for any kind of state struct pointer you have.
 */
void set_transfer_mode_bind_mp(void *user, godot_int p_mode) {
	((MultiplayerPeerNative *) user)->set_transfer_mode(p_mode);
}

godot_int get_transfer_mode_bind_mp(const void *user) {
	return ((MultiplayerPeerNative *) user)->get_transfer_mode();
}

void set_target_peer_bind_mp(void *user, godot_int p_target) {
	((MultiplayerPeerNative *) user)->set_target_peer(p_target);
}

godot_int get_packet_peer_bind_mp(const void *user) {
	return ((MultiplayerPeerNative *) user)->get_packet_peer();
}

godot_bool is_server_bind_mp(const void *user) {
	return ((MultiplayerPeerNative *) user)->is_server();
}

void poll_bind_mp(void *user) {
	((MultiplayerPeerNative *) user)->poll();
}

int32_t get_unique_id_bind_mp(const void *user) {
	return ((MultiplayerPeerNative *) user)->get_unique_id();
}

void set_refuse_new_connections_bind_mp(void *user, godot_bool p_refuse) {
	((MultiplayerPeerNative *) user)->set_refuse_new_connections(p_refuse);
}

godot_bool is_refusing_new_connections_bind_mp(const void *user) {
	return ((MultiplayerPeerNative *) user)->is_refusing_new_connections();
}

godot_int get_connection_status_bind_mp(const void *user) {
	return ((MultiplayerPeerNative *) user)->get_connection_status();
}

}
}
