# PacketPeer and MultiplayerPacketPeer via GDNative C++ Bindings

## Requirements

Create a new folder. And inside that folder follow these steps
- Clone godot from PR branch (`git clone https://github.com/Faless/godot -b gdnet_pr`)
- Clone godot-cpp `nativescript-1.1` branch (`git clone https://github.com/GodotNativeTools/godot-cpp -b nativescript-1.1`)
- Clone this repo (`git clone https//github.com/Faless/GDNativeNet`)

## Building

- From the `godot` folder:
  - Compile godot (e.g. `scons p=x11 -j9`)
  - Export new API json file to the `godot-cpp` folder: e.g. `bin/godot.x11.tools.64 --gdnative-generate-json-api ../godot-cpp/godot_api.json`
- From the `godot-cpp` folder:
  - The first time, create a new folder in `src/gen` (e.g. `mkdir src/gen`)
  - Build and regenerate bindings: e.g. `scons godotbinpath="../godot/bin/godot.x11.tools.64" generate_bindings=yes use_custom_api_file=yes custom_api_file="godot_api.json" headers="../godot/modules/gdnative/include/" p=linux regenerate_headers=yes -j9`
  - Move the compiled library to appropriate name (`libgodot-cpp.a` on GNU/Linux): e.g. `cp bin/libgodot-cpp.linux.64.a bin/libgodot-cpp.a`
- From the `GDNativeNet` folder:
  - Build using `./build.sh`
  - Copy resulting lib (`lib/MyNetworkPeer.so`) to `demo/lib/MyNetworkPeer.so`: e.g. `cp lib/MyNetworkPeer.so demo/lib/MyNetworkPeer.so`
  - Run demo project with `../godot/bin/godot.x11.tools.64 --path demo/`
