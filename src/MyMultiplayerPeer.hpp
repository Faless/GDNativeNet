#ifndef MY_MULTIPLAYER_PEER
#define MY_MULTIPLAYER_PEER

#include <Godot.hpp>
#include <Reference.hpp>
#include <MultiplayerPeerGDNative.hpp>

#include <net/godot_net.h>
#include "net/MultiplayerPeerNative.hpp"

class MyMultiplayerPeer : public godot::net::MultiplayerPeerNative {
	GODOT_CLASS(MyMultiplayerPeer, MultiplayerPeerGDNative);
public:
	static void _register_methods();

	void _init();

	/* PacketPeer */
	virtual godot_error get_packet(const uint8_t **r_buffer, int *r_len);
	virtual godot_error put_packet(const uint8_t *p_buffer, int p_len);
	virtual godot_int get_available_packet_count() const;
	virtual godot_int get_max_packet_size() const;

	/* MultiplayerPeer */
	virtual void set_transfer_mode(godot_int p_mode);
	virtual godot_int get_transfer_mode() const;
	virtual void set_target_peer(godot_int p_peer_id);
	virtual int get_packet_peer() const;
	virtual bool is_server() const;
	virtual void poll();
	virtual int get_unique_id() const;
	virtual void set_refuse_new_connections(godot_bool p_enable);
	virtual bool is_refusing_new_connections() const;
	virtual godot_int get_connection_status() const;
};

#endif // MY_MULTIPLAYER_PEER
