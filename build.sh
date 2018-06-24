#/bin/sh
CC_FLAGS="-g -O3 -std=c++14" # Build flags
INC="-I../godot-cpp/include/core -I../godot-cpp/include/gen -I../godot-cpp/include" # C++ NativeScript
BASE="-I../godot/modules/gdnative/include/" # gdnative_api_struct.gen.h
CC_OPTS="$CC_FLAGS $INC $BASE"

clang -fPIC -o src/net/PacketPeerNative.os -c src/net/PacketPeerNative.cpp $CC_OPTS
clang -fPIC -o src/net/MultiplayerPeerNative.os -c src/net/MultiplayerPeerNative.cpp $CC_OPTS
# PacketPeer
clang -fPIC -o src/MyPacketPeer.os -c src/MyPacketPeer.cpp $CC_OPTS
# MultiplayerPeer
clang -fPIC -o src/MyMultiplayerPeer.os -c src/MyMultiplayerPeer.cpp $CC_OPTS
# Init
clang -fPIC -o src/init.os -c src/init.cpp $CC_OPTS

# Library
clang -o lib/MyNetworkPeer.so -shared src/MyMultiplayerPeer.os src/MyPacketPeer.os src/net/PacketPeerNative.os src/net/MultiplayerPeerNative.os src/init.os -L../godot-cpp/bin -lgodot-cpp
