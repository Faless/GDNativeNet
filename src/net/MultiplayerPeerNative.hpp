#ifndef MULTIPLAYER_PEER_NATIVE
#define MULTIPLAYER_PEER_NATIVE

#include <Godot.hpp>
#include <Reference.hpp>
#include <MultiplayerPeerGDNative.hpp>

#include <net/godot_net.h>

namespace godot {
namespace net {

/* Forward declare interface functions (PacketPeer) */
godot_error get_packet_bind_mp(void *, const uint8_t **, int &);
godot_error put_packet_bind_mp(void *, const uint8_t *, int);
godot_int get_available_packet_count_bind_mp(const void *);
godot_int get_max_packet_size_bind_mp(const void *);

/* Forward declare interface functions (MultiplayerPeer) */
void set_transfer_mode_bind_mp(void *, godot_int);
godot_int get_transfer_mode_bind_mp(const void *);
void set_target_peer_bind_mp(void *, godot_int); // 0 = broadcast, 1 = server, <0 = all but abs(value)
godot_int get_packet_peer_bind_mp(const void *);
godot_bool is_server_bind_mp(const void *);
void poll_bind_mp(void *);
int32_t get_unique_id_bind_mp(const void *); // Must be > 0, 1 is for server
void set_refuse_new_connections_bind_mp(void *, godot_bool);
godot_bool is_refusing_new_connections_bind_mp(const void *);
godot_int get_connection_status_bind_mp(const void *);

class MultiplayerPeerNative : public MultiplayerPeerGDNative {
	GODOT_CLASS(MultiplayerPeerNative, MultiplayerPeerGDNative);

protected:
	godot_net_multiplayer_peer interface = {
		{3, 1},
		this,
		&get_packet_bind_mp,
		&put_packet_bind_mp,
		&get_available_packet_count_bind_mp,
		&get_max_packet_size_bind_mp,
		&set_transfer_mode_bind_mp,
		&get_transfer_mode_bind_mp,
		&set_target_peer_bind_mp, // 0 = broadcast, 1 = server, <0 = all but abs(value)
		&get_packet_peer_bind_mp,
		&is_server_bind_mp,
		&poll_bind_mp,
		&get_unique_id_bind_mp, // Must be > 0, 1 is for server
		&set_refuse_new_connections_bind_mp,
		&is_refusing_new_connections_bind_mp,
		&get_connection_status_bind_mp,
		NULL
	};

public:
	static void _register_methods();

	void _init();
	~MultiplayerPeerNative();

	/* PacketPeer */
	virtual godot_error get_packet(const uint8_t **r_buffer, int &r_len) = 0;
	virtual godot_error put_packet(const uint8_t *p_buffer, int p_len) = 0;
	virtual godot_int get_available_packet_count() const = 0;
	virtual godot_int get_max_packet_size() const = 0;

	/* MultiplayerPeer */
	virtual void set_transfer_mode(godot_int p_mode) = 0;
	virtual godot_int get_transfer_mode() const = 0;
	virtual void set_target_peer(godot_int p_peer_id) = 0;
	virtual int get_packet_peer() const = 0;
	virtual bool is_server() const = 0;
	virtual void poll() = 0;
	virtual int get_unique_id() const = 0;
	virtual void set_refuse_new_connections(godot_bool p_enable) = 0;
	virtual bool is_refusing_new_connections() const = 0;
	virtual godot_int get_connection_status() const = 0;
};

}
}
#endif // MULTIPLAYER_PEER_NATIVE
