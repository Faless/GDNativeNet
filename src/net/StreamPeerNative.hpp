#ifndef STREAM_PEER_NATIVE
#define STREAM_PEER_NATIVE

#include <Godot.hpp>
#include <Reference.hpp>
#include <StreamPeerGDNative.hpp>

#include <net/godot_net.h>

/* Forward declare interface functions */
godot_error get_data_bind_sp(void *, uint8_t *, int);
godot_error get_partial_data_bind_sp(void *, uint8_t *, int, int *);
godot_error put_data_bind_sp(void *, const uint8_t *, int);
godot_error put_partial_data_bind_sp(void *, const uint8_t *, int, int *);
godot_int get_available_bytes_bind_sp(const void *);

class StreamPeerNative : public godot::StreamPeerGDNative {
	GODOT_CLASS(StreamPeerNative, godot::StreamPeerGDNative);

protected:
	godot_net_stream_peer interface = {
		{3, 1},
		this,
		&get_data_bind_sp,
		&get_partial_data_bind_sp,
		&put_data_bind_sp,
		&put_partial_data_bind_sp,
		&get_available_bytes_bind_sp,
		NULL
	};

public:
	static void _register_methods();

	void _init();

	/* StreamPeer */
	virtual godot_error get_data(uint8_t *p_buffer, int p_bytes) = 0;
	virtual godot_error get_partial_data(uint8_t *p_buffer, int p_bytes, int *r_reveived) = 0;
	virtual godot_error put_data(const uint8_t *p_buffer, int p_bytes) = 0;
	virtual godot_error put_partial_data(const uint8_t *p_buffer, int p_bytes, int *r_sent) = 0;
	virtual godot_int get_available_bytes() const = 0;

	~StreamPeerNative();
};

#endif // STREAM_PEER_NATIVE
