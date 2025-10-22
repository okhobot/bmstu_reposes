#!/bin/bash
PORT=54321
echo "Starting echo server on port $PORT..."
ncat -l -p $PORT -c 'xargs -n1 echo'
