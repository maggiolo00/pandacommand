#!/bin/sh

valac -g --save-temps  --pkg   gmodule-2.0 --pkg gee-1.0  --pkg libsoup-2.4 --pkg gstreamer-0.10 -C PandaRadio.vala PandaPlayer.vala ../../src/PandaPlugin.vala
gcc -shared -fPIC $(pkg-config --cflags --libs glib-2.0 gmodule-2.0 libsoup-2.4 gstreamer-0.10 gee-1.0 ) -o libpandaradio.so PandaRadio.c  PandaPlayer.c PandaPlugin.c
