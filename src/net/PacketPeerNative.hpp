#ifndef PACKET_PEER_NATIVE
#define PACKET_PEER_NATIVE

#include <Godot.hpp>
#include <Reference.hpp>
#include <PacketPeerGDNative.hpp>

#include <net/godot_net.h>

/* Forward declare interface functions */
godot_error get_packet_bind_pp(void *, const uint8_t **, int &);
godot_error put_packet_bind_pp(void *, const uint8_t *, int);
godot_int get_available_packet_count_bind_pp(const void *);
godot_int get_max_packet_size_bind_pp(const void *);

class PacketPeerNative : public godot::PacketPeerGDNative {
	GODOT_CLASS(PacketPeerNative, godot::PacketPeerGDNative);

protected:
	godot_net_packet_peer interface = {
		{3, 1},
		this,
		&get_packet_bind_pp,
		&put_packet_bind_pp,
		&get_available_packet_count_bind_pp,
		&get_max_packet_size_bind_pp,
		NULL
	};

public:
	static void _register_methods();

	void _init();

	/* PacketPeer */
	virtual godot_error get_packet(const uint8_t **r_buffer, int &r_len) = 0;
	virtual godot_error put_packet(const uint8_t *p_buffer, int p_len) = 0;
	virtual godot_int get_available_packet_count() const = 0;
	virtual godot_int get_max_packet_size() const = 0;

	~PacketPeerNative();
};

#endif // PACKET_PEER_NATIVE
