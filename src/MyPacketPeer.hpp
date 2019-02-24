#ifndef MY_PACKET_PEER
#define MY_PACKET_PEER

#include <Godot.hpp>

#include "net/PacketPeerNative.hpp"

class MyPacketPeer : public PacketPeerNative {
	GODOT_CLASS(MyPacketPeer, PacketPeerNative);

public:
	static void _register_methods();

	void _init();

	/* PacketPeer */
	virtual godot_error get_packet(const uint8_t **r_buffer, int *r_len);
	virtual godot_error put_packet(const uint8_t *p_buffer, int p_len);
	virtual godot_int get_available_packet_count() const;
	virtual godot_int get_max_packet_size() const;

	~MyPacketPeer();
};

#endif // MY_PACKET_PEER
