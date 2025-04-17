#!/bin/sh

curl -I "$1" 2>/dev/null | grep "Location:" | cut -d " " -f 2
