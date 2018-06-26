#ifndef MY_STREAM_PEER
#define MY_STREAM_PEER

#include <Godot.hpp>

#include "net/StreamPeerNative.hpp"

class MyStreamPeer : public StreamPeerNative {
	GODOT_CLASS(MyStreamPeer, StreamPeerNative);

public:
	static void _register_methods();

	void _init();

	/* StreamPeer */
	virtual godot_error get_data(uint8_t *p_buffer, int p_bytes);
	virtual godot_error get_partial_data(uint8_t *p_buffer, int p_bytes, int &r_received);
	virtual godot_error put_data(const uint8_t *p_buffer, int p_bytes);
	virtual godot_error put_partial_data(const uint8_t *p_buffer, int p_bytes, int &r_sent);
	virtual godot_int get_available_bytes() const;

	~MyStreamPeer();
};

#endif // MY_STREAM_PEER
