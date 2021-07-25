#!/bin/bash
make
sudo cp -r tinmusic /usr/local/bin/tinmusic
sudo mkdir -p /usr/local/man/man1/
install -g 0 -o 0 -m 0644 tinmusic.1 /usr/local/man/man1/
sudo gzip -f /usr/local/man/man1/tinmusic.1
sudo mandb
echo "tinmusic has been installed."
