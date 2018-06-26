extends Node

const NativeStreamPeer = preload("res://lib/stream_peer_gdnative.gdns")
const NativePacketPeer = preload("res://lib/packet_peer_gdnative.gdns")
const NativeMultiplayerPeer = preload("res://lib/multiplayer_peer_gdnative.gdns")
var _packet_peer = NativePacketPeer.new()
var _multiplayer_peer = NativeMultiplayerPeer.new()
var _stream_peer = NativeStreamPeer.new()

func _ready():
	printt(_packet_peer, _multiplayer_peer, _stream_peer)
	var data = PoolByteArray([1, 5, 6])
	prints("\nPacket Peer Tests")
	prints("Get available packet count:", _packet_peer.get_available_packet_count())
	prints("Put packet:", _packet_peer.put_packet(data))
	prints("Get packet (size):", _packet_peer.get_packet().size())
	prints("Put var:", _packet_peer.put_var(1))
	prints("Allow decoding:", _packet_peer.allow_object_decoding)

	prints("\nMultiplayer Peer Tests")
	prints("Get connection status:", _multiplayer_peer.get_connection_status())
	prints("Poll:", _multiplayer_peer.poll())

	prints("\nStream Peer Tests")
	prints("Get available bytes:", _stream_peer.get_available_bytes())
	prints("Get data:", _stream_peer.get_data(5))
	prints("Get partial data:", _stream_peer.get_partial_data(5))
	prints("Put data:", _stream_peer.put_data(data))
	prints("Put partial data:", _stream_peer.put_partial_data(data))
