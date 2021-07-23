#!/bin/bash
sudo rm -rf /usr/local/man/man1/tinmusic.1.gz
sudo rm -rf /usr/local/bin/tinmusic
sudo mandb
echo "tinmusic has been uninstalled."
