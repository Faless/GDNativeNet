extends Node

const NativePacketPeer = preload("res://lib/packet_peer_gdnative.gdns")
const NativeMultiplayerPeer = preload("res://lib/multiplayer_peer_gdnative.gdns")
var _packet_peer = NativePacketPeer.new()
var _multiplayer_peer = NativeMultiplayerPeer.new()

func _ready():
	print(_packet_peer)
	prints("Get available packet count:", _packet_peer.get_available_packet_count())
	prints("Put packet:", _packet_peer.put_packet(PoolByteArray([0])))
	prints("Get packet (size):", _packet_peer.get_packet().size())
	prints("Put var:", _packet_peer.put_var(1))
	prints("Allow decoding:", _packet_peer.allow_object_decoding)

	prints("\nMultiplayer Peer Tests")
	prints("Get connection status:", _multiplayer_peer.get_connection_status())
	prints("Poll:", _multiplayer_peer.poll())